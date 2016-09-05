#include <qdialog.h>

class ProjectInfo;
class Person;

class QLineEdit;
class QDateTimeEdit;

class PersonDialog : public QDialog
{
	Q_OBJECT
public:
	PersonDialog(ProjectInfo * proj, QWidget * parent = nullptr);

	Person * constructPerson();
private:
	QLineEdit		 * m_fNameEdit;
	QLineEdit		 * m_lNameEdit;
	QDateTimeEdit	 * m_dobEdit;
	ProjectInfo * m_projInfo;
};