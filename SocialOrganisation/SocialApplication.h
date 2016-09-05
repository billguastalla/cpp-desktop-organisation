#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QtWidgets/QMainWindow>
#include <qmap.h>

class QActionGroup;
class Project;
class SocialMenuBar;

class DockWidget_Base;


class ApplicationWindow : public QMainWindow
{
	Q_OBJECT
public:
	ApplicationWindow(QWidget *parent = 0);
	~ApplicationWindow();

private:		
	void createDockWindows();
	void createActions();

private:
	Project				 * m_proj;
	SocialMenuBar		 * m_menuBar;


	QMap<QString,DockWidget_Base*> m_dockViews;
	void enableViews();
	//void updateViews();
};

#endif // APPLICATIONWINDOW_H
