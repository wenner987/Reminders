#ifndef UTIL_H
#define UTIL_H

#include <QDir>
#include <QStandardItemModel>

#define APP_VERSION 0.0.1

class Util {
public:
    static Util* GetUtil() { // Get util signatone.
        static Util* util;
        if (util == nullptr) {
            util = new Util();
        }
        return util;
    }

    void Init();

    void SaveNoticeMsg();
    QStandardItemModel* GetNoticeModel();




private:
    QString home_dir;
    QString cache_name;
};

#endif // UTIL_H
