#include "Entity.h"

Entity::Entity(SerialisableObject * parent)
	: SerialisableObject(parent), IdentifiableObject()
{
}

Entity::~Entity()
{
}
