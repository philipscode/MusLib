#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer();

    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SLOT(onMediaStatusChanged(QMediaPlayer::MediaStatus)));
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

    TagLib::FileRef file(fileName.toUtf8());
    TagLib::String titleString = file.tag()->title();
    TagLib::String artistString = file.tag()->artist();
    TagLib::String albumString = file.tag()->album();
    int duration = file.audioProperties()->lengthInSeconds();
    int year = file.tag()->year();

    QString title = QString::fromStdWString(titleString.toWString());
    QString artist = QString::fromStdWString(artistString.toWString());
    QString album = QString::fromStdWString(albumString.toWString());
    song = new Song(title, album, artist, duration, year, fileName);

    qDebug() << song->getTitle();
    qDebug() << song->getAlbum();
    qDebug() << song->getArtist();
    qDebug() << song->getDuration();
    qDebug() << song->getYear();
    qDebug() << song->getPath();
}

/*void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::BufferedMedia)
    {
        qDebug() << "In here";
        qDebug() << player->metaData(QMediaMetaData::Author).toString();
        player->stop();
    }
}*/

void MainWindow::on_playButton_clicked()
{
    song->play();
}

void MainWindow::on_pauseButton_clicked()
{
    song->pause();
}
