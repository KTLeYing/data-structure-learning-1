/******************************************************************************************
*FunctionName:Search                                                                      *
*                                                                                         *
*Description:�ò�ͬ�ļ�����ʽ������·��Ϣ                                               *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:������                                                                             *
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
        cout<<"û�и÷��ŵĵ�·!";
    else
        if(sum<5)
        {
            for(i=eMap->num;i>=1;i--)
               if(eMap->roadRecord[i].classInfo==key)
               {
                   cout<<"��ѯ���Ϊ:\n";
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
                cout<<"\t�������5��������ת�浽�ı��ļ�D:\\searchlinkidresult.txt\n";
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
        cout<<"û�иò�·���ĵ�·!";
    else
        if(sum<5)
        {
            for(i=eMap->num;i>=1;i--)
               if(eMap->roadRecord[i].brunch==key)
               {
                   cout<<"��ѯ���Ϊ:\n";
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
                cout<<"\t�������5��������ת�浽�ı��ļ�D:\\searchresult.txt\n";
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
        cout<<"û�и����ֵĵ�·";
     else
        if(sum<5)
       {
            for(i=eMap->num;i>=1;i--)
              if(strcmp(eMap->roadRecord[i].roadName,name)==0)
               {
                    cout<<"��ѯ���Ϊ:\n";
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
               cout<<"\t�������5��������ת�浽�ı��ļ�D:\\searchroadnameresult.txt\n";
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
    cout<<"��ѡ�������ʽ:\n";
    cout<<"\t1.ָ��LinkID ����\n\t2.ָ���Ľ���Link�б�ʾClass���� ����\n\t3.���Ҳ�·�� ����\n\t4.ָ����·���� ����\n\t0.����\n";
    int choose,sum=0,mid,key;
    char name[30];
    cout<<"��ѡ��:";
    cin>>choose;
    if(choose==1)
    {
        cout<<"������Link��ID:";
        cin>>key;
        cout<<endl;
        mid=BinarySearch_LinkID(&eMap,key);
        if(mid!=0)
        {
            cout<<"��ѯ���Ϊ:\n";
            cout<<"**************************************************************************\n";
            cout<<"#linkid="<<eMap->roadRecord[mid].LinkID<<";roadflag="<<eMap->roadRecord[mid].roadFlag
            <<";brunch="<<eMap->roadRecord[mid].brunch<<";disclass="<<eMap->roadRecord[mid].classInfo
            <<";roadName="<<eMap->roadRecord[mid].roadName<<"#\n";
            cout<<"**************************************************************************\n";
            sum++;
         }
         if(sum==0)
            cout<<"û��ƥ��Ľ�����������!\n";
         return 0;
     }
     if(choose==2)
     {
          cout<<"�����뽻��Link�б�ʾ��Class����:";
          cin>>key;
          cout<<endl;
          LinearSearch_Class(&eMap,key);
     }
     if(choose==3)
     {
         cout<<"������Ҫ���ҵĲ�·��:";
         cin>>key;
         cout<<endl;
         LinearSearch_RoadBrunchNum(&eMap,key);
     }
     if(choose==4)
     {
         cout<<"������Ҫ���ҵĵ�·����:";
         cin>>name[30];
         cout<<endl;
         LinearSearch_RoadName(&eMap,char name);
     }
     if(choose==0)
     {
         cout<<"��������!������ѡ�������ʽ!\n";
     }


}
