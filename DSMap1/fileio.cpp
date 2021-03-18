/******************************************************************************************
*FunctionName:ReadFile                                                                    *
*                                                                                         *
*Description:读取二进制文件，并将存储在文本文档中                                       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<cstdlib>
#include<string.h>

#include "Header.h"

using namespace std;

#define ERROR 0

int ReadFile(ElecMap *eMap)
{
    FILE *fp,*fileWrite;
    int num=0;
    unsigned short recordSize;
    unsigned int LinkID;
    unsigned short roadNameLen;
    unsigned int roadInfo;
    char roadName[30];

    unsigned int classInfo;
    unsigned int brunch;
    int roadFlag;

    if((fp=fopen("d:\\GTBL.dat","rb"))==NULL)
    {
       cout<<"文件打开失败!\n";
       exit(0);
    }
    cout<<"文件打开成功!\n";

    fileWrite=fopen("d:\\Map.txt","w");

    cout<<"文件读取中......\n";
    while(1)
    {
        fread(&recordSize,sizeof(short int),1,fp);
        if(feof(fp))
            break;
        fread(&LinkID,sizeof(long),1,fp);
        fread(&roadNameLen,sizeof(short int),1,fp);
        fread(&roadInfo,sizeof(long),1,fp);

        recordSize=M_CHG_INT16(recordSize);
        LinkID=M_CHG_INT32(LinkID);
        roadNameLen=M_CHG_INT16(roadNameLen);

        roadInfo=M_CHG_INT32(roadInfo);
        roadFlag=GET_FLAG(roadInfo);
        brunch=GET_BRUNCH(roadInfo);
        classInfo=GET_DISPCLASS(roadInfo);

        if(recordSize>12)
        {
            fread(roadName,recordSize-12,1,fp);
            strcpy(eMap->roadRecord[eMap->num].roadName,roadName);
        }
        eMap->roadRecord[eMap->num].recordSize=recordSize;
        eMap->roadRecord[eMap->num].LinkID=LinkID;
        eMap->roadRecord[eMap->num].roadInfo=roadInfo;

        fprintf(fileWrite,"%d\t信息大小:%d\tLinkID:%d\t有无Flag:%d\t分岔路数:%d\t番号:%d\n",
                eMap->num+1,recordSize,LinkID,roadFlag,brunch,classInfo);
        if(recordSize>12)
           fprintf(fileWrite,"道路名称:%s\n",roadName);
        else
            fprintf(fileWrite,"无道路名称\n");
        eMap->num++;
    }
    cout<<"读取记录一共为:"<<eMap->num<<endl;

    fclose(fp);
    cout<<"文件读取成功!\nSuccess!\n";
    return 0;
}




