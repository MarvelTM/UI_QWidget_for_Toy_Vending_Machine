#include "d1_screen_7.h"
#include "ui_d1_screen_7.h"

#include <QDebug>
#include <QResizeEvent>

#include <QtMath>

d1_Screen_7::d1_Screen_7(QWidget *parent) : QWidget(parent), ui(new Ui::d1_Screen_7)
{
	ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	//connect(ui->d1_7_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });
}

d1_Screen_7::~d1_Screen_7()
{
	delete ui;
}

void d1_Screen_7::playAnimation()
{
	animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void d1_Screen_7::resizeEvent(QResizeEvent *event)
{
	qDebug() << "test 2" << event->size();

    QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 800.0, size.height() / 900.0);

	QFont font = ui->d1_7_lblInfo->font();
	font.setPixelSize(48 * scaled.y());
	ui->d1_7_lblInfo->setFont(font);

	ui->d1_7_lblInfo->setGeometry(0, 80 * scaled.y(), size.width(), 80 * scaled.y());

	int sizeMargins = 80 * scaled.y();
	ui->d1_7_lblRainbow->setGeometry(sizeMargins,
									 ui->d1_7_lblInfo->geometry().bottom() + sizeMargins,
									 size.width() - 2 * sizeMargins,
									 size.height() - ui->d1_7_lblInfo->geometry().bottom()
										 - 2 * sizeMargins);


	QSize sizeHorse = QSize(200 * scaled.y(), 200 * scaled.y());
	ui->d1_7_lblRedHorse->setGeometry(ui->d1_7_lblRainbow->geometry().topLeft().x(),
									  ui->d1_7_lblRainbow->geometry().topLeft().y(),
									  sizeHorse.width(),
									  sizeHorse.width());

	//qDebug() <<  "Test" << ui->d1_7_lblRainbow->geometry().bottomRight();

	//	ui->d1_7_vlBackground->setContentsMargins(0 * scaled.x(),
	//											  80 * scaled.y(),
	//											  0 * scaled.x(),
	//											  0 * scaled.y());


	this->update();

	animation = new QPropertyAnimation(ui->d1_7_lblRedHorse, "geometry");
	animation->setDuration(3000);
	animation->setEasingCurve(QEasingCurve::Linear);

	QPointF start = ui->d1_7_lblRainbow->geometry().topLeft();
	QPointF stop  = ui->d1_7_lblRainbow->geometry().bottomRight()
				   - QPointF(ui->d1_7_lblRedHorse->width(),
							 ui->d1_7_lblRedHorse->height() + 40);

	int w = stop.x() - start.x();
	int h = stop.y() - start.y();

	qDebug() << start;

    int n = 90;
	for (int i = 0; i <= n; i++) {
		double angle = M_PI / (2.0 * n);
		QRect tmp    = QRect(start.x() + sin(angle * i) * w,
						  stop.y() - cos(angle * i) * h,
						  ui->d1_7_lblRedHorse->width(),
						  ui->d1_7_lblRedHorse->height());

		animation->setKeyValueAt(i / static_cast<double>(n), tmp);
		qDebug() <<i / static_cast<double>(n) << tmp;
	}

	qDebug() << stop;
}

void d1_Screen_7::showEvent(QShowEvent *event)
{
	qDebug() << "test 1";
	animation->start();
	QTimer::singleShot(11000, this, [=]() { emit pressedButtonClose(); });
}
