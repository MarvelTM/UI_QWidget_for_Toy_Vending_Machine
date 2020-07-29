#include "d1_screen_3.h"
#include "ui_d1_screen_3.h"

#include <QResizeEvent>

d1_Screen_3::d1_Screen_3(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_3)
{
	ui->setupUi(this);

	connect(ui->d1_3_btnClose, &QPushButton::clicked, [=]() {emit  pressedButtonClose(); });
	connect(ui->d1_3_btnBack, &QPushButton::clicked, [=]() {emit  pressedButtonBack(); });

    connect(ui->d1_3_btnCash, &QPushButton::clicked, [=]() {emit  pressedButtonCash(); });
    connect(ui->d1_3_btnCredit, &QPushButton::clicked, [=]() {emit  pressedButtonCredit(); });
    connect(ui->d1_3_btnQRCode, &QPushButton::clicked, [=]() {emit  pressedButtonQrCode(); });

    //ui->d1_3_widgetCash->hide();
	//ui->d1_3_widgetCredit->hide();
	//ui->d1_3_widgetQRCode->hide();
}

d1_Screen_3::~d1_Screen_3()
{
	delete ui;
}

void d1_Screen_3::setShowCash(bool is_show)
{
    is_show ? ui->d1_3_widgetCash->show(): ui->d1_3_widgetCash->hide();
}

void d1_Screen_3::setShowCredit(bool is_show)
{
    is_show ? ui->d1_3_widgetCredit->show(): ui->d1_3_widgetCredit->hide();
}

void d1_Screen_3::setShowQR(bool is_show)
{
    is_show ? ui->d1_3_widgetQRCode->show(): ui->d1_3_widgetQRCode->hide();
}

void d1_Screen_3::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 860.0, size.height() / 1200.0);

	QFont font = ui->d1_3_lblInfo->font();
	font.setPixelSize(60 * scaled.y());
	ui->d1_3_lblInfo->setFont(font);

	font = ui->d1_3_lblCash->font();
	font.setPixelSize(60 * scaled.y());
	ui->d1_3_lblCash->setFont(font);
	ui->d1_3_lblCredit->setFont(font);
	ui->d1_3_lblQrTest->setFont(font);

	ui->d1_3_vlBackground->setContentsMargins(12 * scaled.x(),
											  0 * scaled.y(),
											  12 * scaled.x(),
											  2 * scaled.y());

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_3_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
	ui->d1_3_btnBack->setFixedSize(300 * scaled.x(), 80 * scaled.y());

	int sizeBtnCash = 320 * scaled.x();
	ui->d1_3_btnCash->setFixedSize(sizeBtnCash, sizeBtnCash);
	ui->d1_3_btnCredit->setFixedSize(sizeBtnCash, sizeBtnCash);
    ui->d1_3_btnQRCode->setFixedSize(sizeBtnCash, sizeBtnCash);

	ui->d1_3_widgetTop->setFixedHeight(150 *  scaled.y());
}

