#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("MusLib");

    songModule = new Module();

    AppWindow *appWindow = new AppWindow();
    this->setCentralWidget(appWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToSongModule(Unit *item)
{
    this->songModule->insert(item, [](Unit *a, Unit *b)
    { return a->getTitle() < b->getTitle(); });
}
