#pragma once
#include <qsortfilterproxymodel.h>

class ExplorerModel;

class ExplorerSearchProxyModel : public QSortFilterProxyModel
{
public:
	ExplorerSearchProxyModel(QObject * parent = nullptr);

	void setSourceModel(ExplorerModel * model);
protected:
	/*<--- i.e implement these :  ---> */
	bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
	bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override;
	bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

private:
	/*<--- Stop user of this class from setting a model that isn't an explorer model. --->*/
	__inline void setSourceModel(QAbstractItemModel * inaccessible) { QSortFilterProxyModel::setSourceModel(inaccessible); }
};