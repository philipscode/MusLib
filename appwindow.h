#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>


namespace Ui {
class AppWindow;
}

class AppWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private slots:
    void on_addButton_clicked();

private:
    Ui::AppWindow *ui;
};

#endif // APPWINDOW_H
