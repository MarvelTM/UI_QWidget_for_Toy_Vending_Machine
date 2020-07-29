#ifndef SCREEN_5_H
#define SCREEN_5_H

#include <QWidget>

namespace Ui {
class Screen_5;
}

class Screen_5 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_5(QWidget *parent = nullptr);
	~Screen_5();

signals:
    void pressedButtonBack();

private:
	Ui::Screen_5 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_5_H
