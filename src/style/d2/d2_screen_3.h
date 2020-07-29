#ifndef SCREEN_3_H
#define SCREEN_3_H

#include <QWidget>

namespace Ui {
class Screen_3;
}

class Screen_3 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_3(QWidget *parent = nullptr);
	~Screen_3();

public slots:

	void setShowCash(bool is_show);
	void setShowCredit(bool is_show);
	void setShowQR(bool is_show);

private:
	bool is_showCash;
	bool is_showCredit;
	bool is_showQR;

signals:
	void pressedButtonBack();

    void pressedButtonCash();
	void pressedButtonCredit();
    void pressedButtonQrCode();

private:
	Ui::Screen_3 *ui;
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_3_H
