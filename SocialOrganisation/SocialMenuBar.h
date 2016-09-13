#include <qmenubar.h>

class Project;
enum class ProjectState;
class SocialApplication;

enum class FileActions
{
	New,
	Load,
	Save,
	SaveAs,
	CloseProject,
	Exit
};

enum class EditActions
{
	Preferences
};

enum class ProjectActions
{
	Properties
};

class SocialMenuBar : public QMenuBar
{
	Q_OBJECT
public:
	SocialMenuBar(Project * proj, SocialApplication * parent);

private:
	void createMenus();
	void createActions();

	// ------------ Menus ------------
	QMenu * m_fileMenu;
	QMenu * m_editMenu;
	QMenu * m_projectMenu;

	// ------------ Actions ------------
	QMap<FileActions, QAction*>		 m_fileActions;
	QMap<EditActions, QAction*>		 m_editActions;
	QMap<ProjectActions, QAction*>	 m_projectActions;

	public slots:
		void updateMenuBar(ProjectState state);

		void preferencesEdit();
		void propertiesEdit();
private:
	Project				 * m_proj;
	SocialApplication	 * m_app;
};