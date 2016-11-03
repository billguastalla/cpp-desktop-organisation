#include <qxmlstream.h>

#include "SerialisableObject.h"

SerialisableObject::SerialisableObject(SerialisableObject * parent) : m_modified(false)
{
	m_parent = parent;
}