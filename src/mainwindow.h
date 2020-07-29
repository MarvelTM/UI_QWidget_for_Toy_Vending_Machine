#ifndef MAINWINDOW
#define MAINWINDOW

class MainWindow{
public:
   virtual void showThanks() = 0;
   virtual void showFeedBack() = 0;
   virtual void showOutToy() = 0;
   virtual void showRefund() = 0;


   virtual void setShowCash(bool is_show) = 0;
   virtual void setShowCredit(bool is_show) = 0;
   virtual void setShowQRPay(bool is_show) = 0;

   virtual void setShowBill(bool is_show) = 0;

   virtual void setProductCount(int count) = 0;
};

#endif // MAINWINDOW

