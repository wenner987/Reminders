#include "ui/include/main_widget.h"
#include "ui/include/main_window.h"
#include "ui/include/notice_list.h"

MainWidget::MainWidget(QWidget *parent)
    :QWidget(parent)
{
    Init();
    RegisterHandler();
}

MainWidget::~MainWidget() {

}

void MainWidget::Init() {
    MainWindow* parent = dynamic_cast<MainWindow*>(this->parent());
    this->notice_window_ = parent->GetNoticeWindow();

    this->resize(parent->width(), parent->height());

    const size_t notice_list_width = 300;

    this->notice_list_ = new NoticeList{this};
    this->notice_list_->setGeometry(0, 0, notice_list_width, this->height());
    this->notice_list_->setStyleSheet("background-color:rgb(200,200,200);");
    this->notice_list_->show();

    this->add_notice_ = new AddReminderButton{this};
    this->add_notice_->setGeometry(notice_list_width, 0, this->width() - notice_list_width, this->height());
    this->add_notice_->setAttribute(Qt::WA_StyledBackground);
    this->notice_list_->setStyleSheet("background-color:white;");
//    this->add_notice_->setStyleSheet("background-color:black;");
}

void MainWidget::add_notice() {
    this->notice_window_->show();

}

void MainWidget::change_window(int n) {
    qDebug() << "change: " << n;
    if (n == 0) {
        this->add_notice_->ChangeToToday();
    } else if (n == 1) {
        this->add_notice_->ChangeToScheduled();
    }

}

void MainWidget::RegisterHandler() {
    connect(this->add_notice_, SIGNAL(clicked()), this, SLOT(add_notice()));
    connect(this->notice_list_, SIGNAL(change(int)), this, SLOT(change_window(int)));
}
