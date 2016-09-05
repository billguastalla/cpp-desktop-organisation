#include "DockWidget_Base.h"
#include "Project.h"

DockWidget_Base::DockWidget_Base(Project * proj, QWidget * parent) : QWidget(parent)
{
	m_proj = proj;
}
