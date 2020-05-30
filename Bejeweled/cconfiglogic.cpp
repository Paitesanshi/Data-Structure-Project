#include "cconfiglogic.h"

CConfigLogic::CConfigLogic()
{

}

void CConfigLogic::changeTheme(int theme){
    CConfig config=dao.ReadConFile();
    config.Set_Picture_Style(theme);
    dao.WriteConFile(config);
}

void CConfigLogic::setBgMusicType(int type){
    CConfig config=dao.ReadConFile();
    config.Set_Music_Type(type);
    dao.WriteConFile(config);
}

void CConfigLogic::setUserDefinedBgMusic(QString bgMusic){
    CConfig config=dao.ReadConFile();
    config.Set_Music_BgMusicPath(bgMusic);
    dao.WriteConFile(config);
}

void CConfigLogic::setBgMusicSwitch(int type){
    CConfig config=dao.ReadConFile();
    config.Set_Switch_BgMusic(type);
    dao.WriteConFile(config);
}

void CConfigLogic::setSoundSwitch(int type){
    CConfig config=dao.ReadConFile();
    config.Set_Switch_Sound(type);
    dao.WriteConFile(config);
}


