#include "mainwindow.h"
#include<QMovie>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(R"(
            QLabel { background-color: white; color: black; }
            #whiteLabel { background-color: white; color: black;}
                    #blackLabel { background-color: black; color: black;}  // 覆盖特定标签
        )");

    MainWindow w;
    w.show();
    return a.exec();
}
