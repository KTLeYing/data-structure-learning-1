/******************************************************************************************
*FunctionName:Search                                                                      *
*                                                                                         *
*Description:在已完成排序的基础上进行不同方式的检索                                     *
*                                                                                         *
*MakingDate:2019/7/20                                                                     *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include "header.h"        //引用头文件

using namespace std;

int BinarySearch_LinkID(ElecMap *eMap)      //用LinkID进行二分查找
{

     int key,mid;
     cout<<"请输入要检索的Link的ID:";
     cin>>key;
     int low=1,high=eMap->roadNum;
     while(low<=high)
     {
         mid=(low+high)/2;
         if(key==eMap->roadRecord[mid].LinkID)
         {
         	cout<<"查询结果为:\n";
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[mid].LinkID<<";roadflag="<<eMap->roadRecord[mid].flag
                   <<";brunch="<<eMap->roadRecord[mid].brunch<<";disclass="<<eMap->roadRecord[mid].disclass
                   <<";roadName="<<eMap->roadRecord[mid].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
            break;
          }
         else
            if(key<eMap->roadRecord[mid].LinkID)
                high=mid-1;
            else
                if(key>eMap->roadRecord[mid].LinkID)
                    low=mid+1;
     }
}

int SqSearch_RoadName(ElecMap *eMap)           //用路名进行顺序查找
{
     FILE *pf;
     pf=fopen("searchroadnameresult.txt","w+");
     char r_name[30];
     cout<<"请输入要检索的路名:";
     cin>>r_name;
     int sum=0,i;
     for(i=eMap->roadNum;i>=1;i--)
        if(strcmp(eMap->roadRecord[i].roadName,r_name)==0)
           sum++;
     if(sum==0)
        cout<<"没有该名字的道路\n";
     else
        if(sum<5)
       {
            cout<<"查询结果为:(结果小于5条，直接输出)\n";
            for(i=eMap->roadNum;i>=1;i--)
              if(strcmp(eMap->roadRecord[i].roadName,r_name)==0)
               {
                    cout<<"**************************************************************************\n";
                    cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].flag
                    <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].disclass
                    <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                    cout<<"**************************************************************************\n";
               }
       }
       else
          if(sum>=5)
          {
               cout<<"**************************************************************************\n";
               cout<<"\t结果大于5条，已将其转存到文本文件D:\\searchroadnameresult.txt\n";
               cout<<"**************************************************************************\n";
               for(i=eMap->roadNum;i>=1;i--)
                  if(strcmp(eMap->roadRecord[i].roadName,r_name)==0)
                  {
                      fprintf(pf,"linkid=%d\troadflag=%d\tbrunch=%d\t\tdisclass=%d\troadName=%s\n",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass,
                      eMap->roadRecord[i].roadName);
                  }
          }
     return 0;
}


int  SqSearch_RoadBrunchNum(ElecMap *eMap)       //用分支数进行顺序查找
{
    FILE *pf;
    pf=fopen("searchbrunchresult.txt","w+");
    int sum=0,i,key;
    cout<<"请输入要检索的路的分支数:";
    cin>>key;
    for(i=eMap->roadNum;i>=1;i--)
        if(eMap->roadRecord[i].brunch==key)
            sum++;
    if(sum==0)
        cout<<"没有该岔路数的道路!\n";
    else
        if(sum<5)
        {
            cout<<"查询结果为:(结果小于5条，直接输出)\n";
            for(i=eMap->roadNum;i>=1;i--)
               if(eMap->roadRecord[i].brunch==key)
               {
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].flag
                   <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].disclass
                   <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
               }
        }
        else
            if(sum>=5)
            {
                cout<<"**************************************************************************\n";
                cout<<"\t结果大于5条，已将其转存到文本文件D:\\searchbrunchresult.txt\n";
                cout<<"**************************************************************************\n";
                for(i=eMap->roadNum;i>=1;i--)
                   if(eMap->roadRecord[i].brunch==key)
                   {
                      fprintf(pf,"linkid=%d\troadflag=%d\tbrunch=%d\t\tdisclass=%d\troadName=%s\n",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass,
                      eMap->roadRecord[i].roadName);
                   }
            }
     return 0;
}

int SqSearch_Class(ElecMap *eMap)       //用番号进行顺序查找
{
    FILE *pf;
    pf=fopen("searchclassinforesult.txt","w+");
    int sum=0,i,key;
    cout<<"请输入要检索的番号:";
    cin>>key;
    for(i=eMap->roadNum;i>=1;i--)
        if(eMap->roadRecord[i].disclass==key)
            sum++;
    if(sum==0)
        cout<<"没有该番号的道路!\n";
    else
        if(sum<5)
        {
            cout<<"查询结果为:(结果小于5条，直接输出)\n";
            for(i=eMap->roadNum;i>=1;i--)
               if(eMap->roadRecord[i].disclass==key)
               {
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].flag
                   <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].disclass
                   <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
               }
        }
        else
            if(sum>=5)
            {
                cout<<"**************************************************************************\n";
                cout<<"\t结果大于5条，已将其转存到文本文件D:\\searchclassinforesult.txt\n";
                cout<<"*********************************************s*****************************\n";
                for(i=eMap->roadNum;i>=1;i--)
                   if(eMap->roadRecord[i].disclass==key)
                   {
                      fprintf(pf,"linkid=%d\troadflag=%d\tbrunch=%d\t\tdisclass=%d\troadName=%s\n",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass,
                      eMap->roadRecord[i].roadName);
                   }
            }
    return 0;

}

int Search(ElecMap *eMap)       //所有查找方式的汇集，选择自己想要的检索方式进行检索
{
    int choose=1,key;
    char name[30];
    cout<<"检索方式如下:\n";
    cout<<"\t1.指定LinkID 检索\n\t2.指定道路名称 检索\n\t3.查找岔路数 检索\n\t4.指定的交叉Link列表示Class番号 检索\n\t0.返回\n";
    while(choose)
    {
        cout<<"\n请选择检索方式:";
        cin>>choose;
        switch(choose)
        {
           case 1:                        //选1用LinkID进行折半查找
             BinarySearch_LinkID(eMap);
             break;
           case 2:                         //选2用路名进行顺序查找
             SqSearch_RoadName(eMap);
             break;
           case 3:                          //选3用分支数进行顺序查找
             SqSearch_RoadBrunchNum(eMap);
             break;
           case 4:                          //选4用番号进行顺序查找
             SqSearch_Class(eMap);
             break;
           case 0:                       //选0退出检索
               cout<<"退出检索!\n";
               break;
           default:
             cout<<"输入有误!请重新选择!\n";
        }
    }
}
