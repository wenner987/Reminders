#ifndef NOTICEITEM_H
#define NOTICEITEM_H

#include <QListWidgetItem>
#include <QMetaType>
#include <QStyledItemDelegate>
#include <QTime>

class NoticeDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit NoticeDelegate(QWidget* parent);
    ~NoticeDelegate();

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;


};

//class NoticeListView: public

#endif // NOTICEITEM_H
