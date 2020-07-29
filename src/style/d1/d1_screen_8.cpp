#include "d1_screen_8.h"
#include "ui_d1_screen_8.h"

#include <QResizeEvent>

d1_Screen_8::d1_Screen_8(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_8)
{
	ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d1_8_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });

    connect(ui->d1_8_btnTry, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });
    connect(ui->d1_8_btnReturnVisa, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });

    connect(ui->d1_8_btnBuyMore, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });
    connect(ui->d1_8_btnGetCoin, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });


    //ui->d1_8_btnTry->hide();
    ui->d1_8_btnReturnVisa->hide();

    ui->d1_8_lblInfoReturn->hide();
    //ui->d1_8_btnGetCoin->hide();
}

d1_Screen_8::~d1_Screen_8()
{
	delete ui;
}

void d1_Screen_8::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 800.0, size.height() / 900.0);

	QFont font = ui->d1_8_lblInfo->font();
	font.setPixelSize(36 * scaled.y());
	ui->d1_8_lblInfo->setFont(font);

    ui->d1_8_lblInfoReturn->setFont(font);

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_8_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);

	ui->d1_8_hlTopWidget->setContentsMargins(sizeBtnBack, 0, 0, 20 * scaled.y());
	ui->d1_8_vlText->setContentsMargins(0, 60 * scaled.y(), 0, 0);

	ui->d1_8_btnTry->setFixedSize(300 * scaled.x(), 75 * scaled.y());
    ui->d1_8_btnReturnVisa->setFixedSize(300 * scaled.x(), 75 * scaled.y());

    ui->d1_8_btnBuyMore->setFixedSize(300 * scaled.x(), 75 * scaled.y());

    ui->d1_8_btnGetCoin->setFixedSize(300 * scaled.x(), 75 * scaled.y());


}
