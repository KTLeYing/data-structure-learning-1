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

int AddEmp()
{
    FILE *fp;
    EMP *emp1;
    int i=0;
    char choose='Y';
    if((fp=fopen("emp.dat","ab"))==NULL)
    {
        cout<<"���ļ�emp.dat����!\n";
        return 0;
    }
    do
    {
        i++;
        emp1=(EMP *)malloc(sizeof(EMP));
        if(emp1==NULL)
        {
            cout<<"�ڴ����ʧ��,�����������!\n";
            return 0;
        }
        cout<<"�����"<<i<<"��Ա������Ϣ:\n";
        Bound('_',20);
        cout<<"����:";
        cin>>emp1->num;
        cout<<"ְ��:";
        cin>>emp1->duty;
        cout<<"����:";
        cin>>emp1->name;
        cout<<"�Ա�:";
        cin>>emp1->sex;
        cout<<"����:";
        cin>>emp1->age;
        cout<<"�Ļ��̶�:";
        cin>>emp1->edu;
        cout<<"����:";
        cin>>emp1->salary;
        cout<<"�칫�绰:";
        cin>>emp1->tel_office;
        cout<<"��ͥ�绰:";
        cin>>emp1->tel_home;
        cout<<"�ƶ��绰:";
        cin>>emp1->mobile;
        cout<<"QQ:";
        cin>>emp1->qq;
        cout<<"סַ:";
        cin>>emp1->address;
        emp1->next=NULL;
        if(emp_first==NULL)
        {
            emp_first=emp1;
            emp_end=emp1;
        }
        else
        {
            emp_end->next=emp1;
            emp_end=emp1;
        }
        fwrite(emp_end,sizeof(EMP),1,fp);
        gfirst=0;
        cout<<"\n";
        Bound('_',20);
        cout<<"\n�Ƿ��������?(Y/N)";
        choose=getchar();
        if(toupper(choose)!='Y')
        {
            fclose(fp);
            cout<<"\n�������,�����������\n";
        }
        system("cls");
    }while(1);
}
