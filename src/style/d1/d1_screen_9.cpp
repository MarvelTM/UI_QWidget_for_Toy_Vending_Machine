#include "d1_screen_9.h"
#include "ui_d1_screen_9.h"

#include <QResizeEvent>

d1_Screen_9::d1_Screen_9(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::d1_Screen_9)
{
	ui->setupUi(this);

	connect(ui->d1_9_btnClose, &QPushButton::clicked, [=]() {emit  pressedButtonClose(); });
	//connect(ui->d1_9_btnBack, &QPushButton::clicked, [=]() {emit  pressedButtonBack(); });
}

d1_Screen_9::~d1_Screen_9()
{
	delete ui;
}

void d1_Screen_9::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 800.0, size.height() / 900.0);

	QFont font = ui->d1_9_lblInfo->font();
    font.setPixelSize(46 * scaled.y());
	ui->d1_9_lblInfo->setFont(font);

	font = ui->d1_9_lblText_1->font();
    font.setPixelSize(36 * scaled.y());
	ui->d1_9_lblText_1->setFont(font);
	ui->d1_9_lblText_2->setFont(font);


	int sizeBtnBack = 125 * scaled.x();
	ui->d1_9_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);

}

//void d1_Screen_9::showEvent(QShowEvent *event)
//{
//	ui->d1_9_btnClose->setEnabled(false);
//	QTimer::singleShot(8000, this, [=]() {	ui->d1_9_btnClose->setEnabled(true); });
//}
