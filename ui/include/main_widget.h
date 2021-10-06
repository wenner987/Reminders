#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "add_reminde_button.h"
#include "notice_list.h"

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

    ~MainWidget() override;

public slots:
    void add_notice();
    void change_window(int n);

private:
    void Init();
    void RegisterHandler();

private:
    QMainWindow* notice_window_; // Alert window
    AddReminderButton* add_notice_; // right pannel
    NoticeList* notice_list_; // left pannel
};

#endif // MAINWIDGET_H
