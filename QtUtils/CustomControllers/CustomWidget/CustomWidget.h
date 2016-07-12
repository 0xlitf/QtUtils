#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include "qtutils_global.h"

class QTUTILS_EXPORT CustomWidget : public QWidget
{
	Q_OBJECT
public:
	CustomWidget(QWidget *parent);
	~CustomWidget();

	Q_PROPERTY(QPixmap backgroundPixmap MEMBER m_backgroundPixmap READ backgroundPixmap WRITE setBackgroundPixmap NOTIFY backgroundPixmapChanged)
		Q_PROPERTY(QColor backgroundColor MEMBER m_backgroundPixmap READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
		Q_PROPERTY(bool movable MEMBER m_movable READ movable WRITE setMovable)

public:
	void setBackgroundPixmap(QPixmap&);
	QPixmap backgroundPixmap();
	void setBackgroundColor(QColor&);
	QColor backgroundColor();

	void setMovable(bool);
	bool movable() const;

	QWidget* lastParent(QWidget*);

signals:
	void backgroundPixmapChanged();
	void backgroundColorChanged();

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


private:
	QPixmap m_backgroundPixmap;
	QColor m_backgroundColor = QColor(255, 255, 255);
	bool m_movable = false;
	bool m_pressed = false;
	QPoint m_pressPoint;
};

#endif // BASEWIDGET_H
