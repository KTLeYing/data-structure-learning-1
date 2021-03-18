/******************************************************************************************
*FunctionName:Update                                                                   *
*                                                                                         *
*Description:更新数据                                                                     *
*                                                                                         *
*MakingDate:2019/7/25                                                                     *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/



#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<cstdlib>
#include<string.h>        //引用string函数库

#include "header.h"          //引用header头文件

using namespace std;

#define ERROR 0

int Update(ElecMap *eMap)
{
    FILE *pf;
    int i;
    pf=fopen("updatedresult.txt","w+");
    for(i=1;i<=eMap->roadNum;i++)
    {
        fprintf(pf,"信息大小:%d\tLinkID:%d\tFlag:%d\t岔路数:%d\t番号:%d\t",eMap->roadRecord[i].recordSize,
                eMap->roadRecord[i].LinkID,eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass);

         if(eMap->roadRecord[i].recordSize>12)
           fprintf(pf,"道路名称:%s\n",eMap->roadRecord[i].roadName);
        else
            fprintf(pf,"无道路名称\n");
        i++;
    }
    cout<<"更新已完成!\n";
    return 0;
}
