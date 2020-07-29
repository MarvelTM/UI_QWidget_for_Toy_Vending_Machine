#ifndef SCREEN_10_H
#define SCREEN_10_H

#include <QWidget>

namespace Ui {
class Screen_10;
}

class Screen_10 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_10(QWidget *parent = nullptr);
	~Screen_10();

public slots:
	void setShowQR(bool is_show);

private:
	Ui::Screen_10 *ui;
	void resizeEvent(QResizeEvent *event);

signals:
	void pressedButtonClose();

//	// QWidget interface
//protected:
//	void closeEvent(QCloseEvent *event);
};

#endif // SCREEN_10_H
