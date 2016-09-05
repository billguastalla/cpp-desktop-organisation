#include "SerialisableObject.h"

#include <qmap.h>
#include <qstring.h>


class Project;
class Person;
// This is expected to hold all pointers to a project's information.

class ProjectInfo : public SerialisableObject
{
public:
	ProjectInfo(Project * proj);

	__inline QMap<QString, Person *> & people() { return m_people; }


	bool __parseFromFile(QXmlStreamReader & reader); // Will switch m_modified off.
	bool __writeToFile(QXmlStreamWriter & writer);	// Will switch m_modified off.


	QString & fileDirectory(){ return m_fileDirectory; }
	QString & projectName() { return m_projectName; }
	QString & id() { return m_id; }
	QString & author() { return m_author; }
	QString & notes() { return m_notes; }

protected:
	virtual QList<SerialisableObject*> m_children();
private:

	QMap<QString, Person *> m_people;

	// Name of the project
	QString m_projectName;
	// Autogenerated unique identifier for the project
	QString m_id;
	// Working directory of the project
	QString m_fileDirectory;
	// Author of the project
	QString m_author;
	// Notes on the project
	QString m_notes;

	Project * m_proj;
};