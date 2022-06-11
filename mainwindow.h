#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "musicplayer.h"
#include "imageviewer.h"
#include "recorder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonMusic_clicked();

    void on_pushButtonImages_clicked();

    void on_pushButtonRecorder_clicked();

private:
    Ui::MainWindow *ui;

    MusicPlayer *musicPlayer;
    ImageViewer *imageViewer;
    Recorder *recorder;


};
#endif // MAINWINDOW_H
