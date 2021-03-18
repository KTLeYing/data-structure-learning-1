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
    cout<<"原工资:"<<s<<endl;
    cout<<"新工资:";
    cin>>salary;
    return salary;
}

char *Modi_Field(char *field,char *s,int n)
{
    char *str;
    str=(char*)malloc(sizeof(char)*n);
    if(str==NULL)
    {
        cout<<"内存分配失败,按任意键返回!\n";
        return NULL;
    }
    cout<<"原"<<field<<":"<<s;
    cout<<"修改为(不超过"<<n<<"个字符):";
    cin>>str;
    return str;
}

int ModifyEmp()
{
    EMP *emp1;
    char name[10],*str;
    int choose;
    cout<<"\n输入要修改的员工姓名:";
    cin>>name;
    emp1=FindName(name);
    DisplayEmp(emp1,"姓名",name);
    if(emp1)
    {
        cout<<"\n选择要修改的项目:\n";
        Bound('_',35);
        cout<<"1.修改职务      2.修改文化程度\n";
        cout<<"3.修改工资      4.修改办公电话\n";
        cout<<"5.修改家庭电话  6.修改移动电话\n";
        cout<<"7.修改QQ号码    8.修改住址\n";
        cout<<"0.返回\n";
        Bound('_',35);
        cout<<"请选择:";
        do
        {
            cin>>choose;
            switch(choose)
            {
                 case 1:
                   str=Modi_Field("职务",emp1->duty,10);
                   if(str!=NULL)
                   {
                       strcpy(emp1->duty,str);
                       free(str);
                   }
                   break;
                case 2:
                   str=Modi_Field("文化程度",emp1->edu,10);
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
                   str=Modi_Field("办公电话",emp1->tel_office,13);
                   if(str!=NULL)
                   {
                       strcpy(emp1->tel_office,str);
                       free(str);
                   }
                   break;
               case 5:
                   str=Modi_Field("家庭电话",emp1->tel_home,13);
                   if(str!=NULL)
                   {
                       strcpy(emp1->tel_home,str);
                       free(str);
                   }
                   break;
               case 6:
                   str=Modi_Field("移动电话",emp1->mobile,12);
                   if(str!=NULL)
                   {
                       strcpy(emp1->mobile,str);
                       free(str);
                   }
                   break;
               case 7:
                   str=Modi_Field("QQ号码",emp1->qq,10);
                   if(str!=NULL)
                   {
                       strcpy(emp1->qq,str);
                       free(str);
                   }
                   break;
               case 8:
                   str=Modi_Field("住址",emp1->address,13);
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
        cout<<"\n修改完成，按任意键返回.\n";
    }
    return 0;
}
