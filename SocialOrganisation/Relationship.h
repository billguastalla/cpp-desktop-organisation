#pragma once
#include "SerialisableObject.h"
#include <vector>

class Entity;

class Relationship : public SerialisableObject
{
public:
	Relationship(Entity * one, Entity * two);
	~Relationship();

private:
	std::pair<Entity*, Entity*> p_entities;
};

