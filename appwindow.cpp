#include "appwindow.h"
#include "ui_appwindow.h"
#include "mainwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppWindow)
{
    ui->setupUi(this);
}

AppWindow::~AppWindow()
{
    delete ui;
}

void AppWindow::on_addButton_clicked()
{
    AddForm *af = new AddForm();
    (qobject_cast<MainWindow*>(this->parent()))->setCentralWidget(af);
}
