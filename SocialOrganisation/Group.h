#pragma once
#include "Entity.h"
#include <qstring.h>
#include <qmap.h>

class Person;
class ProjectInfo;

class Group : public Entity
{
public:
	Group(ProjectInfo * pInfo);
	~Group();

	void addPerson(Person *);
	void removePerson(Person *);
	bool hasPerson(Person * pers);

private:
	QMap<QString/*id*/, Person*> p_people;
};