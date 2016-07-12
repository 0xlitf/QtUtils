#ifndef ClickableLabel_H
#define ClickableLabel_H

#include "qtutils_global.h"
#include <QLabel>

class QTUTILS_EXPORT ClickableLabel : public QLabel
{
	Q_OBJECT

public:
	ClickableLabel(QWidget* parent);
	~ClickableLabel();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
	signals:
	void clicked();

public slots :
	void setPixmap(const QString&);
	void updatePixmap();
	void clear();

private:
	bool m_mouseEnter = false;
	bool m_ctrlPressed = false;
	QPixmap m_pixmap;
	QSizeF m_pixmapSize;
};

#endif // ClickableLabel_H


