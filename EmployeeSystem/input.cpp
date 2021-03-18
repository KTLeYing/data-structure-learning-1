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
        cout<<"打开文件emp.dat出错!\n";
        return 0;
    }
    do
    {
        i++;
        emp1=(EMP *)malloc(sizeof(EMP));
        if(emp1==NULL)
        {
            cout<<"内存分配失败,按任意键返回!\n";
            return 0;
        }
        cout<<"输入第"<<i<<"个员工的信息:\n";
        Bound('_',20);
        cout<<"工号:";
        cin>>emp1->num;
        cout<<"职务:";
        cin>>emp1->duty;
        cout<<"姓名:";
        cin>>emp1->name;
        cout<<"性别:";
        cin>>emp1->sex;
        cout<<"年龄:";
        cin>>emp1->age;
        cout<<"文化程度:";
        cin>>emp1->edu;
        cout<<"工资:";
        cin>>emp1->salary;
        cout<<"办公电话:";
        cin>>emp1->tel_office;
        cout<<"家庭电话:";
        cin>>emp1->tel_home;
        cout<<"移动电话:";
        cin>>emp1->mobile;
        cout<<"QQ:";
        cin>>emp1->qq;
        cout<<"住址:";
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
        cout<<"\n是否继续输入?(Y/N)";
        choose=getchar();
        if(toupper(choose)!='Y')
        {
            fclose(fp);
            cout<<"\n输入完毕,按任意键返回\n";
        }
        system("cls");
    }while(1);
}
