#include <QMenu>
#include <QToolButton>

#include "interface.h"
#include "ui_interface.h"

#include "settings.h"

#include <QDebug>
#include <QFontDatabase>

Interface::Interface(QWidget *parent) : QMainWindow(parent), ui(new Ui::Interface) {
    ui->setupUi(this);

    int id = QFontDatabase::addApplicationFont(":/desing2/fonts/PT Sans/PT_Sans.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    mainWindow = new d2_MainWindow;

    QWidget *widget = dynamic_cast<QWidget *>(mainWindow);
    ui->centralLayout->addWidget(widget);
    mainWindow->setProductCount(12);

    ui->toolBar->hide();

    // инициализация панели инструментов для отладки
    initToolBar();

    this->start(DisplayResolution::WXGA);
}

Interface::~Interface() { delete ui; }

void Interface::start(DisplayResolution display) {
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

    QRect geometry = QApplication::desktop()->screenGeometry(1);
    this->setGeometry(geometry.x(), geometry.y(), resolution.width(), resolution.height());
    this->show();
}

void Interface::initToolBar() {
    //    для d1 работает не коректно

    //  Отладка разрешения
    //    QToolButton *display = new QToolButton(this);
    //    display->setText("Display resolution");
    //    display->setPopupMode(QToolButton::InstantPopup);

    //    QMenu *displayMenu = new QMenu(display);

    //    QAction *WXGAAction = new QAction("768x1366", this);
    //    QAction *HDAction   = new QAction("900x1600", this);
    //    QAction *FHDAction  = new QAction("1080x1920", this);

    //    connect(WXGAAction, &QAction::triggered, [=]() { resizeWidget(WXGA); });
    //    connect(HDAction, &QAction::triggered, [=]() { resizeWidget(HD); });
    //    connect(FHDAction, &QAction::triggered, [=]() { resizeWidget(FHD); });

    //    displayMenu->addAction(WXGAAction);
    //    displayMenu->addAction(HDAction);
    //    displayMenu->addAction(FHDAction);
    //    display->setMenu(displayMenu);

    //    ui->toolBar->addWidget(display);
    //   ui->toolBar->show();

    // Отладка кнопок
    QToolButton *product = new QToolButton(this);
    product->setText("Button count");
    product->setPopupMode(QToolButton::InstantPopup);

    QMenu *productMenu = new QMenu(product);

    QAction *button_8_Action = new QAction("Button 8", this);
    QAction *button_12_Action = new QAction("Button 12", this);
    QAction *button_21_Action = new QAction("Button 21", this);

    connect(button_8_Action, &QAction::triggered, [=]() { mainWindow->setProductCount(8); });
    connect(button_12_Action, &QAction::triggered, [=]() { mainWindow->setProductCount(12); });
    connect(button_21_Action, &QAction::triggered, [=]() { mainWindow->setProductCount(21); });

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

    QAction *Action_1 = new QAction("Закончилась игрушка / К сожелению не удалось выдать игрушку", this);
    QAction *Action_2 = new QAction("Спасибо", this);
    QAction *Action_3 = new QAction("Возврат денежных средств", this);
    QAction *Action_4 = new QAction("Отзыв", this);

    connect(Action_1, &QAction::triggered, [=]() { mainWindow->showOutToy(); });
    connect(Action_2, &QAction::triggered, [=]() { mainWindow->showThanks(); });
    connect(Action_3, &QAction::triggered, [=]() { mainWindow->showRefund(); });
    connect(Action_4, &QAction::triggered, [=]() { mainWindow->showFeedBack(); });

    popupsMenu->addAction(Action_1);
    popupsMenu->addAction(Action_2);
    popupsMenu->addAction(Action_3);
    popupsMenu->addAction(Action_4);
    popupsTB->setMenu(popupsMenu);

    ui->toolBar->addWidget(popupsTB);

    // отображения способа оплаты
    QToolButton *selectionPay = new QToolButton(this);
    selectionPay->setText("Настройки отображения элементов");
    selectionPay->setPopupMode(QToolButton::InstantPopup);

    QMenu *selectionPayMenu = new QMenu(selectionPay);

    QAction *Action_Cash = new QAction("Наличные", this);
    QAction *Action_Credit = new QAction("Картой", this);
    QAction *Action_QRPay = new QAction("Оплата QR code ", this);

    QAction *Action_QRBill = new QAction("Чек QR code ", this);

    //    QAction *Action_btnCoins     = new QAction("Монеты ", this);
    //    QAction *Action_btnPhine     = new QAction("Телефон ", this);
    //    QAction *Action_btnDiscount     = new QAction("Акции ", this);

    connect(Action_Cash, &QAction::toggled, [=](bool is_show) { mainWindow->setShowCash(is_show); });
    connect(Action_Credit, &QAction::toggled, [=](bool is_show) { mainWindow->setShowCredit(is_show); });
    connect(Action_QRPay, &QAction::toggled, [=](bool is_show) { mainWindow->setShowQRPay(is_show); });

    connect(Action_QRBill, &QAction::toggled, [=](bool is_show) { mainWindow->setShowBill(is_show); });

    //    connect(Action_btnCoins, &QAction::toggled, p_Screen_1, &Screen_1::setShowCoins);
    //    connect(Action_btnPhine, &QAction::toggled, p_Screen_1, &Screen_1::setShowPhone);
    //    connect(Action_btnDiscount, &QAction::toggled, p_Screen_1, &Screen_1::setShowDiscount);

    Action_Cash->setCheckable(true);
    Action_Credit->setCheckable(true);
    Action_QRPay->setCheckable(true);

    Action_QRBill->setCheckable(true);

    //    Action_btnCoins->setCheckable(true);
    //    Action_btnPhine->setCheckable(true);
    //    Action_btnDiscount->setCheckable(true);

    Action_Cash->setChecked(true);
    Action_Credit->setChecked(true);
    Action_QRPay->setChecked(true);

    Action_QRBill->setChecked(true);

    //    Action_btnCoins->setChecked(true);
    //    Action_btnPhine->setChecked(true);
    //    Action_btnDiscount->setChecked(true);

    selectionPayMenu->addAction(Action_Cash);
    selectionPayMenu->addAction(Action_Credit);
    selectionPayMenu->addAction(Action_QRPay);

    selectionPayMenu->addSeparator();
    selectionPayMenu->addAction(Action_QRBill);
    selectionPayMenu->addSeparator();

    //    selectionPayMenu->addAction(Action_btnCoins);
    //    selectionPayMenu->addAction(Action_btnPhine);
    //    selectionPayMenu->addAction(Action_btnDiscount);

    selectionPay->setMenu(selectionPayMenu);

    ui->toolBar->addWidget(selectionPay);
    ui->toolBar->show();
}
