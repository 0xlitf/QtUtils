#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>
#include "qtutils_global.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>

class QTUTILS_EXPORT CustomToolButton : public QToolButton
{
	Q_OBJECT

public:
	CustomToolButton(QWidget *parent = nullptr);
	~CustomToolButton();
	void setTextColor(QColor color = QColor(230, 230, 230));
	void setMousePressed(bool mousePressed);
	void CustomToolButton::paintGradient(int topColor, int middleColor, int bottomColor);
	void focusOutEvent(QFocusEvent* e) override;
protected:
	void enterEvent(QEvent *event) override;
	void leaveEvent(QEvent *event) override;

	void mousePressEvent(QMouseEvent *) override;
	void mouseReleaseEvent(QMouseEvent *) override;
	void mouseMoveEvent(QMouseEvent *) override;

	void keyPressEvent(QKeyEvent *) override;
	void keyReleaseEvent(QKeyEvent *event) override;

	void paintEvent(QPaintEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;

protected:
	bool m_mouseOver = false;
	bool m_mousePressed = false;
};

#endif // TOOLBUTTON_H
