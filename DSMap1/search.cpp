/******************************************************************************************
*FunctionName:Search                                                                      *
*                                                                                         *
*Description:用不同的检索方式检索道路信息                                               *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include "Header.h"

using namespace std;

int BinarySearch_LinkID(ElecMap *eMap,int key)
{
    int low=1,high=eMap->num,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==eMap->roadRecord[mid].LinkID)
           return mid;
        else
            if(key<eMap->roadRecord[mid].LinkID)
                high=mid-1;
            else
                if(key>eMap->roadRecord[mid].LinkID)
                    low=mid+1;
    }
    return 0;
}

int LinearSearch_Class(ElecMap *eMap,int key)
{
    FILE *pf;
    int i,sum=0;
    for(i=eMap->num;i>=1;i--)
        if(eMap->roadRecord[i].classInfo==key)
            sum++;
    if(sum==0)
        cout<<"没有该番号的道路!";
    else
        if(sum<5)
        {
            for(i=eMap->num;i>=1;i--)
               if(eMap->roadRecord[i].classInfo==key)
               {
                   cout<<"查询结果为:\n";
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].roadFlag
                   <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].classInfo
                   <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
               }
        }
        else
            if(sum>=5)
            {
                cout<<"**************************************************************************\n";
                cout<<"\t结果大于5条，将其转存到文本文件D:\\searchlinkidresult.txt\n";
                cout<<"*********************************************s*****************************\n";
                pf=fopen("D:\\searchclassinforesult.txt","w");
                for(i=eMap->num;i>=1;i--)
                   if(eMap->roadRecord[i].classInfo==key)
                   {
                      fprintf(pf,"#linkid=%d;roadflag=%d;brunch=%d;disclass=%d;roadName=%d#",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].roadFlag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].classInfo,
                      eMap->roadRecord[i].roadName);
                   }
                fclose(pf);
                return 0;
            }
}

int LinearSearch_RoadBrunchNum(ElecMap *eMap,int key)
{
    FILE *pf;
    int i,sum=0;
    for(i=eMap->num;i>=1;i--)
        if(eMap->roadRecord[i].brunch==key)
            sum++;
    if(sum==0)
        cout<<"没有该岔路数的道路!";
    else
        if(sum<5)
        {
            for(i=eMap->num;i>=1;i--)
               if(eMap->roadRecord[i].brunch==key)
               {
                   cout<<"查询结果为:\n";
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].roadFlag
                   <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].classInfo
                   <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
               }
        }
        else
            if(sum>=5)
            {
                cout<<"**************************************************************************\n";
                cout<<"\t结果大于5条，将其转存到文本文件D:\\searchresult.txt\n";
                cout<<"**************************************************************************\n";
                pf=fopen("D:\\searchbrunchresult.txt","w");
                for(i=eMap->num;i>=1;i--)
                   if(eMap->roadRecord[i].brunch==key)
                   {
                      fprintf(pf,"#linkid=%d;roadflag=%d;brunch=%d;disclass=%d;roadName=%d#",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].roadFlag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].classInfo,
                      eMap->roadRecord[i].roadName);
                   }
                fclose(pf);
                return 0;
            }
}

int LinearSearch_RoadName(ElecMap *eMap,char name[])
{
     FILE *pf;
     int sum=0,i;
     for(i=eMap->num;i>=1;i--)
        if(strcmp(eMap->roadRecord[i].roadName,name)==0)
           sum++;
     if(sum==0)
        cout<<"没有该名字的道路";
     else
        if(sum<5)
       {
            for(i=eMap->num;i>=1;i--)
              if(strcmp(eMap->roadRecord[i].roadName,name)==0)
               {
                    cout<<"查询结果为:\n";
                    cout<<"**************************************************************************\n";
                    cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].roadFlag
                    <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].classInfo
                    <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                    cout<<"**************************************************************************\n";
               }
       }
       else
          if(sum>=5)
          {
               cout<<"**************************************************************************\n";
               cout<<"\t结果大于5条，将其转存到文本文件D:\\searchroadnameresult.txt\n";
               cout<<"**************************************************************************\n";
               pf=fopen("D:\\searchroadnameresult.txt","w");
               for(i=eMap->num;i>=1;i--)
                  if(strcmp(eMap->roadRecord[i].roadName,name)==0)
                  {
                      fprintf(pf,"#linkid=%d;roadflag=%d;brunch=%d;disclass=%d;roadName=%d#",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].roadFlag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].classInfo,
                      eMap->roadRecord[i].roadName);
                  }
               fclose(pf);
               return 0;
          }
}


int Search(ElecMap *eMap)
{
    cout<<"请选择检索方式:\n";
    cout<<"\t1.指定LinkID 检索\n\t2.指定的交叉Link列表示Class番号 检索\n\t3.查找岔路数 检索\n\t4.指定道路名称 检索\n\t0.返回\n";
    int choose,sum=0,mid,key;
    char name[30];
    cout<<"请选择:";
    cin>>choose;
    if(choose==1)
    {
        cout<<"请输入Link的ID:";
        cin>>key;
        cout<<endl;
        mid=BinarySearch_LinkID(&eMap,key);
        if(mid!=0)
        {
            cout<<"查询结果为:\n";
            cout<<"**************************************************************************\n";
            cout<<"#linkid="<<eMap->roadRecord[mid].LinkID<<";roadflag="<<eMap->roadRecord[mid].roadFlag
            <<";brunch="<<eMap->roadRecord[mid].brunch<<";disclass="<<eMap->roadRecord[mid].classInfo
            <<";roadName="<<eMap->roadRecord[mid].roadName<<"#\n";
            cout<<"**************************************************************************\n";
            sum++;
         }
         if(sum==0)
            cout<<"没有匹配的结果或输入错误!\n";
         return 0;
     }
     if(choose==2)
     {
          cout<<"请输入交叉Link列表示的Class番号:";
          cin>>key;
          cout<<endl;
          LinearSearch_Class(&eMap,key);
     }
     if(choose==3)
     {
         cout<<"请输入要查找的岔路数:";
         cin>>key;
         cout<<endl;
         LinearSearch_RoadBrunchNum(&eMap,key);
     }
     if(choose==4)
     {
         cout<<"请输入要查找的道路名字:";
         cin>>name[30];
         cout<<endl;
         LinearSearch_RoadName(&eMap,char name);
     }
     if(choose==0)
     {
         cout<<"输入有误!请重新选择检索方式!\n";
     }


}
