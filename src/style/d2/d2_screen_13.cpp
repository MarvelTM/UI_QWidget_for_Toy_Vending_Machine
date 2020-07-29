#include "d2_screen_13.h"
#include "ui_d2_screen_13.h"


#include <QResizeEvent>
#include <QDebug>

Screen_13::Screen_13(QWidget *parent) :
	  QWidget(parent),
	  ui(new Ui::Screen_13)
{
	ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_TranslucentBackground);

	connect(ui->d2_13_btnClose, &QPushButton::clicked, [=](){ emit pressedButtonClose(); });
	connect(ui->d2_13_btnSend, &QPushButton::clicked, [=]() { send(); });
//	// лучше перед отправкой сформировать данные и отправлять данные какие кнопки выбраны через
//	// QPushButton->isChecked
//	connect(ui->d2_13_btnRatingExelent_1, &QPushButton::clicked, [=](){ qDebug() << "Exelent_1"; });
//	connect(ui->d2_13_btnRatingGood_1, &QPushButton::clicked, [=]() { qDebug() << "Good_1"; });
//	connect(ui->d2_13_btnRatingBad_1, &QPushButton::clicked, [=]() { qDebug() << "Bad_1"; });

//	connect(ui->d2_13_btnRatingExelent_2, &QPushButton::clicked, [=](){ qDebug() << "Exelent_2"; });
//	connect(ui->d2_13_btnRatingGood_2, &QPushButton::clicked, [=]() { qDebug() << "Good_2"; });
//	connect(ui->d2_13_btnRatingBad_2, &QPushButton::clicked, [=]() { qDebug() << "Bad_2"; });

//	connect(ui->d2_13_btnRatingExelent_3, &QPushButton::clicked, [=](){ qDebug() << "Exelent_3"; });
//	connect(ui->d2_13_btnRatingGood_3, &QPushButton::clicked, [=]() { qDebug() << "Good_3"; });
//	connect(ui->d2_13_btnRatingBad_3, &QPushButton::clicked, [=]() { qDebug() << "Bad_3"; });

//	connect(ui->d2_13_btnRatingExelent_4, &QPushButton::clicked, [=](){ qDebug() << "Exelent_4"; });
//	connect(ui->d2_13_btnRatingGood_4, &QPushButton::clicked, [=]() { qDebug() << "Good_4"; });
//	connect(ui->d2_13_btnRatingBad_4, &QPushButton::clicked, [=]() { qDebug() << "Bad_4"; });

//	connect(ui->d2_13_btnRatingExelent_5, &QPushButton::clicked, [=](){ qDebug() << "Exelent_5"; });
//	connect(ui->d2_13_btnRatingGood_5, &QPushButton::clicked, [=]() { qDebug() << "Good_5"; });
//	connect(ui->d2_13_btnRatingBad_5, &QPushButton::clicked, [=]() { qDebug() << "Bad_5"; });

	//connect(buttonGroup, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked),
	//		[=](QAbstractButton *button){ /* ... */ });
}

Screen_13::~Screen_13()
{
	delete ui;
}

void Screen_13::send()
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


void Screen_13::resizeEvent(QResizeEvent *event)
{
	
    QSizeF size    = event->size();
    QPointF scaled = QPointF(size.width() / 1000.0, size.height() / 1020.0);

    QFont font = ui->d2_13_lblInfoText->font();
    font.setPointSize(24 * scaled.y());
     ui->d2_13_lblInfoText->setFont(font);

    font = ui->d2_13_lblText->font();
    font.setPointSize(18 * scaled.y());
    ui->d2_13_lblText->setFont(font);

    ui->d2_13_lblRatingText_1->setFont(font);
    ui->d2_13_lblRatingText_2->setFont(font);
    ui->d2_13_lblRatingText_3->setFont(font);
    ui->d2_13_lblRatingText_4->setFont(font);
    ui->d2_13_lblRatingText_5->setFont(font);

    ui->d2_13_lblComment->setFont(font);


    font.setPointSize(15 * scaled.y());
    ui->d2_13_lblBack->setFont(font);

    font.setPointSize(20 * scaled.y());
    ui->d2_13_teComment->setFont(font);
    ui->d2_13_lePhoneNumber->setFont(font);


    //!
    int sizeRating  = 60 * scaled.x();

    /// 1
    ui->d2_13_btnRatingExelent_1->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingGood_1->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingBad_1->setFixedSize(sizeRating,sizeRating);

    /// 2
    ui->d2_13_btnRatingExelent_2->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingGood_2->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingBad_2->setFixedSize(sizeRating,sizeRating);

    /// 3
    ui->d2_13_btnRatingExelent_3->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingGood_3->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingBad_3->setFixedSize(sizeRating,sizeRating);

    /// 4
    ui->d2_13_btnRatingExelent_4->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingGood_4->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingBad_4->setFixedSize(sizeRating,sizeRating);

    /// 5
    ui->d2_13_btnRatingExelent_5->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingGood_5->setFixedSize(sizeRating,sizeRating);
    ui->d2_13_btnRatingBad_5->setFixedSize(sizeRating,sizeRating);


    ui->d2_13_lePhoneNumber->setFixedSize(300 * scaled.x(), 40 * scaled.y());

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_13_btnClose->setFixedSize(sizeBtnBack, sizeBtnBack);
    ui->d2_13_btnSend->setFixedSize(300 * scaled.x(), 90 * scaled.y());

    //ui->d2_13_hlTop->setContentsMargins(sizeBtnBack, 110 * scaled.y(), 0, 0);
    //ui->d2_13_hlButton->setContentsMargins(0, 20 * scaled.y(), 0, 60 * scaled.y());
    //ui->d2_13_hlRating->setContentsMargins(40 * scaled.x(), 0, 40 * scaled.x(),0);
}
