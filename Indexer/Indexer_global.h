#ifndef INDEXER_GLOBAL_H
#define INDEXER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(INDEXER_LIBRARY)
#  define INDEXER_EXPORT Q_DECL_EXPORT
#else
#  define INDEXER_EXPORT Q_DECL_IMPORT
#endif

#endif // INDEXER_GLOBAL_H
