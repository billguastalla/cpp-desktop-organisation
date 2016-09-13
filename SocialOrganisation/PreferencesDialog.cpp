#include "PreferencesDialog.h"

#include <qtabwidget.h>
#include <qdialogbuttonbox.h>
#include <qgridlayout.h>

PreferencesDialog::PreferencesDialog(QWidget * parent) : QDialog(parent)
{
	setWindowTitle("Preferences");

	m_preferencesTabs = new QTabWidget(this);

	//m_preferencesTabs->setTabPosition(QTabWidget::TabPosition::West);
	//m_preferencesTabs->setTabShape(QTabWidget::TabShape::Rounded);

	m_preferencesTabs->addTab(new QWidget(),tr("General"));
	m_preferencesTabs->addTab(new QWidget(),tr("UI"));
	m_preferencesTabs->addTab(new QWidget(),tr("Advanced"));

	m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

	QGridLayout * lay = new QGridLayout(this);
	lay->addWidget(m_preferencesTabs,	0, 0, 1, 1);
	lay->addWidget(m_buttonBox,			1, 0, 1, 1);
	lay->setRowStretch(0,5);

	setLayout(lay);
	setMinimumSize(720,480);
}