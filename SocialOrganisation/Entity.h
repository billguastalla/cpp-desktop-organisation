#pragma once
#include "SerialisableObject.h"
#include "IdentifiableObject.h"
/* Abstract as far as I understand so far..*/

class Entity : public SerialisableObject, public IdentifiableObject
{
public:
	Entity(SerialisableObject * parent);
	~Entity();
};

