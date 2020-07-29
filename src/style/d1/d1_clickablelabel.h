#ifndef D1_CLICKABLELABEL_H
#define D1_CLICKABLELABEL_H

#include <QLabel>

class d1_ClickableLabel : public QLabel {
	Q_OBJECT

public:
	explicit d1_ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~d1_ClickableLabel();

signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);

};

#endif // D1_CLICKABLELABEL_H
