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
		reader.readNext();

		if (reader.name() == "Project")
		{
			QXmlStreamAttributes projectAttributes = reader.attributes();

			// ProjectID ID
			m_projectName = projectAttributes.value("Name").toString();
			__parseID(projectAttributes);
			m_fileDirectory = projectAttributes.value("Directory").toString();
			m_author = projectAttributes.value("Author").toString();
			m_notes = projectAttributes.value("Notes").toString();

			while (!(reader.name() == "Project" && reader.isEndElement()))
			{
				reader.readNext();

				if (reader.name() == "People")
				{
					while (!(reader.name() == "People" && reader.isEndElement()))
					{
						reader.readNext();
						if (reader.isStartElement() && reader.name() == "Person")
						{
							Person * p = new Person(this, "", "");
							if (p->__parseFromFile(reader))
								m_people.insert(p->id(), p);
							else
								delete p;
						}
					}
				}
			}
		}

	}

	bool idExists = m_id.count() != 0;
	bool readerError = reader.hasError();
	return (idExists && !readerError);
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