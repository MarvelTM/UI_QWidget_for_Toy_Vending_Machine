#ifndef D1_SCREEN_7_H
#define D1_SCREEN_7_H

#include <QWidget>
#include <QTimer>
#include <QPropertyAnimation>

namespace Ui {
class d1_Screen_7;
}

class d1_Screen_7 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_7(QWidget *parent = nullptr);
	~d1_Screen_7();

private:
	Ui::d1_Screen_7 *ui;
	QPropertyAnimation *animation;
	void playAnimation();
signals:
	void pressedButtonClose();
	// QWidget interface
protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void showEvent(QShowEvent *event);
};

#endif // D1_SCREEN_7_H
