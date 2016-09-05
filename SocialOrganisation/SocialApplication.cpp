#include "SocialApplication.h"
#include "SocialMenuBar.h"

#include "PersonWidget.h"

#include "EditPreferencesDialog.h"

#include "NewProjectDialog.h"

#include "FileIO.h"
#include "Project.h"
#include "ProjectInfo.h"

#include <qtoolbar.h>
#include <qmenubar.h>
#include <qdockwidget.h>
#include <qmessagebox.h>

ApplicationWindow::ApplicationWindow(QWidget *parent)
	: QMainWindow(parent)
{
	m_proj = new Project(this);

	m_menuBar = new SocialMenuBar(m_proj, this);
	setMenuBar(m_menuBar);

	createDockWindows();

	setWindowTitle("Social Organisation");
	setMinimumSize(1280,720);

	setCentralWidget(new QWidget(this));
}

ApplicationWindow::~ApplicationWindow()
{

}

void ApplicationWindow::createDockWindows()
{
	m_dockViews.insert("People",new PersonWidget(m_proj,this));

	QDockWidget * peopleDock = new QDockWidget(tr("People"), this);
	peopleDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	peopleDock->setWidget(m_dockViews["People"]);
	addDockWidget(Qt::LeftDockWidgetArea, peopleDock);
}