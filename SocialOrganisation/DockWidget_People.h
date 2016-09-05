#include "DockWidget_Base.h"

class QListWidget;
class QPushButton;

class DockWidget_People : public DockWidget_Base
{
	Q_OBJECT
public:
	DockWidget_People(Project * proj, QWidget * parent = nullptr);


public slots:
	void addPerson();
	void removePerson();
	virtual void updateWidget(ProjectState state);

signals:
		void personChanged(int id);

private:
	QPushButton * m_addPerson;
	QPushButton * m_removePerson;

	QListWidget * m_personList;
};