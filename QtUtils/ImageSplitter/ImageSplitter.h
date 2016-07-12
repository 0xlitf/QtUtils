#ifndef IMAGESPLITTER_H
#define IMAGESPLITTER_H
#include <QtGui/qpixmap.h>
#include "qtutils_global.h"

namespace QtUtils
{
	class QTUTILS_EXPORT ImageSplitter
	{
	public:
		ImageSplitter();
		ImageSplitter(QPixmap pix, int x, int y);
		~ImageSplitter();
		void setDimension(int x, int y);
		void setPixmap(QPixmap pix);
		QPixmap at(int x, int y) const;

	private:
		int m_xDimention = 1;
		int m_yDimension = 1;
		QPixmap m_pixmap;
	};
}
#endif // IMAGESPLITTER_H
