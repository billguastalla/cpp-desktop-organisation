#pragma once
#include <qstring.h>
#include <quuid.h>

class QXmlStreamAttributes;
class QXmlStreamWriter;

class IdentifiableObject
{
public:
	IdentifiableObject(const QString & id = QUuid::createUuid().toString());
	IdentifiableObject(const IdentifiableObject & other);
	~IdentifiableObject();
	__inline const QString & id() { return m_id; }
	__inline void setId(const QString & id) { m_id = id; }
protected:
	QString m_id;
	virtual bool __parseID(QXmlStreamAttributes & ourAttributes);
	virtual void __writeID(QXmlStreamWriter & writer);
};