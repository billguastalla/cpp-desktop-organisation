#include <qdialog.h>

class QWidget;
class QTabWidget;
class QDialogButtonBox;

class PreferencesDialog : public QDialog
{
	Q_OBJECT
public:
	PreferencesDialog(QWidget * parent = nullptr);


private:
	QTabWidget * m_preferencesTabs;
	QDialogButtonBox * m_buttonBox;
};