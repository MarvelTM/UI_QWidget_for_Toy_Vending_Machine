#include "d1_screen_4.h"
#include "ui_d1_screen_4.h"

#include <QResizeEvent>

d1_Screen_4::d1_Screen_4(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_4)
{
	ui->setupUi(this);

	connect(ui->d1_4_btnClose, &QPushButton::clicked, [=]() {emit  pressedButtonClose(); });
	connect(ui->d1_4_btnBack, &QPushButton::clicked, [=]() {emit  pressedButtonBack(); });
}

d1_Screen_4::~d1_Screen_4()
{
	delete ui;
}

void d1_Screen_4::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 860.0, size.height() / 1200.0);

	QFont font = ui->d1_4_lblInfo->font();
	font.setPixelSize(60 * scaled.y());
	ui->d1_4_lblInfo->setFont(font);

	font = ui->d1_4_lblText->font();
	font.setPixelSize(50 * scaled.y());
	ui->d1_4_lblText->setFont(font);
	ui->d1_4_lblText_2->setFont(font);


	ui->d1_4_vlBackground->setContentsMargins(12 * scaled.x(),
											  0 * scaled.y(),
											  12 * scaled.x(),
											  2 * scaled.y());

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_4_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
	ui->d1_4_btnBack->setFixedSize(300 * scaled.x(), 80 * scaled.y());

	int sizeBtnCash = 350 * scaled.x();
	ui->d1_4_lblIcon->setFixedSize(sizeBtnCash, sizeBtnCash);

	ui->d1_4_widgetTop->setFixedHeight(150 *  scaled.y());
}
