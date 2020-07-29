#ifndef D1_MAINWINDOW_H
#define D1_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsEffect>

#include "d1_screen_1.h"
#include "d1_screen_2.h"
#include "d1_screen_3.h"
#include "d1_screen_4.h"
#include "d1_screen_5.h"
#include "d1_screen_6.h"

#include "d1_screen_7.h"
#include "d1_screen_8.h"
#include "d1_screen_9.h"
#include "d1_screen_10.h"
#include "d1_screen_11.h"

#include "d1_videowidget.h"

#include "../../mainwindow.h"
#include "../../settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class d1_MainWindow; }
QT_END_NAMESPACE

class d1_MainWindow : public QMainWindow, public MainWindow
{
	Q_OBJECT

public:
	d1_MainWindow(QWidget *parent = nullptr);
	~d1_MainWindow();

	void start(DisplayResolution displayResolution);
	void setProductCount(int count);

    // MainWindow interface
public:
    void showThanks();
    void showOutToy();
    void showRefund();
    void showFeedBack();

    void setShowCash(bool is_show);
    void setShowCredit(bool is_show);
    void setShowQRPay(bool is_show);

    void setShowBill(bool is_show);


private:
	Ui::d1_MainWindow *ui;



	d1_Screen_1 *d1_screen_1;
	d1_Screen_2 *d1_screen_2;
	d1_Screen_3 *d1_screen_3;
	d1_Screen_4 *d1_screen_4;
	d1_Screen_5 *d1_screen_5;
    d1_Screen_6 *d1_screen_6;


	void showProductInfo(int id);
	void showPaymentType();

	void showPaymentCash();
	void showPaymentCredit();
    void showPaymentQrCode();



	// popups
	QWidget *popupWidget; //! виджет текущего popus (при отображение фон становиться размытый)

    d1_Screen_7 *d1_screen_7; //Выдача игрушки
    d1_Screen_8 *d1_screen_8; //Возможно товар закончился
    d1_Screen_9 *d1_screen_9; //Возврат на карту
    d1_Screen_10 *d1_screen_10; // Спасибо за покупку
    d1_Screen_11 *d1_screen_11; // Отзыв

    d1_VideoWidget *d1_videoWidget;




	// For testing
	void createMenu();
	void createProduct(int count);

	QSizeF p_size;

	// эффекты для экранов
	QGraphicsBlurEffect *effectBlure;
	QGraphicsOpacityEffect *effectOpacity;

	// отступы
	int topMargins;
	int buttonMargins;

	QVector<Product> p_products;
	int p_currentProductId; //! текущий идект выбранного товара;


protected:
	void resizeWidget(DisplayResolution display);
	void resizeEvent(QResizeEvent *event);

private slots:
	void showPopup();
	void closePopup();

	void showVideo();
    void closeVideo(); 

};
#endif // D1_MAINWINDOW_H
