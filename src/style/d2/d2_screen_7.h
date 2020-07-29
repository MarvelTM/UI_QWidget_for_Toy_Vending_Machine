#ifndef SCREEN_7_H
#define SCREEN_7_H

#include <QWidget>

namespace Ui {
class Screen_7;
}

class Screen_7 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_7(QWidget *parent = nullptr);
	~Screen_7();

signals:
	void pressedButtonBack();

private:
	Ui::Screen_7 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_7_H
