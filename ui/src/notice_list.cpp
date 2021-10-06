#include <QPainter>
#include "ui/include/notice_list.h"

NoticeList::NoticeList(QWidget* parent): QWidget(parent)
{
    this->today_card_ = new CardWidget{this, "Today", 0}; // 0 signal no
    this->today_card_->setGeometry(10, 10, 130, 80);
    this->today_card_->SetColorWhenClicked(QColor{135, 135, 190});
    this->today_card_->SetDefaultClick();
    this->today_card_->SetIcon("./res/icon/calendar.svg");
    this->today_card_->show();

    this->schedule_card_ = new CardWidget{this, "Schedule", 1}; // 1 signal no
    this->schedule_card_->setGeometry(150, 10, 130, 80);
    this->schedule_card_->SetColorWhenClicked(QColor{190, 135, 135});
    this->schedule_card_->SetIcon("./res/icon/calendar_red.svg");
    this->schedule_card_->show();

    this->card_map_[0] = this->today_card_;
    this->card_map_[1] = this->schedule_card_;
    this->RegisterHandler();
}

NoticeList::~NoticeList() {

}

void NoticeList::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter{this};
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor{230, 230, 230});
    painter.drawRect(this->rect());
}

void NoticeList::SendSignal(int n) {
    auto iter = this->card_map_.begin();
    while (iter != this->card_map_.end()) {
        if (iter.key() != n) {
            iter.value()->ChangeToDefaultColor();
        }
        iter++;
    }
    emit change(n);
}

void NoticeList::RegisterHandler() {
    connect(this->today_card_, SIGNAL(clicked(int)), this, SLOT(SendSignal(int)));
    connect(this->schedule_card_, SIGNAL(clicked(int)), this, SLOT(SendSignal(int)));
}

void NoticeList::ChangeWindow(int n) {
    emit change(1);
}
