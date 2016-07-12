#ifndef EXPANDTOOLBUTTON_H
#define EXPANDTOOLBUTTON_H

#include <QToolButton>
#include "qtutils_global.h"
#include <CustomControllers/CustomToolButton/CustomToolButton.h>

class QTUTILS_EXPORT ExpandToolButton : public CustomToolButton
{
	Q_OBJECT

public:
	ExpandToolButton(QWidget *parent = nullptr);
	~ExpandToolButton();
	void addToolButton(QIcon icon, QString text);

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

	void focusInEvent(QFocusEvent *e) override;
	void focusOutEvent(QFocusEvent *e) override;

public slots:
	void collapse();
	bool eventFilter(QObject* obj, QEvent* event) override;

private:
	QList<CustomToolButton*> m_buttonList;
	bool b_visiable = false;
	int m_index = 0;
};

#endif // EXPANDTOOLBUTTON_H
