#ifndef D1_SCREEN_2_H
#define D1_SCREEN_2_H

#include <QWidget>
#include <QLabel>

#include "d1_productitem.h"

namespace Ui {
class d1_Screen_2;
}

class d1_Screen_2 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_2(QWidget *parent = nullptr);
	~d1_Screen_2();
	void setProduct(Product product);

private:
	Ui::d1_Screen_2 *ui;
	void setupConnectionLabel();

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);

signals:
	void pressedButtonBuy();
	void pressedButtonClose();
	void pressedButtonShowVideo();

private slots:
	void on_d1_2_btnBuy_clicked();
};

#endif // D1_SCREEN_2_H
