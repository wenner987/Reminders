//
// Created by Wenner on 2021/10/7.
//

#include "ui/include/notice_item.h"

int NoticeItemData::getId() const {
    return id_;
}

void NoticeItemData::setId(int id) {
    id_ = id;
}

const QString &NoticeItemData::getNoticeText() const {
    return notice_text_;
}

void NoticeItemData::setNoticeText(const QString &noticeText) {
    notice_text_ = noticeText;
}

const QDate &NoticeItemData::getNoticeDate() const {
    return notice_date_;
}

void NoticeItemData::setNoticeDate(const QDate &noticeDate) {
    notice_date_ = noticeDate;
}

const QTime &NoticeItemData::getNoticeTime() const {
    return notice_time_;
}

void NoticeItemData::setNoticeTime(const QTime &noticeTime) {
    notice_time_ = noticeTime;
}

const QDate &NoticeItemData::getFinishDate() const {
    return finish_date_;
}

void NoticeItemData::setFinishDate(const QDate &finishDate) {
    finish_date_ = finishDate;
}

const QTime &NoticeItemData::getFinishTime() const {
    return finish_time_;
}

void NoticeItemData::setFinishTime(const QTime &finishTime) {
    finish_time_ = finishTime;
}

const QDate &NoticeItemData::getCreateDate() const {
    return create_date_;
}

void NoticeItemData::setCreateDate(const QDate &createDate) {
    create_date_ = createDate;
}

const QTime &NoticeItemData::getCreateTime() const {
    return create_time_;
}

void NoticeItemData::setCreateTime(const QTime &createTime) {
    create_time_ = createTime;
}

NoticeStatus NoticeItemData::getStatus() const {
    return status_;
}

void NoticeItemData::setStatus(NoticeStatus status) {
    status_ = status;
}
