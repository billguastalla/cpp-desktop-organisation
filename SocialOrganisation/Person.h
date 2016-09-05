#include "SerialisableObject.h"

#include <qstring.h>
#include <qdatetime.h>

class ProjectInfo;

class Person : public SerialisableObject
{
public:
	Person(ProjectInfo * pInfo, QString firstName, QString lastName);
	Person(const Person & other);

	QString fullName() { return m_firstName + " " + m_lastName; }
	const QDateTime & dateOfBirth() { return m_dob; }

	const QString & id() { return m_id; }

	void setDateOfBirth(const QDateTime & dob) { m_dob = dob; }

private:
	QString m_firstName;
	QString m_lastName;
	QDateTime m_dob;

	QString m_id;


	QList<SerialisableObject*> m_children();
	ProjectInfo * m_projInfo;
// Serialisation
public:
	bool __writeToFile(QXmlStreamWriter & writer);
	bool __parseFromFile(QXmlStreamReader & reader);
};