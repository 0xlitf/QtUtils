#pragma once
#include <QtCore/qstring.h>
#include <QtCore/qtextstream.h>
#include <QtCore/QFile>
#include <QtCore/QDateTime>
#include <QApplication>

namespace QtUtils
{
	inline void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
	{
		static QMutex mutex;
		mutex.lock();

		QString urgency;
		switch (type)
		{
		case QtDebugMsg:
			urgency = QString("Debug:>");
			break;

		case QtWarningMsg:
			urgency = QString("Warning:>");
			break;

		case QtCriticalMsg:
			urgency = QString("Critical:>");
			break;

		case QtFatalMsg:
			urgency = QString("Fatal:>");

		case QtInfoMsg:
			urgency = QString("Info:>");
		}

		QString context_info = QString("<File:%1, Line:%2>").arg(context.file).arg(context.line);
		QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
		QString current_date = QString("<%1>").arg(current_date_time);
		QString message = QString("%1  %2, %3, %4").arg(urgency).arg(msg).arg(context_info).arg(current_date);

		QString strPath = QString("%1/log.txt").arg(QApplication::applicationDirPath());
		QFile file(strPath);
		file.open(QIODevice::WriteOnly | QIODevice::Append);
		QTextStream text_stream(&file);
		text_stream << message << "\r\n";
		file.flush();
		file.close();

		mutex.unlock();
	}
}

