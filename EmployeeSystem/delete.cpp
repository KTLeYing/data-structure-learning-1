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
    cout<<"\n����Ҫɾ��Ա��������:";
    cin>>name;
    emp1=emp_first;
    emp2=emp1;
    while(emp1)
    {
        if(strcmp(emp1->name,name)==0)
        {
            find=1;
            system("cls");
            cout<<"Ա��:"<<emp1->name<<"��Ϣ����:";
            Bound('_',25);
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
            cout<<"���Ҫɾ����Ա������Ϣ��?(Y/N)";
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
        cout<<"δ�ҵ�����Ϊ:"<<name<<"����Ϣ!\n";
    }
    return 0;
}
