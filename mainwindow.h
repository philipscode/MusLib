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

/*#include "tag.h"
#include "fileref.h"*/
#include "unit.h"
#include "song.h"
#include "video.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_to_Library_triggered();

    /*void onMediaStatusChanged(QMediaPlayer::MediaStatus);*/

    void on_playButton_clicked();

    void on_pauseButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    Song *song;
};

#endif // MAINWINDOW_H
