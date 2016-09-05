#include <qxmlstream.h>

#include "SerialisableObject.h"

SerialisableObject::SerialisableObject(SerialisableObject * parent) : m_modified(false)
{
	m_parent = parent;
}

//void SerialisableObject::__parseFromFile()
//{
//	m_modified = false;
//
//	
//}
//
//void SerialisableObject::__writeToFile()
//{
//	m_modified = false;
//
//
//}
//
