#include <qdialog.h>

class QWidget;
class QTabWidget;
class QDialogButtonBox;

class EditPreferencesDialog : public QDialog
{
	Q_OBJECT
public:
	EditPreferencesDialog(QWidget * parent = nullptr);


private:
	QTabWidget * m_preferencesTabs;
	QDialogButtonBox * m_buttonBox;
};