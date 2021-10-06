#ifndef NOTICELIST_H
#define NOTICELIST_H

#include "card_widget.h"

#include <QWidget>
#include <QMap>

class NoticeList: public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event) override;

public:
    NoticeList(QWidget* parent);
    ~NoticeList() override;

public: signals:
    void change(int n);

public slots:
    void SendSignal(int n);

private:
    void ChangeWindow(int n);
    void RegisterHandler();

private:
    CardWidget* today_card_;
    CardWidget* schedule_card_;
    QMap<int, CardWidget*> card_map_;
};

#endif // NOTICELIST_H
