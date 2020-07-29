#ifndef SCREEN_1_H
#define SCREEN_1_H

#include <QWidget>
#include "d2_product_item.h"

namespace Ui {
class Screen_1;
}

class Screen_1 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_1(QWidget *parent = nullptr);
	~Screen_1();
    void addProducts(QVector<d2::Product> products);
	void setVideo(QWidget *widget);
	void showWideo(bool show);

private:
	Ui::Screen_1 *ui;
	QVector<d2_ProductItem *> items;

	bool is_showWideo;

public slots:
	void setShowCoins(bool is_show);
	void setShowDiscount(bool is_show);

signals:
	void pressedButtonCoins();
	void pressedButtonDiscount();

	void pressedButtonProduct(int id);

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_1_H
