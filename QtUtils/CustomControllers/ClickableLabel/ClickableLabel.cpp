#include "ClickableLabel.h"
#include <QDebug>
#include <QtGui/QPainter>
#include <QMouseEvent>
#include <QtWidgets/QMessageBox>
#include <QDateTime>
#include <QMessageBox>
#include <QAbstractButton>

ClickableLabel::ClickableLabel(QWidget* parent)
	: QLabel(parent)
{
	this->setFocusPolicy(Qt::ClickFocus);
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
	QLabel::mousePressEvent(event);
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent* event)
{
	if (this->rect().contains(event->pos()))
	{
		emit this->clicked();
	}
	QLabel::mouseReleaseEvent(event);
}

void ClickableLabel::mouseMoveEvent(QMouseEvent* event)
{

}

void ClickableLabel::enterEvent(QEvent* event)
{
	m_mouseEnter = true;
	this->setFocus();
	this->update();
	QWidget::enterEvent(event);
}

void ClickableLabel::leaveEvent(QEvent* event)
{
	m_mouseEnter = false;
	this->clearFocus();
	this->update();
	QWidget::leaveEvent(event);
}

void ClickableLabel::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QLinearGradient gradient(this->rect().topLeft(), this->rect().bottomLeft());
	if (m_mouseEnter)
	{
		gradient.setColorAt(0, QColor(0, 0, 255, 50));
		gradient.setColorAt(0.5, QColor(0, 0, 255, 70));
		gradient.setColorAt(1, QColor(0, 0, 255, 110));
	}
	else
	{
		gradient.setColorAt(0, QColor(0, 0, 0, 50));
		gradient.setColorAt(0.5, QColor(0, 0, 0, 70));
		gradient.setColorAt(1, QColor(0, 0, 0, 110));
	}

	painter.setBrush(gradient);
	painter.drawRect(this->rect());

	QLabel::paintEvent(event);
}

void ClickableLabel::resizeEvent(QResizeEvent* event)
{

}

void ClickableLabel::keyPressEvent(QKeyEvent* event)
{
#pragma region 
	if (event->key() == Qt::Key_D)
	{
		QMessageBox mess(QMessageBox::Question, QStringLiteral("删除提示"), QStringLiteral("确认删除所选组件?"), NULL);
		QPushButton* okButton = mess.addButton(QStringLiteral("确定"), QMessageBox::AcceptRole);
		QPushButton* cancelButton = mess.addButton(QStringLiteral("取消"), QMessageBox::RejectRole);
		mess.exec();
		if (reinterpret_cast<QPushButton*>(mess.clickedButton()) == okButton)
		{
		}
	}
#pragma endregion
}

void ClickableLabel::keyReleaseEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_D)
	{
	}
}

void ClickableLabel::wheelEvent(QWheelEvent* event)
{
	QLabel::wheelEvent(event);
}

void ClickableLabel::setPixmap(const QString& fileName)
{
	m_pixmap = QPixmap(fileName);
	m_pixmapSize = m_pixmap.size();

	this->QLabel::setPixmap(m_pixmap.scaled(this->width(), this->height(), Qt::KeepAspectRatio));

	m_pixmap = *this->pixmap();
	updatePixmap();
}

void ClickableLabel::updatePixmap()
{
	QPixmap newMap = m_pixmap;

	if (newMap.isNull())
	{
		return;
	}
	double scale = static_cast<double>(m_pixmapSize.height()) / static_cast<double>(m_pixmap.size().height());

	QPainter painter(&newMap);
	QPen pen;
	auto m_pointColor = QColor(255, 0, 0, 255);

	m_pointColor = QColor(255, 0, 0, 255);

	pen.setColor(m_pointColor);
	pen.setWidth(3);
	painter.setPen(pen);
	painter.setBrush(m_pointColor);

	this->QLabel::setPixmap(newMap.scaled(QSize(this->width() - 15, this->height() - 15), Qt::KeepAspectRatio));
}

void ClickableLabel::clear()
{
	QLabel::clear();
}

