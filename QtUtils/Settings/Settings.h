#ifndef SETTINGS_H
#define SETTINGS_H
#include <QtCore/QSettings>
#include <qtutils_global.h>
#include <QtWidgets/QMainWindow>

namespace QtUtils
{
	class QTUTILS_EXPORT Settings
	{
	public:
		Settings();
		~Settings() = default;

		static void setApplicationName(const QString& name);
		static void setOrganizationName(const QString& name);
		static void setFormat(QSettings::Format format);

		void setValue(const QString& key, const QVariant& value);
		QVariant value(const QString& key, const QVariant& defaultValue = QVariant()) const;

		static void saveMainWindow(QSettings& settings, QMainWindow& mainWindow, QString key = "MainWindow")
		{
			settings.beginGroup(key);
			settings.setValue("Geometry", mainWindow.saveGeometry());
			settings.endGroup();
		}

		static void restoreMainWindow(QSettings& settings, QMainWindow& mainWindow, QString key = "MainWindow")
		{
			settings.beginGroup(key);
			mainWindow.restoreGeometry(settings.value("Geometry", QByteArray()).toByteArray());
			settings.endGroup();
		}

	private:
		QSettings m_settings;

		QSettings::SettingsMap m_settingsMap;

		static QString m_applicationName;
		static QString m_organizationName;
		static QSettings::Format m_settingsFormat;
	};
}
#endif // SETTINGS_H


