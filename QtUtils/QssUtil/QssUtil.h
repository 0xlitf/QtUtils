#ifndef QSSUTIL_H
#define QSSUTIL_H
#include <QtWidgets/qapplication.h>

class QApplication;

namespace QtUtils
{
	class QssUtil
	{
	public:
		enum Style
		{
			Dark,
			Black,
			Coffee,
			Default,
			Evilworks,
			Transparent,
			Application,
			Khaki
		};

		static void setStyle(const QString& qssFilePath);
		static void setStyle(QssUtil::Style style);

	private:
	};
}

#endif // QSSUTIL_H


