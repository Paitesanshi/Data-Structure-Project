#include "cconfigdao.h"
#include <QSettings>
#include <QFileInfo>

CConfigDao::CConfigDao()
{

}

CConfig* CConfigDao::ReadConFile(){
    BgStyle style;
    CConfig *config;
    config = new CConfig();
    QSettings *configFile = new QSettings("./config.ini", QSettings::IniFormat);
    QFileInfo *file = new QFileInfo(configFile->fileName());
    qDebug()<<55;
    if(!file->isFile()){
        qDebug()<<66;
        WriteConFile(config);
    }
    config->Set_Picture_Style(configFile->value("/Picture/Style").toInt());
    style.picture_BgPic = configFile->value("/Picture/Bgpic").toString();
    style.picture_Element[0] = configFile->value("/Picture/Element1").toString();
    style.picture_Element[1] = configFile->value("/Picture/Element2").toString();
    style.picture_Element[2] = configFile->value("/Picture/Element3").toString();
    style.picture_Element[3] = configFile->value("/Picture/Element4").toString();
    style.picture_Element[4] = configFile->value("/Picture/Element5").toString();
    style.picture_Element[5] = configFile->value("/Picture/Element6").toString();
    style.picture_Element[6] = configFile->value("/Picture/Element7").toString();
    style.picture_Element[7] = configFile->value("/Picture/Element8").toString();
    style.picture_Element[8] = configFile->value("/Picture/Element9").toString();
    style.picture_Element[9] = configFile->value("/Picture/Element10").toString();
    style.picture_Element[10] = configFile->value("/Picture/Element11").toString();
    style.picture_Mask[0] = configFile->value("/Picture/Mask1").toString();
    style.picture_Mask[1] = configFile->value("/Picture/Mask2").toString();
    style.picture_Mask[2] = configFile->value("/Picture/Mask3").toString();
    style.picture_Mask[3] = configFile->value("/Picture/Mask4").toString();
    style.picture_Mask[4] = configFile->value("/Picture/Mask5").toString();
    style.picture_Mask[5] = configFile->value("/Picture/Mask6").toString();
    config->Set_BgStyle(style);
    config->Set_Music_Type(configFile->value("/Music/Type").toInt());
    config->Set_Music_BgMusicPath(configFile->value("/Music/BgMusicPath").toString());
    config->Set_Switch_BgMusic(configFile->value("/Switch/BgMusic").toInt());
    config->Set_Switch_Sound(configFile->value("/Switch/Sound").toInt());

    delete configFile;

    return config;
}

void CConfigDao::WriteConFile(CConfig *config){
    BgStyle style = config->Get_Picture_Style();

    QSettings *configFile = new QSettings("./config.ini", QSettings::IniFormat);
    qDebug()<<11;
    configFile->setValue("/Picture/Style", QString::number(config->Get_PictureStyle()));
    configFile->setValue("/Picture/BgPic", style.picture_BgPic);
    configFile->setValue("/Picture/Element1", style.picture_Element[0]);
    configFile->setValue("/Picture/Element2", style.picture_Element[1]);
    configFile->setValue("/Picture/Element3", style.picture_Element[2]);
    configFile->setValue("/Picture/Element4", style.picture_Element[3]);
    configFile->setValue("/Picture/Element5", style.picture_Element[4]);
    configFile->setValue("/Picture/Element6", style.picture_Element[5]);
    configFile->setValue("/Picture/Element7", style.picture_Element[6]);
    configFile->setValue("/Picture/Element8", style.picture_Element[7]);
    configFile->setValue("/Picture/Element9", style.picture_Element[8]);
    configFile->setValue("/Picture/Element10", style.picture_Element[9]);
    configFile->setValue("/Picture/Element11", style.picture_Element[10]);
    configFile->setValue("/Picture/Mask1", style.picture_Mask[0]);
    configFile->setValue("/Picture/Mask2", style.picture_Mask[1]);
    configFile->setValue("/Picture/Mask3", style.picture_Mask[2]);
    configFile->setValue("/Picture/Mask4", style.picture_Mask[3]);
    configFile->setValue("/Picture/Mask5", style.picture_Mask[4]);
    configFile->setValue("/Picture/Mask6", style.picture_Mask[5]);

    configFile->setValue("/Music/Type", QString::number(config->Get_Music_Type()));
    configFile->setValue("/Music/BgMusicPath", config->Get_Music_BgMusicPath());

    configFile->setValue("/Switch/BgMusic",QString::number(config->Get_Switch_BgMusic()));
    configFile->setValue("/Switch/Sound",QString::number(config->Get_Switch_Sound()));

    //qDebug()<<22;
    delete configFile;
    //qDebug()<<33;
}
