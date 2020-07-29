#ifndef SCREEN_4_H
#define SCREEN_4_H

#include <QWidget>

namespace Ui {
class Screen_4;
}

class Screen_4 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_4(QWidget *parent = nullptr);
	~Screen_4();

signals:
	void pressedButtonBack();
	void pressedButtonPay();

private:
	Ui::Screen_4 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_4_H
