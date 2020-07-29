#ifndef D1_SCREEN_10_H
#define D1_SCREEN_10_H

#include <QWidget>

namespace Ui {
class d1_Screen_10;
}

class d1_Screen_10 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_10(QWidget *parent = nullptr);
	~d1_Screen_10();

public:
	void setShowQR(bool show);

signals:
	void pressedButtonClose();
	void pressedButtonBuyMore();

private:
	Ui::d1_Screen_10 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // D1_SCREEN_10_H
