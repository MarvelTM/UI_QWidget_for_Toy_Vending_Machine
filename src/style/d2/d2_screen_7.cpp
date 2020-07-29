#include "d2_screen_7.h"
#include "ui_d2_screen_7.h"

#include <QResizeEvent>

Screen_7::Screen_7(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_7)
{
	ui->setupUi(this);
	connect(ui->d2_7_btnBack, &QPushButton::clicked, [=](){ emit pressedButtonBack(); });
}

Screen_7::~Screen_7()
{
	delete ui;
}

void Screen_7::resizeEvent(QResizeEvent *event)
{
	
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);


    QFont font = ui->d2_7_lblInfoText->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_7_lblInfoText->setFont(font);

    ui->d2_7_lblInfoText->setFixedHeight(160 * scaled.x());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_7_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);


    ui->d2_7_backgroundWidget->setContentsMargins(35 * scaled.x(),
                                                  35 * scaled.y(),
                                                  35 * scaled.x(),
                                                  170 * scaled.y());

    ui->d2_7_hlTop->setContentsMargins(0,0,0,50 * scaled.y());


    int sizeIcon = 550 * scaled.y();
    // 1.17 отношение  width / height  - no-change-illustration.png
    ui->d2_7_lblTakeChange->setFixedSize(1.17 * sizeIcon,  sizeIcon);


    font = ui->d2_7_lblText->font();
    font.setPointSize(36 * scaled.x());
    ui->d2_7_lblText->setFont(font);

    ui->d2_7_lePhoneNumber->setFixedSize(720* scaled.x(), 145 * scaled.y());
    ui->d2_7_lePhoneNumber->setFont(font);

    QSize sizeBtn = QSize(500 * scaled.x(),  225 * scaled.y());
    ui->d2_7_btnSendPhone->setFixedSize(sizeBtn.width() , sizeBtn.height());
}
