#ifndef SCREEN_6_H
#define SCREEN_6_H

#include <QWidget>

namespace Ui {
class Screen_6;
}

class Screen_6 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_6(QWidget *parent = nullptr);
	~Screen_6();

signals:
	void pressedButtonBack();
	void pressedButtonTakeCoins();
	void pressedButtonSendPhone();

private:
	Ui::Screen_6 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_6_H
