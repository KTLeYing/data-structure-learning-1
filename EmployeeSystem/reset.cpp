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


int ResetPwd()
{
    char pwd[9],pwd1[9],ch;
    int i;
    FILE *fp1;
    system("cls");
    cout<<"\n�����������:";
    for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
        putchar('*');
    pwd[i]='\0';
    if((strcmp(password,pwd))!=0)
    {
        cout<<"\n����������󣬰����������!\n";
        return 0;
    }
    do
    {
        cout<<"\n����������(���8λ):";
        for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
            putchar('*');
        cout<<"\n�ٴ�ȷ������:";
        for(i=0;i<8 && ((pwd1[i]=getchar())!=13);i++)
            putchar('*');
        pwd[i]='\0';
        pwd1[i]='\0';
        if(strcmp(pwd,pwd1)!=0)
            cout<<"\n������������벻ͬ������������!\n\n";
        else
            break;
    }while(1);
    if((fp1=fopen("config.dat","wb"))==NULL)
    {
        cout<<"\n����ϵͳ�����ļ�ʧ��,��������˳�ϵͳ!\n";
        exit(1);
    }
    i=0;
    while(pwd[i])
    {
        putw(pwd[i],fp1);
        i++;
    }
    fclose(fp1);
    cout<<"\n�����޸ĳɹ�,�����������!\n";
    return 0;
}
