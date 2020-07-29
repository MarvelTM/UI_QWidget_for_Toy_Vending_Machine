#ifndef SCREEN_8_H
#define SCREEN_8_H

#include <QWidget>

namespace Ui {
class Screen_8;
}

class Screen_8 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_8(QWidget *parent = nullptr);
	~Screen_8();


signals:
	void pressedButtonBack();

private:
	Ui::Screen_8 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_8_H
