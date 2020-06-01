#include "cmusicplayer.h"

CMusicPlayer::CMusicPlayer(QString BgMusicPath)
{
    BgMusic = new QMediaPlayer;
    Sound_Start = new QMediaPlayer;
    Sound_Click = new QMediaPlayer;
    Sound_Eliminate = new QMediaPlayer;
    Sound_Down = new QMediaPlayer;
    Sound_Success = new QMediaPlayer;
    Sound_Fail = new QMediaPlayer;

    BgMusic->setMedia(QUrl::fromLocalFile(BgMusicPath));
    Sound_Start->setMedia(QUrl::fromLocalFile("./music/Start.mp3"));
    Sound_Click->setMedia(QUrl::fromLocalFile("./music/Click.mp3"));
    Sound_Eliminate->setMedia(QUrl::fromLocalFile("./music/Eliminate.mp3"));
    Sound_Down->setMedia(QUrl::fromLocalFile("./music/Down.mp3"));
    Sound_Success->setMedia(QUrl::fromLocalFile("./music/Success.mp3"));
    Sound_Fail->setMedia(QUrl::fromLocalFile("./music/Fail.mp3"));

    Sound_Start->setVolume(30);
    Sound_Click->setVolume(30);
    Sound_Eliminate->setVolume(30);
    Sound_Down->setVolume(30);
    Sound_Success->setVolume(30);
    Sound_Fail->setVolume(30);
}

void CMusicPlayer::PlayBgMusic(){
    BgMusic->setVolume(30);
    BgMusic->play();
}

void CMusicPlayer::StopBgMusic(){
    BgMusic->stop();
}

void CMusicPlayer::PlaySound(int i){
    if(i == 1) Sound_Start->play();
    else if(i == 2) Sound_Click->play();
    else if(i == 3) Sound_Eliminate->play();
    else if(i == 4) Sound_Down->play();
    else if(i == 5) Sound_Success->play();
    else if(i == 6) Sound_Fail->play();
}
