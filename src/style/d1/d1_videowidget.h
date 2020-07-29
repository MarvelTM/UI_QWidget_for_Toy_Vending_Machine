#ifndef D1_VIDEOWIDGET_H
#define D1_VIDEOWIDGET_H

#include <QWidget>

namespace Ui {
class d1_VideoWidget;
}

class d1_VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit d1_VideoWidget(QWidget *parent = 0);
    ~d1_VideoWidget();

signals:
    void pressedButtonClose();

private:
    Ui::d1_VideoWidget *ui;
    void resizeEvent(QResizeEvent *event);
};

#endif // D1_VIDEOWIDGET_H
