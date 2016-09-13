#include "SocialMenuBar.h"
#include "SocialApplication.h"
#include "Project.h"

#include "ProjectDialog.h"
#include "PreferencesDialog.h"

SocialMenuBar::SocialMenuBar(Project * proj, SocialApplication * parent)
	: QMenuBar(parent),
	m_proj(proj),
	m_app(parent)
{
	createActions();
	createMenus();

	connect(m_proj,SIGNAL(projectStateChanged(ProjectState)),this,SLOT(updateMenuBar(ProjectState)));
	updateMenuBar(m_proj->state());
}

void SocialMenuBar::createActions()
{
	// File
	m_fileActions[FileActions::New] = new QAction(tr("&New"), this);
	m_fileActions[FileActions::New]->setShortcuts(QKeySequence::New);
	m_fileActions[FileActions::New]->setStatusTip(tr("Create a new social project"));
	connect(m_fileActions[FileActions::New], &QAction::triggered, m_proj, &Project::createNewFile);

	m_fileActions[FileActions::Load] = new QAction(tr("&Load"), this);
	m_fileActions[FileActions::Load]->setShortcuts(QKeySequence::Open);
	m_fileActions[FileActions::Load]->setStatusTip(tr("Load a project from file"));
	connect(m_fileActions[FileActions::Load], &QAction::triggered, m_proj, &Project::openFromFile);

	m_fileActions[FileActions::Save] = new QAction(tr("&Save"), this);
	m_fileActions[FileActions::Save]->setShortcuts(QKeySequence::Save);
	m_fileActions[FileActions::Save]->setStatusTip(tr("Save this project"));
	connect(m_fileActions[FileActions::Save], SIGNAL(triggered()), m_proj, SLOT(saveToFile()));

	m_fileActions[FileActions::SaveAs] = new QAction(tr("&Save As"), this);
	m_fileActions[FileActions::SaveAs]->setShortcuts(QKeySequence::SaveAs);
	m_fileActions[FileActions::SaveAs]->setStatusTip(tr("Save this project as a new file"));
	connect(m_fileActions[FileActions::SaveAs], &QAction::triggered, m_proj, &Project::saveAsToFile);

	m_fileActions[FileActions::CloseProject] = new QAction(tr("&Close Current Project"), this);
	//m_fileActions[FileActions::CloseProject]->setShortcuts(QKeySequence::);
	m_fileActions[FileActions::CloseProject]->setStatusTip(tr("Close the current project"));
	connect(m_fileActions[FileActions::CloseProject], &QAction::triggered, m_proj, &Project::closeProject);

	m_fileActions[FileActions::Exit] = new QAction(tr("&Exit"), this);
	m_fileActions[FileActions::Exit]->setShortcuts(QKeySequence::Close);
	m_fileActions[FileActions::Exit]->setStatusTip(tr("Close the program"));
	connect(m_fileActions[FileActions::Exit], &QAction::triggered, m_app, &SocialApplication::close);

	// Edit
	m_editActions[EditActions::Preferences] = new QAction(tr("&Preferences"), this);
	m_editActions[EditActions::Preferences]->setShortcuts(QKeySequence::Preferences);
	m_editActions[EditActions::Preferences]->setStatusTip(tr("Edit Preferences"));
	connect(m_editActions[EditActions::Preferences], &QAction::triggered, this, &SocialMenuBar::preferencesEdit);

	// Project
	m_projectActions[ProjectActions::Properties] = new QAction(tr("&Properties"), this);
	m_projectActions[ProjectActions::Properties]->setStatusTip(tr("Properties of the current Project"));
	connect(m_projectActions[ProjectActions::Properties], &QAction::triggered, this, &SocialMenuBar::propertiesEdit);
}

void SocialMenuBar::createMenus()
{
	m_fileMenu = addMenu(tr("File"));
	QMapIterator<FileActions,QAction*> fileActIter(m_fileActions);
	while(fileActIter.hasNext())
	{
		fileActIter.next();
		m_fileMenu->addAction(m_fileActions[fileActIter.key()]);
	}
	m_editMenu = addMenu(tr("Edit"));
	QMapIterator<EditActions,QAction*> editActIter(m_editActions);
	while(editActIter.hasNext())
	{
		editActIter.next();
		m_editMenu->addAction(m_editActions[editActIter.key()]);
	}
	m_projectMenu = addMenu(tr("Project"));
	QMapIterator<ProjectActions,QAction*> projActIter(m_projectActions);
	while(projActIter.hasNext())
	{
		projActIter.next();
		m_projectMenu->addAction(m_projectActions[projActIter.key()]);
	}
}

void SocialMenuBar::preferencesEdit()
{
	PreferencesDialog * dlg = new PreferencesDialog(this);
	dlg->exec();
}

void SocialMenuBar::propertiesEdit()
{
	// Open properties for the current project.
	ProjectDialog * dlg = new ProjectDialog(m_proj->data(), this);
	dlg->exec();
}

void SocialMenuBar::updateMenuBar(ProjectState state)
{
	switch (state)
	{
	case ProjectState::FileClosed:
		m_fileActions[FileActions::Save]->setEnabled(false);
		m_fileActions[FileActions::SaveAs]->setEnabled(false);
		m_fileActions[FileActions::CloseProject]->setEnabled(false);
		{
			QMapIterator<ProjectActions,QAction*> projectActionIter(m_projectActions);
			while(projectActionIter.hasNext())
			{
				projectActionIter.next();
				m_projectActions[projectActionIter.key()]->setEnabled(false);
			}
		}
		break;
	case ProjectState::FileCreated:
		m_fileActions[FileActions::Save]->setEnabled(false);
		m_fileActions[FileActions::SaveAs]->setEnabled(true);
		m_fileActions[FileActions::CloseProject]->setEnabled(true);
		{
			QMapIterator<ProjectActions,QAction*> projectActionIter(m_projectActions);
			while(projectActionIter.hasNext())
			{
				projectActionIter.next();
				m_projectActions[projectActionIter.key()]->setEnabled(true);
			}
		}
		break;
	case ProjectState::FileOpen:
		m_fileActions[FileActions::Save]->setEnabled(false);
		m_fileActions[FileActions::SaveAs]->setEnabled(true);
		m_fileActions[FileActions::CloseProject]->setEnabled(true);
		{
			QMapIterator<ProjectActions,QAction*> projectActionIter(m_projectActions);
			while(projectActionIter.hasNext())
			{
				projectActionIter.next();
				m_projectActions[projectActionIter.key()]->setEnabled(true);
			}
		}
		break;
	case ProjectState::FileModified:
		m_fileActions[FileActions::Save]->setEnabled(true);
		m_fileActions[FileActions::SaveAs]->setEnabled(true);
		m_fileActions[FileActions::CloseProject]->setEnabled(true);
		{
			QMapIterator<ProjectActions,QAction*> projectActionIter(m_projectActions);
			while(projectActionIter.hasNext())
			{
				projectActionIter.next();
				m_projectActions[projectActionIter.key()]->setEnabled(true);
			}
		}
		break;
	default:
		break;
	}
}