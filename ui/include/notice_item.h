//
// Created by Wenner on 2021/10/7.
//

#ifndef REM_NOTICE_ITEM_H
#define REM_NOTICE_ITEM_H

#include <QDate>
#include <QMetaType>

enum class NoticeStatus {
    kNormal = 0,
    kFinished = 1,
    kCancel = 2,
    kChange = 3,
    };

class NoticeItemData {
public:
    int getId() const;

    void setId(int id);

    const QString &getNoticeText() const;

    void setNoticeText(const QString &noticeText);

    const QDate &getNoticeDate() const;

    void setNoticeDate(const QDate &noticeDate);

    const QTime &getNoticeTime() const;

    void setNoticeTime(const QTime &noticeTime);

    const QDate &getFinishDate() const;

    void setFinishDate(const QDate &finishDate);

    const QTime &getFinishTime() const;

    void setFinishTime(const QTime &finishTime);

    const QDate &getCreateDate() const;

    void setCreateDate(const QDate &createDate);

    const QTime &getCreateTime() const;

    void setCreateTime(const QTime &createTime);

    [[nodiscard]] NoticeStatus getStatus() const;

    void setStatus(NoticeStatus status);

private:
    int id_;
    QString notice_text_;
    QDate notice_date_;
    QTime notice_time_;
    QDate finish_date_;
    QTime finish_time_;
    QDate create_date_;
    QTime create_time_;
    NoticeStatus status_;
};

Q_DECLARE_METATYPE(NoticeItemData)



#endif //REM_NOTICE_ITEM_H
