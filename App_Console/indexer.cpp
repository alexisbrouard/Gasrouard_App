#include "indexer.h"

Indexer::Indexer()
{

}

void Indexer::scanRepository(QString m_start_path)
{
    QStringList temp;

    QDirIterator it(m_start_path, QDirIterator::Subdirectories);

    while(it.hasNext())
    {
        //Path
        temp.append(it.filePath());
        //Name
        temp.append(it.fileName());
        //Suffix
        temp.append(it.fileInfo().suffix());
        //Size
        temp.append(QString::number(it.fileInfo().size()));

        _vectorIndexes.append(temp);
    }
}

void Indexer::sendDatabase()
{
    _db.addDatabase(_vectorIndexes);
}
