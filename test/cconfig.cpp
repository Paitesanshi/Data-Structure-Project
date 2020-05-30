#include "cconfig.h"

CConfig::CConfig()
{
    for(int i=0;i<3;i++){
        style[i].picture_BgPic="Picture\\Theme";
        style[i].picture_BgPic.append(QString::number(i+1));
        style[i].picture_BgPic.append("\\background.bmp");
        QString s="Picture\\Theme";
        s.append(QString::number(i+1));
        s.append("\\Element\\");
        for(int j=1;j<=6;j++){
            style[i].picture_Element[i]=s;
            style[i].picture_Element[i].append(QString::number(j));
            style[i].picture_Element[i].append(".bmp");
        }
        s="Picture\\Theme";
        s.append(QString::number(i+1));
        s.append("\\Mask\\");
        for(int j=1;j<=6;j++){
            style[i].picture_Mask[i]=s;
            style[i].picture_Mask[i].append(QString::number(j));
            style[i].picture_Mask[i].append(".bmp");
        }
    }
    music_BgMusicPath="music\\backgroundMusic1.mp3";
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
