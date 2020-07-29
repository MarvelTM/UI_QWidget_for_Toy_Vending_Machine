#ifndef D1_SCREEN_1_H
#define D1_SCREEN_1_H

#include <QWidget>

#include "d1_productitem.h"

namespace Ui {
class d1_Screen_1;
}

class d1_Screen_1 : public QWidget
{
	Q_OBJECT

public:
	explicit d1_Screen_1(QWidget *parent = nullptr);
	~d1_Screen_1();
	void showVideo(bool show);
	void setVideo(QWidget *widget);

	void addProducts(QVector<Product> products);

private:
	Ui::d1_Screen_1 *ui;
	QVector<d1_ProductItem *> items;

signals:
	void pressedButtonProduct(int id);
	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // D1_SCREEN_1_H
