#include "d2_screen_10.h"
#include "ui_d2_screen_10.h"

#include <QResizeEvent>
#include <QDebug>

Screen_10::Screen_10(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_10)
{
	ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d2_10_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });
}

Screen_10::~Screen_10()
{
	delete ui;
}

void Screen_10::setShowQR(bool is_show)
{
    is_show ? ui->d2_10_widgetQR->show(): ui->d2_10_widgetQR->hide();
}

void Screen_10::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1000.0, size.height() / 1020.0);

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_10_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_10_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  35 * scaled.y());


    ui->d2_10_lblText->setFixedSize(410 * scaled.x(), 70 * scaled.y());


    //ui->d2_10_hlTop->setContentsMargins(0,0,0,50 * scaled.y());

    QFont font = ui->d2_10_lblqrCodeText->font();
    font.setPointSize(18);
    ui->d2_10_lblqrCodeText->setFont(font);

    font = ui->d2_10_lblInfoText->font();
    font.setPointSize(37 * scaled.x());
    ui->d2_10_lblInfoText->setFont(font);

    ui->d2_10_lblInfoText->setFixedHeight(80 * scaled.x());


    int sizeQR = 250 * scaled.x();
    ui->d2_10_lblQRCode->setFixedSize(sizeQR, sizeQR);

    int sizeIcon = 400;
    ui->d2_10_lblIllustration->setFixedSize(sizeIcon * scaled.x(), sizeIcon * scaled.y());

}
