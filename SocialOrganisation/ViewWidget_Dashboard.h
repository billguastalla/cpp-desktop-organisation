#include "ViewWidget_Base.h"

/* 
	Total people, total connections. All stats...
*/
enum class ProjectState;
class QLabel;
class QLineEdit;
class QFormLayout;

class ViewWidget_Dashboard : public ViewWidget_Base
{
	Q_OBJECT
public:
	ViewWidget_Dashboard(Project * m_proj, TabManager * parent);

	public slots:
		void updateDashboard(ProjectState state);

private:
	QLabel * m_peopleCountLabel;
	QLineEdit * m_peopleCountEdit;

	QFormLayout * m_layout;
};