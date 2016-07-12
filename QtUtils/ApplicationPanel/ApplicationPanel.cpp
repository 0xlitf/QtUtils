#include "ApplicationPanel.h"
#include <QFont>
#include <QSplashScreen>
#include <QThread>
#include <QSharedMemory>
#include <QMessageBox>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

namespace QtUtils
{
	ApplicationPanel::ApplicationPanel(QApplication* pApp)
	{
	}

	ApplicationPanel::~ApplicationPanel()
	{
	}

	void ApplicationPanel::setSingleInstance()
	{
		QSharedMemory* shared_memory = new QSharedMemory;
		shared_memory->setKey(QString(qApp->applicationName()));

		if (shared_memory->attach())
		{
			exit(1);
		}

		shared_memory->create(1);
	}

	void ApplicationPanel::setApplicationFont(QFont font)
	{
		//QFont font(QString::fromLocal8Bit("微软雅黑"), 9, QFont::Normal, false);
		font.setStyleStrategy(QFont::PreferAntialias);
		QApplication::setFont(font);
	}

	void ApplicationPanel::showSplashScreen(const QPixmap& pixmap)
	{
		if (pixmap.isNull())
		{
			return;
		}
		QSplashScreen splash(pixmap);
		splash.setDisabled(true); //禁用用户的输入响应事件
		splash.show();
		QThread().sleep(1);
	}

	void ApplicationPanel::setStyle(const QString& qssFilePath)
	{
		QssUtil::setStyle(qssFilePath);
	}

	void ApplicationPanel::setStyle(QssUtil::Style style)
	{
		QssUtil::setStyle(style);
	}
}

