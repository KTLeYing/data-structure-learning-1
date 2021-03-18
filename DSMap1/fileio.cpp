/******************************************************************************************
*FunctionName:ReadFile                                                                    *
*                                                                                         *
*Description:��ȡ�������ļ��������洢���ı��ĵ���                                       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:������                                                                             *
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
       cout<<"�ļ���ʧ��!\n";
       exit(0);
    }
    cout<<"�ļ��򿪳ɹ�!\n";

    fileWrite=fopen("d:\\Map.txt","w");

    cout<<"�ļ���ȡ��......\n";
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

        fprintf(fileWrite,"%d\t��Ϣ��С:%d\tLinkID:%d\t����Flag:%d\t�ֲ�·��:%d\t����:%d\n",
                eMap->num+1,recordSize,LinkID,roadFlag,brunch,classInfo);
        if(recordSize>12)
           fprintf(fileWrite,"��·����:%s\n",roadName);
        else
            fprintf(fileWrite,"�޵�·����\n");
        eMap->num++;
    }
    cout<<"��ȡ��¼һ��Ϊ:"<<eMap->num<<endl;

    fclose(fp);
    cout<<"�ļ���ȡ�ɹ�!\nSuccess!\n";
    return 0;
}




