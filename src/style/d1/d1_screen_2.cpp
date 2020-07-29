#include "d1_screen_2.h"
#include "ui_d1_screen_2.h"

#include <QResizeEvent>

#include <QDebug>



d1_Screen_2::d1_Screen_2(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_2)
{
	ui->setupUi(this);
	setupConnectionLabel();

	connect(ui->d1_2_btnClose, &QPushButton::clicked, [=]() {emit  pressedButtonClose(); });
	connect(ui->d1_2_btnVideo, &QPushButton::clicked, [=]() {emit  pressedButtonShowVideo(); });
}

d1_Screen_2::~d1_Screen_2()
{
	delete ui;
}

void d1_Screen_2::setProduct(Product product)
{
	ui->d1_2_lblRootImage->setPixmap(QPixmap(product.pathImage[0]));

	ui->d1_2_lblImage_1->setPixmap(QPixmap(product.pathImage[0]));
	ui->d1_2_lblImage_2->setPixmap(QPixmap(product.pathImage[1]));
	ui->d1_2_lblImage_3->setPixmap(QPixmap(product.pathImage[2]));
	ui->d1_2_lblImage_4->setPixmap(QPixmap(product.pathImage[3]));

	ui->d1_2_lblName->setText(product.fullName);
	ui->d1_2_lblPrice->setText("Цена: " + product.price);
	ui->d1_2_textEdit->setText(product.description);
}

void d1_Screen_2::setupConnectionLabel()
{
	connect(ui->d1_2_lblImage_1, &d1_ClickableLabel::clicked, [=](){
		const QPixmap *pixmap = ui->d1_2_lblImage_1->pixmap();
		ui->d1_2_lblRootImage->setPixmap(*pixmap);
	});

	connect(ui->d1_2_lblImage_2, &d1_ClickableLabel::clicked, [=](){
		const QPixmap *pixmap = ui->d1_2_lblImage_2->pixmap();
		ui->d1_2_lblRootImage->setPixmap(*pixmap);
	});

	connect(ui->d1_2_lblImage_3, &d1_ClickableLabel::clicked, [=](){
		const QPixmap *pixmap = ui->d1_2_lblImage_3->pixmap();
		ui->d1_2_lblRootImage->setPixmap(*pixmap);
	});

	connect(ui->d1_2_lblImage_4, &d1_ClickableLabel::clicked, [=](){
		const QPixmap *pixmap = ui->d1_2_lblImage_4->pixmap();
		ui->d1_2_lblRootImage->setPixmap(*pixmap);
	});
}

void d1_Screen_2::resizeEvent(QResizeEvent *event)
{
	QSizeF size = event->size();

	qDebug() << size;
	QPointF scaled = QPointF(size.width() / 860.0, size.height() / 1200.0);

	QFont font = ui->d1_2_lblName->font();
	font.setPixelSize(60 * scaled.y());
	ui->d1_2_lblName->setFont(font);

	font = ui->d1_2_lblPrice->font();
	font.setPixelSize(68 * scaled.y());
	ui->d1_2_lblPrice->setFont(font);


	ui->d1_2_vlBackground->setContentsMargins(12 * scaled.x(),
											  0 * scaled.y(),
											  12 * scaled.x(),
											  2 * scaled.y());

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_2_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);

	ui->d1_2_btnVideo->setFixedSize(140 * scaled.x(), 36 * scaled.y());
	ui->d1_2_btnBuy->setFixedSize(300 * scaled.x(), 80 * scaled.y());

	ui->d1_2_lblRootImage->setFixedSize(400 * scaled.x(), 450 * scaled.y());

	QSize sizeImage = QSize(100, 100);
	ui->d1_2_lblImage_1->setMaximumSize(sizeImage.width() * scaled.x(), sizeImage.height()* scaled.y());
	ui->d1_2_lblImage_2->setMaximumSize(sizeImage.width() * scaled.x(), sizeImage.height()* scaled.y());
	ui->d1_2_lblImage_3->setMaximumSize(sizeImage.width() * scaled.x(), sizeImage.height()* scaled.y());
	ui->d1_2_lblImage_4->setMaximumSize(sizeImage.width() * scaled.x(), sizeImage.height()* scaled.y());

}

void d1_Screen_2::on_d1_2_btnBuy_clicked()
{
	emit pressedButtonBuy();
}
