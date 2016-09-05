class ProjectInfo;
class QWidget;

namespace FileIO
{
	bool saveProject(ProjectInfo * proj, QWidget * parent);
	bool loadProject(ProjectInfo * proj, QWidget * parent);


}