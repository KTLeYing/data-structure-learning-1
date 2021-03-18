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

EMP *FindName(char *name)
{
    EMP *emp1;
    emp1=emp_first;
    while(emp1)
    {
        if(strcmp(name,emp1->name)==0)
            return emp1;
        emp1=emp1->next;
    }
    return NULL;
}

EMP *FindNum(int num)
{
    EMP *emp1;
    emp1=emp_first;
    while(emp1)
    {
        if(num==emp1->num)
            return emp1;
        emp1=emp1->next;
    }
    return NULL;
}

EMP *FindTelephone(char *name)
{
    EMP *emp1;
    emp1=emp_first;
    while(emp1)
    {
        if((strcmp(name,emp1->tel_office)==0) || (strcmp(name,emp1->tel_home)==0) || (strcmp(name,emp1->mobile)==0))
            return emp1;
        emp1=emp1->next;
    }
    return NULL;
}

EMP *FindQQ(char *name)
{
    EMP *emp1;
    emp1=emp_first;
    while(emp1)
    {
        if(strcmp(name,emp1->qq)==0)
            return emp1;
        emp1=emp1->next;
    }
    return NULL;
}

int DisplayEmp(EMP *emp,char *field,char *name)
{
    if(emp)
    {
        cout<<"\n"<<field<<":"<<name<<"��Ϣ����:\n";
        Bound('_',25);
        cout<<"����:"<<emp->num<<endl;
        cout<<"ְ��"<<emp->duty<<endl;
        cout<<"����:"<<emp->name<<endl;
        cout<<"�Ա�:"<<emp->sex<<endl;
        cout<<"����:"<<emp->age<<endl;
        cout<<"�Ļ��̶�:"<<emp->edu<<endl;
        cout<<"����:"<<emp->salary<<endl;
        cout<<"�칫�绰:"<<emp->tel_office<<endl;
        cout<<"��ͥ�绰:"<<emp->tel_home<<endl;
        cout<<"�ƶ��绰:"<<emp->mobile<<endl;
        cout<<"QQ����:"<<emp->qq<<endl;
        cout<<"סַ:"<<emp->address<<endl;
        Bound('_',20);
    }
    else
    {
        Bound('_',40);
        cout<<"ϵͳ��û��"<<field<<"Ϊ:"<<name<<"��Ա����Ϣ!\n";
    }
}

int FindEmp()
{
    int choose,ret=0,num;
    char str[13];
    EMP *emp1;
    system("cls");
    do
    {
        cout<<"\t��ѯԱ����Ϣ\n";
        Bound('_',25);
        cout<<"\t1.��������ѯ\n";
        cout<<"\t2.�����Ų�ѯ\n";
        cout<<"\t3.���绰��ѯ\n";
        cout<<"\t4.��QQ�Ų�ѯ\n";
        cout<<"\t0.�������˵�\n";
        Bound('_',25);
        cout<<"\n��ѡ��˵�:";
        do
        {
            cin>>choose;
            system("cls");
            switch(choose)
            {
                case 1:
                     cout<<"\n������Ҫ��ѯԱ��������";
                     cin>>str;
                     emp1=FindName(str);
                     DisplayEmp(emp1,"����",str);
                     break;
                case 2:
                     cout<<"\n����Ҫ��ѯԱ���Ĺ���";
                     cin>>num;
                     emp1=FindNum(num);
                     itoa(num,str,10);
                     DisplayEmp(emp1,"����",str);
                     break;
                case 3:
                    cout<<"\n����Ҫ��ѯԱ���ĵ绰:";
                    cin>>str;
                    emp1=FindTelephone(str);
                    DisplayEmp(emp1,"�绰",str);
                    break;
                case 4:
                    cout<<"\n����Ҫ��ѯ��Ա����QQ����:";
                    cin>>str;
                    emp1=FindQQ(str);
                    DisplayEmp(emp1,"QQ����",str);
                    break;
                case 0:
                    ret=1;
                    break;
            }
        }while(choose<0 || choose>4);
        system("cls");
        if(ret)
            break;
    }while(1);
}
