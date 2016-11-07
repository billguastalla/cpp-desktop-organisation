#include "ExplorerModelItem.h"

#include "Person.h"
#include "Group.h"
ExplorerModelItem_Person::ExplorerModelItem_Person(Person * pers)
	: ExplorerModelItem_Base{}, p_pers{pers}
{
	setText(pers->fullName());
}

ExplorerModelItem_Group::ExplorerModelItem_Group(Group * grp)
	: ExplorerModelItem_Base{}, p_group{grp}
{
	setText("group name..");
}

ExplorerModelItem_Base::ExplorerModelItem_Base() : QStandardItem()
{

}
