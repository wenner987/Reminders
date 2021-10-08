#include "ui/include/notice_view.h"

NoticeDelegate::NoticeDelegate(QWidget* parent): QStyledItemDelegate(parent)
{

}

void NoticeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);
}

QSize NoticeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    return QStyledItemDelegate::sizeHint(option, index);
}
