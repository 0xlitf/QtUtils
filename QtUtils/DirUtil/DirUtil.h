#ifndef DIRUTIL_H
#define DIRUTIL_H

#include "qtutils_global.h"
#include <QtCore/QObject>

namespace QtUtils
{
	class QTUTILS_EXPORT DirUtil : public QObject
	{
		Q_OBJECT

	public:
		explicit DirUtil(QObject* parent = nullptr);

		/// @brief �����ļ��������е��ļ�
		/// @param path Ҫ���ҵ��ļ���
		/// @param nameFilters �ļ�����
		/// @return �ҵ����ļ��б�
		QStringList findFiles(const QString& path,
							  const QStringList& nameFilters = QStringList());

		/// @brief ����Ŀ¼�������е��ļ������ļ���
		/// @param fromPath Դ�ļ���
		/// @param toPath Ŀ���ļ���
		/// @param nameFilters �ļ�����
		/// @param overWrite �Ƿ񸲸�
		/// @return ���Ƶ��ļ�����
		int copyDirs(const QString& fromPath, const QString& toPath,
					 const QStringList& nameFilters = QStringList(),
					 bool overWrite = true);

		/// @brief �����ļ��б����ļ���
		/// @param files Դ�ļ��б�
		/// @param toPath Ŀ���ļ���
		/// @param overWrite �Ƿ񸲸�
		/// @return ���Ƶ��ļ�����
		int copyFiles(const QStringList& files, const QString& toPath,
					  bool overWrite = true);

		/// @brief ����m_copyFileCountΪ0
		void resetCopyFileCount();
		Q_SIGNALS:
		/// @brief �źţ���ǰ���Ƶ��ļ��ļ������ļ���
		/// @param count �ڼ����ļ�
		/// @param name Դ�ļ���
		void currentFile(int count, const QString& name);
	private:
		int m_copyFileCount;

		void doDirTree(const QString& fromPath, const QString& toPath,
					   const QStringList& nameFilters, bool overWrite,
					   QStringList& findFiles, bool isFind);
		QString formatPath(const QString& path);
	};
}

#endif // DIRUTIL_H


