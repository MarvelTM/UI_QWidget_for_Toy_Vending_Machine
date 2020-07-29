#include "d1_screen_1.h"
#include "ui_d1_screen_1.h"

#include <QResizeEvent>

d1_Screen_1::d1_Screen_1(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_1)
{
	ui->setupUi(this);
}

d1_Screen_1::~d1_Screen_1()
{
	delete ui;
}

void d1_Screen_1::showVideo(bool show)
{
	ui->d1_1_widgetBackgroundVideo->setVisible(show);
}

void d1_Screen_1::addProducts(QVector<Product> products)
{
	if (items.count() > 0) {
		int count_button = ui->d1_1_gridLayout->count();
		for (int i = count_button - 1; i >= 0; i--) {
			QLayoutItem *item = ui->d1_1_gridLayout->takeAt(i);
			if (QWidget *widget = item->widget())
				widget->deleteLater();
			delete item;
		}
		items.clear();
	}

	for (int i = 0; i < products.count(); i++) {
		items.push_back(new d1_ProductItem);
		items.last()->setProduct(products[i]);
		connect(items.last(), &QPushButton::pressed, [=]() { emit pressedButtonProduct(i); });
	}


	switch (products.count()) {
	case 8:
		for (int row = 0; row < 2; row++)
		for (int col = 0; col < 4; col++)
			 {
				int id = row * 4 + col;
				ui->d1_1_gridLayout->addWidget(items[id], row, col, 1, 1);
			}

		break;

	case 12:
		for (int row = 0; row < 4; row++)
		for (int col = 0; col < 3; col++)
			 {
				int id = row * 3 + col;
				ui->d1_1_gridLayout->addWidget(items[id], row, col, 1, 1);
			}
		break;

	case 21: {
		ui->d1_1_gridLayout->addWidget(items[0], 0, 0, 1, 4);
		ui->d1_1_gridLayout->addWidget(items[1], 0, 4, 1, 4);
		ui->d1_1_gridLayout->addWidget(items[2], 0, 8, 1, 4);

		ui->d1_1_gridLayout->addWidget(items[3], 1, 0, 1, 4);
		ui->d1_1_gridLayout->addWidget(items[4], 1, 4, 1, 4);
		ui->d1_1_gridLayout->addWidget(items[5], 1, 8, 1, 4);

		ui->d1_1_gridLayout->addWidget(items[6], 2, 0, 1, 4);
		ui->d1_1_gridLayout->addWidget(items[7], 2, 4, 1, 4);
		ui->d1_1_gridLayout->addWidget(items[8], 2, 8, 1, 4);

		ui->d1_1_gridLayout->addWidget(items[9], 3, 0, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[10], 3, 3, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[11], 3, 6, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[12], 3, 9, 1, 3);

		ui->d1_1_gridLayout->addWidget(items[13], 4, 0, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[14], 4, 3, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[15], 4, 6, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[16], 4, 9, 1, 3);

		ui->d1_1_gridLayout->addWidget(items[17], 5, 0, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[18], 5, 3, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[19], 5, 6, 1, 3);
		ui->d1_1_gridLayout->addWidget(items[20], 5, 9, 1, 3);
	}
	break;
	default:
		break;
	}
}

void d1_Screen_1::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 900.0, size.height() / 1600.0);

	ui->d1_1_vlBackground->setContentsMargins(14 * scaled.x(),
											  0 * scaled.y(),
											  14 * scaled.x(),
											  12 * scaled.y());

//	int sizeBackground                                 = 0;
//	ui->d1_1_widgetVideo->isVisible() ? sizeBackground = 950 : sizeBackground = 0;


	ui->d1_1_widgetBackgroundVideo->setFixedHeight(950 * scaled.y());
	ui->d1_1_vlBackgroundVideo->setContentsMargins(0, 220 * scaled.y(), 0, 0);

	ui->d1_1_gridLayout->setContentsMargins(0, 12 * scaled.y(), 0, 9 * scaled.y());
	ui->d1_1_gridLayout->setHorizontalSpacing(9 * scaled.x());
	ui->d1_1_gridLayout->setVerticalSpacing(9 * scaled.y());

	//ui->d1_widgetVideo->setFixedHeight(640 * scaled.y());
	//ui->d1_1_widgetGrid->setFixedHeight(360 * scaled.y());
}
