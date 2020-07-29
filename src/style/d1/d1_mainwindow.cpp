#include "d1_mainwindow.h"
#include "ui_d1_mainwindow.h"

#include <QResizeEvent>
#include <QApplication>
#include <QDesktopWidget>

#include <QToolButton>
#include <QMenu>

#include <QDebug>

d1_MainWindow::d1_MainWindow(QWidget *parent)
	: QMainWindow(parent)
	  , ui(new Ui::d1_MainWindow)
{
	ui->setupUi(this);

	ui->d1_pbnMenu->setVisible(false);

	// Различные эффекты для отображения
	effectBlure = new QGraphicsBlurEffect;
	effectBlure->setBlurRadius(10);

	effectOpacity = new QGraphicsOpacityEffect;
	effectOpacity->setOpacity(1.0);

	ui->toolBar->hide();

	// Testing
    //createMenu();

	d1_screen_1 = new d1_Screen_1(this);
	d1_screen_2 = new d1_Screen_2(this);
	d1_screen_3 = new d1_Screen_3(this);
	d1_screen_4 = new d1_Screen_4(this);
	d1_screen_5 = new d1_Screen_5(this);
    d1_screen_6 = new d1_Screen_6(this);

    d1_screen_9 = new d1_Screen_9(this);

	//popups
	d1_screen_7 = new d1_Screen_7(this);
	d1_screen_8 = new d1_Screen_8(this);

	d1_screen_10 = new d1_Screen_10(this);
	d1_screen_11 = new d1_Screen_11(this);

	connect(d1_screen_7, &d1_Screen_7::pressedButtonClose, this, &d1_MainWindow::closePopup);
	connect(d1_screen_8, &d1_Screen_8::pressedButtonClose, this, &d1_MainWindow::closePopup);
	connect(d1_screen_9, &d1_Screen_9::pressedButtonClose, this, &d1_MainWindow::closePopup);
	connect(d1_screen_10, &d1_Screen_10::pressedButtonClose, this, &d1_MainWindow::closePopup);
	connect(d1_screen_11, &d1_Screen_11::pressedButtonClose, this, &d1_MainWindow::closePopup);


	connect(d1_screen_8, &d1_Screen_8::pressedButtonTry, this, [=]() { qDebug() << "Try";});
	connect(d1_screen_10, &d1_Screen_10::pressedButtonBuyMore, this, [=]() { ui->d1_stackedWidget->setCurrentIndex(0);});
	connect(d1_screen_11, &d1_Screen_11::pressedButtonSend, this, [=]() { qDebug() << "Отправить отзыв";});

	d1_screen_7->hide();
	d1_screen_8->hide();
	d1_screen_9->hide();
	d1_screen_10->hide();
	d1_screen_11->hide();

    d1_videoWidget= new d1_VideoWidget(this);
    d1_videoWidget->hide();

    connect(d1_videoWidget, &d1_VideoWidget::pressedButtonClose, this, &d1_MainWindow::closeVideo);


	ui->d1_stackedWidget->addWidget(d1_screen_1);
	ui->d1_stackedWidget->addWidget(d1_screen_2);
	ui->d1_stackedWidget->addWidget(d1_screen_3);
	ui->d1_stackedWidget->addWidget(d1_screen_4);
	ui->d1_stackedWidget->addWidget(d1_screen_5);
    ui->d1_stackedWidget->addWidget(d1_screen_6);
    //ui->d1_stackedWidget->addWidget(d1_screen_9);

	connect(ui->d1_pbnMenu, &QPushButton::clicked, [=]() {ui->d1_stackedWidget->setCurrentIndex(0);});

	connect(d1_screen_1, &d1_Screen_1::pressedButtonProduct, this, &d1_MainWindow::showProductInfo);

	connect(d1_screen_2, &d1_Screen_2::pressedButtonBuy, this, &d1_MainWindow::showPaymentType);
	connect(d1_screen_2, &d1_Screen_2::pressedButtonShowVideo, this, &d1_MainWindow::showVideo);
	connect(d1_screen_2, &d1_Screen_2::pressedButtonClose, [=]() {ui->d1_stackedWidget->setCurrentIndex(0);});

	connect(d1_screen_3, &d1_Screen_3::pressedButtonCash, this, &d1_MainWindow::showPaymentCash);
	connect(d1_screen_3, &d1_Screen_3::pressedButtonCredit, this, &d1_MainWindow::showPaymentCredit);
    connect(d1_screen_3, &d1_Screen_3::pressedButtonQrCode, this, &d1_MainWindow::showPaymentQrCode);

	connect(d1_screen_3, &d1_Screen_3::pressedButtonClose, [=]() {ui->d1_stackedWidget->setCurrentIndex(1);});
	connect(d1_screen_3, &d1_Screen_3::pressedButtonBack, [=]() {ui->d1_stackedWidget->setCurrentIndex(1);});

    connect(d1_screen_4, &d1_Screen_4::pressedButtonClose, [=]() {ui->d1_stackedWidget->setCurrentIndex(2);});
    connect(d1_screen_4, &d1_Screen_4::pressedButtonBack, [=]() {ui->d1_stackedWidget->setCurrentIndex(2);});

	connect(d1_screen_5, &d1_Screen_5::pressedButtonClose, [=]() {ui->d1_stackedWidget->setCurrentIndex(2);});
	connect(d1_screen_5, &d1_Screen_5::pressedButtonBack, [=]() {ui->d1_stackedWidget->setCurrentIndex(2);});

    connect(d1_screen_6, &d1_Screen_6::pressedButtonClose, [=]() {ui->d1_stackedWidget->setCurrentIndex(2);});
    connect(d1_screen_6, &d1_Screen_6::pressedButtonBack, [=]() {ui->d1_stackedWidget->setCurrentIndex(2);});

    connect(d1_screen_9, &d1_Screen_9::pressedButtonClose, [=]() {ui->d1_stackedWidget->setCurrentIndex(0);});
    //connect(d1_Screen_9, &d1_Screen_9::pressedButtonBack, [=]() {ui->d1_stackedWidget->setCurrentIndex(1);});
}

d1_MainWindow::~d1_MainWindow()
{
	delete ui;
}

void d1_MainWindow::start(DisplayResolution displayResolution)
{
	resizeWidget(displayResolution);
    this->show();
}

void d1_MainWindow::showProductInfo(int id)
{
	ui->d1_stackedWidget->setCurrentIndex(1);
	d1_screen_2->setProduct(p_products[id]);

	QSizeF size    = ui->d1_centralwidget->size();
	QPointF scaled = QPointF(size.width() / 900.0, size.height() / 1600.0);

	ui->d1_vlStackedWidgetBackground->setContentsMargins(14 * scaled.x(),
														 12 * scaled.y(),
														 14 * scaled.x(),
														 12 * scaled.y());

}

void d1_MainWindow::resizeEvent(QResizeEvent *event)
{
	QSizeF size    = event->size();
	p_size         = size;

	QPointF scaled = QPointF(size.width() / 900.0, size.height() / 1600.0);

	ui->d1_lblLogo->setFixedSize(706 * scaled.x(), 135 * scaled.y());

	QFont font = ui->d1_lblCallInfo->font();
	font.setPixelSize(32 * scaled.y());
	ui->d1_lblCallInfo->setFont(font);

	font = ui->d1_lblDateInfo->font();
	font.setPixelSize(22 * scaled.y());
	ui->d1_lblDateInfo->setFont(font);
	ui->d1_lblNumberInfo->setFont(font);

	font = ui->d1_lblMoneyInfo->font();
	font.setPixelSize(42 * scaled.y());
	ui->d1_lblMoneyInfo->setFont(font);
	ui->d1_lblMoneyInfo->setFixedSize(541 * scaled.x(), 81 * scaled.y());

	ui->d1_pbnMenu->setFixedSize(320 * scaled.x(), 81 * scaled.y());
	ui->d1_pbnBuyCoin->setFixedSize(320 * scaled.x(), 81 * scaled.y());

	ui->d1_widgetfooter->setFixedSize(900 * scaled.x(), 81 * scaled.y());

	ui->d1_vlStackedWidget->setContentsMargins(20 * scaled.x(), 0, 20 * scaled.x(), 16 * scaled.y());
}

void d1_MainWindow::closePopup()
{
	if (popupWidget == nullptr)
		return;

	popupWidget->hide();
    // костыль для правельного отображения Popup (модального окна) в fullScreen
    ui->d1_centralwidget->setEnabled(true);

    popupWidget = nullptr;

	ui->d1_centralwidget->graphicsEffect()->setEnabled(false);
}

void d1_MainWindow::showVideo()
{
    QRect tmp_geometry = ui->d1_centralwidget->geometry();
    d1_videoWidget->setGeometry(tmp_geometry.x(),
                                tmp_geometry.y() + topMargins,
                                tmp_geometry.width(),
                                tmp_geometry.height() - topMargins - buttonMargins);

    d1_videoWidget->show();
}

void d1_MainWindow::closeVideo()
{
    d1_videoWidget->hide();
}

void d1_MainWindow::showPaymentType()
{
	ui->d1_stackedWidget->setCurrentIndex(2);
}

void d1_MainWindow::showPaymentCash()
{
	ui->d1_stackedWidget->setCurrentIndex(4);
}

void d1_MainWindow::showPaymentCredit()
{
    ui->d1_stackedWidget->setCurrentIndex(3);
}

void d1_MainWindow::showPaymentQrCode()
{
    ui->d1_stackedWidget->setCurrentIndex(5);
}

void d1_MainWindow::showPopup()
{
	if (popupWidget == nullptr)
		return;

	QSize size_popup = QSize(p_size.width() * 0.8, p_size.height() * 0.5);

	if(popupWidget == d1_screen_11 ){
        size_popup = QSize(p_size.width() * 0.8, p_size.height() * 0.7);
	}


    QPoint point = QPoint(p_size.width() / 2 - size_popup.width() / 2,
                          p_size.height() / 2 - size_popup.height() / 2);

    qDebug() << point;
//    QRect tmp_geometry = this->geometry();
//    popupWidget->setGeometry(tmp_geometry.x() + point.x(),
//                             tmp_geometry.y() + point.y(),
//                             size_popup.width(),
//                             size_popup.height());


    popupWidget->setGeometry(point.x(),
                             point.y(),
                             size_popup.width(), size_popup.height());


    // костыль для правельного отображения Popup (модального окна) в fullScreen
    ui->d1_centralwidget->setEnabled(false);
    popupWidget->show();

	// Включение небольшой прозрачности
	popupWidget->setGraphicsEffect(effectOpacity);
	popupWidget->graphicsEffect()->setEnabled(true);


	// Включение размытия основного меню
	ui->d1_centralwidget->setGraphicsEffect(effectBlure);
	ui->d1_centralwidget->graphicsEffect()->setEnabled(true);
}

void d1_MainWindow::setProductCount(int count)
{
	if (count == 8) {
		topMargins    = 30;
		buttonMargins = 60;
		d1_screen_1->showVideo(true);
		//p_Screen_1->setVideo(p_Screen_0);
	}

	if (count == 12) {
		topMargins    = 30;
		buttonMargins = 110;

		d1_screen_1->showVideo(false);
        showVideo();
		//video = p_Screen_0;
	}

	if (count == 21) {
		topMargins    = 0;
		buttonMargins = 0;
		d1_screen_1->showVideo(false);
        showVideo();
	}

	createProduct(count);
	d1_screen_1->addProducts(p_products);
    ui->d1_centerLayout->setContentsMargins(0, topMargins, 0, buttonMargins);
}

void d1_MainWindow::showThanks()
{
    popupWidget = d1_screen_10;
    showPopup();
}

void d1_MainWindow::showOutToy()
{
    popupWidget = d1_screen_8;
    showPopup();
}

void d1_MainWindow::showRefund()
{
    popupWidget = d1_screen_9;
    showPopup();
}

void d1_MainWindow::showFeedBack()
{
    popupWidget = d1_screen_11;
    showPopup();
}

void d1_MainWindow::setShowCash(bool is_show)
{
    d1_screen_3->setShowCash(is_show);
}

void d1_MainWindow::setShowCredit(bool is_show)
{
    d1_screen_3->setShowCredit(is_show);
}

void d1_MainWindow::setShowQRPay(bool is_show)
{
    d1_screen_3->setShowQR(is_show);
}

void d1_MainWindow::setShowBill(bool is_show)
{
    d1_screen_10->setShowQR(is_show);
}


void d1_MainWindow::createMenu()
{
	QToolButton *display = new QToolButton(this);
	display->setText("Display resolution");
	display->setPopupMode(QToolButton::InstantPopup);

	QMenu *displayMenu = new QMenu(display);

	QAction *WXGAAction = new QAction("768x1366", this);
	QAction *HDAction   = new QAction("900x1600", this);
	QAction *FHDAction  = new QAction("1080x1920", this);

	connect(WXGAAction, &QAction::triggered, [=]() { resizeWidget(WXGA); });
	connect(HDAction, &QAction::triggered, [=]() { resizeWidget(HD); });
	connect(FHDAction, &QAction::triggered, [=]() { resizeWidget(FHD); });

	displayMenu->addAction(WXGAAction);
	displayMenu->addAction(HDAction);
	displayMenu->addAction(FHDAction);
	display->setMenu(displayMenu);


	//ui->toolBar->addWidget(display);
	display->hide();

	// Отладка кнопок
	QToolButton *product = new QToolButton(this);
	product->setText("Button count");
	product->setPopupMode(QToolButton::InstantPopup);

	QMenu *productMenu = new QMenu(product);

	QAction *button_8_Action  = new QAction("Button 8", this);
	QAction *button_12_Action = new QAction("Button 12", this);
	QAction *button_21_Action = new QAction("Button 21", this);

	connect(button_8_Action, &QAction::triggered, [=]() { setProductCount(8); });
	connect(button_12_Action, &QAction::triggered, [=]() { setProductCount(12); });
	connect(button_21_Action, &QAction::triggered, [=]() { setProductCount(21); });

	productMenu->addAction(button_8_Action);
	productMenu->addAction(button_12_Action);
	productMenu->addAction(button_21_Action);
	product->setMenu(productMenu);

	ui->toolBar->addWidget(product);

	// Отладка Popups
	QToolButton *popups = new QToolButton(this);
	popups->setText("Popups");
	popups->setPopupMode(QToolButton::InstantPopup);

	QMenu *popupsMenu = new QMenu(popups);

	QAction *Action_1 = new QAction("Выдача игрушки игрушка", this);
	QAction *Action_2 = new QAction("Возможно товар закончился", this);
    QAction *Action_3 = new QAction("Спасибо за покупку", this);
    QAction *Action_4 = new QAction("Отзыв", this);


	connect(Action_1, &QAction::triggered, [=]() {
		popupWidget = d1_screen_7;
		showPopup();
	});

	connect(Action_2, &QAction::triggered, [=]() {
        showOutToy();
	});


    connect(Action_3, &QAction::triggered, [=]() {
        showThanks();
	});

    connect(Action_4, &QAction::triggered, [=]() {
        showFeedBack();
	});

	popupsMenu->addAction(Action_1);
	popupsMenu->addAction(Action_2);
	popupsMenu->addAction(Action_3);
	popupsMenu->addAction(Action_4);
	popups->setMenu(popupsMenu);

	ui->toolBar->addWidget(popups);

	ui->toolBar->show();
}

void d1_MainWindow::createProduct(int count)
{
	p_products.clear();

	for (int i = 0; i < count; i++) {
		Product newProduct;
		newProduct.id    = i;
		newProduct.price = QString("%0 руб").arg(i * 10 + 10);
		newProduct.name  = "Заводные робокары";
		newProduct.fullName = "Заводные робокары: \n ОЧЕНЬ КЛАССНЫЕ ЧЕС";

		newProduct.stat = static_cast<Stat>(i % 5);

			newProduct.pathImage.push_back(QString(":/d1_hare.png"));
			newProduct.pathImage.push_back(QString(":/d1_boy.png"));
			newProduct.pathImage.push_back(QString(":/d1_ball.png"));
			newProduct.pathImage.push_back(QString(":/d1_girl.png"));

			newProduct.pathVideo = QString(":/desing2/video/productVideo.png");
			newProduct.description = QString("Slime - это необыкновенный лизун,\n"
											 "наделенный суперсилой,\n"
											 "пластичностью и эластичностью.\n"
											 "Из него можно выдувать пузыри\n"
											 "используя трубочки из набора.");


			p_products.push_back(newProduct);
		}
}

void d1_MainWindow::resizeWidget(DisplayResolution display)
{

	QSize resolution = QSize(1080, 1920);
	switch (display) {
	case WXGA: {
		resolution = QSize(768, 1366);
	} break;

	case HD: {
		resolution = QSize(900, 1600);
	}
	break;

	case FHD: {
		resolution = QSize(1080, 1920);
	}
	break;

	default:
		break;
	}


	//this->resize(resolution);

	p_size         = resolution;
	QRect geometry = QApplication::desktop()->screenGeometry(1);
	this->setGeometry(geometry.x(), geometry.y(), resolution.width(), resolution.height());

}

