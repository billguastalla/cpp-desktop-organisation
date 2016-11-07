#include "ExplorerSearchBar.h"
#include "ExplorerSearchProxyModel.h"

#include <qlineedit.h>
#include <qgridlayout.h>

ExplorerSearchBar::ExplorerSearchBar(QWidget *parent, ExplorerSearchProxyModel * model)
	: QWidget{ parent }, p_searchModel{ model }
{
	m_searchEdit = new QLineEdit{ this };
	m_searchEdit->setPlaceholderText("Search...");
	connect(m_searchEdit, SIGNAL(textChanged(const QString &)), this, SLOT(updateProxyText(const QString &)));

	/* TODO :  Add ability to filter types e.g. combobox or whatever. */
	QGridLayout * lay = new QGridLayout{ this };
	lay->addWidget(m_searchEdit, 0, 0);
	lay->setContentsMargins(0, 0, 0, 0);

	setLayout(lay);
}

void ExplorerSearchBar::setProxyModel(ExplorerSearchProxyModel * model)
{
	p_searchModel = model;
}

ExplorerSearchBar::~ExplorerSearchBar()
{

}

void ExplorerSearchBar::updateProxyText(const QString & text)
{
	/* or if you don't use the standard string implementation then you can do some custom update here. */
	p_searchModel->setFilterFixedString(text);
}