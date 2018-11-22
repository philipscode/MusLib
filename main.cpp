#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <functional>

#include "song.h"
#include "video.h"
#include "module.h"

using function_bool = const std::function<bool(Unit*, Unit*)>;
using function_str = const std::function<std::string(Unit*)>;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
