#include <qsystemtrayicon.h>

class SocialApplication;

class SocialSystemTray : public QSystemTrayIcon
{
	Q_OBJECT
public:
	SocialSystemTray(SocialApplication * app = nullptr);

	private slots:
		void iconActivated(QSystemTrayIcon::ActivationReason reason);
		void dispMessage();
		void displayMessageAfterClicked();

private:
	SocialApplication * m_app;
};