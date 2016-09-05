#include "FileIO.h"

#include "ProjectInfo.h"

#include <qfiledialog.h>
#include <qxmlstream.h>

bool FileIO::loadProject(ProjectInfo * proj, QWidget * parent)
{
	bool success = false;

	QString fileName = QFileDialog::getOpenFileName(parent,"Open Project",	proj->fileDirectory(),"All files (*.*)");


	if(fileName.count() == 0)
		return false;

	QFile a (fileName);
    if (!a.open(QFile::ReadOnly | QFile::Text))
	{
        return false;
    }
	QXmlStreamReader reader (&a);
	success = proj->__parseFromFile(reader);

	return success;
}

bool FileIO::saveProject(ProjectInfo * proj, QWidget * parent)
{
	bool success = false;

	QString fileName = QFileDialog::getSaveFileName(parent,"Save Project",	proj->fileDirectory(),"All files (*.*)");
//	fileName.append(".sclProj");

	if(fileName.count() == 0)
		return false;

	QFile a (fileName);
    if (!a.open(QFile::WriteOnly | QFile::Text))
	{
		return false;
    }

	QXmlStreamWriter writer (&a);
	writer.setAutoFormatting(true);
	writer.writeStartDocument();
	success = proj->__writeToFile(writer);
	writer.writeEndDocument();

	a.close();

	return success;
}