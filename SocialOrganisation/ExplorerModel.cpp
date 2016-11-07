#include "ExplorerModel.h"
#include "ExplorerModelItem.h"

#include "Project.h"
#include "ProjectInfo.h"

ExplorerModel::ExplorerModel(Project * proj) : QStandardItemModel{}, p_proj{ proj }, p_info{proj->data()}
{
	refreshProject(proj->state());
	connect(proj, SIGNAL(projectStateChanged(ProjectState)), this, SLOT(refreshProject(ProjectState)));
}

void ExplorerModel::refreshProject(ProjectState state)
{
	switch (state)
	{
	case ProjectState::FileClosed:
		clear();
		break;
	case ProjectState::FileCreated:
		clear();
		break;
	case ProjectState::FileOpen:
	{
		clear();

		/*<--- Insert people --->*/
		QMapIterator<QString, Person*> peopleIter{ p_proj->data()->people() };
		while (peopleIter.hasNext())
		{
			peopleIter.next();
			ExplorerModelItem_Person * itm = new ExplorerModelItem_Person{ p_proj->data()->people()[peopleIter.key()] };
			insertRow(0, itm);
		}
	}
	break;
	case ProjectState::FileModified:
	{
		// ... You'll have to do something here.
	}
		break;
	default:
		break;
	}
	/* ... */
}