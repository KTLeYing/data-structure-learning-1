/******************************************************************************************
*FunctionName:Main                                                                        *
*                                                                                         *
*Description:����������ϵͳ����ڣ��Ը���ģ�麯�����е���                               *
*                                                                                         *
*MakingDate:2019/7/17                                                                     *
*                                                                                         *
*Maker:������                                                                             *
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
        cout<<"\n��ϵͳ����δ��ʼ��������������г�ʼ������!\n";
        Bound('_',50);
        do
        {
            cout<<"\n���õ�¼ϵͳ����(���8λ):";
            for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
                putchar('*');
            pwd[i]='\0';
            pwd[i]='\0';
            if(strcmp(pwd,pwd1)!=0)
                cout<<"\n������������벻ͬ������������!\n\n";
            else
                break;
        }while(1);
        if((fp1=fopen("config.dat","wb"))==NULL)
        {
            cout<<"\n����ϵͳ�����ļ�ʧ�ܣ���������˳�ϵͳ!\n";
            exit(1);
        }
        i=0;
        while(pwd[i])
        {
            putw(pwd[i],fp1);
            i++;
        }
        fclose(fp1);
        cout<<"\n\nϵͳ���óɹ�����������˳�ϵͳ�������½���!\n";
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
        cout<<"���������ϵͳ������:";
        for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
            putchar('*');
        pwd[i]='\0';
        if(strcmp(pwd,password))
        {
            cout<<"\n�����������������!\n";
            system("cls");
            n--;
        }
        else
            break;
    }while(n>0);
    if(!n)
    {
        cout<<"�Ƿ��û�����ػ�!\n";
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
            cout<<"�ڴ����ʧ��!\n";
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
        cout<<"\tԱ������ϵͳ\n";
        Bound('_',30);
        cout<<"\t1.����Ա����Ϣ\n";
        cout<<"\t2.��ѯԱ����Ϣ\n";
        cout<<"\t3.��ʾԱ����Ϣ\n";
        cout<<"\t4.�޸�Ա����Ϣ\n";
        cout<<"\t5.ɾ��Ա����Ϣ\n";
        cout<<"\t6.ͳ��Ա����Ϣ\n";
        cout<<"\t7.����ϵͳ����\n";
        cout<<"\t0.�˳�ϵͳ\n";
        Bound('_',30);
        cout<<"\n��ѡ��˵�:";
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
                        cout<<"ϵͳ�л�ûԱ����Ϣ��������Ա����Ϣ!\n";
                        break;
                    }
                    FindEmp();
                    break;
                case 3:
                    if(gfirst)
                    {
                        cout<<"ϵͳ�л�ûԱ����Ϣ���������Ա����Ϣ!\n";
                        break;
                    }
                    ListEmp();
                    break;
                case 4:
                    if(gfirst)
                    {
                        cout<<"ϵͳ�л�ûԱ����Ϣ���������Ա����Ϣ!\n";
                        break;
                    }
                    ModifyEmp();
                    break;
                case 5:
                    if(gfirst)
                    {
                        cout<<"ϵͳ�л�ûԱ����Ϣ���������Ա����Ϣ!\n";
                        break;
                    }
                    DeleteEmp();
                    break;
                case 6:
                    if(gfirst)
                    {
                        cout<<"ϵͳ�л�ûԱ����Ϣ���������Ա����Ϣ!\n";
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
