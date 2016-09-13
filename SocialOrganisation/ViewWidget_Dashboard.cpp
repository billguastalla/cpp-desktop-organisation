#include "ViewWidget_Dashboard.h"
#include "Project.h"
#include "ProjectInfo.h"
#include "Person.h"

#include <qlineedit.h>
#include <qlabel.h>
#include <qformlayout.h>

ViewWidget_Dashboard::ViewWidget_Dashboard(Project * proj, TabManager * app)
	: ViewWidget_Base(proj,app)
{
	m_peopleCountLabel = new QLabel("Total People:",this);
	m_peopleCountEdit = new QLineEdit(this);

	m_layout = new QFormLayout(this);
	m_layout->addRow(m_peopleCountLabel,m_peopleCountEdit);

	connect(m_proj,SIGNAL(projectStateChanged(ProjectState)),this,SLOT(updateDashboard(ProjectState)));
	updateDashboard(m_proj->state());

	setLayout(m_layout);
}

void ViewWidget_Dashboard::updateDashboard(ProjectState state)
{
	switch (state)
	{
	case ProjectState::FileClosed:
		setEnabled(false);
		break;
	case ProjectState::FileCreated:
		setEnabled(true);
		m_peopleCountEdit->setText(QString(m_proj->data()->people().count())); // Make this more modular..
		break;
	case ProjectState::FileOpen:
		setEnabled(true);
		m_peopleCountEdit->setText(QString(m_proj->data()->people().count()));
		break;
	case ProjectState::FileModified:
		setEnabled(true);
		m_peopleCountEdit->setText(QString(m_proj->data()->people().count()));
		break;
	default:
		break;
	}
}