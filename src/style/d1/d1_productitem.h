#ifndef D1_PRODUCTITEM_H
#define D1_PRODUCTITEM_H

#include <QPushButton>

namespace Ui {
class d1_ProductItem;
}

enum Stat { NONE, HIT, NEW, SALE, OUT };

struct Product
{
	int id;
	QString price;
	QString name;
	QString fullName;
	Stat stat;
	QVector<QString> pathImage;
	QString pathVideo;
	QString description;
};

class d1_ProductItem : public QPushButton
{
	Q_OBJECT

public:
	explicit d1_ProductItem(QWidget *parent = nullptr);
	~d1_ProductItem();
	void setProduct(Product product);

private:
	Ui::d1_ProductItem *ui;

	int id;
	void setNumber(int i);
	void setName(QString name);
	void setStat(Stat stat);
	void setImage(QString pathImage);
	void setPrice(QString price);

	Product *m_currentProduct;

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // D1_PRODUCTITEM_H
