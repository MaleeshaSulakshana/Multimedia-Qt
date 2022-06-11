#include "musicplayer.h"
#include "ui_musicplayer.h"

#include "mainwindow.h"

#include <QMediaPlayer>
#include <QFileDialog>
#include <QUrl>

MusicPlayer::MusicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    mediaPlayer = new QMediaPlayer(this);

    connect(mediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos) {
        ui->progressBar->setValue(pos);
    });

    connect(mediaPlayer, &QMediaPlayer::durationChanged, [&](qint64 dur) {
        ui->progressBar->setMaximum(dur);
    });

    ui->volumn->setValue(100);
}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

void MusicPlayer::on_volumn_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}

void MusicPlayer::on_pushButtonOpenFolder_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select audio file", "", tr("Audio (*.mp3 *.wav);;" ));
    if (filename.isEmpty()) {
        return;
    }

    mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mediaPlayer->setVolume(ui->volumn->value());
    on_pushButtonPlay_clicked();
}

void MusicPlayer::on_pushButtonPlay_clicked()
{
    mediaPlayer->play();
}

void MusicPlayer::on_pushButtonPause_clicked()
{
    mediaPlayer->pause();
}

void MusicPlayer::on_pushButtonStop_clicked()
{
    mediaPlayer->stop();
}

void MusicPlayer::on_pushButtonMute_clicked()
{

    if (mediaPlayer->isMuted()){
        mediaPlayer->setMuted(false);
    } else {
        mediaPlayer->setMuted(true);
    }

}

void MusicPlayer::on_pushButtonBack_clicked()
{
    MainWindow *mainWindow;
    mainWindow = new MainWindow();
    this->hide();
    mainWindow->show();
}
