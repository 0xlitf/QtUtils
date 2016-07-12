#include "ImageSplitter.h"

namespace QtUtils
{
	ImageSplitter::ImageSplitter()
	{

	}

	ImageSplitter::ImageSplitter(QPixmap pix, int x, int y)
	{
		this->setPixmap(pix);
		this->setDimension(x, y);
	}

	ImageSplitter::~ImageSplitter()
	{

	}

	void ImageSplitter::setDimension(int x, int y)
	{
		m_xDimention = x;
		m_yDimension = y;
	}

	void ImageSplitter::setPixmap(QPixmap pix)
	{
		m_pixmap = pix;
	}

	QPixmap ImageSplitter::at(int x, int y) const
	{
		if (m_pixmap.isNull())
		{
			return {};
		}

		auto w = m_pixmap.width();
		auto h = m_pixmap.height();

		QSize sz(w / m_xDimention, h / m_yDimension);
		QPoint point(x * w / m_xDimention, y * h / m_yDimension);

		return m_pixmap.copy(QRect(point, sz));
	}
}