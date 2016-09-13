#include "DockWidget_Base.h"

class QListWidget;
class QListWidgetItem;
class QPushButton;

class Person;

/*
	This should be DockWidget_Explorer.
		-> Should contain a TreeView, and implement a treemodel/modelitem...
		-> Should have a search bar.
		-> Should be able to search people/groups. Should be able to expand & find associated people/groups..
*/

class DockWidget_People : public DockWidget_Base
{
	Q_OBJECT
public:
	DockWidget_People(Project * proj, QWidget * parent = nullptr);


public slots:
	void addPerson();
	void removePerson();
	virtual void updateWidget(ProjectState state);

	void sendPersonToEdit(QListWidgetItem * item);
signals:
		void editPerson(Person * pers, const QString & id);

private:
	QPushButton * m_addPerson;
	QPushButton * m_removePerson;

	QListWidget * m_personList;
};

