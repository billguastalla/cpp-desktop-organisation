#include "SerialisableObject.h"
#include "IdentifiableObject.h"

#include <qmap.h>
#include <qstring.h>

#include <memory>
class Project;
class Person;
class Group;
class Entity;
// This is expected to hold all pointers to a project's information.

class ProjectInfo : public SerialisableObject, public IdentifiableObject
{
public:
	ProjectInfo(Project * proj);

	/* Normal accessors */
	QString & fileDirectory() { return m_fileDirectory; }
	QString & projectName() { return m_projectName; }
	QString & author() { return m_author; }
	QString & notes() { return m_notes; }

	/* Serialisation */
	bool __parseFromFile(QXmlStreamReader & reader); // Will switch m_modified off.
	bool __writeToFile(QXmlStreamWriter & writer);	// Will switch m_modified off.


	/* These are const because modification should use the provided public functions so any set model can be updated with changes to the project's data. */
	__inline const QMap<QString, Entity *> & entities() { return m_entities; }
	__inline QMap<QString, Person *> & people() { return m_people; }
	__inline const QMap<QString, Group *> & groups() { return m_groups; }

	/* Modify Entities owned by Project Info. */
	
	void clear();
protected:
	virtual QList<SerialisableObject*> m_children();
private:

	QMap<QString, Entity*> m_entities;
	QMap<QString, Person*> m_people;
	QMap<QString, Group*> m_groups;

	// Name of the project
	QString m_projectName;
	// Working directory of the project
	QString m_fileDirectory;
	// Author of the project
	QString m_author;
	// Notes on the project
	QString m_notes;

	Project * m_proj;
};