#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "song.h"
#include "video.h"
#include "module.h"

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
    m.insert(s1);
    m.insert(s2);
    m.insert(s3);
    for (Module::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << (*it)->getTitle() << std::endl;
    }
    std::cout << "////" << std::endl;
    m.remove("smells");
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
    for (Module::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << (*it)->getTitle() << std::endl;
    }
    return 0;
}
