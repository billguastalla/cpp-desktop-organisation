#include "Entity.h"

#include <qstring.h>
#include <qdatetime.h>
#include <qmap.h>

class ProjectInfo;
class Group;

/*
-> Contact details
-> Intended frequency of contact.
-> "Event" class..
	-> Memory subclass
-> 
-> 

*/

class Person : public Entity
{
public:
	Person(ProjectInfo * pInfo, QString firstName, QString lastName);
	Person(const Person & other);

	QString fullName() { return m_firstName + " " + m_lastName; }
	QString fName() { return m_firstName; }
	QString lName() { return m_lastName; }

	const QDateTime & dateOfBirth() { return m_dob; }

	void setDateOfBirth(const QDateTime & dob) { m_dob = dob; }

	void addGroup(Group * grp);
	void removeGroup(Group * grp);
	bool hasGroup(Group* grp);
private:
	QString m_firstName;
	QString m_lastName;
	QDateTime m_dob;

	QList<SerialisableObject*> m_children();

	QMap<QString/*id*/, Group*> p_groups;

	ProjectInfo * p_projInfo;
	// Serialisation
public:
	bool __writeToFile(QXmlStreamWriter & writer);
	bool __parseFromFile(QXmlStreamReader & reader);
};