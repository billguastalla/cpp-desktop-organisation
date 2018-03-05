#pragma once
#include <qdialog.h>
class ProjectInfo;

class QStackedWidget;
class QComboBox;
class QGridLayout;
class QDialogButtonBox;

class CreateEntityDialog : public QDialog
{
public:
	CreateEntityDialog(ProjectInfo * proj, QWidget * parent = nullptr);
	~CreateEntityDialog();

	QStackedWidget * m_entityWidgets;
	QComboBox * m_entityTypes;
	QDialogButtonBox * m_buttons;
	
	QGridLayout * m_layout;
private:
	ProjectInfo * p_projInfo;
};

