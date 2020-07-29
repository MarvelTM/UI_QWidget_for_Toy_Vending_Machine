#ifndef SCREEN_0_H
#define SCREEN_0_H

#include <QWidget>

namespace Ui {
class Screen_0;
}

class Screen_0 : public QWidget
{
	Q_OBJECT

public:
	explicit Screen_0(QWidget *parent = nullptr);
	~Screen_0();

	Ui::Screen_0 *ui;

signals:
	void closeVideo();
};

#endif // SCREEN_0_H
