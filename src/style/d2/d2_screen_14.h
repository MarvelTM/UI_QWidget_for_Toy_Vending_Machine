#ifndef Screen_14_H
#define Screen_14_H

#include <QWidget>

namespace Ui {
class Screen_14;
}

class Screen_14 : public QWidget
{
	Q_OBJECT

public:
    explicit Screen_14(QWidget *parent = nullptr);
    ~Screen_14();

signals:
    void pressedButtonBack();

private:
    Ui::Screen_14 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // Screen_14_H
