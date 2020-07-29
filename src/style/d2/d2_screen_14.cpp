#include "d2_screen_14.h"
#include "ui_d2_screen_14.h"

#include <QResizeEvent>

Screen_14::Screen_14(QWidget *parent) :
	  QWidget(parent),
      ui(new Ui::Screen_14)
{
	ui->setupUi(this);
    connect(ui->d2_14_btnBack, &QPushButton::clicked, [=]() { emit pressedButtonBack(); });
}

Screen_14::~Screen_14()
{
	delete ui;
}

void Screen_14::resizeEvent(QResizeEvent *event)
{

    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);


    QFont font = ui->d2_14_lblInfoText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_14_lblInfoText->setFont(font);

    ui->d2_14_lblInfoText->setFixedHeight(160 * scaled.x());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_14_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_14_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  170 * scaled.y());

    ui->d2_14_hlTop->setContentsMargins(0,0,0,50 * scaled.y());


    font = ui->d2_14_lblText->font();
    font.setPointSize(22 * scaled.x());
    ui->d2_14_lblText->setFont(font);


    int sizeQR = 400 * scaled.x();
    ui->d2_14_lblQrCode->setFixedSize(sizeQR, sizeQR);
}
