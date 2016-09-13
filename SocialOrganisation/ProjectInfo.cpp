#include "Project.h"
#include "ProjectInfo.h"
#include "Person.h"

#include <quuid.h>
#include <qxmlstream.h>

ProjectInfo::ProjectInfo(Project * proj) : SerialisableObject(proj)
{
	m_id = QUuid::createUuid().toString();
	m_proj = proj;
}

// Serialisation
bool ProjectInfo::__parseFromFile(QXmlStreamReader & reader)
{
	while(!reader.isEndDocument() && !reader.hasError())
	{
		if(reader.name() == "Project")
		{
			QXmlStreamAttributes projectAttributes = reader.attributes();

			// ProjectID ID
			m_projectName = projectAttributes.value("Name").toString();
			m_id = projectAttributes.value("ID").toString();
			m_fileDirectory = projectAttributes.value("Directory").toString();
			m_author = projectAttributes.value("Author").toString();
			m_notes = projectAttributes.value("Notes").toString();

			while(!reader.hasError() && !(reader.isEndElement() && (reader.text() == "Person")))
			{
				reader.readNext();
				if(reader.isStartElement() && reader.name() == "Person")
				{
					// At this point, you may consider changing the constructor of
					// each serialisable object so that it can serialise on construction.
					// This is dangerous I guess, have a think about it.
					Person * p = new Person(this,"","");
					p->__parseFromFile(reader);
					m_people.insert(p->id(),p);
				}
			}
		}
		reader.readNextStartElement();
	}

	return (m_id.count() != 0);
}

bool ProjectInfo::__writeToFile(QXmlStreamWriter & writer)
{
	writer.writeStartElement("Project");

	// Project attributes
	writer.writeAttribute("Name",m_projectName);
	writer.writeAttribute("ID",m_id);
	writer.writeAttribute("Directory",m_fileDirectory);
	writer.writeAttribute("Author",m_author);
	writer.writeAttribute("Notes",m_notes);

	// People
	writer.writeStartElement("People");
	QMapIterator<QString,Person*> peopleIter(m_people);
	while(peopleIter.hasNext())
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
	QMapIterator<QString,Person*> peopleIter(m_people);
	while(peopleIter.hasNext())
	{
		peopleIter.next();
		children.push_back(m_people[peopleIter.key()]);
	}
	return children;
}