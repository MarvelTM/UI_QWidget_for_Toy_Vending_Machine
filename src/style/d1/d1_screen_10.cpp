#include "d1_screen_10.h"
#include "ui_d1_screen_10.h"

#include <QResizeEvent>

d1_Screen_10::d1_Screen_10(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_10)
{
	ui->setupUi(this);

	//showQR(false);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d1_10_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });
	connect(ui->d1_10_btnBuyMore, &QPushButton::clicked, [=](){ emit pressedButtonBuyMore(); });
}

d1_Screen_10::~d1_Screen_10()
{
	delete ui;
}

void d1_Screen_10::setShowQR(bool show)
{
	ui->d1_10_widgetQRCode->setVisible(show);
}

void d1_Screen_10::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 800.0, size.height() / 900.0);

	QFont font = ui->d1_10_lblInfo->font();
	if (ui->d1_10_widgetQRCode->isVisible()) {
		font.setPixelSize(36 * scaled.y());
	} else {
		font.setPixelSize(56 * scaled.y());
	}
	ui->d1_10_lblInfo->setFont(font);
	ui->d1_10_lblQrTest->setFont(font);

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_10_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);

	int sizeQr = 180 * scaled.x();
	ui->d1_10_lblQrIcon->setFixedSize(sizeQr, sizeQr);

	ui->d1_10_btnBuyMore->setFixedSize(300 * scaled.x(), 75 * scaled.y());

	ui->d1_10_hlBuyMore->setContentsMargins(0, 0, 55 * scaled.x(), 40 * scaled.y());

}
