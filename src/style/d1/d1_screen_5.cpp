#include "d1_screen_5.h"
#include "ui_d1_screen_5.h"

#include <QResizeEvent>

d1_Screen_5::d1_Screen_5(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_5)
{
	ui->setupUi(this);

	connect(ui->d1_5_btnClose, &QPushButton::clicked, [=]() {emit  pressedButtonClose(); });
	connect(ui->d1_5_btnBack, &QPushButton::clicked, [=]() {emit  pressedButtonBack(); });
}

d1_Screen_5::~d1_Screen_5()
{
	delete ui;
}

void d1_Screen_5::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 860.0, size.height() / 1200.0);

	QFont font = ui->d1_5_lblInfo->font();
	font.setPixelSize(60 * scaled.y());
	ui->d1_5_lblInfo->setFont(font);

	font = ui->d1_5_lblAttention->font();
	font.setPixelSize(60 * scaled.y());
	ui->d1_5_lblAttention->setFont(font);

	font = ui->d1_5_lblAttentionText->font();
	font.setPixelSize(50 * scaled.y());
	ui->d1_5_lblAttentionText->setFont(font);

    ui->d1_8_lblInfoReturn->setFont(font);



	ui->d1_5_vlBackground->setContentsMargins(12 * scaled.x(),
											  0 * scaled.y(),
											  12 * scaled.x(),
											  2 * scaled.y());

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_5_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
	ui->d1_5_btnBack->setFixedSize(300 * scaled.x(), 80 * scaled.y());

	ui->d1_5_widgetContent->setFixedSize(620 * scaled.x(), 700 * scaled.y());
	ui->d1_5_widgetTop->setFixedHeight(150 * scaled.y());

	ui->d1_5_vlContent->setContentsMargins(25 * scaled.x(), 260 * scaled.y(), 35 * scaled.x(), 100 * scaled.y());
}
