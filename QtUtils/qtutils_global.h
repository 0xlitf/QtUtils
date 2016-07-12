#ifndef QTUTILS_GLOBAL_H
#define QTUTILS_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef QTUTILS_LIB
# define QTUTILS_EXPORT Q_DECL_EXPORT
#else
# define QTUTILS_EXPORT Q_DECL_IMPORT
#endif

#endif // QTUTILS_GLOBAL_H


