#ifndef CCONFIGLOGIC_H
#define CCONFIGLOGIC_H
#include "cconfig.h"
#include <QString>

#include "cconfigdao.h"

class CConfigLogic
{
    CConfigDao dao;
public:
    CConfigLogic();
    CConfig* getConfig();
    void changeTheme(int theme);  //主题样式 0表示主题1 1表示主题2 2表示主题3
    void setBgMusicType(int type);  //背景音乐类型 0表示默认 1表示自定义
    void setUserDefinedBgMusic(QString bgMusic); //自定义背景音乐路径
    void setBgMusicSwitch(int type);  //背景音乐开关 0表示关闭 1表示开启
    void setSoundSwitch(int type);  //音效开关 0表示关闭 1表示开启
};

#endif // CCONFIGLOGIC_H
