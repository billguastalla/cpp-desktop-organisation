#pragma once
#include <qstandarditemmodel.h>

class Project;
class ProjectInfo;
enum class ProjectState;

/*
	-> Main question is: How do we maintain the model?
		-> i.e. when projectInfo changes, what do we do?
			-> when a person's name changes, how do we tell the model?
		-> I think it's probably a good idea not to overuse the slots mechanism.

*/

class ExplorerModel : public QStandardItemModel
{
	Q_OBJECT
public:
	ExplorerModel(Project * proj);

	public slots:
	void refreshProject(ProjectState state);
private:
	Project * p_proj;
	ProjectInfo * p_info;
};