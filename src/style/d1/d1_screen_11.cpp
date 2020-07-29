#include "d1_screen_11.h"
#include "ui_d1_screen_11.h"

#include <QResizeEvent>

#include <QDebug>

d1_Screen_11::d1_Screen_11(QWidget *parent) : QWidget(parent), ui(new Ui::d1_Screen_11)
{
	ui->setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d1_11_btnClose, &QPushButton::clicked, [=]() { emit pressedButtonClose(); });
	connect(ui->d1_11_btnSend, &QPushButton::clicked, [=]() { send(); });

	//	connect(ui->d1_11_btnRatingExelent_1, &QPushButton::clicked, [=](){ qDebug() << "Exelent_1"; });
	//	connect(ui->d1_11_btnRatingGood_1, &QPushButton::clicked, [=]() { qDebug() << "Good_1"; });
	//	connect(ui->d1_11_btnRatingBad_1, &QPushButton::clicked, [=]() { qDebug() << "Bad_1"; });

	//	connect(ui->d1_11_btnRatingExelent_2, &QPushButton::clicked, [=](){ qDebug() << "Exelent_2"; });
	//	connect(ui->d1_11_btnRatingGood_2, &QPushButton::clicked, [=]() { qDebug() << "Good_2"; });
	//	connect(ui->d1_11_btnRatingBad_2, &QPushButton::clicked, [=]() { qDebug() << "Bad_2"; });

	//	connect(ui->d1_11_btnRatingExelent_3, &QPushButton::clicked, [=](){ qDebug() << "Exelent_3"; });
	//	connect(ui->d1_11_btnRatingGood_3, &QPushButton::clicked, [=]() { qDebug() << "Good_3"; });
	//	connect(ui->d1_11_btnRatingBad_3, &QPushButton::clicked, [=]() { qDebug() << "Bad_3"; });

	//	connect(ui->d1_11_btnRatingExelent_4, &QPushButton::clicked, [=](){ qDebug() << "Exelent_4"; });
	//	connect(ui->d1_11_btnRatingGood_4, &QPushButton::clicked, [=]() { qDebug() << "Good_4"; });
	//	connect(ui->d1_11_btnRatingBad_4, &QPushButton::clicked, [=]() { qDebug() << "Bad_4"; });

	//	connect(ui->d1_11_btnRatingExelent_5, &QPushButton::clicked, [=](){ qDebug() << "Exelent_5"; });
	//	connect(ui->d1_11_btnRatingGood_5, &QPushButton::clicked, [=]() { qDebug() << "Good_5"; });
	//	connect(ui->d1_11_btnRatingBad_5, &QPushButton::clicked, [=]() { qDebug() << "Bad_5"; });
}

d1_Screen_11::~d1_Screen_11()
{
	delete ui;
}

void d1_Screen_11::send()
{

	/// Adds the given button to the button group. If id is -1, an id will be assigned to the button.
	/// Automatically assigned ids are guaranteed to
	/// be negative, starting with -2. If you are assigning your own ids,
	/// use positive values to avoid conflicts.

	// -1 none
	// -2 exelent
	// -3 good
	// -4 bad

	qDebug() << ui->buttonGroup->checkedId();
	qDebug() << ui->buttonGroup_2->checkedId();
	qDebug() << ui->buttonGroup_3->checkedId();
	qDebug() << ui->buttonGroup_4->checkedId();
	qDebug() << ui->buttonGroup_5->checkedId();

	if (ui->buttonGroup->checkedId() != -1) {
		ui->buttonGroup->setExclusive(false);
		ui->buttonGroup->checkedButton()->setChecked(false);
		ui->buttonGroup->setExclusive(true);
	}

	if (ui->buttonGroup_2->checkedId() != -1) {
		ui->buttonGroup_2->setExclusive(false);
		ui->buttonGroup_2->checkedButton()->setChecked(false);
		ui->buttonGroup_2->setExclusive(true);
	}

	if (ui->buttonGroup_3->checkedId() != -1) {
		ui->buttonGroup_3->setExclusive(false);
		ui->buttonGroup_3->checkedButton()->setChecked(false);
		ui->buttonGroup_3->setExclusive(true);
	}
	if (ui->buttonGroup_4->checkedId() != -1) {
		ui->buttonGroup_4->setExclusive(false);
		ui->buttonGroup_4->checkedButton()->setChecked(false);
		ui->buttonGroup_4->setExclusive(true);
	}
	if (ui->buttonGroup_5->checkedId() != -1) {
		ui->buttonGroup_5->setExclusive(false);
		ui->buttonGroup_5->checkedButton()->setChecked(false);
		ui->buttonGroup_5->setExclusive(true);
	}

	emit pressedButtonSend();
}

void d1_Screen_11::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	QPointF scaled = QPointF(size.width() / 800.0, size.height() / 900.0);

	QFont font = ui->d1_11_lblInfoText->font();
	font.setPointSize(18 * scaled.y());

	ui->d1_11_lblInfoText->setFont(font);

	ui->d1_11_lblText->setFont(font);

	ui->d1_11_lblRatingText_1->setFont(font);
	ui->d1_11_lblRatingText_2->setFont(font);
	ui->d1_11_lblRatingText_3->setFont(font);
	ui->d1_11_lblRatingText_4->setFont(font);
	ui->d1_11_lblRatingText_5->setFont(font);

	ui->d1_11_lblComment->setFont(font);

	font.setPointSize(15 * scaled.y());
	ui->d1_11_lblBack->setFont(font);

	font.setPointSize(20 * scaled.y());
	ui->d1_11_teComment->setFont(font);
	ui->d1_11_lePhoneNumber->setFont(font);

	//!
	int sizeRating = 60 * scaled.x();

	/// 1
	ui->d1_11_btnRatingExelent_1->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingGood_1->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingBad_1->setFixedSize(sizeRating, sizeRating);

	/// 2
	ui->d1_11_btnRatingExelent_2->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingGood_2->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingBad_2->setFixedSize(sizeRating, sizeRating);

	/// 3
	ui->d1_11_btnRatingExelent_3->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingGood_3->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingBad_3->setFixedSize(sizeRating, sizeRating);

	/// 4
	ui->d1_11_btnRatingExelent_4->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingGood_4->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingBad_4->setFixedSize(sizeRating, sizeRating);

	/// 5
	ui->d1_11_btnRatingExelent_5->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingGood_5->setFixedSize(sizeRating, sizeRating);
	ui->d1_11_btnRatingBad_5->setFixedSize(sizeRating, sizeRating);

	ui->d1_11_lePhoneNumber->setFixedSize(300 * scaled.x(), 40 * scaled.y());

	int sizeBtnBack = 125 * scaled.x();
	ui->d1_11_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
	ui->d1_11_btnSend->setFixedSize(300 * scaled.x(), 60 * scaled.y());

	ui->d1_11_hlTop->setContentsMargins(sizeBtnBack, 110 * scaled.y(), 0, 0);
	ui->d1_10_hlButton->setContentsMargins(0, 20 * scaled.y(), 0, 60 * scaled.y());
	ui->d1_11_hlRating->setContentsMargins(40 * scaled.x(), 0, 40 * scaled.x(), 0);

	//ui->d1_11_teComment->setFixedHeight(20);
}
