#ifndef Screen_12_H
#define Screen_12_H

#include <QWidget>

namespace Ui {
class Screen_12;
}

class Screen_12 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_12(QWidget *parent = nullptr);
	~Screen_12();

private:
	Ui::Screen_12 *ui;
	void resizeEvent(QResizeEvent *event);

signals:
	void pressedButtonClose();
};

#endif // Screen_12_H
