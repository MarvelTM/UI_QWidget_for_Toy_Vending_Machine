#ifndef SCREEN_2_H
#define SCREEN_2_H

#include <QWidget>
#include "d2_product_item.h"

namespace Ui {
class Screen_2;
}

class Screen_2 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_2(QWidget *parent = nullptr);
	~Screen_2();

    void setProduct(d2::Product product);

private:
	Ui::Screen_2 *ui;
	void resizeEvent(QResizeEvent *event);

    //  Setting font нужно для корректного отображения шрифта Baloo Cyrillic
    // т.к. межстрочный интервал у него шире
    QString confText(QString text);

signals:
	void pressedButtonBack();
	void pressedButtonPlayVideo();
	void pressedButtonBuy();

private slots:
	void on_d2_2_btnLeft_clicked();
	void on_d2_2_btnRight_clicked();
};

#endif // SCREEN_2_H
