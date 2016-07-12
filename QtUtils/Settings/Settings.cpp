#include "Settings.h"

#include <QApplication>

namespace QtUtils
{
	QString Settings::m_applicationName;
	QString Settings::m_organizationName;
	QSettings::Format Settings::m_settingsFormat = QSettings::NativeFormat;

	Settings::Settings() : m_settings(m_settingsFormat, QSettings::UserScope,
									  m_organizationName.isEmpty() ? qApp->organizationName() : m_organizationName,
									  m_applicationName.isEmpty() ? qApp->applicationName() : m_applicationName)
	{
	}

	void Settings::setApplicationName(const QString& name)
	{
		m_applicationName = name;
	}

	void Settings::setOrganizationName(const QString& name)
	{
		m_organizationName = name;
	}

	void Settings::setFormat(QSettings::Format format)
	{
		m_settingsFormat = format;
	}

	void Settings::setValue(const QString& key, const QVariant& value)
	{
		m_settings.setValue(key, value);
	}

	QVariant Settings::value(const QString& key, const QVariant& defaultValue) const
	{
		return m_settings.value(key, defaultValue);
	}
}

