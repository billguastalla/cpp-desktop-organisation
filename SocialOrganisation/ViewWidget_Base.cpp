#include "ViewWidget_Base.h"

#include "Project.h"
#include "SocialApplication.h"

ViewWidget_Base::ViewWidget_Base(Project * proj, ApplicationWindow * parent)
	: QWidget(parent),
	m_proj(proj)
{

}