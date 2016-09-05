#include "Person.h"
#include "ProjectInfo.h"
#include <quuid.h>
#include <qxmlstream.h>

Person::Person(ProjectInfo * pInfo, QString firstName, QString lastName) : SerialisableObject(pInfo)
{
	m_firstName = firstName, m_lastName = lastName;
	m_id = QUuid::createUuid().toString();
}

Person::Person(const Person & other) : SerialisableObject(other.m_projInfo)
{
	m_projInfo = other.m_projInfo;
	m_firstName = other.m_firstName;
	m_lastName = other.m_lastName;
	m_id = other.m_id;
}

// ----- === Serialisation === -----
// ----- ===================== -----
bool Person::__writeToFile(QXmlStreamWriter & writer) // Save
{
	writer.writeStartElement("Person");
	// Person ID
	writer.writeAttribute("PersonID",m_id);
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
	m_id = personAttributes.value("PersonID").toString();
	// First Name
	m_firstName = personAttributes.value("FirstName").toString();
	// Last Name
	m_lastName = personAttributes.value("LastName").toString();
	// Date of Birth
	m_dob = QDateTime::fromString(personAttributes.value("DateOfBirth").toString());


	// There may be something better to use..
	return (m_id.count() != 0);
}

QList<SerialisableObject*> Person::m_children()
{
	return QList<SerialisableObject*>();
}
// ----- ===================== -----
// ----- ===================== -----

