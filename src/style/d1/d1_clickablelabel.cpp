#include "d1_clickablelabel.h"

d1_ClickableLabel::d1_ClickableLabel(QWidget* parent, Qt::WindowFlags f)
	: QLabel(parent) {

}

d1_ClickableLabel::~d1_ClickableLabel() {}

void d1_ClickableLabel::mousePressEvent(QMouseEvent* event) {
	emit clicked();
}
