#include "rem_utils.h"

void Util::Init()  {
    // 1. get home path
    // 2. check notice msg file exists. if not exist create it.
    this->home_dir = QDir::homePath();

}

QStandardItemModel *Util::GetNoticeModel() {
    static QStandardItemModel* model;
    if (model == nullptr) {
        model = new QStandardItemModel{};
    }
    return model;
}

