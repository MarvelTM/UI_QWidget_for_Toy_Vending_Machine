#include "d2_screen_11.h"
#include "ui_d2_screen_11.h"

#include <QResizeEvent>



Screen_11::Screen_11(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_11)
{
	ui->setupUi(this);
	connect(ui->d2_11_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose();});
}

Screen_11::~Screen_11()
{
	delete ui;
}

void Screen_11::setVideo(QString path)
{
	QPixmap pix = QPixmap(path);
	ui->d2_11_lblVideo->setPixmap(pix);
	ui->d2_11_lblVideo->setScaledContents(true);
}

void Screen_11::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);

    int sizeBtnClose = 125 * scaled.x();
    ui->d2_11_btnClose->setFixedSize(sizeBtnClose, sizeBtnClose);
}


