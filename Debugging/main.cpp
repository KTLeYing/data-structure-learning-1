/******************************************************************************************
*FunctionName:Main                                                                        *
*                                                                                         *
*Description:主函数，该系统的入口，对各种模块函数进行调用                               *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<cstdlib>
#include<iostream>
#include "header.h"     //引用header头文件

using namespace std;

ElecMap eMap;      //定义一个结构体成员变量

int main()
{
    int choose=1;
    eMap.roadNum=0;      //初始化道路数量
    eMap.roadSort=0;      //初始化道路未排序
    cout<<endl;
    cout<<"/**********************---Welcome!---**********************\n";
    cout<<"/***\t\t电子地图信息统计系统\t\t\t***/\n";
    cout<<"/***\t\t\t\t马振乐 2019年7月17日\t" "" "" "" "***/\n";
    cout<<"/**********************************************************\n";

    while(choose)
    {
    	cout<<"\n请选择服务种类:\n";
        cout<<"\t1.读取文件(“./data/GTBL.dat”)\n\t2.排序(快速排序)并输出排序结果(“./data/GTBL.dat”)\n\t3.检索\n\t0.退出\n";
        cout<<"请选择:";
        fflush(stdin);     //强制将缓冲区中的内容写入文件
        cin>>choose;
        switch(choose)
        {
           case 1:
               ReadFile(&eMap);       //选择1时进行二进制文件读取
               break;
           case 2:
               TotalSort(&eMap);         //选择2时对已存入文本文件进行道路排序
               break;
           case 3:
               Search(&eMap);
               break;
           case 0:
               break;
           default:
             cout<<"输入有误!请重新选择!\n";
        }
    }
    cout<<"\n......\n......\n\n成功退出电子地图信息统计系统!感谢您使用本程序!\n";

    return 0;
}
