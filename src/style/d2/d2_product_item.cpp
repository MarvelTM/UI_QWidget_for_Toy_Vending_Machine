#include "d2_product_item.h"
#include "ui_d2_product_item.h"


#include <QDebug>
#include <QResizeEvent>

#include <QGraphicsDropShadowEffect>

d2_ProductItem::d2_ProductItem(QWidget *parent) :
	  QPushButton(parent),
      ui(new Ui::d2_ProductItem)
{
	ui->setupUi(this);
	m_currentProduct = nullptr;

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(0);
    effect->setColor(QColor("#d6d6d6"));
    effect->setOffset(1,1);

    ui->d2_lblNumber->setGraphicsEffect(effect);

}

d2_ProductItem::~d2_ProductItem()
{
	delete ui;
}

void d2_ProductItem::setProduct(d2::Product product)
{
	id = product.id;
	setPrice(product.price);
	setName(product.name);
	setStat(product.stat);
	setImage(product.pathImage.first());
    ui->d2_lblNumber->setText(QString::number(product.id + 1));

	m_currentProduct = &product;
}

void d2_ProductItem::setPrice(QString price)
{
    ui->d2_lblPrice->setText(price.toLower());
}

void d2_ProductItem::setName(QString name)
{
    ui->d2_lblName->setText(name.toLower());
}

void d2_ProductItem::setStat(d2::Stat stat)
{
    ui->d2_lblStatus->setScaledContents(true);
	switch (stat) {
    case d2::HIT:
        ui->d2_lblStatus->setPixmap(QPixmap(":/desing2/lables/hit.png"));
		break;

    case d2::NEW:
        ui->d2_lblStatus->setPixmap(QPixmap(":/desing2/lables/new.png"));
		break;

    case d2::SALE:
        ui->d2_lblStatus->setPixmap(QPixmap(":/desing2/lables/sale.png"));
        break;

	case d2::OUT:
		ui->d2_lblStatus->setPixmap(QPixmap());
		ui->d2_lblPrice->setText("Закончилось");
		//ui->d2_widgetBachground->setEnabled(false);
		this->setEnabled(false);
		break;

	default:
		break;
	}
}

void d2_ProductItem::setImage(QString pathImage)
{
	QPixmap pix = QPixmap(pathImage);
    ui->d2_lblImage->setScaledContents(true);
    ui->d2_lblImage->setPixmap(pix);

}

void d2_ProductItem::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 180.0, size.height() / 230.0);

    QFont font = ui->d2_lblName->font();
    font.setPointSize(20 * scaled.y());

    ui->d2_lblName->setFont(font);
    ui->d2_lblPrice->setFont(font);
    ui->d2_lblNumber->setFont(font);

    int sizelbl = 30 * scaled.y();
    ui->d2_widgetImage->setGeometry(0,10, size.width(), size.height() - 2 * sizelbl - 10);

    int sizeImage = ui->d2_widgetImage->height();
    ui->d2_lblImage->setFixedSize(sizeImage * 0.75, sizeImage);


    ui->d2_lblName->setGeometry(0 , ui->d2_widgetImage->geometry().bottom(), size.width(), sizelbl);
    ui->d2_lblPrice->setGeometry(0 , ui->d2_lblName->geometry().bottom(), size.width(), sizelbl);

    int sizelblNumber = 50 * scaled.x();
    int numberMargin = 20 * scaled.x();

    ui->d2_lblNumberBackground->setGeometry(0,0, sizelblNumber,sizelblNumber);
    ui->d2_lblNumber->setGeometry(0, 0, sizelblNumber - numberMargin,sizelblNumber - numberMargin);



    int m = 6 * scaled.x();
    QSize sizeStutus = QSize(52 * scaled.x(), 20 * scaled.x());
    ui->d2_lblStatus->setGeometry(size.width() - sizeStutus.width() - m,
                                  m,
                                  sizeStutus.width(),
                                  sizeStutus.height());

}
