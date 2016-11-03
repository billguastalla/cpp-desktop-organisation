#pragma once
#include <qwidget.h>

class Project;
class TabManager;

/*
	-> Since these exist as tabs, they need a modified state. Then they can be appended with an asterisk.
	-> Need to catch the key events so we can have Ctrl-S and Ctrl-W.
	-> Need to think about way to hold original and modified copy of object.
*/
class ViewWidget_Base : public QWidget
{
	Q_OBJECT
public:
	ViewWidget_Base(Project * m_proj, TabManager * parent);

	const virtual QString & id() const = 0; /*<--- Returns the ID of the object they hold.  */
protected:
	Project * m_proj;
};

