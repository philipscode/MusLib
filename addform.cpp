#include "addform.h"
#include "ui_addform.h"
#include "mainwindow.h"

#include <QFileDialog>
#include <QDir>


AddForm::AddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddForm)
{
    ui->setupUi(this);
}

AddForm::~AddForm()
{
    delete ui;
}

void AddForm::on_videoRadioButton_clicked()
{
    this->ui->albumLineEdit->clear();
    this->ui->albumLineEdit->hide();
    this->ui->albumLabel->hide();
}

void AddForm::on_songRadioButton_clicked()
{
    this->ui->albumLineEdit->show();
    this->ui->albumLabel->show();
}

void AddForm::on_backButton_clicked()
{
    AppWindow *aw = new AppWindow();
    (qobject_cast<MainWindow*>(this->parent()))->setCentralWidget(aw);
}

void AddForm::on_chooseButton_clicked()
{
    if (this->ui->songRadioButton->isChecked())
    {
        qPath = QFileDialog::getOpenFileName(this, tr("Select a song"),
                             QDir::homePath(), tr("Songs (*.mp3 *.flac)"));
    }
    else
    {
        qPath = QFileDialog::getOpenFileName(this, tr("Select a music video"),
                             QDir::homePath(), tr("Videos (*.mp4)"));
    }
}

void AddForm::on_doneButton_clicked()
{
    qTitle = ui->titleLineEdit->text();
    qArtist = ui->artistLineEdit->text();
    qYear = ui->yearLineEdit->text().toInt();
    if (this->ui->songRadioButton->isChecked())
    {
        qAlbumTitle = this->ui->albumLineEdit->text();
        Song *song = new Song(qTitle.toUtf8().constData(),
                              qAlbumTitle.toUtf8().constData(),
                              qArtist.toUtf8().constData(),
                              qPath.toUtf8().constData(),
                              qYear);
        (qobject_cast<MainWindow*>(this->parent()))->addToSongModule(song);
        this->on_backButton_clicked();
    }


}
