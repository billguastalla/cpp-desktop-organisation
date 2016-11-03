#include "SocialApplication.h"
#include "SocialMenuBar.h"
#include "SocialSystemTray.h"

#include "DockWidget_People.h"

#include "PreferencesDialog.h"

#include "ProjectDialog.h"

#include "TabManager.h"

#include "FileIO.h"
#include "Project.h"
#include "ProjectInfo.h"

#include <qtoolbar.h>
#include <qmenubar.h>
#include <qdockwidget.h>
#include <qmessagebox.h>

#include <qtabwidget.h>

#include <qevent.h>

SocialApplication::SocialApplication(QWidget *parent)
	: QMainWindow(parent)
{
	QIcon ico("C:\\GIT\\SocialOrganisation\\SocialOrganisation\\images\\SocialOrganisation.png"); // This should be relative to the executable.
	setWindowIcon(ico);
	setMinimumSize(1280, 720);
	setWindowTitle("Social Organisation");


	m_proj = new Project(this);

	m_menuBar = new SocialMenuBar(m_proj, this);
	setMenuBar(m_menuBar);

	m_tabManager = new TabManager(m_proj, this);
	setCentralWidget(m_tabManager);

	createDockWindows();

	m_trayIcon = new SocialSystemTray(this);
	m_trayIcon->show();

}

SocialApplication::~SocialApplication()
{

}

void SocialApplication::createDockWindows()
{
	m_dockViews.insert("People", new DockWidget_People(m_proj, this));

	QDockWidget * peopleDock = new QDockWidget(tr("People"), this);
	peopleDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	peopleDock->setWidget(m_dockViews["People"]);
	addDockWidget(Qt::LeftDockWidgetArea, peopleDock);

	connect(m_dockViews["People"], SIGNAL(editPerson(Person*, const QString&)), m_tabManager, SLOT(createTab(Person*, const QString&)));

}

void SocialApplication::closeEvent(QCloseEvent *event)
{
	if (isVisible())
		if (m_trayIcon->isVisible())
		{
			hide();
			event->ignore();
		}
}

void SocialApplication::close()
{
	if (m_proj->closeProject())
		QMainWindow::close();
}