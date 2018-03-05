#pragma once
#include "Entity.h"
#include <qdatetime.h>
class ProjectInfo;

class Task : public Entity
{
	Task(ProjectInfo * info);


private:
	QString m_name, m_notes, m_topic, m_subtopic, m_nextStep;
	QDateTime m_dateAdded, m_dateDone;
	QString m_progress;
};