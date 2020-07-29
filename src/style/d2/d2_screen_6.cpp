#include "d2_screen_6.h"
#include "ui_d2_screen_6.h"

#include <QResizeEvent>



Screen_6::Screen_6(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_6)
{
	ui->setupUi(this);

	connect(ui->d2_6_btnBack, &QPushButton::clicked, [=]() { emit pressedButtonBack(); });
	connect(ui->d2_6_btnTakeCoins, &QPushButton::clicked, [=]() { emit pressedButtonTakeCoins(); });
	connect(ui->d2_6_btnSendPhone, &QPushButton::clicked, [=]() { emit pressedButtonSendPhone(); });
}

Screen_6::~Screen_6()
{
	delete ui;
}

void Screen_6::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);


    QFont font = ui->d2_6_lblInfoText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_6_lblInfoText->setFont(font);

    ui->d2_6_lblInfoText->setFixedHeight(160 * scaled.x());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_6_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_6_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  170 * scaled.y());

    ui->d2_6_hlTop->setContentsMargins(0,0,0,50 * scaled.y());


    int sizeIcon = 750 * scaled.y();
    // 0.56 отношение width / height - take-change-illustration.png
    ui->d2_6_lblTakeChange->setFixedSize(0.56 * sizeIcon,  sizeIcon);


    font = ui->d2_6_lblText->font();
    font.setPointSize(22 * scaled.x());
    ui->d2_6_lblText->setFont(font);

    QSize sizeBtn = QSize(500 * scaled.x(),  225 * scaled.y());
    ui->d2_6_btnSendPhone->setFixedSize(sizeBtn.width() , sizeBtn.height());
    ui->d2_6_btnTakeCoins->setFixedSize(sizeBtn.width() , sizeBtn.height());


}
