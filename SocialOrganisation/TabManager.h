#include <qtabwidget.h>
#include <qmap.h>

class ViewWidget_Base;
class Person;
class SocialApplication;
class Project;

enum class ProjectState;

class TabManager : public QTabWidget
{
	Q_OBJECT
public:
	TabManager(Project * proj, SocialApplication * parent = nullptr);

public slots:
	void createTab(Person * pers, const QString & id);
	void createDashboard();
	//void createTab(/* ... ,*/QString id);
	void closeTab(const QString & id);

	private slots:
		void enableTabManager(ProjectState state);

private:
	QMap<QString/*id*/,ViewWidget_Base*> m_tabs;

	SocialApplication	* m_app;
	Project				* m_proj;
};