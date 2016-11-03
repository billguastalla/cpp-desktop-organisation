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
	const virtual QString & id() const {
		return m_id;
	} /*<--- Returns the ID of the object they hold.  */

	public slots:
		void updateDashboard(ProjectState state);

private:
	QString m_id; /*<-- For want of being replaced by the id of the object that it owns..*/

	QLabel * m_peopleCountLabel;
	QLineEdit * m_peopleCountEdit;

	QFormLayout * m_layout;
};