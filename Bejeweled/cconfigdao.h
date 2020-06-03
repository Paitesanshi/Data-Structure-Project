#ifndef CCONFIGDAO_H
#define CCONFIGDAO_H
#include "cconfig.h"
#include <QString>

class CConfigDao
{
public:
    CConfigDao();
    CConfig* ReadConFile();
    void WriteConFile(CConfig *config);
};

#endif // CCONFIGDAO_H
