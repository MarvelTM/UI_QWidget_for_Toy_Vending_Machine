#include "d2_mainwindow.h"
#include "ui_d2_mainwindow.h"

#include <QFile>

#include <QDebug>

#include <QAction>
#include <QMenu>

#include <QResizeEvent>
#include <QToolButton>

void d2_MainWindow::showOutToy() {
    popupWidget = d2_screen_9;
    showPopups();
}

void d2_MainWindow::showRefund() {
    popupWidget = d2_screen_12;
    showPopups();
}

void d2_MainWindow::createMenu() {
    QToolButton *product = new QToolButton(this);
    product->setText("Button count");
    product->setPopupMode(QToolButton::InstantPopup);

    QMenu *productMenu = new QMenu(product);

    QAction *button_8_Action = new QAction("Button 8", this);
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
    QToolButton *popupsTB = new QToolButton(this);
    popupsTB->setText("Popups");
    popupsTB->setPopupMode(QToolButton::InstantPopup);

    QMenu *popupsMenu = new QMenu(popupsTB);

    QAction *Action_1 = new QAction("Закончилась игрушка", this);
    QAction *Action_2 = new QAction("Спасибо", this);
    QAction *Action_3 = new QAction("Возврат денежных средств", this);
    QAction *Action_4 = new QAction("Отзыв", this);

    connect(Action_1, &QAction::triggered, [=]() { showOutToy(); });

    connect(Action_2, &QAction::triggered, [=]() { showThanks(); });

    connect(Action_3, &QAction::triggered, [=]() { showRefund(); });

    connect(Action_4, &QAction::triggered, [=]() { showFeedBack(); });

    popupsMenu->addAction(Action_1);
    popupsMenu->addAction(Action_2);
    popupsMenu->addAction(Action_3);
    popupsMenu->addAction(Action_4);
    popupsTB->setMenu(popupsMenu);

    ui->toolBar->addWidget(popupsTB);

    // ui->toolBar->hide();

    // отображения способа оплаты
    QToolButton *selectionPay = new QToolButton(this);
    selectionPay->setText("Настройки отображения элементов");
    selectionPay->setPopupMode(QToolButton::InstantPopup);

    QMenu *selectionPayMenu = new QMenu(selectionPay);

    QAction *Action_Cash = new QAction("Наличные", this);
    QAction *Action_Credit = new QAction("Картой", this);
    QAction *Action_QRPay = new QAction("Оплата QR code ", this);

    QAction *Action_QRBill = new QAction("Чек QR code ", this);

    QAction *Action_btnCoins = new QAction("Монеты ", this);
    QAction *Action_btnPhine = new QAction("Телефон ", this);
    QAction *Action_btnDiscount = new QAction("Акции ", this);

    connect(Action_Cash, &QAction::toggled, d2_screen_3, &Screen_3::setShowCash);
    connect(Action_Credit, &QAction::toggled, d2_screen_3, &Screen_3::setShowCredit);
    connect(Action_QRPay, &QAction::toggled, d2_screen_3, &Screen_3::setShowQR);

    connect(Action_QRBill, &QAction::toggled, d2_screen_10, &Screen_10::setShowQR);

    connect(Action_btnCoins, &QAction::toggled, d2_screen_1, &Screen_1::setShowCoins);
    connect(Action_btnDiscount, &QAction::toggled, d2_screen_1, &Screen_1::setShowDiscount);

    Action_Cash->setCheckable(true);
    Action_Credit->setCheckable(true);
    Action_QRPay->setCheckable(true);

    Action_QRBill->setCheckable(true);

    Action_btnCoins->setCheckable(true);
    Action_btnPhine->setCheckable(true);
    Action_btnDiscount->setCheckable(true);

    Action_Cash->setChecked(true);
    Action_Credit->setChecked(true);
    Action_QRPay->setChecked(true);

    Action_QRBill->setChecked(true);

    Action_btnCoins->setChecked(true);
    Action_btnPhine->setChecked(true);
    Action_btnDiscount->setChecked(true);

    selectionPayMenu->addAction(Action_Cash);
    selectionPayMenu->addAction(Action_Credit);
    selectionPayMenu->addAction(Action_QRPay);

    selectionPayMenu->addSeparator();
    selectionPayMenu->addAction(Action_QRBill);
    selectionPayMenu->addSeparator();

    selectionPayMenu->addAction(Action_btnCoins);
    selectionPayMenu->addAction(Action_btnPhine);
    selectionPayMenu->addAction(Action_btnDiscount);

    selectionPay->setMenu(selectionPayMenu);

    ui->toolBar->addWidget(selectionPay);
}

d2_MainWindow::d2_MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::d2_MainWindow) {
    ui->setupUi(this);
    p_currentProductId = -1;

    popupWidget = nullptr;
    videoWidget = nullptr;

    // Различные эффекты для отображения
    effectBlure = new QGraphicsBlurEffect;
    effectBlure->setBlurRadius(10);

    effectOpacity = new QGraphicsOpacityEffect;
    effectOpacity->setOpacity(0.9);

    ui->d2_lblMoneyInfo->setText("Внесено: 0 Руб");
    ui->d2_lblCallInfo->setText("По любым вопросам звоните: 8 800-000-00 (бесплатно 24/7)");

    d2_screen_0 = new Screen_0(this);

    d2_screen_1 = new Screen_1(this);
    d2_screen_2 = new Screen_2(this);
    d2_screen_3 = new Screen_3(this);

    d2_screen_4 = new Screen_4(this);
    d2_screen_5 = new Screen_5(this);
    d2_screen_6 = new Screen_6(this);
    d2_screen_7 = new Screen_7(this);
    d2_screen_8 = new Screen_8(this);
    d2_screen_9 = new Screen_9(this);
    d2_screen_10 = new Screen_10(this);
    d2_screen_11 = new Screen_11(this);
    d2_screen_12 = new Screen_12(this);
    d2_screen_13 = new Screen_13(this);
    d2_screen_14 = new Screen_14(this);

    ui->stackedWidget->addWidget(d2_screen_1);
    ui->stackedWidget->addWidget(d2_screen_2);
    ui->stackedWidget->addWidget(d2_screen_3);
    ui->stackedWidget->addWidget(d2_screen_4);
    ui->stackedWidget->addWidget(d2_screen_5);
    ui->stackedWidget->addWidget(d2_screen_6);
    ui->stackedWidget->addWidget(d2_screen_7);
    ui->stackedWidget->addWidget(d2_screen_8);
    ui->stackedWidget->addWidget(d2_screen_14);

    // Video Screen
    // p_Screen_0->hide(); // main

    // Popups()
    d2_screen_9->hide();
    d2_screen_10->hide();
    d2_screen_11->hide();
    d2_screen_12->hide();
    d2_screen_13->hide();

    ui->stackedWidget->setCurrentIndex(0);

    // popups = p_Screen_10;
    // showPopups();

    connect(d2_screen_0, &Screen_0::closeVideo, [=]() {
        closeVideo();
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(d2_screen_1, &Screen_1::pressedButtonProduct, this, &d2_MainWindow::showProductInfo);

    connect(d2_screen_2, &Screen_2::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(0); });

    connect(d2_screen_2, &Screen_2::pressedButtonBuy, this, &d2_MainWindow::showBuyInfo);
    connect(d2_screen_2, &Screen_2::pressedButtonPlayVideo, this, &d2_MainWindow::showVideoProduct);

    connect(d2_screen_3, &Screen_3::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(1); });

    connect(d2_screen_3, &Screen_3::pressedButtonCash, [=]() { ui->stackedWidget->setCurrentIndex(3); });

    // TODO необходимо уточнить стиль и текст
    connect(d2_screen_3, &Screen_3::pressedButtonCredit, [=]() { ui->stackedWidget->setCurrentIndex(4); });
    connect(d2_screen_3, &Screen_3::pressedButtonQrCode, [=]() { ui->stackedWidget->setCurrentIndex(8); });

    connect(d2_screen_4, &Screen_4::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(2); });

    connect(d2_screen_4, &Screen_4::pressedButtonPay, [=]() { ui->stackedWidget->setCurrentIndex(5); });

    connect(d2_screen_5, &Screen_5::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(2); });

    connect(d2_screen_6, &Screen_6::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(3); });
    connect(d2_screen_6, &Screen_6::pressedButtonTakeCoins, this, &d2_MainWindow::takeCoins);
    connect(d2_screen_6, &Screen_6::pressedButtonSendPhone, [=]() { ui->stackedWidget->setCurrentIndex(7); });

    connect(d2_screen_7, &Screen_7::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(5); });

    connect(d2_screen_8, &Screen_8::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(5); });

    connect(d2_screen_14, &Screen_14::pressedButtonBack, [=]() { ui->stackedWidget->setCurrentIndex(2); });

    connect(d2_screen_9, &Screen_9::pressedButtonClose, this, &d2_MainWindow::closePopups);
    connect(d2_screen_10, &Screen_10::pressedButtonClose, this, &d2_MainWindow::closePopups);
    connect(d2_screen_12, &Screen_12::pressedButtonClose, this, &d2_MainWindow::closePopups);
    connect(d2_screen_13, &Screen_13::pressedButtonClose, this, &d2_MainWindow::closePopups);

    connect(d2_screen_11, &Screen_11::pressedButtonClose, this, &d2_MainWindow::closeVideo);

    ui->toolBar->hide();
    // Отладка кнопок
    // createMenu();
}

d2_MainWindow::~d2_MainWindow() { delete ui; }

void d2_MainWindow::showPopups() {
    if (popupWidget == nullptr) return;

    QSize size_popup = QSize(p_size.width() * 0.8, p_size.height() * 0.7);

    // if(popupWidget == d1_screen_11 ){
    //    size_popup = QSize(p_size.width() * 0.8, p_size.height() * 0.7);
    // }

    QPoint point = QPoint(p_size.width() / 2 - size_popup.width() / 2, p_size.height() / 2 - size_popup.height() / 2);

    //    QRect tmp_geometry = this->geometry();
    //    popupWidget->setGeometry(tmp_geometry.x() + point.x(),
    //                             tmp_geometry.y() + point.y(),
    //                             size_popup.width(),
    //                             size_popup.height());

    popupWidget->setGeometry(point.x(), point.y(), size_popup.width(), size_popup.height());

    // костыль для правельного отображения Popup (модального окна) в fullScreen
    ui->d2_centralwidget->setEnabled(false);
    popupWidget->show();

    // Включение небольшой прозрачности
    popupWidget->setGraphicsEffect(effectOpacity);
    popupWidget->graphicsEffect()->setEnabled(true);

    // Включение размытия основного меню
    ui->d2_centralwidget->setGraphicsEffect(effectBlure);
    ui->d2_centralwidget->graphicsEffect()->setEnabled(true);
}

void d2_MainWindow::showVideo() {
    if (videoWidget == nullptr) return;

    // QRect tmp_geometry = ui->d2_centralwidget->geometry();
    videoWidget->setGeometry(0, 0 + topMargins, p_size.width(), p_size.height() - topMargins - buttonMargins);

    videoWidget->show();
    qDebug() << "show" << videoWidget->geometry() << p_size;
}

void d2_MainWindow::resizeWidget(DisplayResolution display) {
    QSize resolution = QSize(1080, 1920);
    switch (display) {
        case WXGA: {
            resolution = QSize(768, 1366);
        } break;

        case HD: {
            resolution = QSize(900, 1600);
        } break;

        case FHD: {
            resolution = QSize(1080, 1920);
        } break;

        default:
            break;
    }

    p_size = resolution;
    QRect geometry = QApplication::desktop()->screenGeometry(1);
    this->setGeometry(geometry.x(), geometry.y(), resolution.width(), resolution.height());
}

void d2_MainWindow::setProductCount(int count) {
    if (count == 8) {
        topMargins = 30;
        buttonMargins = 60;
        d2_screen_1->showWideo(true);
        d2_screen_1->setVideo(d2_screen_0);
    }

    if (count == 12) {
        topMargins = 30;
        buttonMargins = 110;

        d2_screen_1->showWideo(false);
        videoWidget = d2_screen_0;
        showVideo();
    }

    if (count == 21) {
        topMargins = 0;
        buttonMargins = 0;

        d2_screen_1->showWideo(false);
        showVideo();
    }

    p_products.clear();

    for (int i = 0; i < count; i++) {
        d2::Product newProduct;
        newProduct.id = i;
        newProduct.price = QString("40 руб");
        newProduct.name = "Slime Ninja";
        newProduct.fullName = "Slime Ninja: \n желтый и красный";
        newProduct.stat = static_cast<d2::Stat>(i % 5);
        newProduct.pathImage.push_back(QString(":/desing2/toy/Slime_ninja.png"));
        newProduct.pathImage.push_back(QString(":/desing2/toy/Slime_ninja.png"));
        newProduct.pathVideo = QString(":/desing2/video/productVideo.png");
        newProduct.description = QString(
            "Slime - это необыкновенный лизун,\n"
            "наделенный суперсилой,\n"
            "пластичностью и эластичностью.\n"
            "Из него можно выдувать пузыри\n"
            "используя трубочки из набора.");

        p_products.push_back(newProduct);
    }

    d2_screen_1->addProducts(p_products);
    ui->d2_centerLayout->setContentsMargins(0, topMargins, 0, buttonMargins);
}

void d2_MainWindow::showThanks() {
    popupWidget = d2_screen_10;
    showPopups();
}

void d2_MainWindow::showFeedBack() {
    popupWidget = d2_screen_13;
    showPopups();
}

void d2_MainWindow::setShowCash(bool is_show) { d2_screen_3->setShowCash(is_show); }

void d2_MainWindow::setShowCredit(bool is_show) { d2_screen_3->setShowCredit(is_show); }

void d2_MainWindow::setShowQRPay(bool is_show) { d2_screen_3->setShowQR(is_show); }

void d2_MainWindow::setShowBill(bool is_show) { d2_screen_10->setShowQR(is_show); }

void d2_MainWindow::showProductInfo(int id) {
    p_currentProductId = id;
    d2_screen_2->setProduct(p_products[id]);
    ui->stackedWidget->setCurrentIndex(1);
}

void d2_MainWindow::showBuyInfo() {
    if (p_currentProductId == -1) return;
    ui->stackedWidget->setCurrentIndex(2);
}

void d2_MainWindow::takeCoins() {
    bool errorTakeCoins = true;
    if (errorTakeCoins) ui->stackedWidget->setCurrentIndex(6);
}

void d2_MainWindow::closePopups() {
    if (popupWidget == nullptr) return;

    popupWidget->hide();
    // костыль для правельного отображения Popup (модального окна) в fullScreen
    ui->d2_centralwidget->setEnabled(true);

    popupWidget = nullptr;
    ui->d2_centralwidget->graphicsEffect()->setEnabled(false);
}

void d2_MainWindow::closeVideo() {
    if (videoWidget == nullptr) return;
    videoWidget->hide();
    videoWidget = nullptr;
}

void d2_MainWindow::showVideoProduct() {
    d2_screen_11->setVideo(p_products[p_currentProductId].pathVideo);
    videoWidget = d2_screen_11;
    showVideo();
}

void d2_MainWindow::resizeEvent(QResizeEvent *event) {
    QSizeF size = event->size();
    p_size = size;

    QPointF scaled = QPointF(size.width() / 1040.0, size.height() / 1560.0);

    // изменение размера шрифта
    QFont font = ui->d2_lblCallInfo->font();
    font.setLetterSpacing(QFont::PercentageSpacing, 110.0);
    font.setPointSize(17 * scaled.y());
    ui->d2_lblCallInfo->setFont(font);

    font = ui->d2_lblMoneyInfo->font();
    font.setLetterSpacing(QFont::PercentageSpacing, 110.0);
    font.setPointSize(30 * scaled.y());
    ui->d2_lblMoneyInfo->setFont(font);

    ui->d2_lblCallInfo->setFixedSize(1000 * scaled.x(), 54 * scaled.y());
    ui->d2_lblMoneyInfo->setFixedSize(1000 * scaled.x(), 70 * scaled.y());

    //	// popups
    //	if (popups != nullptr){

    //	QRect geometry = this->geometry();

    //	qDebug() << "test" << geometry;
    //	QPoint center  = geometry.center();

    //	geometry.setWidth(event->size().width() * 0.8);
    //	geometry.setHeight(event->size().height() * 0.5);
    //	geometry.moveCenter(center);

    //	popups->setGeometry(geometry);
    //	}

    //	// Video
    if (videoWidget != nullptr) {
        showVideo();
    }
    //		QRect geometry(0, topMargins, event->size().width(), event->size().height() - buttonMargins);
    //		video->setGeometry(geometry);
    //		video->show();
    //	}
}
