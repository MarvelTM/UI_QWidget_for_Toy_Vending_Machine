#ifndef SCREEN_9_H
#define SCREEN_9_H

#include <QWidget>

namespace Ui {
class Screen_9;
}

class Screen_9 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_9(QWidget *parent = nullptr);
	~Screen_9();

signals:
	void pressedButtonClose();
    void pressedButtonTry();

private:
	Ui::Screen_9 *ui;
	//void closeEvent(QCloseEvent *event);
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_9_H
