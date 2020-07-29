#ifndef SCREEN_11_H
#define SCREEN_11_H

#include <QWidget>

namespace Ui {
class Screen_11;
}

class Screen_11 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_11(QWidget *parent = nullptr);
	~Screen_11();
	void setVideo(QString path);

private:
	Ui::Screen_11 *ui;

signals:
	void pressedButtonClose();

	// QWidget interface
protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // SCREEN_11_H
