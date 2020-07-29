#include "d2_screen_9.h"
#include "ui_d2_screen_9.h"



#include <QCloseEvent>

Screen_9::Screen_9(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_9)
{
	ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d2_9_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });



    connect(ui->d2_9_btnTry, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });
    connect(ui->d2_9_btnReturnVisa, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });

    connect(ui->d2_9_btnBuyMore, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });
    connect(ui->d2_9_btnGetCoin, &QPushButton::clicked, [=](){ emit pressedButtonTry(); });


    //ui->d2_9_btnTry->hide();
    ui->d2_9_btnReturnVisa->hide();

    ui->d2_9_lblInfoReturn->hide();
    //ui->d2_9_btnGetCoin->hide();

}

Screen_9::~Screen_9()
{
	delete ui;
}

//void Screen_9::closeEvent(QCloseEvent *event)
//{
//	//emit closePopups();
//	event->ignore();
//}

void Screen_9::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1000.0, size.height() / 1020.0);

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_9_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);

     ui->d2_9_lbInfoText->setFixedHeight(80 * scaled.x());


    ui->d2_9_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  35 * scaled.y());

    ui->d2_9_lblIllustrationNoToy->setFixedSize(400 * scaled.x(),  330 * scaled.y());

   // ui->d2_9_hlTop->setContentsMargins(0,0,0,50 * scaled.y());

    ui->verticalLayout_2->setContentsMargins(0,0,0,50 * scaled.y());

    QSize sizeBtn = QSize(300 * scaled.x(),  100 * scaled.y());
    ui->d2_9_btnBuyMore->setFixedSize(sizeBtn.width() , sizeBtn.height());
    ui->d2_9_btnGetCoin->setFixedSize(sizeBtn.width() , sizeBtn.height());
    ui->d2_9_btnReturnVisa->setFixedSize(sizeBtn.width() , sizeBtn.height());
    ui->d2_9_btnTry->setFixedSize(sizeBtn.width() , sizeBtn.height());

    ui->verticalLayout_4->setSpacing(9 * scaled.y());
}
