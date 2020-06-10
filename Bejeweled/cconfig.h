#ifndef CCONFIG_H
#define CCONFIG_H

#include <QString>
struct BgStyle  // 主题样式信息
{
    QString picture_BgPic;          // 背景图片路径 相对路径
    QString picture_Element[22];     // 元素图片路径 相对路径
    QString picture_Mask[6];        // 掩码图片路径 相对路径
};

class CConfig
{
public:
    CConfig();
    void Set_Picture_Style(int style);
    void Set_BgStyle(BgStyle bgstyle);
    void Set_Music_Type(int type);
    void Set_Music_BgMusicPath(QString bgMusic);
    void Set_Switch_BgMusic(int bgMus);
    void Set_Switch_Sound(int sound);

    BgStyle Get_Picture_Style();
    int Get_PictureStyle();
    int Get_Music_Type();
    QString Get_Music_BgMusicPath();
    int Get_Switch_BgMusic();
    int Get_Switch_Sound();

private:
    int picture_Style;              // 主题样式 0表示主题1 1表示主题2 2表示主题3
    BgStyle style[3];               // 主题样式信息
    int music_Type;                 // 背景音乐类型 0表示默认 1表示自定义
    QString music_BgMusicPath;      // 背景音乐文件路径
    int switch_BgMusic;             // 背景音乐开关 0表示关闭 1表示开启
    int switch_Sound;               // 音效开关 0表示关闭 1表示开启
};

#endif // CCONFIG_H
