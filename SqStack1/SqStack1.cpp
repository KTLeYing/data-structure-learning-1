#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define ERROR 0
#define OVERFLOW -1
#define MAX 100
typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

int CreateStack(SqStack &S)
{
    S.base=new ElemType[MAX];
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=MAX;
}

int Push(SqStack &S,int i)
{
    int j=0,x;
    while(j<5)
    {
        cout<<"����������:";
        cin>>x;
        if(S.top-S.base==S.stacksize)
           return ERROR;
        *S.top++=x;
        j++;
    }
}

int Pop(SqStack &S,int i)
{
    int x;
    while(i>0)
    {
       if(S.top==S.base)
          return ERROR;
       x=*--S.top;
       cout<<x<<" ";
       i--;
    }
}

int Push1(SqStack &S1,ElemType x)
{
    if(S1.top-S1.base==S1.stacksize)
        return ERROR;
    *S1.top++=x;
}

int Pop1(SqStack &S1,int i)
{
    int x;
    while(i>0)
    {
       if(S1.top==S1.base)
        return ERROR;
        x=*--S1.top;
        cout<<x;
        i--;
    }
}


int Transf(SqStack &S1,int x)
{
    int i=0,j,m=x,n;
    while(m)
    {
        n=m%2;
        Push1(S1,n);
        m=m/2;
        i++;
    }
    Pop1(S1,i);
}


int main()
{
    SqStack S,S1;
    ElemType e;
    cout<<endl;
    cout<<"\t\t\t\t��������ϵͳ"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----��ջ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----��ջ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----��ʾ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----�󳤶�\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t5-----����ת��\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t��ѡ��˵���(0--5)"<<endl<<endl;

    int choose=1,i;
    CreateStack(S);
    CreateStack(S1);
    while(choose)
    {
        cout<<"��ѡ��:"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
                cout<<"��ջ:"<<endl;
                Push(S,5);
                cout<<endl;
                break;
            case 2:
                cout<<"��ջ:"<<endl<<endl;
                break;
            case 3:
                cout<<"��ʾ��ջ���:"<<endl;
                Pop(S,5);
                cout<<endl<<endl;
                break;
            case 4:
                cout<<"����ת��:"<<endl;
                cout<<"������һ����:";
                cin>>e;
                Transf(S1,e);
                cout<<endl<<endl;
                break;
            case 0:
                cout<<"����!������ѡ��!"<<endl;
                cout<<"\t\t\t\t��������ϵͳ"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*\t\t1-----��ջ\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t2-----��ջ\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t3-----��ʾ\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t4-----�󳤶�\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t5-----����ת��\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t��ѡ��˵���(0--5)"<<endl<<endl;

                break;
        }
    }
}

