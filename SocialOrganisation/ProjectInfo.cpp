#include "Project.h"
#include "ProjectInfo.h"
#include "Person.h"

#include <quuid.h>
#include <qxmlstream.h>

ProjectInfo::ProjectInfo(Project * proj) : SerialisableObject(proj), IdentifiableObject()
{
	m_proj = proj;
}

void ProjectInfo::clear()
{
	m_author.clear();
	m_fileDirectory.clear();
	m_id.clear();
	m_notes.clear();
	m_people.clear(); // <-- Need to delete people!
	m_projectName.clear();
}

// Serialisation
bool ProjectInfo::__parseFromFile(QXmlStreamReader & reader)
{
	clear();
	while (!reader.isEndDocument() && !reader.hasError())
	{
		reader.readNextStartElement();

		if (reader.name() == "Project")
		{
			QXmlStreamAttributes projectAttributes = reader.attributes();

			// ProjectID ID
			m_projectName = projectAttributes.value("Name").toString();
			__parseID(projectAttributes);
			m_fileDirectory = projectAttributes.value("Directory").toString();
			m_author = projectAttributes.value("Author").toString();
			m_notes = projectAttributes.value("Notes").toString();

			while (!reader.hasError() && !(reader.isEndElement() && (reader.text() == "Person")))
			{
				reader.readNext();
				if (reader.isStartElement() && reader.name() == "Person")
				{
					// At this point, you may consider changing the constructor of
					// each serialisable object so that it can serialise on construction.
					// This is dangerous I guess, have a think about it.
					Person * p = new Person(this, "", "");
					if (p->__parseFromFile(reader))
						m_people.insert(p->id(), p);
					else
						return false;
				}
			}
		}
	}

	return (m_id.count() != 0 && !reader.hasError());
}

bool ProjectInfo::__writeToFile(QXmlStreamWriter & writer)
{
	writer.writeStartElement("Project");
	__writeID(writer);

	// Project attributes
	writer.writeAttribute("Name", m_projectName);
	writer.writeAttribute("Directory", m_fileDirectory);
	writer.writeAttribute("Author", m_author);
	writer.writeAttribute("Notes", m_notes);

	// People
	writer.writeStartElement("People");
	QMapIterator<QString, Person*> peopleIter(m_people);
	while (peopleIter.hasNext())
	{
		peopleIter.next();
		peopleIter.value()->__writeToFile(writer);
	}
	writer.writeEndElement();

	// Anything new to write to file goes here..

	writer.writeEndElement();

	return writer.hasError();
}

QList<SerialisableObject*> ProjectInfo::m_children()
{
	QList<SerialisableObject*> children;
	QMapIterator<QString, Person*> peopleIter(m_people);
	while (peopleIter.hasNext())
	{
		peopleIter.next();
		children.push_back(m_people[peopleIter.key()]);
	}
	return children;
}