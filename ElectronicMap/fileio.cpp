/******************************************************************************************
*FunctionName:ReadFile                                                                    *
*                                                                                         *
*Description:读取二进制文件，并将存储在文本文档中                                       *
*                                                                                         *
*MakingDate:2019/7/19                                                                     *
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
    unsigned short e_recordSize;       //使用全局变量的结构体数组进行索引
    unsigned int e_LinkID;
    unsigned short e_roadNameLen;
    unsigned int e_roadInfo;              //道路信息
    char e_roadName[30];            //数组存储道路名字

    unsigned int e_disclass;      //番号
    unsigned int e_brunch;       //分支
    int e_flag;                   //标志

    if((fp=fopen("d:\\GTBL.dat","rb"))==NULL)      //判断GTBL文件是否为空，若为空则打开失败
    {
       cout<<"文件打开失败!\n";
       exit(0);
    }
    cout<<"文件打开成功!\n";                    //文件不能空，则成功打开文件，并读取二进制文件

    fileWrite=fopen("Map.txt","w+");         //文件指针fileWrite指向要存储进去的目标文本文件，并写进文本文件中
    cout<<"文件读取中......\n";
    while(1)
    {
        fread(&e_recordSize,2,1,fp);    //读取一个short int（2个字节）的道路记录大小，并取地址
        if(feof(fp))                                  //如果读取到二进制文件的结尾时，结束读取
            break;
        fread(&e_LinkID,4,1,fp);          //读取一个long（4个字节）的道路LinkID，并取其地址
        fread(&e_roadNameLen,2,1,fp);            //读取一个short int（2个字节）道路名字的长度，并取其地址
        fread(&e_roadInfo,4,1,fp);                  //读取一个long（4个字节）道路信息，并取其地址

        e_recordSize=M_CHG_INT16(e_recordSize);                    //调用宏反转短整型的16位进制码，反转道路记录大小
        e_LinkID=M_CHG_INT32(e_LinkID);                          //调用宏反转短整型的32位进制码，反转LinkID
        e_roadNameLen=M_CHG_INT16(e_roadNameLen);               //调用宏反转短整型的16位进制码，反转道路名的长度
        e_roadInfo=M_CHG_INT32(e_roadInfo);                     //调用宏反转短整型的32位进制码，反转道路信息

        e_flag=GET_FLAG(e_roadInfo);                      //获取标记有无道路名称的flag
        e_brunch=GET_BRUNCH(e_roadInfo);                  //获取道路分支数量
        e_disclass=GET_DISPCLASS(e_roadInfo);               //获取道路番号

        if(e_recordSize>12)                        //如果记录大小大于12（前面已用的内存），代表还有内存存道路名，并读取道路名
        {
            fread(e_roadName,e_recordSize-12,1,fp);  //roadName是一个数组，已是地址，不用在用取址符号“&”
            strcpy(eMap->roadRecord[eMap->roadNum].roadName,e_roadName);     //把二进制文本的道路名称复制结构体数组的道路名（新建的文本）
        }
        eMap->roadRecord[eMap->roadNum].recordSize=e_recordSize;             //把获取的记录大小赋值给结构体数组的记录大小
        eMap->roadRecord[eMap->roadNum].LinkID=e_LinkID;          //把获取的LinkID赋值给结构体数组LinkID
        eMap->roadRecord[eMap->roadNum].roadInfo=e_roadInfo;         //把获取的道路信息赋值给结构体数组的道路信息

        eMap->roadRecord[eMap->roadNum].brunch=e_brunch;           //把获取到的分支给结构体数组的分支
        eMap->roadRecord[eMap->roadNum].disclass=e_disclass;        //把获取到的番号给结构体数组的番号
        eMap->roadRecord[eMap->roadNum].flag=e_flag;                //把获取到的道路标志给结构体数组的道路标志


        fprintf(fileWrite,"%d\t信息大小:%d\tLinkID:%d\t有无Flag:%d\t分岔路数:%d\t番号:%d\t",  //把获取的一条道路的各种信息写进去文本文档中
                eMap->roadNum+1,e_recordSize,e_LinkID,e_flag,e_brunch,e_disclass);
        if(e_recordSize>12)                         //如果记录大小大于12，则有空间存储道路名称，
           fprintf(fileWrite,"道路名称:%s\n",e_roadName);            //把获取的道路名写入文件
        else
            fprintf(fileWrite,"无道路名称\n");                  //如果记录大小小于大于12，则无内存空间存储道路名
        eMap->roadNum++;                        //循环一次，写入一条道路，道路数量加1（即结构体数组索引加1）
    }
    cout<<"读取记录一共为:"<<eMap->roadNum<<endl;     //输出道路的数量

    fclose(fp);             //关闭文件
    cout<<"文件读取成功!\n";
    return 0;
}




