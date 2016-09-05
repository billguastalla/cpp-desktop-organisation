#include <qobject.h>
#include "SerialisableObject.h"

class ProjectInfo;
class ApplicationWindow;

enum class ProjectState
{
	FileClosed,			// No file is open..
	FileNotSaved,		// New file created, but has never been saved to disk.
	FileOpen,			// File is open, and unchanged
	FileModified,		// File is open and has been modified.
};

class Project : public QObject, public SerialisableObject
{
	Q_OBJECT
public:
	Project(ApplicationWindow * parent);
	ProjectInfo * data() { return m_pInfo; }
	ProjectState state() { return m_state; }

	public slots:
		bool createNewFile();
		bool openFromFile(bool silent = false);
		bool saveToFile(bool silent = false, QString path = QString());
		bool saveAsToFile(bool silent = false);
		bool closeProject(bool silent = false);
private:
	bool warnSave();

signals:
		void projectStateChanged(ProjectState state);

private:
	bool __parseFromFile(QXmlStreamReader & reader);
	bool __writeToFile(QXmlStreamWriter & writer);

	virtual QList<SerialisableObject*> m_children();
	virtual void setModified()
	{
		m_state = ProjectState::FileModified;
	}
	
	ProjectState m_state;
	QString m_currentPath;

	ProjectInfo * m_pInfo;

	ApplicationWindow * m_app;
};