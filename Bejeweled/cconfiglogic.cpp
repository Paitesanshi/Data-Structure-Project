#include "cconfiglogic.h"

CConfigLogic::CConfigLogic()
{

}

void CConfigLogic::setConfig(CConfig cconfig)
{
    //配置文件格式：
    //[背景图片路径]
    //[宝石图片1路径]
    //...
    //[宝石图片6路径]
    //[掩码图片1路径]
    //...
    //[掩码图片6路径]
    //[背景音乐类型，0默认，1自定义]
    //[背景音乐路径]
    //[背景音乐开关，0表示关闭 1表示开启]
    //[音效音乐开关，0表示关闭 1表示开启]
    QString file="";
    BgStyle bgStyle=cconfig.Get_Picture_Style();
    file.append(bgStyle.picture_BgPic);
    file.append("\n");

    for(int i=0;i<6;i++){
        file.append(bgStyle.picture_Element[i]);
        file.append("\n");
    }

    for(int i=0;i<6;i++){
        file.append(bgStyle.picture_Mask[i]);
        file.append("\n");
    }

    file.append(QString::number(cconfig.Get_Music_Type()));
    file.append("\n");
    file.append(cconfig.Get_Music_BgMusicPath());
    file.append("\n");
    file.append(QString::number(cconfig.Get_Switch_BgMusic()));
    file.append("\n");
    file.append(QString::number(cconfig.Get_Switch_Sound()));

//    CConfigDao c;
//    c.WriteConFile(file);
}

