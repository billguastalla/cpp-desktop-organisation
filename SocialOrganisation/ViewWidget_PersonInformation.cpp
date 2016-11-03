#include "ViewWidget_PersonInformation.h"
#include "Person.h"

#include <qformlayout.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>

ViewWidget_PersonInformation::ViewWidget_PersonInformation(Person * pers, Project * proj, TabManager * app)
	: ViewWidget_Base(proj,app),
	p_pers(pers)
{

	QFormLayout * lay = new QFormLayout(this);
	QLineEdit * m_fNameEdit = new QLineEdit(this);
	QLineEdit * m_lNameEdit = new QLineEdit(this);
	QDateTimeEdit * m_dobEdit = new QDateTimeEdit(QDateTime::currentDateTime(),this);

	m_fNameEdit->setText(pers->fName());
	m_lNameEdit->setText(pers->lName());
	m_dobEdit->setDateTime(pers->dateOfBirth());


	lay->addRow(tr("First Name:\t"),m_fNameEdit);
	lay->addRow(tr("Last Name:\t"),m_lNameEdit);
	lay->addRow(tr("Date of Birth: \t"),m_dobEdit);
	setLayout(lay);
}

const QString & ViewWidget_PersonInformation::id() const
{
	return p_pers->id();
} /*<--- Returns the ID of the object they hold.  */
