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
    cout<<"\nԱ���б�:\n";
    Bound('_',25);
    emp1=emp_first;
    while(emp1)
    {
        cout<<"����:"<<emp1->num<<endl;
        cout<<"ְ��"<<emp1->duty<<endl;
        cout<<"����:"<<emp1->name<<endl;
        cout<<"�Ա�:"<<emp1->sex<<endl;
        cout<<"����:"<<emp1->age<<endl;
        cout<<"�Ļ��̶�:"<<emp1->edu<<endl;
        cout<<"����:"<<emp1->salary<<endl;
        cout<<"�칫�绰:"<<emp1->tel_office<<endl;
        cout<<"��ͥ�绰:"<<emp1->tel_home<<endl;
        cout<<"�ƶ��绰:"<<emp1->mobile<<endl;
        cout<<"QQ����:"<<emp1->qq<<endl;
        cout<<"סַ:"<<emp1->address<<endl;
        Bound('_',25);
        emp1=emp1->next;
    }
    cout<<"\n�����������\n";
}
