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

int ListEmp()
{
    EMP *emp1;
    cout<<"\n员工列表:\n";
    Bound('_',25);
    emp1=emp_first;
    while(emp1)
    {
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
        emp1=emp1->next;
    }
    cout<<"\n按任意键返回\n";
}
