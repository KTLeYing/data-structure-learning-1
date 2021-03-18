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

int DeleteEmp()
{
    int i=0,find=0;
    EMP *emp1,*emp2;
    char name[10],choose;
    system("cls");
    cout<<"\n输入要删除员工的姓名:";
    cin>>name;
    emp1=emp_first;
    emp2=emp1;
    while(emp1)
    {
        if(strcmp(emp1->name,name)==0)
        {
            find=1;
            system("cls");
            cout<<"员工:"<<emp1->name<<"信息如下:";
            Bound('_',25);
            cout<<"工号:"<<emp1->num<<endl;
            cout<<"职务"<<emp1->duty<<endl;
            cout<<"姓名:"<<emp1->name<<endl;
            cout<<"性别:"<<emp1->sex<<endl;
            cout<<"年龄:"<<emp1->age<<endl;
            cout<<"文化程度:"<<emp1->edu<<endl;
            cout<<"工资:"<<emp1->salary<<endl;
            cout<<"办公电话:"<<emp1->tel_office<<endl;
            cout<<"家庭电话:"<<emp1->tel_home<<endl;
            cout<<"移动电话:"<<emp1->mobile<<endl;
            cout<<"QQ号码:"<<emp1->qq<<endl;
            cout<<"住址:"<<emp1->address<<endl;
            Bound('_',25);
            cout<<"真的要删除该员工的信息吗?(Y/N)";
            choose=getchar();
            if(choose!='Y' && choose!='y')
                return 0;
            if(emp1==emp_first)
                emp_first=emp1->next;
            else
                emp2->next=emp1->next;
            free(emp1);
            gsave=1;
            SaveData();
            return 0;
        }
        else
        {
            emp2=emp1;
            emp1=emp1->next;
        }
    }
    if(!find)
    {
        Bound('_',30);
        cout<<"未找到姓名为:"<<name<<"的信息!\n";
    }
    return 0;
}
