#include "d2_screen_2.h"
#include "ui_d2_screen_2.h"

#include <QDebug>
#include <QResizeEvent>

Screen_2::Screen_2(QWidget *parent) : QWidget(parent), ui(new Ui::Screen_2) {
    ui->setupUi(this);

    connect(ui->d2_2_btnBack, &QPushButton::clicked, [=]() { emit pressedButtonBack(); });
    connect(ui->d2_2_btnBuy, &QPushButton::clicked, [=]() { emit pressedButtonBuy(); });
    connect(ui->d2_2_btnPlayVideo, &QPushButton::clicked, [=]() { emit pressedButtonPlayVideo(); });
}

Screen_2::~Screen_2() { delete ui; }

void Screen_2::setProduct(d2::Product product) {
    ui->d2_2_btnLeft->setEnabled(false);
    ui->d2_2_btnRight->setEnabled(false);

    ui->d2_2_lblNameProdct->setText(confText(product.fullName));
    ui->d2_2_lblPriceProduct->setText(confText(product.price));
    ui->d2_2_lblDescriptionProdct->setText(product.description);

    for (int i = ui->d2_2_stackedImageWidget->count() - 1; i >= 0; --i) {
        QWidget *widget = ui->d2_2_stackedImageWidget->widget(i);
        ui->d2_2_stackedImageWidget->removeWidget(widget);
        widget->deleteLater();
    }

    for (int i = 0; i < product.pathImage.count(); i++) {
        QLabel *label = new QLabel(this);
        QPixmap pix = QPixmap(product.pathImage[i]);
        label->setPixmap(pix);
        label->setScaledContents(true);

        ui->d2_2_stackedImageWidget->addWidget(label);
    }

    if (ui->d2_2_stackedImageWidget->count() > 0) {
        ui->d2_2_stackedImageWidget->setCurrentIndex(0);
        if (ui->d2_2_stackedImageWidget->count() > 1) ui->d2_2_btnRight->setEnabled(true);
    }
}

void Screen_2::on_d2_2_btnLeft_clicked() {
    if (ui->d2_2_stackedImageWidget->currentIndex() > 0) {
        ui->d2_2_btnRight->setEnabled(true);
        int index = ui->d2_2_stackedImageWidget->currentIndex();
        ui->d2_2_stackedImageWidget->setCurrentIndex(--index);
        if (ui->d2_2_stackedImageWidget->currentIndex() == 0) {
            ui->d2_2_btnLeft->setEnabled(false);
        }
    }
}

void Screen_2::on_d2_2_btnRight_clicked() {
    ui->d2_2_btnLeft->setEnabled(true);
    int index = ui->d2_2_stackedImageWidget->currentIndex();
    ui->d2_2_stackedImageWidget->setCurrentIndex(++index);

    if (ui->d2_2_stackedImageWidget->currentIndex() == ui->d2_2_stackedImageWidget->count() - 1) {
        ui->d2_2_btnRight->setEnabled(false);
    }
}

void Screen_2::resizeEvent(QResizeEvent *event) {
    QSizeF size = event->size();
    QPointF scaled = QPointF(size.width() / 1080.0, size.height() / 1920.0);

    QFont font = ui->d2_2_lblNameProdct->font();
    font.setPointSize(56 * scaled.x());
    ui->d2_2_lblNameProdct->setFont(font);

    font.setPointSize(42 * scaled.x());
    ui->d2_2_lblPriceText->setFont(font);

    font.setPointSize(62 * scaled.x());
    ui->d2_2_lblPriceProduct->setFont(font);

    font = ui->d2_2_lblDescriptionProdct->font();
    font.setPointSize(18 * scaled.x());
    ui->d2_2_lblDescriptionProdct->setFont(font);

    ui->d2_2_lblNameProdct->setFixedHeight(160 * scaled.x());
    ui->d2_2_lblPriceText->setFixedHeight(60 * scaled.x());
    ui->d2_2_lblPriceProduct->setFixedHeight(110 * scaled.x());

    QSize sizeArrow = QSize(65 * scaled.x(), 165 * scaled.y());
    ui->d2_2_btnLeft->setFixedSize(sizeArrow);
    ui->d2_2_btnRight->setFixedSize(sizeArrow);

    int sizeBtnBack = 100 * scaled.x();
    ui->d2_2_btnBack->setFixedSize(sizeBtnBack, sizeBtnBack);

    int sizeImage = 850 * scaled.y();
    ui->d2_2_stackedImageWidget->setFixedSize(0.75 * sizeImage, sizeImage);

    int sizeBtnPlay = 170 * scaled.x();
    ui->d2_2_btnPlayVideo->setFixedSize(sizeBtnPlay, sizeBtnPlay);

    ui->d2_2_btnBuy->setFixedSize(490 * scaled.x(), 215 * scaled.y());
    ui->d2_2_backgroundWidget->setContentsMargins(35 * scaled.x(), 35 * scaled.y(), 35 * scaled.x(), 70 * scaled.y());

    ui->d2_2_hlTop->setContentsMargins(0, 0, 0, 50 * scaled.y());
    ui->verticalLayout_3->setContentsMargins(50 * scaled.x(), 0, 0, 0);
}

QString Screen_2::confText(QString text) {
    QString temp = "<p style=\"line-height:%1%\">%2<p>";
    return QString(temp).arg(60).arg(text);
}
