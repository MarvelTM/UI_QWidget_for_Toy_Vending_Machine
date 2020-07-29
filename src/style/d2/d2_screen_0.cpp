#include "d2_screen_0.h"
#include "ui_d2_screen_0.h"

#include <QDebug>

Screen_0::Screen_0(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_0)
{
	ui->setupUi(this);
	connect(ui->d2_0_btnClose, &QPushButton::pressed, [=]() {
		emit closeVideo();
	});
}

Screen_0::~Screen_0()
{
	delete ui;
}
