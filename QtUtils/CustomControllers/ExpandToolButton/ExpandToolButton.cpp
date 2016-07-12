#include "ExpandToolButton.h"
#include <QDebug>
#include <QApplication>

ExpandToolButton::ExpandToolButton(QWidget *parent)
	: CustomToolButton(parent)
{
	this->setFocusPolicy(Qt::ClickFocus);
	this->setTextColor(QColor(85, 85, 255));
}

ExpandToolButton::~ExpandToolButton()
{

}

void ExpandToolButton::addToolButton(QIcon icon, QString text)
{
	auto* btn = new CustomToolButton;
	btn->setTextColor(QColor(85, 85, 255));
	btn->setIcon(icon);
	btn->setText(text);
	btn->setParent(static_cast<QWidget*>(this->parent()));
	btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	btn->setIconSize(this->iconSize());
	btn->setFocusPolicy(Qt::ClickFocus);
	btn->hide();
	btn->setCheckable(false);

	auto index = m_buttonList.size();
	connect(btn, &QToolButton::clicked, [=]()
	{
		qDebug() << "child clicked";
		btn->setFocus();
		this->setIcon(btn->icon());
		this->setText(btn->text());
		m_index = index;
		qDebug() << m_index;

		this->collapse();
	});

	m_buttonList.append(btn);
}

void ExpandToolButton::enterEvent(QEvent *)
{
	m_mouseOver = true;
}

void ExpandToolButton::leaveEvent(QEvent *)
{
	m_mouseOver = false;
}

void ExpandToolButton::mousePressEvent(QMouseEvent* event)
{
	qDebug() << QString("ExpandToolButton clicked:%1,%2").arg(this->pos().x()).arg(this->pos().y());
	if (m_buttonList.isEmpty())
	{
		return;
	}

	auto i = 0;
	for (auto btn : m_buttonList)
	{
		btn->setMinimumSize(this->size());
		btn->setMaximumSize(this->size());
		btn->move(this->pos().x() + (i + 1) * this->size().width(), this->pos().y());

		b_visiable ? btn->hide() : btn->show();

		++i;
	}

	b_visiable = !b_visiable;

	QToolButton::mousePressEvent(event);
}

void ExpandToolButton::mouseReleaseEvent(QMouseEvent* event)
{
	QToolButton::mouseReleaseEvent(event);
}

void ExpandToolButton::mouseMoveEvent(QMouseEvent* event)
{
	event->accept();
}

void ExpandToolButton::keyPressEvent(QKeyEvent* event)
{
	QToolButton::keyPressEvent(event);
}

void ExpandToolButton::keyReleaseEvent(QKeyEvent* event)
{
	QToolButton::keyReleaseEvent(event);
}

void ExpandToolButton::paintEvent(QPaintEvent* event)
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

void ExpandToolButton::resizeEvent(QResizeEvent* event)
{
	QToolButton::resizeEvent(event);
}

void ExpandToolButton::focusInEvent(QFocusEvent* e)
{
	QToolButton::focusInEvent(e);

}

void ExpandToolButton::focusOutEvent(QFocusEvent* e)
{
	for (auto btn : m_buttonList)
	{
		if (QApplication::focusWidget() == btn)
		{
			return;
		}
	}
	this->collapse();

	QToolButton::focusOutEvent(e);
}

void ExpandToolButton::collapse()
{
	b_visiable = false;
	for (auto btn : m_buttonList)
	{
		btn->hide();
	}
}

bool ExpandToolButton::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::FocusOut) {
		QFocusEvent *e = static_cast<QFocusEvent *>(event);
		qDebug("Ate key press %d", e->lostFocus());
		return true;
	}
	else
	{
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}
