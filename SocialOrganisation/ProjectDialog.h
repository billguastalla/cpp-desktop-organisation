#include <qdialog.h>

class ProjectInfo;
class ProjectPropertiesWidget;
class SocialApplication;

class QDialogButtonBox;
class ProjectDialog : public QDialog
{
	Q_OBJECT
public:
	ProjectDialog(ProjectInfo * proj, QWidget * parent);


private:
	// UI
	ProjectPropertiesWidget * m_projectPropsWid;
	QDialogButtonBox * m_btns;
	// DATA
	ProjectInfo * m_project;
public:
	ProjectInfo * project();
	public slots:
		void save();
};