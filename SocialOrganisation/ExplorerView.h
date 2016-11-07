#pragma once
#include <qtreeview.h>

class ExplorerModel;

class ExplorerView : public QTreeView
{
	Q_OBJECT
public:
	ExplorerView(QWidget * parent  = nullptr);


// 
	//void doubleClicked(const QModelIndex &index);
//signals:
//	void entityDoubleClicked(Entity * en);

private:
};

