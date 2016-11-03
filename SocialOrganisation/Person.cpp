#include "Person.h"
#include "Group.h"
#include "ProjectInfo.h"
#include <quuid.h>
#include <qxmlstream.h>

Person::Person(ProjectInfo * pInfo, QString firstName, QString lastName) : Entity(pInfo)
{
	m_firstName = firstName, m_lastName = lastName;
}

Person::Person(const Person & other) : Entity(other.p_projInfo)
{
	p_projInfo = other.p_projInfo;
	m_firstName = other.m_firstName;
	m_lastName = other.m_lastName;
}

// ----- === Serialisation === -----
// ----- ===================== -----
bool Person::__writeToFile(QXmlStreamWriter & writer) // Save
{
	writer.writeStartElement("Person");
	// Person ID
	__writeID(writer);
	// First Name
	writer.writeAttribute("FirstName",m_firstName);
	// Last Name
	writer.writeAttribute("LastName",m_lastName);
	// Date of Birth
	writer.writeAttribute("DateOfBirth",m_dob.toString());

	// Anything new to write to file goes here..


	writer.writeEndElement();
	return true;
}

// Note : This has assumed that the reader's head is at the element named "Person" already. Reasonable assumption but a convention needs to be maintained.
bool Person::__parseFromFile(QXmlStreamReader & reader) // Load
{
	QXmlStreamAttributes personAttributes = reader.attributes();

	// Person ID
	__parseID(personAttributes);
	// First Name
	m_firstName = personAttributes.value("FirstName").toString();
	// Last Name
	m_lastName = personAttributes.value("LastName").toString();
	// Date of Birth
	m_dob = QDateTime::fromString(personAttributes.value("DateOfBirth").toString());


	// There may be something better to use..
	return (m_id.count() != 0);
}

void Person::addGroup(Group * grp)
{
	p_groups.insert(grp->id(), grp);
}

void Person::removeGroup(Group * grp)
{
	p_groups.remove(grp->id());
}

bool Person::hasGroup(Group * grp)
{
	return p_groups.contains(grp->id());
}

QList<SerialisableObject*> Person::m_children()
{
	return QList<SerialisableObject*>();
}
// ----- ===================== -----
// ----- ===================== -----

