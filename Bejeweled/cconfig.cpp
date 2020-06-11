#include "cconfig.h"
#include <QDebug>
CConfig::CConfig()
{
    picture_Style = 0; // 初始化主题为主题1
    for(int i = 0; i < 3; i++){
        style[i].picture_BgPic = "./img/";
        style[i].picture_BgPic.append(QString::number(i+1));
        style[i].picture_BgPic.append("/background.png");

        int k = 0;
        QString s = "./img/";
        s.append(QString::number(i+1)+"/");
        for(int j = 1; j <= 22; j++){
            style[i].picture_Element[k] = s;
            style[i].picture_Element[k].append(QString::number(j));
            style[i].picture_Element[k].append(".png");
            k++;
            qDebug()<< style[i].picture_Element[k]<<endl;
        }

        // 掩码初始化待修改 目前三套主题掩码图片相同 确认后再修改
        k = 0;
        for(int j = 23; j <= 25; j++){
            style[i].picture_Mask[k] = s;
            style[i].picture_Mask[k].append(QString::number(j));
            style[i].picture_Mask[k].append(".png");
            k++;
        }
    }
    music_Type = 0; // 背景音乐初始化为默认
    music_BgMusicPath = "./music/backgroundMusic1.mp3"; // 初始化音乐为backgroundMusic1.mp3
    switch_BgMusic = 1; // 背景音乐初始化为开
    switch_Sound = 1; // 音效初始化为开
}

void CConfig::Set_Picture_Style(int style){
    picture_Style = style;
}

void CConfig::Set_BgStyle(BgStyle bgstyle){
    style[picture_Style] = bgstyle;
}

void CConfig::Set_Music_Type(int type){
    music_Type = type;
}

void CConfig::Set_Music_BgMusicPath(QString bgMusic){
    music_BgMusicPath = bgMusic;
}

void CConfig::Set_Switch_BgMusic(int bgMus){
    switch_BgMusic = bgMus;
}

void CConfig::Set_Switch_Sound(int sound){
    switch_Sound = sound;
}

BgStyle CConfig::Get_Picture_Style(){
    if(picture_Style == 0) return style[0];
    else if(picture_Style == 1) return style[1];
    else if(picture_Style == 2) return style[2];
}

int CConfig::Get_PictureStyle(){
    return picture_Style;
}

int CConfig::Get_Music_Type(){
    return music_Type;
}

QString CConfig::Get_Music_BgMusicPath(){
    return music_BgMusicPath;
}

int CConfig::Get_Switch_BgMusic(){
    return switch_BgMusic;
}

int CConfig::Get_Switch_Sound(){
    return switch_Sound;
}
