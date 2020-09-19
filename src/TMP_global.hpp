#ifndef TMP_GLOBAL_HPP
#define TMP_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(TMP_LIBRARY)
#  define TMP_EXPORT Q_DECL_EXPORT
#else
#  define TMP_EXPORT Q_DECL_IMPORT
#endif

#endif // TMP_GLOBAL_HPP
