#include "d2_screen_12.h"
#include "ui_d2_screen_12.h"

#include <QResizeEvent>


Screen_12::Screen_12(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_12)
{
	ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d2_12_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });
}

Screen_12::~Screen_12()
{
	delete ui;
}


void Screen_12::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1000.0, size.height() / 1020.0);

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_12_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_12_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  35 * scaled.y());


    QFont font = ui->d2_12_lblInfoText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_12_lblInfoText->setFont(font);

    font = ui->d2_12_lblText_1->font();
    font.setPointSize(24 * scaled.y());
    ui->d2_12_lblText_1->setFont(font);

    font = ui->d2_12_lblText_2->font();
    font.setPointSize(24 * scaled.y());
    ui->d2_12_lblText_2->setFont(font);
}
