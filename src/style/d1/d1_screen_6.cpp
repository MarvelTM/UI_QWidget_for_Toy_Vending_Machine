#include "d1_screen_6.h"
#include "ui_d1_screen_6.h"

#include <QResizeEvent>

d1_Screen_6::d1_Screen_6(QWidget *parent) :
	  QWidget(parent),
      ui(new Ui::d1_Screen_6)
{
	ui->setupUi(this);

    connect(ui->d1_6_btnClose, &QPushButton::clicked, [=]() {emit  pressedButtonClose(); });
    connect(ui->d1_6_btnBack, &QPushButton::clicked, [=]() {emit  pressedButtonBack(); });
}

d1_Screen_6::~d1_Screen_6()
{
	delete ui;
}

void d1_Screen_6::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 860.0, size.height() / 1200.0);

    QFont font = ui->d1_6_lblInfo->font();
	font.setPixelSize(60 * scaled.y());
    ui->d1_6_lblInfo->setFont(font);

    font = ui->d1_6_lblInfoQrCodeTop->font();
	font.setPixelSize(60 * scaled.y());
    ui->d1_6_lblInfoQrCodeTop->setFont(font);
    ui->d1_6_lblInfoQrCodeBottom->setFont(font);

    ui->d1_6_vlBackground->setContentsMargins(12 * scaled.x(),
                                              0 * scaled.y(),
                                              12 * scaled.x(),
                                              2 * scaled.y());


    int sizeQr = 400 * scaled.x();
    ui->d1_6_lblQrCode->setFixedSize(sizeQr, sizeQr);


    int sizeBtnBack = 125 * scaled.x();
    ui->d1_6_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
    ui->d1_6_btnBack->setFixedSize(300 * scaled.x(), 80 * scaled.y());

   // ui->d1_6_widgetContent->setFixedSize(620 * scaled.x(), 700 * scaled.y());
    ui->d1_6_widgetTop->setFixedHeight(150 * scaled.y());

   // ui->d1_6_vlContent->setContentsMargins(25 * scaled.x(), 260 * scaled.y(), 35 * scaled.x(), 100 * scaled.y());
}
