#ifndef D1_SCREEN_3_H
#define D1_SCREEN_3_H

#include <QWidget>

namespace Ui {
class d1_Screen_3;
}

class d1_Screen_3 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_3(QWidget *parent = nullptr);
	~d1_Screen_3();

    void setShowQR(bool is_show);
    void setShowCredit(bool is_show);
    void setShowCash(bool is_show);
private:
	Ui::d1_Screen_3 *ui;

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);

signals:
	void pressedButtonCash();
	void pressedButtonCredit();
    void pressedButtonQrCode();

	void pressedButtonClose();
	void pressedButtonBack();
};

#endif // D1_SCREEN_3_H
