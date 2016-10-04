#include "SocialSystemTray.h"
#include "SocialApplication.h"

#include <qmessagebox.h>
#include <qmenu.h>

SocialSystemTray::SocialSystemTray(SocialApplication * app)
	: QSystemTrayIcon(app),
	m_app(app)
{

	// Create menu

	// Set icon to app's icon.
	setToolTip(tr("Social Organisation"));
	setIcon(m_app->windowIcon());

	QMenu * menu = new QMenu("ASDF",m_app);
	QAction * exitAct = new QAction("Exit",this);
	menu->addAction(exitAct);
	connect(exitAct,SIGNAL(triggered()),m_app,SLOT(close()));
	setContextMenu(menu);
}

void SocialSystemTray::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::Trigger:
	case QSystemTrayIcon::DoubleClick:
		dispMessage();
		break;
	case QSystemTrayIcon::MiddleClick:
		break;
	default:
		break;
	}
}

void SocialSystemTray::dispMessage()
{
	QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon::Information;
	QSystemTrayIcon::showMessage("Title", "Body", icon,5000);
}

void SocialSystemTray::displayMessageAfterClicked()
{
	QMessageBox::information(0, tr("Systray"),
		tr("Sorry, I already gave what help I could.\n"
		"Maybe you should try asking a human?"));
}
