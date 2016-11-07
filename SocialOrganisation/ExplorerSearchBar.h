#pragma once

#include <QWidget>

class QLineEdit;
class ExplorerSearchProxyModel;

class ExplorerSearchBar : public QWidget
{
	Q_OBJECT

public:
	ExplorerSearchBar(QWidget *parent, ExplorerSearchProxyModel * model = nullptr);

	void setProxyModel(ExplorerSearchProxyModel * model);
	~ExplorerSearchBar();

protected slots:
void updateProxyText(const QString & text);

private:
	QLineEdit * m_searchEdit;
	ExplorerSearchProxyModel * p_searchModel; /*<---  Expect that this should be owned by the view and not the model.*/
};
