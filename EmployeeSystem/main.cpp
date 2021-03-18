/******************************************************************************************
*FunctionName:Main                                                                        *
*                                                                                         *
*Description:主函数，该系统的入口，对各种模块函数进行调用                               *
*                                                                                         *
*MakingDate:2019/7/17                                                                     *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


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


int CheckFirst()
{
    FILE *fp,*fp1;
    char pwd[9],pwd1[9],ch;
    int i;
    if((fp=fopen("config.dat","rb"))==NULL)
    {
        cout<<"\n新系统，还未初始化，按任意键进行初始化操作!\n";
        Bound('_',50);
        do
        {
            cout<<"\n设置登录系统密码(最多8位):";
            for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
                putchar('*');
            pwd[i]='\0';
            pwd[i]='\0';
            if(strcmp(pwd,pwd1)!=0)
                cout<<"\n两次输入的密码不同，请重新输入!\n\n";
            else
                break;
        }while(1);
        if((fp1=fopen("config.dat","wb"))==NULL)
        {
            cout<<"\n创建系统配置文件失败，按任意键退出系统!\n";
            exit(1);
        }
        i=0;
        while(pwd[i])
        {
            putw(pwd[i],fp1);
            i++;
        }
        fclose(fp1);
        cout<<"\n\n系统配置成功，按任意键退出系统，再重新进入!\n";
        exit(1);
    }
    else
    {
        i=0;
        while(!feof(fp) && i<8)
             pwd[i++]=getw(fp);
        pwd[i]='\0';
        if(i>=8)
            i--;
        while(pwd[i]!=-1 && i>=0)
            i--;
        pwd[i]='\0';
        strcpy(password,pwd);
    }
}

int Login()
{
    int i,n=3;
    char pwd[9];
    do
    {
        cout<<"请输入进入系统的密码:";
        for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
            putchar('*');
        pwd[i]='\0';
        if(strcmp(pwd,password))
        {
            cout<<"\n密码错误，请重新输入!\n";
            system("cls");
            n--;
        }
        else
            break;
    }while(n>0);
    if(!n)
    {
        cout<<"非法用户，请关机!\n";
        exit(1);
    }
}

int ReadData()
{
    FILE *fp;
    EMP *emp1;
    if((fp=fopen("emp.dat","rb"))==NULL)
    {
        gfirst=1;
        return 0;
    }
    while(!feof(fp))
    {
        emp1=(EMP *)malloc(sizeof(EMP));
        if(emp1==NULL)
        {
            cout<<"内存分配失败!\n";
            return 0;
        }
        fread(emp1,sizeof(EMP),1,fp);
        if(feof(fp))
            break;
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
        emp_end->next=NULL;
    }
    gfirst=0;
    fclose(fp);
}

int Menu()
{
    int choose;
    system("cls");
    do
    {
        cout<<"\t员工管理系统\n";
        Bound('_',30);
        cout<<"\t1.输入员工信息\n";
        cout<<"\t2.查询员工信息\n";
        cout<<"\t3.显示员工信息\n";
        cout<<"\t4.修改员工信息\n";
        cout<<"\t5.删除员工信息\n";
        cout<<"\t6.统计员工信息\n";
        cout<<"\t7.重设系统密码\n";
        cout<<"\t0.退出系统\n";
        Bound('_',30);
        cout<<"\n请选择菜单:";
        do
        {
            cin>>choose;
            system("cls");
            switch(choose)
            {
                case 1:
                    AddEmp();
                    break;
                case 2:
                    if(gfirst)
                    {
                        cout<<"系统中还没员工信息，请先添员工信息!\n";
                        break;
                    }
                    FindEmp();
                    break;
                case 3:
                    if(gfirst)
                    {
                        cout<<"系统中还没员工信息，请先添加员工信息!\n";
                        break;
                    }
                    ListEmp();
                    break;
                case 4:
                    if(gfirst)
                    {
                        cout<<"系统中还没员工信息，请先添加员工信息!\n";
                        break;
                    }
                    ModifyEmp();
                    break;
                case 5:
                    if(gfirst)
                    {
                        cout<<"系统中还没员工信息，请先添加员工信息!\n";
                        break;
                    }
                    DeleteEmp();
                    break;
                case 6:
                    if(gfirst)
                    {
                        cout<<"系统中还没员工信息，请先添加员工信息!\n";
                        break;
                    }
                    SummaryEmp();
                    break;
                case 7:
                    ResetPwd();
                    break;
                case 0:
                    SaveData();
                    exit(0);
            }
        }while(choose<0 || choose>7);
        system("cls");
    }while(1);
}

int main()
{
    emp_first=emp_end=NULL;
    gsave=gfirst=0;
    CheckFirst();
    Login();
    ReadData();
    Menu();
    return 0;
}
