#include "ui/include/card_widget.h"

#include <QPainter>
#include <QtSvg/QSvgRenderer>

CardWidget::CardWidget(QWidget *parent, const QString& name, int no): QWidget(parent), no_(no) {
    this->setStyleSheet("background-color:rgb(200,200,200);");
    this->show_name_ = new QLabel{QString{name}, this};
    this->show_name_->setGeometry(10, 50, 80, 20);
    this->show_name_->setAttribute(Qt::WA_TranslucentBackground);
    this->show_name_->show();

    this->default_color_ = QColor{220, 220, 220};
    this->click_color_ = this->default_color_;

    this->icon_ = nullptr;
    this->active_ = 0;
}

CardWidget::~CardWidget() {

}

void CardWidget::paintEvent(QPaintEvent *event) { // 绘制圆角
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 反锯齿
    if (this->active_ == 0) {
        painter.setBrush(QBrush{this->default_color_});
    } else {
        painter.setBrush(QBrush{this->click_color_});
    }
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);
    QWidget::paintEvent(event);
}

void CardWidget::mouseReleaseEvent(QMouseEvent *event) {
//    QWidget::mouseReleaseEvent(event);
    qDebug() << "card: " << this->show_name_->text() << " clicked.";
    this->active_ = 1;
    this->RefershColor();
    emit this->clicked(this->no_);
}

void CardWidget::SetIcon(const QString& icon_path) {
    delete this->icon_;
    this->icon_ = new QLabel{this};
    this->icon_->setGeometry(10, 10, 30, 30);
    QPixmap pixmap{icon_path};
    this->icon_->setPixmap(pixmap.scaled(25, 25));

    this->icon_->setAttribute(Qt::WA_TranslucentBackground);
    this->icon_->show();
}

void CardWidget::SetColorWhenClicked(const QColor& color) {
    this->click_color_ = color;
}

void CardWidget::RefershColor() {
    QWidget::update();
}

void CardWidget::SetDefaultClick() {
    this->active_ = 1;
    this->RefershColor();
}

void CardWidget::ChangeToDefaultColor() {
    active_ = 0;
    this->RefershColor();
}
