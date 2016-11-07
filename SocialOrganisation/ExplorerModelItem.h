#pragma once
#include <qstandarditemmodel.h>

enum class ExplorerItemType /*<--- Assume these are all entities. */
{
	Person,
	Group //..
};

class Person;
class Group;

class ExplorerModelItem_Base : public QStandardItem
{
public:
	ExplorerModelItem_Base();

private:
	
};

class ExplorerModelItem_Person : public ExplorerModelItem_Base
{
public:
	ExplorerModelItem_Person(Person * pers);

private:
	Person * p_pers;
};

class ExplorerModelItem_Group : public ExplorerModelItem_Base
{
public:
	ExplorerModelItem_Group(Group * grp);

private:
	Group * p_group;
};
