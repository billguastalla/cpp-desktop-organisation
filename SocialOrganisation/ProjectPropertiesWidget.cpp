#include "ProjectPropertiesWidget.h"

#include "ProjectInfo.h"

#include <qformlayout.h>
#include <qplaintextedit.h>
#include <qlabel.h>
#include <qlineedit.h>

ProjectPropertiesWidget::ProjectPropertiesWidget(ProjectInfo * proj, QWidget * parent) : QWidget(parent)
{
	// Hold passed project info.
	m_project = proj;
	
	m_lay = new QFormLayout(this);

	m_nameEdit								= new QLineEdit(m_project->projectName(), this);
	m_idEdit								= new QLineEdit(m_project->id(), this);
	m_idEdit->setDisabled(true);
	m_fileDirectoryEdit						= new QLineEdit(m_project->fileDirectory(), this);
	m_fileDirectoryEdit->setDisabled(true);
	m_authorEdit							= new QLineEdit(m_project->author(), this);
	m_notesEdit								= new QPlainTextEdit(m_project->notes(), this);

	m_lay->addRow(tr("Name"),				 m_nameEdit);
	m_lay->addRow(tr("Author"),				 m_authorEdit);
	m_lay->addRow(tr("Notes"),				 m_notesEdit);
	m_lay->addRow(tr("Project ID"),			 m_idEdit);
	m_lay->addRow(tr("Working Directory"),	 m_fileDirectoryEdit);

	setLayout(m_lay);
}

void ProjectPropertiesWidget::save()
{
	m_project->projectName() = m_nameEdit->text();
	m_project->id() = m_idEdit->text();
	m_project->fileDirectory() = m_fileDirectoryEdit->text();
	m_project->author() = m_authorEdit->text();
	m_project->notes() = m_notesEdit->toPlainText();
}