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
#include "Header.h"

using namespace std;

ElecMap eMap;

int main()
{
    eMap.num=0;
    eMap.sorted=0;
    int choose=1;
    cout<<endl;
    cout<<"/**********************---Welcome!---**********************\n";
    cout<<"/***\t\t电子地图信息统计系统\t\t\t***/\n";
    cout<<"/***\t\t\t\t马振乐 2019年7月17日\t" "" "" "" "***/\n";
    cout<<"/**********************************************************\n";
    cout<<"请选择服务种类:\n";
    cout<<"\t\t1.读取文件(“./data/GTBL.dat”）\n";
    cout<<"\t\t2.排序（快速排序）并输出排序结果(“./data/GTBL.dat”）\n";
    cout<<"\t\t3.检索\n";
    cout<<"\t\t0.退出\n";
    while(choose)
    {
        cout<<"请选择:";
        fflush(stdin);
        cin>>choose;
        switch(choose)
        {
           case 1:
               ReadFile(&eMap);
               break;
           case 2:
               Sort(&eMap);
               break;
           case 3:
               Search(&eMap);
               break;
           case 0:
               return 0;
               break;
           default:
             cout<<"输入有误!请重新选择:\n";
        }
        cout<<"\n请选择服务种类:\n";
        cout<<"\t1.读取文件(“./data/GTBL.dat”)\n\t2.排序(快速排序)并输出排序结果(“./data/GTBL.dat”)\n\t3.检索\n\t0.退出\n";
    }
    cout<<"感谢您使用本程序!\n";

    return 0;
}
