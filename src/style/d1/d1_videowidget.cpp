#include "d1_videowidget.h"
#include "ui_d1_videowidget.h"

#include <QResizeEvent>

d1_VideoWidget::d1_VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::d1_VideoWidget)
{
    ui->setupUi(this);

 //   setWindowFlags(Qt::FramelessWindowHint);
 //   setWindowModality(Qt::WindowModal);
 //   this->setAttribute(Qt::WA_WState_WindowOpacitySet);
    connect(ui->d1_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });
}

d1_VideoWidget::~d1_VideoWidget()
{
    delete ui;
}

void d1_VideoWidget::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 900.0, size.height() / 1600.0);

    int sizeBtnBack = 125 * scaled.x();
    ui->d1_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
}
