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
        cout<<"\n"<<field<<":"<<name<<"信息如下:\n";
        Bound('_',25);
        cout<<"工号:"<<emp->num<<endl;
        cout<<"职务"<<emp->duty<<endl;
        cout<<"姓名:"<<emp->name<<endl;
        cout<<"性别:"<<emp->sex<<endl;
        cout<<"年龄:"<<emp->age<<endl;
        cout<<"文化程度:"<<emp->edu<<endl;
        cout<<"工资:"<<emp->salary<<endl;
        cout<<"办公电话:"<<emp->tel_office<<endl;
        cout<<"家庭电话:"<<emp->tel_home<<endl;
        cout<<"移动电话:"<<emp->mobile<<endl;
        cout<<"QQ号码:"<<emp->qq<<endl;
        cout<<"住址:"<<emp->address<<endl;
        Bound('_',20);
    }
    else
    {
        Bound('_',40);
        cout<<"系统中没有"<<field<<"为:"<<name<<"的员工信息!\n";
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
        cout<<"\t查询员工信息\n";
        Bound('_',25);
        cout<<"\t1.按姓名查询\n";
        cout<<"\t2.按工号查询\n";
        cout<<"\t3.按电话查询\n";
        cout<<"\t4.按QQ号查询\n";
        cout<<"\t0.返回主菜单\n";
        Bound('_',25);
        cout<<"\n请选择菜单:";
        do
        {
            cin>>choose;
            system("cls");
            switch(choose)
            {
                case 1:
                     cout<<"\n输入想要查询员工的姓名";
                     cin>>str;
                     emp1=FindName(str);
                     DisplayEmp(emp1,"姓名",str);
                     break;
                case 2:
                     cout<<"\n输入要查询员工的工号";
                     cin>>num;
                     emp1=FindNum(num);
                     itoa(num,str,10);
                     DisplayEmp(emp1,"工号",str);
                     break;
                case 3:
                    cout<<"\n输入要查询员工的电话:";
                    cin>>str;
                    emp1=FindTelephone(str);
                    DisplayEmp(emp1,"电话",str);
                    break;
                case 4:
                    cout<<"\n输入要查询的员工的QQ号码:";
                    cin>>str;
                    emp1=FindQQ(str);
                    DisplayEmp(emp1,"QQ号码",str);
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
