
#ifndef SERIALISABLE_OBJECT
#define SERIALISABLE_OBJECT
#include <qlist.h>
class QXmlStreamWriter;
class QXmlStreamReader;

/*
	-> A base class for an object that can be saved and read from file.
		-> Contains methods to read and write, and an "modified" state which is toggled on under modification & off when saving.
	NOTE:
		-> Ran into an interesting design consideration with this:
			-> If you are making objects with methods for serialisation throughout the project, then when you load a file,
				something needs to know in advance which & how many objects you are going to make?
			-> I can think of three solutions.
				-> One is to make the read from file also a constructor. Then when the main parser reads
					an element that has the name of an existing object, it can just pass the reader to the constructor.
				-> Two, would be to make the parser static.
				-> The last would be best, esp in combination with 1 & 2:
					-> Get a QDomDocument up & load the XML into it. Then create lists of objects, just grabbing the element names.
						-> Then have a method loop through the lists & call the constructor of the object matching the name of what's in the list.
		-> Yet to think about encapsulation of objects.. I.e. reader needs to be called by parent object if it wants to own the child.
			-> what if an object is a set & subset?..
*/

class SerialisableObject
{
public:
	SerialisableObject(SerialisableObject * parent);
	virtual bool __parseFromFile(QXmlStreamReader & reader) = 0; // Will switch m_modified off.
	virtual bool __writeToFile(QXmlStreamWriter & writer) = 0;	// Will switch m_modified off.

	void setSaved() // On successful save all your children are saved.
	{ 
		m_modified = false;
		foreach(SerialisableObject * obj, m_children())
		{
			if(obj != nullptr)
				if(obj->isModified())
					obj->setSaved();
		}
	}
	virtual void setModified()	// On modification of anything, all your parents are also modified.
	{
		m_modified = true;
		if(m_parent != nullptr)
			if(!m_parent->isModified())
				m_parent->setModified();
	}
	__inline bool isModified() { return m_modified; }
	/*
		Great idea: All derived classes should implement a name for their tag.
			-> The next step would be to write a generic parse & read function.
				-> You'd need a way to register attributes, child objects, and lists of child objects...
					-> I guess you'd derive a list<T> as a Serialisable list which would inherit SerialisableObject & List<T>
	*/
protected:
	SerialisableObject			 * m_parent;
	virtual QList<SerialisableObject*> m_children() = 0; // Should return all serialisable objects held by the derived class.


private:
	bool m_modified;
};
#endif