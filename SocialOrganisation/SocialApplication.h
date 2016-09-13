#ifndef SocialApplication_H
#define SocialApplication_H

#include <QtWidgets/QMainWindow>
#include <qmap.h>

class QActionGroup;
class Project;

class TabManager;
class SocialMenuBar;

class DockWidget_Base;


class SocialApplication : public QMainWindow
{
	Q_OBJECT
public:
	SocialApplication(QWidget *parent = 0);
	~SocialApplication();

public slots:
	void close();

private:		
	void createDockWindows();
	void createActions();

private:
	Project				 * m_proj;
	SocialMenuBar		 * m_menuBar;
	TabManager			 * m_tabManager;

	QMap<QString,DockWidget_Base*> m_dockViews;
	void enableViews();
	//void updateViews();
};

#endif // SocialApplication_H
