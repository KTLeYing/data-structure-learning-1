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
        if(strcmp(emp1->sex,"��")==0)
            man++;
        else
            woman++;
        emp1=emp1->next;
    }
    cout<<"\nԱ��ͳ����Ϣ:\n";
    Bound('_',20);
    cout<<"������:"<<num<<endl;
    cout<<"��:"<<man<<endl;
    cout<<"Ů:"<<woman<<endl;
    cout<<"�����ܶ�:"<<sum<<endl;
    Bound('_',20);
    cout<<"�����������!\n";
    return 0;
}
