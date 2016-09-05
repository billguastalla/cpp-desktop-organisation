#include <qwidget.h>

class Project;
enum class ProjectState;

class DockWidget_Base : public QWidget
{
	Q_OBJECT
public:
	DockWidget_Base(Project * proj, QWidget * parent = nullptr);

	public slots:
		virtual void updateWidget(ProjectState) = 0;

protected:
	Project * m_proj;
};