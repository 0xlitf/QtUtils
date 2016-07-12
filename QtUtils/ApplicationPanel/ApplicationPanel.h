#ifndef APPLICATIONPANEL_H
#define APPLICATIONPANEL_H
#include "qtutils_global.h"
#include <QtWidgets/qapplication.h>
#include <QFont>
#include <QssUtil/QssUtil.h>

class QApplication;

namespace QtUtils
{
	class QTUTILS_EXPORT ApplicationPanel
	{
	public:
		explicit ApplicationPanel(QApplication* pApp = qApp);
		~ApplicationPanel();

		static void setSingleInstance();
		static void setApplicationFont(QFont font = QFont(QString::fromLocal8Bit("Î¢ÈíÑÅºÚ"), 9, QFont::Normal, false));
		static void showSplashScreen(const QPixmap& pixmap);
		static void setStyle(const QString& qssFilePath);
		static void setStyle(QssUtil::Style style);

	private:
	};
}
#endif // APPLICATIONPANEL_H


