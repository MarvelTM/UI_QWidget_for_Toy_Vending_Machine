#include "d2_screen_3.h"
#include "ui_d2_screen_3.h"

#include <QResizeEvent>

Screen_3::Screen_3(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_3)
{
	ui->setupUi(this);

	connect(ui->d2_3_btnBack, &QPushButton::clicked, [=](){ emit pressedButtonBack(); });

    connect(ui->d2_3_btnCash, &QPushButton::clicked, [=](){ emit pressedButtonCash(); });
	connect(ui->d2_3_btnCredit, &QPushButton::clicked, [=](){ emit pressedButtonCredit(); });
    connect(ui->d2_3_btnQRCode, &QPushButton::clicked, [=](){ emit pressedButtonQrCode(); });

}

Screen_3::~Screen_3()
{
	delete ui;
}

void Screen_3::setShowCash(bool is_show)
{
	is_show ? ui->d2_3_widgetCash->show(): ui->d2_3_widgetCash->hide();
}

void Screen_3::setShowCredit(bool is_show)
{
	is_show ? ui->d2_3_widgetCredit->show(): ui->d2_3_widgetCredit->hide();
}

void Screen_3::setShowQR(bool is_show)
{
	is_show ? ui->d2_3_widgetQR->show(): ui->d2_3_widgetQR->hide();
}

void Screen_3::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);


    QFont font = ui->d2_3_lblSlelectionText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_3_lblSlelectionText->setFont(font);

    ui->d2_3_lblSlelectionText->setFixedHeight(160 * scaled.x());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_3_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_3_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  70 * scaled.y());

    ui->d2_3_hlTop->setContentsMargins(0,0,0,50 * scaled.y());


    QSize sizeBtn = QSize(500 * scaled.x(),  225 * scaled.y());
    ui->d2_3_btnCash->setFixedSize(sizeBtn.width() , sizeBtn.height());
    ui->d2_3_btnCredit->setFixedSize(sizeBtn.width() , sizeBtn.height());

    QSize sizeIcon = QSize(400 * scaled.x(),  360 * scaled.y());
    ui->d2_3_lblIconCash->setFixedSize(sizeIcon.width(), sizeIcon.height());
    ui->d2_3_lblIconCredit->setFixedSize(sizeIcon.width(), sizeIcon.height());

    font = ui->d2_3_lblqrCodeText->font();
    font.setPointSize(18);
    ui->d2_3_lblqrCodeText->setFont(font);

    int sizeQR = 400 * scaled.x();
    ui->d2_3_btnQRCode->setFixedSize(sizeQR, sizeQR);
}
