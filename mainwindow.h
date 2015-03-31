#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <qdebug.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int showImage(QString imagePath);

public slots:
    void onloadButtonClicked()
    {
        showImage(ui->pathInput->text());
        qDebug() << "pressed";
    }

};

#endif // MAINWINDOW_H
