#include "CustomToolButton.h"


CustomToolButton::CustomToolButton(QWidget *parent)
	: QToolButton(parent)
{
	this->setTextColor();

	this->setAutoRaise(true);
}

CustomToolButton::~CustomToolButton()
{

}

void CustomToolButton::setTextColor(QColor color)
{
	QPalette palette = this->palette();
	palette.setColor(QPalette::ButtonText, color);
	this->setPalette(palette);
}

void CustomToolButton::enterEvent(QEvent *)
{
	m_mouseOver = true;
}

void CustomToolButton::leaveEvent(QEvent *)
{
	m_mouseOver = false;
}

void CustomToolButton::setMousePressed(bool mousePressed)
{
	m_mousePressed = mousePressed;
	update();
}

void CustomToolButton::mousePressEvent(QMouseEvent* event)
{

	QToolButton::mousePressEvent(event);
}

void CustomToolButton::mouseReleaseEvent(QMouseEvent* event)
{
	QToolButton::mouseReleaseEvent(event);
}

void CustomToolButton::mouseMoveEvent(QMouseEvent* event)
{
	event->accept();
}

void CustomToolButton::keyPressEvent(QKeyEvent* event)
{
	QToolButton::keyPressEvent(event);
}

void CustomToolButton::keyReleaseEvent(QKeyEvent* event)
{
	QToolButton::keyReleaseEvent(event);
}

void CustomToolButton::paintEvent(QPaintEvent* event)
{
	this->setMousePressed(this->isChecked());

	if (m_mouseOver)
	{
		paintGradient(0, 10, 50);
	}
	else
	{
		if (m_mousePressed)
		{
			paintGradient(0, 10, 150);
		}
	}

	QToolButton::paintEvent(event);
}

void CustomToolButton::resizeEvent(QResizeEvent* event)
{
	QToolButton::resizeEvent(event);
}


void CustomToolButton::paintGradient(int topColor, int middleColor, int bottomColor)
{
	QPainter painter(this);
	QPen pen(Qt::NoBrush, 1);
	painter.setPen(pen);
	QLinearGradient linear(rect().topLeft(), rect().bottomLeft());
	linear.setColorAt(0, QColor(230, 230, 230, topColor));
	linear.setColorAt(0.5, QColor(230, 230, 230, middleColor));
	linear.setColorAt(1, QColor(230, 230, 230, bottomColor));
	painter.setBrush(linear);
	painter.drawRect(rect());
}

void CustomToolButton::focusOutEvent(QFocusEvent* e)
{
	
	QWidget::focusOutEvent(e);
}
