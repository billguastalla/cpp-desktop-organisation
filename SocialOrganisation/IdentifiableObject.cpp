#include "IdentifiableObject.h"
#include <qxmlstream.h>

IdentifiableObject::IdentifiableObject(const QString & id)
	: m_id{ id }
{
}

IdentifiableObject::IdentifiableObject(const IdentifiableObject & other)
{
	m_id = other.m_id;
}

IdentifiableObject::~IdentifiableObject()
{
}

bool IdentifiableObject::__parseID(QXmlStreamAttributes & ourAttributes) {
	if (ourAttributes.hasAttribute("id"))
	{
		m_id = ourAttributes.value("id").toString();
		return true;
	}
	else return false;
};

void IdentifiableObject::__writeID(QXmlStreamWriter & writer) {
	writer.writeAttribute("id", m_id);
}