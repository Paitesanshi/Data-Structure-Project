#include "capptool.h"
#include <QFileDialog>

CAppTool::CAppTool()
{

}

QString CAppTool::GetPath(){
    QString filename;
    QFileDialog fd; // 调用系统文件管理器
    filename = fd.getOpenFileName(0, "选择文件", "/");
    return filename;
}
