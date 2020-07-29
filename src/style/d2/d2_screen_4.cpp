#include "d2_screen_4.h"
#include "ui_d2_screen_4.h"

#include <QResizeEvent>



Screen_4::Screen_4(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_4)
{
	ui->setupUi(this);

	connect(ui->d2_4_btnBack, &QPushButton::clicked, [=](){ emit pressedButtonBack(); });
	connect(ui->d2_4_btnPay, &QPushButton::clicked, [=](){ emit pressedButtonPay(); });

}

Screen_4::~Screen_4()
{
	delete ui;
}


void Screen_4::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);


    QFont font = ui->d2_4_lblInfoText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_4_lblInfoText->setFont(font);

    ui->d2_4_lblInfoText->setFixedHeight(160 * scaled.x());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_4_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_4_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  70 * scaled.y());

    ui->d2_4_hlTop->setContentsMargins(0,0,0,50 * scaled.y());

    font = ui->d2_4_lblMashineAccept->font();
    font.setPointSize(34 * scaled.x());
    ui->d2_4_lblMashineAccept->setFont(font);

    font = ui->d2_4_lblCashAccept->font();
    font.setPointSize(20 * scaled.x());

    ui->d2_4_lblCashAccept->setFont(font);
    ui->d2_4_lblCoinAccept->setFont(font);

    ui->d2_4_vlCash->setSpacing(40 * scaled.y());
    ui->d2_4_vlCash->setContentsMargins(0, 50 * scaled.y(), 0,0);

    ui->d2_4_vlCoin->setSpacing(40 * scaled.y());
    ui->d2_4_vlCoin->setContentsMargins(0, 50 * scaled.y(), 0,0);


    QSize sizeIcon = QSize(400 * scaled.x(),  360 * scaled.y());
    ui->d2_4_lblIconCash->setFixedSize(sizeIcon.width(), sizeIcon.height());
    ui->d2_4_lblIconCoin->setFixedSize(sizeIcon.height(), sizeIcon.height());

    QSize sizeButton = QSize(700 * scaled.x(), 320 * scaled.y());
    ui->d2_4_btnPay->setFixedSize(sizeButton);
}
