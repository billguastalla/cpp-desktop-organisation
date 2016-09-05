#include <qwidget.h>

class ProjectInfo;

class QLineEdit;
class QLabel;
class QFormLayout;
class QPlainTextEdit;

class ProjectPropertiesWidget : public QWidget
{
	Q_OBJECT
public:
	ProjectPropertiesWidget(ProjectInfo * proj = nullptr, QWidget * parent = nullptr);
	public slots:
		void save();
private:
	QFormLayout * m_lay;
	ProjectInfo * m_project;

	QLineEdit		 * m_nameEdit;
	QLineEdit		 * m_idEdit;
	QLineEdit		 * m_fileDirectoryEdit;
	QLineEdit		 * m_authorEdit;
	QPlainTextEdit	 * m_notesEdit;
};