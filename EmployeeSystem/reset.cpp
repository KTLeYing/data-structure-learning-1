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
    cout<<"\n请输入旧密码:";
    for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
        putchar('*');
    pwd[i]='\0';
    if((strcmp(password,pwd))!=0)
    {
        cout<<"\n密码输入错误，按任意键返回!\n";
        return 0;
    }
    do
    {
        cout<<"\n输入新密码(最多8位):";
        for(i=0;i<8 && ((pwd[i]=getchar())!=13);i++)
            putchar('*');
        cout<<"\n再次确认密码:";
        for(i=0;i<8 && ((pwd1[i]=getchar())!=13);i++)
            putchar('*');
        pwd[i]='\0';
        pwd1[i]='\0';
        if(strcmp(pwd,pwd1)!=0)
            cout<<"\n两次输入的密码不同，请重新输入!\n\n";
        else
            break;
    }while(1);
    if((fp1=fopen("config.dat","wb"))==NULL)
    {
        cout<<"\n创建系统配置文件失败,按任意键退出系统!\n";
        exit(1);
    }
    i=0;
    while(pwd[i])
    {
        putw(pwd[i],fp1);
        i++;
    }
    fclose(fp1);
    cout<<"\n密码修改成功,按任意键返回!\n";
    return 0;
}
