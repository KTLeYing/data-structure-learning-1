#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include "header.h"

using namespace std;

int Bound(char ch,int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<ch;
    cout<<endl;
}

int Modi_Salary(int s)
{
    int salary;
    cout<<"ԭ����:"<<s<<endl;
    cout<<"�¹���:";
    cin>>salary;
    return salary;
}

char *Modi_Field(char *field,char *s,int n)
{
    char *str;
    str=(char*)malloc(sizeof(char)*n);
    if(str==NULL)
    {
        cout<<"�ڴ����ʧ��,�����������!\n";
        return NULL;
    }
    cout<<"ԭ"<<field<<":"<<s;
    cout<<"�޸�Ϊ(������"<<n<<"���ַ�):";
    cin>>str;
    return str;
}

int ModifyEmp()
{
    EMP *emp1;
    char name[10],*str;
    int choose;
    cout<<"\n����Ҫ�޸ĵ�Ա������:";
    cin>>name;
    emp1=FindName(name);
    DisplayEmp(emp1,"����",name);
    if(emp1)
    {
        cout<<"\nѡ��Ҫ�޸ĵ���Ŀ:\n";
        Bound('_',35);
        cout<<"1.�޸�ְ��      2.�޸��Ļ��̶�\n";
        cout<<"3.�޸Ĺ���      4.�޸İ칫�绰\n";
        cout<<"5.�޸ļ�ͥ�绰  6.�޸��ƶ��绰\n";
        cout<<"7.�޸�QQ����    8.�޸�סַ\n";
        cout<<"0.����\n";
        Bound('_',35);
        cout<<"��ѡ��:";
        do
        {
            cin>>choose;
            switch(choose)
            {
                 case 1:
                   str=Modi_Field("ְ��",emp1->duty,10);
                   if(str!=NULL)
                   {
                       strcpy(emp1->duty,str);
                       free(str);
                   }
                   break;
                case 2:
                   str=Modi_Field("�Ļ��̶�",emp1->edu,10);
                   if(str!=NULL)
                   {
                       strcpy(emp1->edu,str);
                       free(str);
                   }
                   break;
               case 3:
                   emp1->salary=Modi_Salary(emp1->salary);
                   break;
               case 4:
                   str=Modi_Field("�칫�绰",emp1->tel_office,13);
                   if(str!=NULL)
                   {
                       strcpy(emp1->tel_office,str);
                       free(str);
                   }
                   break;
               case 5:
                   str=Modi_Field("��ͥ�绰",emp1->tel_home,13);
                   if(str!=NULL)
                   {
                       strcpy(emp1->tel_home,str);
                       free(str);
                   }
                   break;
               case 6:
                   str=Modi_Field("�ƶ��绰",emp1->mobile,12);
                   if(str!=NULL)
                   {
                       strcpy(emp1->mobile,str);
                       free(str);
                   }
                   break;
               case 7:
                   str=Modi_Field("QQ����",emp1->qq,10);
                   if(str!=NULL)
                   {
                       strcpy(emp1->qq,str);
                       free(str);
                   }
                   break;
               case 8:
                   str=Modi_Field("סַ",emp1->address,13);
                   if(str!=NULL)
                   {
                       strcpy(emp1->address,str);
                       free(str);
                   }
                   break;
               case 0:
                    return 0;
           }
        }while(choose<0 || choose>8);
        gsave=1;
        SaveData();
        cout<<"\n�޸���ɣ������������.\n";
    }
    return 0;
}
