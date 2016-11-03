#include "Group.h"
#include "ProjectInfo.h"
#include "Person.h"

Group::Group(ProjectInfo * pInfo) : Entity(pInfo)
{
}

Group::~Group()
{
}

void Group::addPerson(Person * pers)
{
	p_people.insert(pers->id(), pers);
	pers->addGroup(this);
}

void Group::removePerson(Person * pers)
{
	p_people.remove(pers->id());
	pers->removeGroup(this);
}

bool Group::hasPerson(Person * pers)
{
	return p_people.contains(pers->id());
}