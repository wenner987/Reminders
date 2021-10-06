//
// Created by Wenner on 2021/10/6.
//

#ifndef REM_CARD_WIDGET_H
#define REM_CARD_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QtSvg/QSvgRenderer>

class CardWidget: public QWidget {
    Q_OBJECT

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    explicit CardWidget(QWidget* parent, const QString& name, int no);

    ~CardWidget() override;

    void paintEvent(QPaintEvent *event) override;
    void SetIcon(const QString& icon_path);
    void SetDefaultClick();
    void SetColorWhenClicked(const QColor& color);
    void ChangeToDefaultColor();

private:
    void RefershColor();

public: signals:
    void clicked(int);

private:
    QColor click_color_;
    QColor default_color_;
    QLabel* show_name_;
    QLabel* icon_;
    int no_;
    int active_;
};

#endif //REM_CARD_WIDGET_H
