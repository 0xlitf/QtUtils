#ifndef QTUTILS_H
#define QTUTILS_H

#include "qtutils_global.h"

//#include "..\DirUtil\DirUtil.h"
#include ".\ApplicationPanel\ApplicationPanel.h"
#include ".\CustomControllers\ClickableLabel\ClickableLabel.h"
#include ".\FileUtil\FileUtil.h"
#include ".\MessageHandler\MessageHandler.h"
#include ".\MessageHandler\MessagePattern.h"
#include ".\QssUtil\QssUtil.h"
#include ".\Settings\Settings.h"
#include ".\TaskBarProgress\TaskBarProgress.h"
#include ".\WindowsPathUtil\WindowsPathUtil.h"
#include ".\ImageSplitter\ImageSplitter.h"
#include <QObject>

namespace QtUtils
{
	template <typename T1 = QObject, typename T2 = QObject>
	class Connector
	{
	public:
		using SignallingType = const T1*;
		using ReceivingType = const T2*;

		Connector() = delete;

		explicit Connector(const T1* signalObj)
			: m_signallingObject(signalObj), m_receivingObject(signalObj)
		{
			Q_ASSERT(signalObj);
		}

		Connector(const T1* signalObj, const T2* recvObj)
			: m_signallingObject(signalObj), m_receivingObject(recvObj)
		{
			Q_ASSERT(m_signallingObject);
			Q_ASSERT(m_receivingObject);
		}

		Connector(const Connector&) = default;

		template <typename Func1, typename Func2>
		const Connector& connect(Func1 signal, Func2 slot) const
		{
			QObject::connect(m_signallingObject, signal, m_receivingObject, slot);
			return *this;
		}

		template <typename Func1, typename Func2>
		const Connector& disconnect(Func1 signal, Func2 slot) const
		{
			QObject::disconnect(m_signallingObject, signal, m_receivingObject, slot);
			return *this;
		}

	protected:
		void operator=(const Connector&) = delete;

		SignallingType const m_signallingObject;
		ReceivingType const m_receivingObject;
	};

	template <typename T1 = QObject, typename T2 = QObject>
	class ConnectorWithType : public Connector<T1, T2>
	{
	public:
		ConnectorWithType() = delete;

		ConnectorWithType(const T1* signalObj, Qt::ConnectionType type)
			: Connector<T1, T2>(signalObj), m_type(type)
		{
		}

		ConnectorWithType(const T1* signalObj, const T2* recvObj, Qt::ConnectionType type)
			: Connector<T1, T2>(signalObj, recvObj), m_type(type)
		{
		}

		ConnectorWithType(const ConnectorWithType&) = default;

		template <typename Func1, typename Func2>
		const ConnectorWithType& connect(Func1 signal, Func2 slot) const
		{
			QObject::connect(this->m_signallingObject, signal, this->m_receivingObject, slot, m_type);
			return *this;
		}

		template <typename Func1, typename Func2>
		const ConnectorWithType& disconnect(Func1 signal, Func2 slot) const
		{
			QObject::disconnect(this->m_signallingObject, signal, this->m_receivingObject, slot, m_type);
			return *this;
		}

		Qt::ConnectionType type() const
		{
			return m_type;
		}

	private:
		void operator=(const ConnectorWithType&) = delete;

		const Qt::ConnectionType m_type;
	};

	template <typename T1, typename T2>
	Connector<T1, T2> makeConnector(const T1* signalObj, const T2* recvObj)
	{
		return Connector<T1, T2>(signalObj, recvObj);
	}

	template <typename T1, typename T2>
	Connector<T1, T2> makeConnector(const QScopedPointer<T1>& signalObj,
									const QScopedPointer<T2>& recvObj)
	{
		return Connector<T1, T2>(signalObj.data(), recvObj.data());
	}

	template <typename T1, typename T2>
	ConnectorWithType<T1, T2> makeQueuedConnector(
		const T1* signalObj, const T2* recvObj)
	{
		return ConnectorWithType<T1, T2>(signalObj, recvObj, Qt::QueuedConnection);
	}

	template <typename T1, typename T2>
	ConnectorWithType<T1, T2> makeQueuedConnector(
		const QScopedPointer<T1>& signalObj,
		const QScopedPointer<T2>& recvObj)
	{
		return ConnectorWithType<T1, T2>(signalObj.data(), recvObj.data(), Qt::QueuedConnection);
	}

	template <typename T, typename Func>
	void deleteLaterOn(const T* signalObj, Func signal)
	{
		Connector<T, T>(signalObj).connect(signal, &QObject::deleteLater);
	}

	template <typename T, typename Func>
	void deleteLaterOn(const QScopedPointer<T>& signalObj, Func signal)
	{
		Connector<T, T>(signalObj.data()).connect(signal, &QObject::deleteLater);
	}
}
#endif // QTUTILS_H


