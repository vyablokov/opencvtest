#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(onloadButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::showImage(QString imagePath)
{
    Mat image;
    image = imread(imagePath.toStdString());
    namedWindow("Image", CV_WINDOW_AUTOSIZE);
    imshow("Image", image);
    waitKey(0);
    return(0);
}
