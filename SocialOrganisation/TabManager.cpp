#include "TabManager.h"

#include "Project.h"
#include "SocialApplication.h"

#include "ViewWidget_PersonInformation.h"
#include "ViewWidget_Dashboard.h"
#include "Person.h"

TabManager::TabManager(Project * proj, SocialApplication * parent)
	: QTabWidget(parent),
	m_app(parent),
	m_proj(proj)
{
	setMovable(true);
	setTabsClosable(true);
	setTabShape(QTabWidget::TabShape::Triangular);
	connect(m_proj,SIGNAL(projectStateChanged(ProjectState)),this,SLOT(enableTabManager(ProjectState)));
}

void TabManager::createTab(Person * pers, const QString & id)
{
	if(!m_tabs.contains(id))
	{
		ViewWidget_Base * tab = new ViewWidget_PersonInformation(pers,m_proj,this);
		m_tabs.insert(id,tab);
		addTab(tab,pers->fullName());
	}
}

void TabManager::closeTab(const QString & id)
{
	ViewWidget_Base * tab = m_tabs[id];
	if(tab != nullptr)
	{
		tab->close(); /*<---- This doesn't look right.*/
		m_tabs.remove(id);
		delete tab;
	}
}

void TabManager::createDashboard()
{
	if(!m_tabs.contains("Dashboard"))
	{
		ViewWidget_Dashboard * dashboard = new ViewWidget_Dashboard(m_proj,this);
		m_tabs.insert("Dashboard",dashboard);
		addTab(dashboard,"Dashboard");
	}
}

void TabManager::enableTabManager(ProjectState state)
{
	switch(state)
	{
	case ProjectState::FileOpen:
		{
			// Add dashboard?
			createDashboard();
			setEnabled(true);
			return;
		}
	case ProjectState::FileCreated:
		{
			// Add dashboard?
			createDashboard();
			setEnabled(true);
			return;
		}
	case ProjectState::FileModified:
		{

		}
		return;
	case ProjectState::FileClosed:
		{
			clear();
			m_tabs.clear();
			setEnabled(false);
		}
		return;
	default:
		return;
	}
}