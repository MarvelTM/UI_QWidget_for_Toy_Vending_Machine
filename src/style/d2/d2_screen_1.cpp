#include "d2_screen_1.h"
#include "ui_d2_screen_1.h"



#include <QFontDatabase>

#include <QFile>
#include <QDebug>
#include <QResizeEvent>

Screen_1::Screen_1(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_1)
{
	ui->setupUi(this);
	is_showWideo = false;

	ui->d2_1_widgetVideo->hide();

	connect(ui->d2_1_btnCoins, &QPushButton::pressed, [=]() {
		qDebug() << "coins";
		emit pressedButtonCoins();
	});


	connect(ui->d2_1_btnDiscount, &QPushButton::pressed, [=]() {
		qDebug() << "Discount";
		emit pressedButtonDiscount();
	});


}

Screen_1::~Screen_1()
{
	delete ui;
}

void Screen_1::addProducts(QVector<d2::Product> products)
{
    if (items.count() > 0) {
        int count_button = ui->d2_1_gridLayout->count();
        for (int i = count_button - 1; i >= 0; i--) {
            QLayoutItem *item = ui->d2_1_gridLayout->takeAt(i);
            if (QWidget *widget = item->widget())
                widget->deleteLater();
            delete item;
        }
        items.clear();
    }

    for (int i = 0; i < products.count(); i++) {
        items.push_back(new d2_ProductItem);
        items.last()->setProduct(products[i]);
        connect(items.last(), &QPushButton::pressed, [=]() { emit pressedButtonProduct(i); });
    }


    switch (products.count()) {
    case 8:
        for (int row = 0; row < 2; row++)
        for (int col = 0; col < 4; col++)
             {
                int id = row * 4 + col;
                ui->d2_1_gridLayout->addWidget(items[id], row, col, 1, 1);
            }

        break;

    case 12:
        for (int row = 0; row < 3; row++)
        for (int col = 0; col < 4; col++)
             {
                int id = row * 4 + col;
                ui->d2_1_gridLayout->addWidget(items[id], row, col, 1, 1);
            }
        break;

    case 21: {
        ui->d2_1_gridLayout->addWidget(items[0], 0, 0, 1, 4);
        ui->d2_1_gridLayout->addWidget(items[1], 0, 4, 1, 4);
        ui->d2_1_gridLayout->addWidget(items[2], 0, 8, 1, 4);

        ui->d2_1_gridLayout->addWidget(items[3], 1, 0, 1, 4);
        ui->d2_1_gridLayout->addWidget(items[4], 1, 4, 1, 4);
        ui->d2_1_gridLayout->addWidget(items[5], 1, 8, 1, 4);

        ui->d2_1_gridLayout->addWidget(items[6], 2, 0, 1, 4);
        ui->d2_1_gridLayout->addWidget(items[7], 2, 4, 1, 4);
        ui->d2_1_gridLayout->addWidget(items[8], 2, 8, 1, 4);

        ui->d2_1_gridLayout->addWidget(items[9], 3, 0, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[10], 3, 3, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[11], 3, 6, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[12], 3, 9, 1, 3);

        ui->d2_1_gridLayout->addWidget(items[13], 4, 0, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[14], 4, 3, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[15], 4, 6, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[16], 4, 9, 1, 3);

        ui->d2_1_gridLayout->addWidget(items[17], 5, 0, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[18], 5, 3, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[19], 5, 6, 1, 3);
        ui->d2_1_gridLayout->addWidget(items[20], 5, 9, 1, 3);
    }
    break;
    default:
        break;
    }
}

void Screen_1::setVideo(QWidget *widget)
{
    ui->d2_1_widgetVideo->layout()->addWidget(widget);
    widget->show();
}

void Screen_1::showWideo(bool show)
{
	is_showWideo = show;
	if (show) {
		ui->d2_1_widgetVideo->show();
        ui->d2_1_widgetSelectToys->hide();
	} else {
		ui->d2_1_widgetVideo->hide();
        ui->d2_1_widgetSelectToys->show();
	}
}

void Screen_1::setShowCoins(bool is_show)
{
	is_show ? ui->d2_1_btnCoins->show(): ui->d2_1_btnCoins->hide();
}



void Screen_1::setShowDiscount(bool is_show)
{
	is_show ? ui->d2_1_btnDiscount->show(): ui->d2_1_btnDiscount->hide();
}


void Screen_1::resizeEvent(QResizeEvent *event)
{
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);

    ui->d2_1_lblLogo->setFixedSize(460 * scaled.x(), 150 * scaled.y());

    QSize sizeButton = QSize(340 * scaled.x(), 150 * scaled.y());
    ui->d2_1_btnCoins->setFixedSize(sizeButton);
    ui->d2_1_btnDiscount->setFixedSize(sizeButton);

    ui->d2_1_widgetVideo->setFixedSize(size.width(), 0.75 * size.width());

    ui->d2_1_widgetSelectToys->setFixedHeight(150 * scaled.y());

    ui->d2_1_gridLayout->setContentsMargins(0, 12 * scaled.y(), 0, 9 * scaled.y());
    ui->d2_1_gridLayout->setHorizontalSpacing(12 * scaled.x());
    ui->d2_1_gridLayout->setVerticalSpacing(12 * scaled.y());

//	double scale = 1.0;
//	is_showWideo ? scale = 6.0 / 14.0 : scale = 6.0 / 9.0;
//	ui->widget->setMaximumSize(QSize(event->size().width() , event->size().height() * scale));


//	ui->d2_1_btnCoins->setFixedWidth(230 * Settings::getInstance()->scale_f);
//	ui->d2_1_btnCoins->setFixedHeight(90 * Settings::getInstance()->scale_f);

//	ui->d2_1_btnPhone->setFixedWidth(230 * Settings::getInstance()->scale_f);
//	ui->d2_1_btnPhone->setFixedHeight(90 * Settings::getInstance()->scale_f);

//	ui->d2_1_btnDiscount->setFixedWidth(230 * Settings::getInstance()->scale_f);
//	ui->d2_1_btnDiscount->setFixedHeight(90 * Settings::getInstance()->scale_f);

//	//int cideo_size = ui->d2_1_widgetVideo->geometry().width();
//	//int cideo_size = 400;

//	//ui->d2_1_widgetVideo->setFixedWidth(cideo_size * Settings::getInstance()->scale_f);
//	//ui->d2_1_widgetVideo->setFixedHeight(cideo_size * Settings::getInstance()->scale_f);

//	ui->d2_1_lblLogo->setFixedHeight(71 * Settings::getInstance()->scale_f);

//	ui->d2_1_lblSelectToys->setFixedWidth(700 * Settings::getInstance()->scale_f );
//	ui->d2_1_lblSelectToys->setFixedHeight(120 * Settings::getInstance()->scale_f);

//	ui->gridLayout->setHorizontalSpacing(7 * Settings::getInstance()->scale_f);
//	ui->gridLayout->setVerticalSpacing(7 * Settings::getInstance()->scale_f);
//	ui->gridLayout->setContentsMargins(0, 7 * Settings::getInstance()->scale_f, 0, 0);
}



