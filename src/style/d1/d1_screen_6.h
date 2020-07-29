#ifndef d1_Screen_6_H
#define d1_Screen_6_H

#include <QWidget>

namespace Ui {
class d1_Screen_6;
}

class d1_Screen_6 : public QWidget
{
	Q_OBJECT

public:
    explicit d1_Screen_6(QWidget *parent = nullptr);
    ~d1_Screen_6();

private:
    Ui::d1_Screen_6 *ui;
signals:
	void pressedButtonClose();
	void pressedButtonBack();
	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // D1_SCREEN_4_H
