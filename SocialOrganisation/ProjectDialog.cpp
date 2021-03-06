#include "ProjectDialog.h"
//#include "SocialApplication.h"

#include "ProjectInfo.h"
#include "ProjectPropertiesWidget.h"

#include <qdialogbuttonbox.h>
#include <qgridlayout.h>

ProjectDialog::ProjectDialog(ProjectInfo * proj, QWidget * parent)
	: QDialog(parent)
{
	m_project = proj;

	m_projectPropsWid = new ProjectPropertiesWidget(m_project,this);
	
	m_btns = new QDialogButtonBox(QDialogButtonBox::StandardButton::Ok | QDialogButtonBox::StandardButton::Cancel,this);
	connect(m_btns,SIGNAL(accepted()),this,SLOT(save()));
	connect(m_btns,SIGNAL(rejected()),this,SLOT(reject()));

	QGridLayout * lay = new QGridLayout(this);

	lay->addWidget(m_projectPropsWid,0,0,1,1);
	lay->addWidget(m_btns,1,0,1,1);

	setLayout(lay);
}

void ProjectDialog::save()
{
	m_projectPropsWid->save();
	accept();
}