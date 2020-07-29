#include "d1_productitem.h"
#include "ui_d1_productitem.h"

#include <QDebug>
#include <QResizeEvent>

d1_ProductItem::d1_ProductItem(QWidget *parent) :
	  QPushButton(parent),
	  ui(new Ui::d1_ProductItem)
{
	ui->setupUi(this);
	ui->d1_lblNumber->setText("1");
}

d1_ProductItem::~d1_ProductItem()
{
	delete ui;
}

void d1_ProductItem::setProduct(Product product)
{
	id = product.id;
	setNumber(id + 1);
	setPrice(product.price);
	setName(product.name);
	setStat(product.stat);
	setImage(product.pathImage.first());

	m_currentProduct = &product;
}

void d1_ProductItem::setNumber(int i)
{
	ui->d1_lblNumber->setText(QString::number(i));
}

void d1_ProductItem::setName(QString name)
{
    QString temp = "<p style=\"line-height:%1%\">%2<p>";
    ui->d1_lblName->setText( QString(temp).arg(60).arg(name));
}

void d1_ProductItem::setStat(Stat stat)
{
	switch (stat) {
	case NONE:
		ui->d1_lblStatus->setPixmap(QPixmap());
		break;

	case HIT:
		ui->d1_lblStatus->setPixmap(QPixmap(":/d1_hit.png"));
		break;

	case NEW:
		ui->d1_lblStatus->setPixmap(QPixmap(":/d1_new.png"));
		break;

	case SALE:
		ui->d1_lblStatus->setPixmap(QPixmap(":/d1_sale.png"));
		break;

	case OUT:	
		ui->d1_lblStatus->setPixmap(QPixmap());
		ui->d1_lblPrice->setText("Закончилось");
		ui->d1_widgetBachground->setEnabled(false);
		this->setEnabled(false);
		break;

	default:
		break;
	}
}

void d1_ProductItem::setImage(QString pathImage)
{
	ui->d1_lblImage->setPixmap(QPixmap(pathImage));
}

void d1_ProductItem::setPrice(QString price)
{
	ui->d1_lblPrice->setText(price);
}

void d1_ProductItem::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 900.0, size.height() / 1600.0);



	QFont font = ui->d1_lblName->font();
    font.setPixelSize(180* scaled.y());
	ui->d1_lblName->setFont(font);


	font = ui->d1_lblPrice->font();
	font.setPixelSize(250 * scaled.y());
	ui->d1_lblPrice->setFont(font);

	font = ui->d1_lblNumber->font();
	font.setPixelSize(250 * scaled.y());
	ui->d1_lblNumber->setFont(font);


	int size_label = 200 * scaled.x();

	ui->d1_lblNumber->setFixedSize(QSize(size_label, size_label));
	ui->d1_lblNumber->setGeometry(30 * scaled.x(), 30 * scaled.y(), size_label, size_label);

    ui->d1_lblName->setGeometry(40 * scaled.x() + size_label,
                                0,
								size.width() - 40 * scaled.x() - size_label,
                                1.2 * size_label);

	ui->widget->setGeometry(0, size_label + 40 * scaled.y(), size.width(), size.height() - 2 * size_label);

	int sizeImage = ui->widget->height();
	ui->d1_lblImage->setFixedSize(0.75 * sizeImage, sizeImage);


	ui->d1_lblPrice->setGeometry(0, ui->widget->geometry().bottom(), size.width(), size_label);

	int size_logo = 250 * scaled.x();
	ui->d1_lblStatus->setGeometry(size.width() - size_logo + 1,
								  size.height() - size_logo + 1,
								  size_logo,
								  size_logo);



	//QRect geometryName = QRect(30 * scaled.x(), 30 * scaled.y(), size.width(), size_label);
	//ui->horizontalLayout->setGeometry(geometryName);



	//ui->horizontalLayout->setContentsMargins(30 * scaled.x(), 30 * scaled.y(), 0, 0);


	//ui->d1_widgetProduct->setFixedSize(QSize(event->size().width(), event->size().height() - size_label));

}
