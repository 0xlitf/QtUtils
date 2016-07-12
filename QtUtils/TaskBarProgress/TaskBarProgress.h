#ifndef TASKBARPROCESS_H
#define TASKBARPROCESS_H

#include <QProgressBar>
#include <qtutils_global.h>

namespace QtUtils
{
	class QTUTILS_EXPORT TaskBarProgress : public QProgressBar
	{
	public:
		explicit TaskBarProgress(QWidget* parent = nullptr);

	private:
	};
}
#endif // TASKBARPROCESS_H


