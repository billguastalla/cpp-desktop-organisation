#include "PersonDialog.h"

#include "Person.h"

#include <qformlayout.h>
#include <qdialogbuttonbox.h>

#include <qlineedit.h>
#include <qdatetimeedit.h>

PersonDialog::PersonDialog(ProjectInfo * proj, QWidget * parent) : QDialog(parent), m_projInfo(proj)
{
	QFormLayout * lay = new QFormLayout(this);

	m_fNameEdit = new QLineEdit(this);
	m_lNameEdit = new QLineEdit(this);
	m_dobEdit = new QDateTimeEdit(QDateTime::currentDateTime(),this);

	lay->addRow(tr("First Name:\t"),m_fNameEdit);
	lay->addRow(tr("Last Name:\t"),m_lNameEdit);
	lay->addRow(tr("Date of Birth: \t"),m_dobEdit);

	QDialogButtonBox * buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
	connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));

	lay->addWidget(buttonBox);

	setLayout(lay);
}

Person * PersonDialog::constructPerson()
{
	Person * p = new Person(m_projInfo, m_fNameEdit->text(),m_lNameEdit->text());
	p->setDateOfBirth(m_dobEdit->dateTime());

	return p;
}

