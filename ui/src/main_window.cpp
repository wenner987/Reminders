#include "ui/include/main_window.h"
#include "ui/include/main_widget.h"

#include <QGraphicsEffect>

MainWindow::MainWindow(NoticeWindow* notice_window, QWidget *parent)
    : QMainWindow(parent), notice_window_(notice_window)
{
    this->resize(850, 500);
    this->setWindowOpacity(0.98);

    this->main_widget_ = new MainWidget{this};
    this->main_widget_->show();
}

MainWindow::~MainWindow()
{
    delete main_widget_;
}

QMainWindow* MainWindow::GetNoticeWindow() {
//    qDebug() << this->notice_window_;
    return this->notice_window_;
}
