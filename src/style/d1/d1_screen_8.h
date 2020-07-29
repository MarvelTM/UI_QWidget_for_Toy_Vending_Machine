#ifndef D1_SCREEN_8_H
#define D1_SCREEN_8_H

#include <QWidget>

namespace Ui {
class d1_Screen_8;
}

class d1_Screen_8 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_8(QWidget *parent = nullptr);
	~d1_Screen_8();

private:
	Ui::d1_Screen_8 *ui;
signals:
	void pressedButtonClose();
	void pressedButtonTry();
	// QWidget interface
protected:
	virtual void resizeEvent(QResizeEvent *event);
};

#endif // D1_SCREEN_8_H
