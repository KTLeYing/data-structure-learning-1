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

int SummaryEmp()
{
    EMP *emp1;
    int sum=0,num=0,man=0,woman=0;
    emp1=emp_first;
    while(emp1)
    {
        num++;
        sum+=emp1->salary;
        if(strcmp(emp1->sex,"男")==0)
            man++;
        else
            woman++;
        emp1=emp1->next;
    }
    cout<<"\n员工统计信息:\n";
    Bound('_',20);
    cout<<"总人数:"<<num<<endl;
    cout<<"男:"<<man<<endl;
    cout<<"女:"<<woman<<endl;
    cout<<"工资总额:"<<sum<<endl;
    Bound('_',20);
    cout<<"按任意键返回!\n";
    return 0;
}
