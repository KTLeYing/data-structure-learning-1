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
#include<string.h>        //引用string函数库

#include "header.h"          //引用header头文件

using namespace std;

#define ERROR 0

int ReadFile(ElecMap *eMap)
{
    FILE *fp,*fileWrite;     //定义指向FILE结构的指针变量*pf和fileWrite
    int roadNum=0;               //初始化道路数量为0
    unsigned short recordSize;       //使用全局变量的结构体数组进行索引
    unsigned int LinkID;
    unsigned short roadNameLen;
    unsigned int roadInfo;              //道路信息
    char roadName[30];            //数组存储道路名字

    unsigned int disclass;
    unsigned int brunch;
    int flag;

    if((fp=fopen("d:\\GTBL.dat","rb"))==NULL)      //判断GTBL文件是否为空，若为空则打开失败
    {
       cout<<"文件打开失败!\n";
       exit(0);
    }
    cout<<"文件打开成功!\n";                    //文件不能空，则成功打开文件，并读取二进制文件

    fileWrite=fopen("d:\\Map3.txt","w");         //文件指针fileWrite指向要存储进去的目标文本文件，并写进文本文件中
    cout<<"文件读取中......\n";
    while(1)
    {
        fread(&recordSize,sizeof(short int),1,fp);    //读取一个short int（2个字节）的道路记录大小，并取地址
        if(feof(fp))                                  //如果读取到二进制文件的结尾时，结束读取
            break;
        fread(&LinkID,sizeof(long),1,fp);          //读取一个long（4个字节）的道路LinkID，并取其地址
        fread(&roadNameLen,sizeof(short int),1,fp);            //读取一个short int（2个字节）道路名字的长度，并取其地址
        fread(&roadInfo,sizeof(long),1,fp);                  //读取一个long（4个字节）道路信息，并取其地址

        recordSize=M_CHG_INT16(recordSize);                    //调用宏反转短整型的16位进制码，反转道路记录大小
        LinkID=M_CHG_INT32(LinkID);                          //调用宏反转短整型的32位进制码，反转LinkID
        roadNameLen=M_CHG_INT16(roadNameLen);               //调用宏反转短整型的16位进制码，反转道路名的长度
        roadInfo=M_CHG_INT32(roadInfo);                     //调用宏反转短整型的32位进制码，反转道路信息

        flag=GET_FLAG(roadInfo);                      //获取标记有无道路名称的flag
        brunch=GET_BRUNCH(roadInfo);                  //获取道路分支数量
        disclass=GET_DISPCLASS(roadInfo);               //获取道路番号

        if(recordSize>12)                        //如果记录大小大于12（前面已用的内存），代表还有内存存道路名，并读取道路名
        {
            fread(roadName,recordSize-12,1,fp);  //roadName是一个数组，已是地址，不用在用取址符号“&”
            strcpy(eMap->roadRecord[eMap->roadNum].roadName,roadName);     //把二进制文本的道路名称复制结构体数组的道路名（新建的文本）
        }
        eMap->roadRecord[eMap->roadNum].recordSize=recordSize;             //把获取的记录大小赋值给结构体数组的记录大小
        eMap->roadRecord[eMap->roadNum].LinkID=LinkID;          //把获取的LinkID赋值给结构体数组LinkID
        eMap->roadRecord[eMap->roadNum].roadInfo=roadInfo;         //把获取的道路信息赋值给结构体数组的道路信息

        eMap->roadRecord[eMap->roadNum].brunch=brunch;
        eMap->roadRecord[eMap->roadNum].disclass=disclass;
        eMap->roadRecord[eMap->roadNum].flag=flag;


        fprintf(fileWrite,"%d\t信息大小:%d\tLinkID:%d\t有无Flag:%d\t分岔路数:%d\t番号:%d\t",  //把获取的一条道路的各种信息写进去文本文档中
                eMap->roadNum+1,recordSize,LinkID,flag,brunch,disclass);
        if(recordSize>12)                         //如果记录大小大于12，则有空间存储道路名称，
           fprintf(fileWrite,"道路名称:%s\n",roadName);            //把获取的道路名写入文件
        else
            fprintf(fileWrite,"无道路名称\n");                  //如果记录大小小于大于12，则无内存空间存储道路名
        eMap->roadNum++;                        //循环一次，写入一条道路，道路数量加1（即结构体数组索引加1）
    }
    cout<<"读取记录一共为:"<<eMap->roadNum<<endl;     //输出道路的数量

    fclose(fp);             //关闭文件
    cout<<"文件读取成功!\n";
    return 0;
}




