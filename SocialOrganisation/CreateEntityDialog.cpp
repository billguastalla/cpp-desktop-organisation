#include "CreateEntityDialog.h"

#include <qstackedwidget.h>
#include <qcombobox.h>
#include <qgridlayout>
#include <qdialogbuttonbox.h>

CreateEntityDialog::CreateEntityDialog(ProjectInfo * proj, QWidget * parent) : QDialog(parent), p_projInfo(proj)
{
	m_layout = new QGridLayout{ this };
	m_entityTypes = new QComboBox{ this };
	m_entityWidgets = new QStackedWidget{ this };
	m_buttons = new QDialogButtonBox{ this };
	

	m_layout->addWidget(m_entityTypes, 0, 0, 1, 1);
	m_layout->addWidget(m_entityWidgets, 1, 1, 5, 5);
	m_layout->addWidget(m_buttons, 2, 3, 1, 3);

	setLayout(m_layout);
}


CreateEntityDialog::~CreateEntityDialog()
{
}
