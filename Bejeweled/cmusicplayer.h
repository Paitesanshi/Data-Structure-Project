#ifndef CMUSICPLAYER_H
#define CMUSICPLAYER_H
#include <QMediaPlayer>
#include <QMediaPlaylist>

class CMusicPlayer
{
public:
    CMusicPlayer(QString BgMusicPath);
    void PlayBgMusic();
    void StopBgMusic();
    void PlaySound(int i);

private:
    QMediaPlayer *BgMusic;                  // 背景音乐播放器
    QMediaPlayer *Sound_Start;              // 开始游戏音效
    QMediaPlayer *Sound_Click;              // 点击音效
    QMediaPlayer *Sound_Eliminate;          // 消子音效
    QMediaPlayer *Sound_Amazing;               // 下移音效
    QMediaPlayer *Sound_Success;            // 胜利音效
    QMediaPlayer *Sound_Fail;               // 失败音效
};

#endif // CMUSICPLAYER_H
