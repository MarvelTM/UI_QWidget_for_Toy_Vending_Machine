#ifndef D1_SCREEN_5_H
#define D1_SCREEN_5_H

#include <QWidget>

namespace Ui {
class d1_Screen_5;
}

class d1_Screen_5 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_5(QWidget *parent = nullptr);
	~d1_Screen_5();

private:
	Ui::d1_Screen_5 *ui;
signals:
	void pressedButtonClose();
	void pressedButtonBack();
	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // D1_SCREEN_4_H
