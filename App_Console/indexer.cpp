#include "indexer.h"


Indexer::Indexer()
{
    _pool.setMaxThreadCount(1);
}

Indexer::~Indexer() {}

bool Indexer::scanRepository(QString m_start_path)
{
    QFuture<void> future = QtConcurrent::run(&_pool, [this,m_start_path]() {

        QStringList temp;

        QDir dir(m_start_path);
        QDirIterator it(dir, QDirIterator::Subdirectories);

        while(it.hasNext())
        {
            QFile file(it.next());
            temp = {};

            //Path
            temp.append(it.filePath());
            //Name
            temp.append(it.fileInfo().fileName());
            //Suffix
            if(!it.fileInfo().suffix().isEmpty())
            {
                temp.append(it.fileInfo().suffix());
            }
            else
            {
                temp.append("NO EXTENSION");
            }
            //Size
            temp.append(QString::number(it.fileInfo().size()));
            //Date
            temp.append(it.fileInfo().lastModified().toString());
            //Status
            temp.append("UNDEFINED");
            if(it.fileInfo().fileName() != ".." && it.fileInfo().fileName() != ".")
            {
                _vectorIndexes.append(temp);
            }
        }
        sendDatabase();
    });
    return false;
}

void Indexer::sendDatabase()
{
    _db.addDatabase(_vectorIndexes);
}
