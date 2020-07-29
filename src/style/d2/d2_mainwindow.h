#ifndef D2_MAINWINDOW_H
#define D2_MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QDesktopWidget>
#include <QGraphicsEffect>

#include "d2_screen_0.h"
#include "d2_screen_1.h"
#include "d2_screen_2.h"
#include "d2_screen_3.h"
#include "d2_screen_4.h"
#include "d2_screen_5.h"
#include "d2_screen_6.h"
#include "d2_screen_7.h"
#include "d2_screen_8.h"
#include "d2_screen_9.h"
#include "d2_screen_10.h"
#include "d2_screen_11.h"
#include "d2_screen_12.h"
#include "d2_screen_13.h"
#include "d2_screen_14.h"

#include "../../mainwindow.h"
#include "../../settings.h"

namespace Ui {
class d2_MainWindow;
}

class d2_MainWindow : public QMainWindow, public MainWindow
{
	Q_OBJECT

public:
    explicit d2_MainWindow(QWidget *parent = nullptr);
    ~d2_MainWindow();


	// Debug
    void resizeWidget(DisplayResolution display);


    void showOutToy();
    void showRefund();
    void showThanks();
    void showFeedBack();

    void setShowCash(bool is_show);
    void setShowCredit(bool is_show);
    void setShowQRPay(bool is_show);

    void setShowBill(bool is_show);

    void setProductCount(int count);

    void createMenu();

private:
    Ui::d2_MainWindow *ui;

    QWidget *popupWidget; //! виджет текущего popus (при отображение фон становиться размытый)
    QWidget *videoWidget; //! виджет текущего video (видео отображается поверх всех остальных виджетов)

    Screen_0 *d2_screen_0; //! Главный видео-экран
    Screen_1 *d2_screen_1; //! Экран с кнопками товара
    Screen_2 *d2_screen_2; //! Карточка товара
    Screen_3 *d2_screen_3; //! Выбор способа оплаты TODO добавить qr и режимы отображения
    Screen_4 *d2_screen_4; //! Оплата наличными
    Screen_5 *d2_screen_5; //! Оплата картой пусто
    Screen_6 *d2_screen_6; //! Выбор способа забора сдачи
    Screen_7 *d2_screen_7; //! Сдача закончилась
    Screen_8 *d2_screen_8; //! Сдача на телефон
    Screen_9 *d2_screen_9; //! Popups закончилась игрушка
    Screen_10 *d2_screen_10; //! Popups спасибо
    Screen_11 *d2_screen_11; //! Video выбранного продукта
    Screen_12 *d2_screen_12; //! Возврат денежных средст на карту
    Screen_13 *d2_screen_13; //! Отзыв
    Screen_14 *d2_screen_14; //! QrCode

    QVector<d2::Product> p_products;
	int p_currentProductId; //! текущий идект выбранного товара;



	// эффекты для экранов
	QGraphicsBlurEffect *effectBlure;
	QGraphicsOpacityEffect *effectOpacity;


	// отступы
	int topMargins;
	int buttonMargins;


    QSizeF p_size;

public slots:
	void showProductInfo(int id);
	void showBuyInfo();
	void takeCoins();

    void showPopups();
	void closePopups();

    void showVideo();
	void closeVideo();

	void showVideoProduct();

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);


};

#endif // MAINWINDOW_H
