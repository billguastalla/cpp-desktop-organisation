#include "ExplorerSearchProxyModel.h"
#include "ExplorerModel.h"

ExplorerSearchProxyModel::ExplorerSearchProxyModel(QObject * parent) : QSortFilterProxyModel{ parent }
{

}

void ExplorerSearchProxyModel::setSourceModel(ExplorerModel * model)
{
	QSortFilterProxyModel::setSourceModel(model);
}

bool ExplorerSearchProxyModel::filterAcceptsRow(int source_row, const QModelIndex & source_parent) const
{
	QModelIndex & col0 = sourceModel()->index(source_row, 0, source_parent);
	if (col0.isValid())
	{
		bool result = sourceModel()->data(col0, Qt::DisplayRole).toString().contains(filterRegExp().pattern());

		if (result) return true;

		for (int i = 0; i < rowCount(); ++i)
			if (filterAcceptsRow(i, col0)) return true;
	}
	return false;
}

bool ExplorerSearchProxyModel::filterAcceptsColumn(int source_column, const QModelIndex & source_parent) const
{
	return true;
}

bool ExplorerSearchProxyModel::lessThan(const QModelIndex & source_left, const QModelIndex & source_right) const
{
	return true;
}
