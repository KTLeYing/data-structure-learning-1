/******************************************************************************************
*FunctionName:Update                                                                   *
*                                                                                         *
*Description:��������                                                                     *
*                                                                                         *
*MakingDate:2019/7/25                                                                     *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/



#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<cstdlib>
#include<string.h>        //����string������

#include "header.h"          //����headerͷ�ļ�

using namespace std;

#define ERROR 0

int Update(ElecMap *eMap)
{
    FILE *pf;
    int i;
    pf=fopen("updatedresult.txt","w+");
    for(i=1;i<=eMap->roadNum;i++)
    {
        fprintf(pf,"��Ϣ��С:%d\tLinkID:%d\tFlag:%d\t��·��:%d\t����:%d\t",eMap->roadRecord[i].recordSize,
                eMap->roadRecord[i].LinkID,eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass);

         if(eMap->roadRecord[i].recordSize>12)
           fprintf(pf,"��·����:%s\n",eMap->roadRecord[i].roadName);
        else
            fprintf(pf,"�޵�·����\n");
        i++;
    }
    cout<<"���������!\n";
    return 0;
}
