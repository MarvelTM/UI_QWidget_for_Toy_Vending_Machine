#ifndef D2_SCREEN_13_H
#define D2_SCREEN_13_H

#include <QWidget>

namespace Ui {
class Screen_13;
}

class Screen_13 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_13(QWidget *parent = nullptr);
	~Screen_13();


private:
	Ui::Screen_13 *ui;
	void resizeEvent(QResizeEvent *event);
	void send();
signals:
	void pressedButtonClose();
	void pressedButtonSend();

public slots:
//	void question_1();
//	void question_2();
//	void question_3();
//	void question_4();
//	void question_5();
};

#endif // D2_SCREEN_13_H
