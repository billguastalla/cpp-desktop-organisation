#include "DockWidget_Explorer.h"
#include "PersonDialog.h"

#include "Project.h"
#include "ProjectInfo.h"
#include "Person.h"

#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qgridlayout.h>

#include <qmessagebox.h>

#include "ExplorerModel.h"
#include "ExplorerView.h"
#include "ExplorerSearchProxyModel.h"
#include "ExplorerSearchBar.h"

DockWidget_Explorer::DockWidget_Explorer(Project * proj, QWidget * parent) : DockWidget_Base(proj, parent)
{
	m_addPerson = new QPushButton("Add", this);
	m_removePerson = new QPushButton("Remove", this);


	QGridLayout * lay = new QGridLayout(this);

	lay->addWidget(m_addPerson, 0, 0, 1, 1);
	lay->addWidget(m_removePerson, 0, 1, 1, 1);


	// ------- Treeview practice
	ExplorerView * view = new ExplorerView{ this };
	ExplorerModel * model = new ExplorerModel{ proj };
	ExplorerSearchProxyModel * pxModel = new ExplorerSearchProxyModel{ view };
	pxModel->setSourceModel(model);
	view->setModel(pxModel);

	ExplorerSearchBar * searchBar = new ExplorerSearchBar{ this,pxModel };
	lay->addWidget(searchBar, 1, 0, 1, 2);
	lay->addWidget(view, 2, 0, 1, 2);
	lay->setRowStretch(2, 5);
	// -------------------------

	connect(m_addPerson, SIGNAL(clicked()), this, SLOT(addPerson()));
	connect(m_removePerson, SIGNAL(clicked()), this, SLOT(removePerson()));

	connect(view, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(sendPersonToEdit(QListWidgetItem*)));

	connect(m_proj, SIGNAL(projectStateChanged(ProjectState)), this, SLOT(updateWidget(ProjectState)));
	updateWidget(m_proj->state());

	setLayout(lay);
}

void DockWidget_Explorer::addPerson()
{
	PersonDialog * dlg = new PersonDialog(m_proj->data(), this);
	if (dlg->exec() == QDialog::Accepted)
	{
		// Add the person.
		Person * p = dlg->constructPerson();

		m_proj->data()->people().insert(p->id(), p);



		//QListWidgetItem * itm = new QListWidgetItem(p->fullName());
		//itm->setData(Qt::UserRole,QVariant::fromValue<void*>(p));
		//m_personList->addItem(itm);
	}
}

void DockWidget_Explorer::removePerson()
{
	//m_personList->currentIndex();
}

void DockWidget_Explorer::updateWidget(ProjectState state)
{
	//	m_personList->clear();
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
		/* Could go down the chain and call the model... */

		/*		QMapIterator<QString,Person*> pplIter(m_proj->data()->people());
		while(pplIter.hasNext())
		{
			pplIter.next();
			QListWidgetItem * itm = new QListWidgetItem(pplIter.value()->fullName());
			itm->setData(Qt::UserRole,QVariant::fromValue<void*>(pplIter.value()));
			m_personList->addItem(itm);
		}*/
	}
	}
}

void DockWidget_Explorer::sendPersonToEdit(QListWidgetItem * item)
{
	Person * pers = (Person*)item->data(Qt::UserRole).value<void*>();
	emit editPerson(pers, pers->id());
}