#include "ui/include/main_window.h"
#include "ui/include/notice_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoticeWindow notice_window;
    MainWindow main_window(&notice_window);
    main_window.show();
    return a.exec();
}
