#include <qwidget.h>

class Project;
class ApplicationWindow;

class ViewWidget_Base : public QWidget
{
	Q_OBJECT
public:
	ViewWidget_Base(Project * m_proj, ApplicationWindow * parent);

private:
	Project * m_proj;
};