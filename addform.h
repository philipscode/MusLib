#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>
#include <QString>


namespace Ui {
class AddForm;
}

class AddForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = nullptr);
    ~AddForm();

private slots:
    void on_videoRadioButton_clicked();

    void on_songRadioButton_clicked();

    void on_backButton_clicked();

    void on_chooseButton_clicked();

    void on_doneButton_clicked();

private:
    Ui::AddForm *ui;
    QString qTitle, qAlbumTitle, qArtist, qPath;
    int qYear;
};

#endif // ADDFORM_H
