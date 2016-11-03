#include "Relationship.h"
#include "Entity.h"

Relationship::Relationship(Entity * one, Entity * two)
	: SerialisableObject(one), p_entities{one,two}
{

}

Relationship::~Relationship()
{
	/* Don't remove the entities. You don't own them. metaphor lol*/
}
