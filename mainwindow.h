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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAdd_to_Library_triggered();

    void on_mediaStatusChanged(QMediaPlayer::MediaStatus);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
