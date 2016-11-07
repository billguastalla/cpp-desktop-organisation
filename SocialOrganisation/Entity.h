#pragma once
#include "SerialisableObject.h"
#include "IdentifiableObject.h"
/* Abstract as far as I understand so far..*/

/*
2016.11.03
	-> This could inherit QStandardItem.
		-> Then we would be able to make a generic tree model.
		-> Issue is that you wanted to be able to expand continuously e.g. group->person->group
*/
class Entity : public SerialisableObject, public IdentifiableObject
{
public:
	Entity(SerialisableObject * parent);
	~Entity();
};

