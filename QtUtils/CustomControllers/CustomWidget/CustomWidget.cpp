#include "CustomWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtWidgets/qapplication.h>
#include <QDebug>

CustomWidget::CustomWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setAutoFillBackground(true);


}

CustomWidget::~CustomWidget()
{

}

void CustomWidget::setBackgroundPixmap(QPixmap& pixmap)
{
	m_backgroundPixmap = pixmap;

	emit backgroundPixmapChanged();
}

QPixmap CustomWidget::backgroundPixmap()
{
	return m_backgroundPixmap;
}

void CustomWidget::setBackgroundColor(QColor& color)
{
	m_backgroundColor = color;

	QPalette pa(this->palette());
	pa.setColor(QPalette::Background, m_backgroundColor);
	this->setPalette(pa);

	emit backgroundColorChanged();
}

QColor CustomWidget::backgroundColor()
{
	return m_backgroundColor;
}

void CustomWidget::setMovable(bool b)
{
	m_movable = b;

	emit backgroundPixmapChanged();
}

bool CustomWidget::movable() const
{
	return m_movable;
}

QWidget* CustomWidget::lastParent(QWidget* widget)
{
	if (widget && widget->parent())
	{
		return lastParent(static_cast<QWidget*>(widget->parent()));
	}
	return widget;
}

void CustomWidget::enterEvent(QEvent* event)
{
	QWidget::enterEvent(event);
}

void CustomWidget::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
}

void CustomWidget::mousePressEvent(QMouseEvent* event)
{
	m_pressed = true;
	m_pressPoint = event->pos();

	QWidget::mousePressEvent(event);
}

void CustomWidget::mouseReleaseEvent(QMouseEvent* event)
{
	QWidget::mouseReleaseEvent(event);
}

void CustomWidget::mouseMoveEvent(QMouseEvent* event)
{
	auto p = this->lastParent(this);
	if (m_movable && m_pressed)
	{
		p->move(p->pos() - (m_pressPoint - event->pos()));
	}

	event->accept();
}

void CustomWidget::keyPressEvent(QKeyEvent* event)
{
	QWidget::keyPressEvent(event);
}

void CustomWidget::keyReleaseEvent(QKeyEvent* event)
{
	QWidget::keyReleaseEvent(event);
}

void CustomWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_backgroundPixmap.width(), m_backgroundPixmap.height(), m_backgroundPixmap);




	QWidget::paintEvent(event);
}

void CustomWidget::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event);
}


