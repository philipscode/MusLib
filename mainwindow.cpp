#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer();

    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SLOT(on_mediaStatusChanged(QMediaPlayer::MediaStatus)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_to_Library_triggered()
{
    QString filter = "All Files (*.*) ;; Flac files (*.flac)";
    QString fileName = QFileDialog::getOpenFileName(this,"Choose your content",
                                                    QDir::homePath(), filter);
    player->setMedia(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    qDebug() << status;
    if (status == QMediaPlayer::LoadedMedia)
    {
        player->setVolume(50);
        player->play();
        qDebug() << player->metaData(QMediaMetaData::Title).toString();
        qDebug() << player->metaData(QMediaMetaData::AlbumTitle).toString();
        qDebug() << player->metaData(QMediaMetaData::Author).toString();
    }
}
