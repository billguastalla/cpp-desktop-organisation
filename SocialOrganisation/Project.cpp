#include "Project.h"
#include "ProjectInfo.h"
#include "FileIO.h"

#include "SocialApplication.h"
#include "ProjectDialog.h"

#include <qmessagebox.h>
#include <qfile.h>
#include <qfiledialog.h>

#include <qxmlstream.h>

#include <cassert>

Project::Project(SocialApplication * parent)
	: SerialisableObject(nullptr), QObject(parent),
	m_pInfo(nullptr), m_state(ProjectState::FileClosed), m_currentPath()
{
	m_app = parent;
}

bool Project::createNewFile()
{	
	if(warnSave())
	{
		ProjectInfo * projectInfo = new ProjectInfo(this);
		ProjectDialog * newProjDlg = new ProjectDialog(projectInfo,m_app);
		if(newProjDlg->exec() == QDialog::Accepted)
		{
			delete m_pInfo;
			m_pInfo = projectInfo;
			m_state = ProjectState::FileCreated;
			emit projectStateChanged(m_state);
			return true;
		}
		else
		{
			delete projectInfo;
			return false;
		}
	}
	else return false;
}

bool Project::openFromFile(bool silent)
{
	if(warnSave())
	{
		bool success = false;
		QString fileName = QFileDialog::getOpenFileName(m_app,"Open Project",	m_currentPath,"All files (*.*)");
		if(fileName.count() == 0)
			return false;
		QFile a (fileName);
		if (!a.open(QFile::ReadOnly | QFile::Text))
		{
			return false;
		}

		assert(m_pInfo == nullptr); /*<-- pInfo should be deleted here.*/

		ProjectInfo * pInfo_Open = new ProjectInfo(this);

		QXmlStreamReader reader (&a);
		if(pInfo_Open->__parseFromFile(reader)) /*<--- Bug: here if */
		{
			m_pInfo = pInfo_Open;
			m_currentPath = fileName;
			m_state = ProjectState::FileOpen;
			emit projectStateChanged(m_state);
			return true;
		}
		else
		{
			delete pInfo_Open;
			return false;
		}
	}
	return false;
}

bool Project::saveToFile(bool silent, QString path)
{
	if(m_state != ProjectState::FileClosed)
	{

		QFile saveFile (path);
		if (!saveFile.open(QFile::WriteOnly | QFile::Text))
			return false;
		QXmlStreamWriter writer (&saveFile);
		writer.setAutoFormatting(true);
		writer.writeStartDocument();
		__writeToFile(writer);
		writer.writeEndDocument();
		saveFile.close();
		m_state = ProjectState::FileOpen;
		emit projectStateChanged(m_state);
		return true;
	}
	return false;
}

bool Project::saveAsToFile(bool silent)
{
	if(m_state != ProjectState::FileClosed)
	{
		QString fileName = QFileDialog::getSaveFileName(m_app,"Save Project", m_currentPath ,"All files (*.*)");
		//	fileName.append(".sclProj");
		if(fileName.count() == 0)
			return false;
		else
			return saveToFile(silent, fileName);
	}
	return false;
}

bool Project::closeProject(bool silent)
{
	if(!silent)
		if(!warnSave())
			return false;
	if(m_pInfo != nullptr)
	{
		m_state = ProjectState::FileClosed;
		emit projectStateChanged(m_state);
		delete m_pInfo;
		m_pInfo = nullptr;
		return true;
	}
	return true;
}

bool Project::warnSave()
{
	if(m_pInfo != nullptr && (m_state == ProjectState::FileCreated || m_state == ProjectState::FileModified))
	{
		// save current project?
		switch(QMessageBox::question(
			m_app,
			tr("Save existing project"),
			tr("Do you want to save the existing project, ") + m_pInfo->projectName() +
			tr(" before continuing?"),
			QFlags<QMessageBox::StandardButton>(
			(QMessageBox::StandardButton::Yes) |
			(QMessageBox::StandardButton::No)  | 
			(QMessageBox::StandardButton::Cancel)
			)
			))
		{
		case QMessageBox::StandardButton::Yes:
			{
				if(saveAsToFile())
					return closeProject(true);
				else
					return false;
			}
		case QMessageBox::StandardButton::No:
			{
				return closeProject(true);
			}
		case QMessageBox::StandardButton::Cancel:
			return false;
		default:
			return false;
		}
	}
	else
		return true;
}

bool Project::__writeToFile(QXmlStreamWriter & writer)
{
	return m_pInfo->__writeToFile(writer);
}

bool Project::__parseFromFile(QXmlStreamReader & reader)
{
	return m_pInfo->__parseFromFile(reader);
}

QList<SerialisableObject*> Project::m_children()
{
	QList<SerialisableObject*> children;
	children.push_back(m_pInfo);
	return children;
}