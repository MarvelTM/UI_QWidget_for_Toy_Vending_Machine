#ifndef D1_SCEEN_11_H
#define D1_SCEEN_11_H

#include <QWidget>

namespace Ui {
class d1_Screen_11;
}

class d1_Screen_11 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_11(QWidget *parent = nullptr);
	~d1_Screen_11();

signals:
	void pressedButtonClose();
	void pressedButtonSend();

private:
	Ui::d1_Screen_11 *ui;
	void send();
	// QWidget interface
protected:
	virtual void resizeEvent(QResizeEvent *event);
};

#endif // D1_SCEEN_11_H
