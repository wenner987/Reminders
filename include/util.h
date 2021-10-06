#ifndef UTIL_H
#define UTIL_H

#include <QDir>

#define APP_VERSION 0.0.1

class Util {
public:
    static Util* GetUtil() { // Get util signatone.
        static Util util;
        if (util == nullptr) {
            util = new Util();
        }
        return util;
    }

    void Init() {
        // 1. get home path
        // 2. check notice msg file exists. if not exist create it.
        this->home_dir = QDir::homePath();

    }

    void SaveNoticeMsg() {

    }

private:
    QString home_dir;
    QString cache_name;
};

#endif // UTIL_H
