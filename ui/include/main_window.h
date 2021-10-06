#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "notice_window.h"
#include "main_widget.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(NoticeWindow* notice_window, QWidget *parent = nullptr);
    ~MainWindow();

    void SetNoticeWindow(NoticeWindow* notice_window);
    QMainWindow* GetNoticeWindow();

private:
    QMainWindow* notice_window_;
    QWidget* main_widget_;
};
#endif // MAINWINDOW_H
