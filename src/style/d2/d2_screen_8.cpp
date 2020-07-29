#include "d2_screen_8.h"
#include "ui_d2_screen_8.h"

#include <QResizeEvent>


Screen_8::Screen_8(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_8)
{
	ui->setupUi(this);
	connect(ui->d2_8_btnBack, &QPushButton::clicked, [=](){ emit pressedButtonBack(); });
}

Screen_8::~Screen_8()
{
	delete ui;
}


void Screen_8::resizeEvent(QResizeEvent *event)
{
	
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_8_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_8_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  170 * scaled.y());

    ui->d2_8_hlTop->setContentsMargins(0,0,0,50 * scaled.y());





    QFont font = ui->d2_8_lblText->font();
    font.setPointSize(36 * scaled.x());
    ui->d2_8_lblText->setFont(font);

    ui->d2_8_lePhoneNumber->setFixedSize(720* scaled.x(), 145 * scaled.y());
    ui->d2_8_lePhoneNumber->setFont(font);

    QSize sizeBtn = QSize(500 * scaled.x(),  225 * scaled.y());
    ui->d2_8_btnSendPhone->setFixedSize(sizeBtn.width() , sizeBtn.height());

}
