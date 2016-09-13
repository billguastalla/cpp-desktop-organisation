#include "DockWidget_People.h"
#include "PersonDialog.h"

#include "Project.h"
#include "ProjectInfo.h"
#include "Person.h"

#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qgridlayout.h>

#include <qmessagebox.h>

DockWidget_People::DockWidget_People(Project * proj, QWidget * parent) : DockWidget_Base(proj, parent)
{
	m_addPerson			 = new QPushButton("Add",this);
	m_removePerson		 = new QPushButton("Remove",this);

	m_personList		 = new QListWidget(this);

	QGridLayout * lay	 = new QGridLayout(this);

	lay->addWidget(m_addPerson, 0, 0, 1, 1);
	lay->addWidget(m_removePerson, 0, 1, 1, 1);

	lay->addWidget(m_personList, 1, 0, 1, 2);
	lay->setRowStretch(1,5);

	connect(m_addPerson,		 SIGNAL(clicked()), this, SLOT(	addPerson()));
	connect(m_removePerson,		 SIGNAL(clicked()), this, SLOT(	removePerson()));

	connect(m_personList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(sendPersonToEdit(QListWidgetItem*)));

	connect(m_proj, SIGNAL(projectStateChanged(ProjectState)), this, SLOT(updateWidget(ProjectState)));
	updateWidget(m_proj->state());

	setLayout(lay);
}

void DockWidget_People::addPerson()
{
	PersonDialog * dlg = new PersonDialog(m_proj->data(),this);
	if(dlg->exec() == QDialog::Accepted)
	{
		// Add the person.
		Person * p = dlg->constructPerson();

		m_proj->data()->people().insert(p->id(),p);

		QListWidgetItem * itm = new QListWidgetItem(p->fullName());
		itm->setData(Qt::UserRole,QVariant::fromValue<void*>(p));
		m_personList->addItem(itm);
	}
}

void DockWidget_People::removePerson()
{
	m_personList->currentIndex();
}

void DockWidget_People::updateWidget(ProjectState state)
{
	m_personList->clear();
	switch (state)
	{
	case ProjectState::FileClosed:
		setEnabled(false);
		break;
	case ProjectState::FileCreated:
	case ProjectState::FileOpen:
	case ProjectState::FileModified:
	default:
		{
			setEnabled(true);
			QMapIterator<QString,Person*> pplIter(m_proj->data()->people());
			while(pplIter.hasNext())
			{
				pplIter.next();
				QListWidgetItem * itm = new QListWidgetItem(pplIter.value()->fullName());
				itm->setData(Qt::UserRole,QVariant::fromValue<void*>(pplIter.value()));
				m_personList->addItem(itm);
			}
		}
	}
}

void DockWidget_People::sendPersonToEdit(QListWidgetItem * item)
{
	Person * pers = (Person*)item->data(Qt::UserRole).value<void*>();
	emit editPerson(pers,pers->id());
}