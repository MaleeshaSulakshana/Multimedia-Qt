#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>

#include <QMediaPlayer>

namespace Ui {
class MusicPlayer;
}

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();

private slots:
    void on_volumn_valueChanged(int value);

    void on_pushButtonOpenFolder_clicked();

    void on_pushButtonPlay_clicked();

    void on_pushButtonPause_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonMute_clicked();

    void on_pushButtonBack_clicked();

private:
    Ui::MusicPlayer *ui;

    QMediaPlayer *mediaPlayer;
    QStringList supportedMimeTypes();
};

#endif // MUSICPLAYER_H
