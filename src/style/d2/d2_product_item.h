#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include <QPushButton>

namespace Ui {
class d2_ProductItem;
}

namespace d2 {
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
}

class d2_ProductItem : public QPushButton
{
	Q_OBJECT

public:

    explicit d2_ProductItem(QWidget *parent = nullptr);
    ~d2_ProductItem();

    void setProduct(d2::Product product);

private:
    Ui::d2_ProductItem *ui;

	int id;
	void setName(QString name);
    void setStat(d2::Stat stat);
	void setImage(QString pathImage);
	void setPrice(QString price);

    d2::Product *m_currentProduct;

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // PRODUCTITEM_H
