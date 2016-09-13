#pragma once
#include <qwidget.h>

class Project;
class TabManager;

class ViewWidget_Base : public QWidget
{
	Q_OBJECT
public:
	ViewWidget_Base(Project * m_proj, TabManager * parent);

protected:
	Project * m_proj;
};