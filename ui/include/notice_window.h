#ifndef NOTICEWINDOW_H
#define NOTICEWINDOW_H

#include <QMainWindow>
#include <QLabel>

class NoticeWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit NoticeWindow(QWidget* parent = nullptr);

    ~NoticeWindow() override;

public:
};

#endif // NOTICEWINDOW_H
