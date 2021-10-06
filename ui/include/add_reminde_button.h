#ifndef ADDREMINDERBUTTON_H
#define ADDREMINDERBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class AddReminderButton: public QWidget
{
    Q_OBJECT

public:
    explicit AddReminderButton(QWidget* parent);
    ~AddReminderButton() override;

    void ChangeToScheduled();
    void ChangeToToday();

signals:
    void clicked();

private:
    void mouseReleaseEvent(QMouseEvent *event) override;

    void GenNoReminbers();

    void GenTitle();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel* no_rember_;
    QLabel* title_;


};

#endif // ADDREMINDERBUTTON_H
