#ifndef d1_Screen_9_H
#define d1_Screen_9_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class d1_Screen_9;
}

class d1_Screen_9 : public QWidget
{
	Q_OBJECT

public:
    explicit d1_Screen_9(QWidget *parent = nullptr);
    ~d1_Screen_9();

private:
    Ui::d1_Screen_9 *ui;

signals:
	void pressedButtonClose();
	//void pressedButtonBack();

	// QWidget interface
protected:
	virtual void resizeEvent(QResizeEvent *event);
//	virtual void showEvent(QShowEvent *event);
};

#endif // d1_Screen_9_H
