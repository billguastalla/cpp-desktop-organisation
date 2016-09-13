#include "ViewWidget_Base.h"

#include "Project.h"
#include "TabManager.h"

ViewWidget_Base::ViewWidget_Base(Project * proj, TabManager * parent)
	: QWidget(parent),
	m_proj(proj)
{

}