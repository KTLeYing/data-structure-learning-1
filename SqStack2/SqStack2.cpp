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

int Push(SqStack &S,ElemType x)
{
        if(S.top-S.base==S.stacksize)
           return ERROR;
        *S.top++=x;
}

int Pop(SqStack &S,ElemType &x)
{
       if(S.top==S.base)
          return ERROR;
       x=*--S.top;
}

int DisStack(SqStack S)
{
   int t;
   while(S.top!=S.base)
   {
       Pop(S,t);
       cout<<t<<" ";
   }
}

int Transf(SqStack &S1,int x)
{
    int m=x,n;
    while(m)
    {
        n=m%2;
        Push(S1,n);
        m=m/2;
    }
    DisStack(S1);
}

int LenStack(SqStack S)
{
    return S.top-S.base;
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

    int choose=1;
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
                cout<<"����������:";
                cin>>e;
                Push(S,e);
                cout<<endl;
                break;
            case 2:
                cout<<"��ջ:"<<endl;
                Pop(S,e);
                cout<<e<<endl<<endl;
                break;
            case 3:
                cout<<"��ʾ:"<<endl;
                DisStack(S);
                cout<<endl<<endl;
                break;
            case 4:
                cout<<"����Ϊ:"<<LenStack(S)<<endl<<endl;
                break;
            case 5:
                cout<<"����ת��:"<<endl;
                cout<<"������һ����:";
                cin>>e;
                Transf(S1,e);
                cout<<endl<<endl;
                break;
            case 0:
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

