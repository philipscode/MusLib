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
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
    Song *s1 = new Song();
    Song *s2 = new Song("joy", "pleasure", "curtis", 40, 1970, "/");
    Song *s3 = new Song("smells", "like", "nirvana", 30, 1990, "/");
    //s1->setTitle("Ian");
    Module m {};
    function_bool rule = [](Unit *a,Unit *b) { return a->getTitle() < b->getTitle(); };
    m.insert(s1, rule);
    m.insert(s2, rule);
    m.insert(s3, rule);
    for (Module::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << (*it)->getTitle() << std::endl;
    }
    std::cout << "////!!!" << std::endl;
    function_str target = [](Unit *a) { return a->getTitle(); };
    m.remove("smells", target);
    for (Module::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << (*it)->getTitle() << std::endl;
    }
    std::cout << "////" << std::endl;
    m.insert(s3);
    for (Module::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << (*it)->getTitle() << std::endl;
    }
    std::cout << "////" << std::endl;
    m.removeAll();
    std::cout << "?" << std::endl;
    for (Module::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << "!" << std::endl;
        std::cout << (*it)->getTitle() << std::endl;
    }
    return 0;
}
