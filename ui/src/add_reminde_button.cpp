#include <QPainter>
#include <QStandardItemModel>

#include "rem_utils.h"

#include "ui/include/add_reminde_button.h"
#include "ui/include/notice_view.h"

AddReminderButton::AddReminderButton(QWidget* parent): QWidget(parent)
{
//    this->resize(parent->width(), parent->height());
    this->notice_list_view_ = new QListView{this};
    this->GenNoReminbers();
    this->GenTitle();
    this->AddListItem();
}

AddReminderButton::~AddReminderButton() {

}

void AddReminderButton::mouseReleaseEvent(QMouseEvent *event) {
    emit clicked();
}

void AddReminderButton::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter{this};
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor{255, 255, 255});
    painter.drawRect(this->rect());
}

void AddReminderButton::GenNoReminbers() {
    this->no_rember_ = new QLabel{"No Rembers", this};
    QFont font;
    font.setPointSize(25);
    this->no_rember_->setFont(font);

    QPalette palette;
    palette.setColor(QPalette::WindowText,QColor{189, 189, 189});
    this->no_rember_->setPalette(palette);

    this->no_rember_->setGeometry(200, 150, 250, 250);
}

void AddReminderButton::GenTitle() {
    this->title_ = new QLabel{"Today", this};
    QFont font;
    font.setWeight(QFont::Bold);
    font.setPointSize(23);
    this->title_->setFont(font);

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor{2, 122, 255});
    this->setPalette(palette);
    this->title_->setGeometry(20, -80, 250, 250);
}

void AddReminderButton::ChangeToToday() {
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor{2, 122, 255});
    this->setPalette(palette);
    this->title_->setText("Today");
}

void AddReminderButton::ChangeToScheduled() {
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor{255, 57, 47});
    this->setPalette(palette);
    this->title_->setText("Scheduled");
}

void AddReminderButton::AddListItem() {
    QStandardItemModel* model = Util::GetUtil()->GetNoticeModel();
    for (int i = 0; i < 10; ++i) {
        NoticeItemData d;
//        model->appendRow()
    }

    NoticeDelegate* delegate = new NoticeDelegate{this};

    this->notice_list_view_->setItemDelegate(delegate);
    this->notice_list_view_->setModel(model);
}
