#include "d2_screen_5.h"
#include "ui_d2_screen_5.h"

#include <QResizeEvent>

Screen_5::Screen_5(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_5)
{
	ui->setupUi(this);
    connect(ui->d2_5_btnBack, &QPushButton::clicked, [=]() { emit pressedButtonBack(); });
}

Screen_5::~Screen_5()
{
	delete ui;
}

void Screen_5::resizeEvent(QResizeEvent *event)
{

    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);


    QFont font = ui->d2_5_lblInfoText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_5_lblInfoText->setFont(font);

    ui->d2_5_lblInfoText->setFixedHeight(160 * scaled.x());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_5_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_5_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  170 * scaled.y());

    ui->d2_5_hlTop->setContentsMargins(0,0,0,50 * scaled.y());


    QSize sizeIcon = QSize(400 * scaled.x(),  360 * scaled.y());
    ui->d2_5_lblTakeChange->setFixedSize(sizeIcon.width(), sizeIcon.height());


    font = ui->d2_5_lblText->font();
    font.setPointSize(22 * scaled.x());
    ui->d2_5_lblText->setFont(font);
}
