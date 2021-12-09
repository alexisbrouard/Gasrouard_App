#include "indexer.h"

Indexer::Indexer()
{

}

void Indexer::scanRepository(QString m_start_path)
{
    QDirIterator it(m_start_path, QDirIterator::Subdirectories);

    //Appel à la base de données
}
