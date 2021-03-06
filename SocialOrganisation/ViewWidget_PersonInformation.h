#include "ViewWidget_Base.h"

class Person;

// By VIEW, we mean the type of central widget displayed, not the dock widgets.

class ViewWidget_PersonInformation : public ViewWidget_Base
{
	Q_OBJECT
public:
	ViewWidget_PersonInformation(Person * pers, Project * proj, TabManager * parent);
	const virtual QString & id() const;
private:
	Person * p_pers;
};