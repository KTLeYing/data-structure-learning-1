/******************************************************************************************
*FunctionName:Main                                                                        *
*                                                                                         *
*Description:����������ϵͳ����ڣ��Ը���ģ�麯�����е���                               *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<cstdlib>
#include<iostream>
#include "header.h"     //����headerͷ�ļ�

using namespace std;

ElecMap eMap;      //����һ���ṹ���Ա����

int main()
{
    int choose=1;
    eMap.roadNum=0;      //��ʼ����·����
    eMap.roadSort=0;      //��ʼ����·δ����
    cout<<endl;
    cout<<"/**********************---Welcome!---**********************\n";
    cout<<"/***\t\t���ӵ�ͼ��Ϣͳ��ϵͳ\t\t\t***/\n";
    cout<<"/***\t\t\t\t������ 2019��7��17��\t" "" "" "" "***/\n";
    cout<<"/**********************************************************\n";
    cout<<"��ѡ���������:\n";
    cout<<"\t\t1.��ȡ�ļ�(��./data/GTBL.dat����\n";
    cout<<"\t\t2.���򣨿������򣩲����������(��./data/GTBL.dat����\n";
    cout<<"\t\t3.����\n";
    cout<<"\t\t0.�˳�\n";
    while(choose)
    {
        cout<<"��ѡ��:";
        fflush(stdin);     //ǿ�ƽ��������е�����д���ļ�
        cin>>choose;
        switch(choose)
        {
           case 1:
               ReadFile(&eMap);       //ѡ��1ʱ���ж������ļ���ȡ
               break;
           /*case 2:
               Sort(&eMap);         //ѡ��2ʱ���Ѵ����ı��ļ����е�·����
               break;
           case 3:
               Search(&eMap);
               break;*/
           case 0:
               return 0;
               break;
           default:
             cout<<"��������!������ѡ��!\n";
        }
        cout<<"\n��ѡ���������:\n";
        cout<<"\t1.��ȡ�ļ�(��./data/GTBL.dat��)\n\t2.����(��������)�����������(��./data/GTBL.dat��)\n\t3.����\n\t0.�˳�\n";
    }
    cout<<"��л��ʹ�ñ�����!\n";

    return 0;
}