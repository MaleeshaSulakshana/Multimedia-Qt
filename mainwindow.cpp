#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonMusic_clicked()
{

//    Open MusicPlayer window
    musicPlayer = new MusicPlayer();
    if (!musicPlayer->isVisible()) {
        this->hide();
        musicPlayer->show();
    }

}

void MainWindow::on_pushButtonImages_clicked()
{

//    Open image viewer window
    imageViewer = new ImageViewer();
    if (!imageViewer->isVisible()) {
        this->hide();
        imageViewer->show();
    }

}

void MainWindow::on_pushButtonRecorder_clicked()
{
//    Open recorder window
    recorder = new Recorder();
    if (!recorder->isVisible()) {
        this->hide();
        recorder->show();
    }
}
