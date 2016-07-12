#ifndef FILEUTIL_H
#define FILEUTIL_H
#include <QtCore/QSettings>
#include <QMainWindow>
#include <QProcessEnvironment>

namespace QtUtils
{
	class FileUtil
	{
	public:
		static bool compareFile(const QString& fileName1, const QString& fileName2, bool canonical = true);
		static QStringList removeFiles(const QStringList& files);
		static QStringList removeWorkDir(const QString& workDir, const QStringList& filters);
		static QMap<QString, QStringList> readFileContext(QIODevice* dev);
		static QString findExecute(const QString& target);
		static QString canExec(QString file, QStringList exts = QStringList());
		static QString lookPath(const QString& fileName, const QProcessEnvironment& env, bool bLocalPriority);
		static QString lookPathInDir(const QString& fileName, const QString& dir);
		static bool CopyDirectory(const QString& src, const QString& dest);
		static void openInExplorer(const QString& path);
		static QList<QString> scanAllFiles(const QString& folder);
	};
}
#endif // FILEUTIL_H


