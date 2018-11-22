#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QUrl>
#include <QStringList>
#include <QDebug>

#include "unit.h"
#include "song.h"
#include "video.h"
#include "module.h"

#include "addform.h"
#include "appwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Module *songModule;

    void addToSongModule(Unit*);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
