#include "QssUtil.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>

namespace QtUtils
{
	void QssUtil::setStyle(const QString& qssFilePath)
	{
		QFile f(qssFilePath);
		if (!f.exists())
		{
			printf("Unable to set stylesheet, file not found\n");
		}
		else
		{
			f.open(QFile::ReadOnly | QFile::Text);
			QTextStream ts(&f);
			qApp->setStyleSheet(ts.readAll());
		}
	}

	void QssUtil::setStyle(QssUtil::Style style)
	{
		QString qssFilePath;
		switch (style)
		{
		case Dark:
			qssFilePath = QStringLiteral(":qdarkstyle/style.qss") ;
			break;
		case Black:
			qssFilePath = QStringLiteral(":/style/black.qss") ;
			break;
		case Coffee:
			qssFilePath = QStringLiteral(":/style/coffee.qss") ;
			break;
		case Default:
			qssFilePath = QStringLiteral(":/style/default.qss") ;
			break;
		case Evilworks:
			qssFilePath = QStringLiteral(":/style/evilworks.qss") ;
			break;
		case Transparent:
			qssFilePath = QStringLiteral(":/style/transparent.qss") ;
			break;
		case Application:
			qssFilePath = QStringLiteral(":/style/application.qss") ;
			break;
		case Khaki:
			qssFilePath = QStringLiteral(":/style/khaki.qss") ;
			break;
		default:
			break;
		}
		if (qssFilePath.isNull())
		{
			return;
		}
		QssUtil::setStyle(qssFilePath);
	}
}

