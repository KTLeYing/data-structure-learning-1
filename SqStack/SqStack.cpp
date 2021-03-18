#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define ERROR 0
#define OVERFLOW -1
#define MAX 100
typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stsize;
}SqStack;

int MakeStack(SqStack &S)
{
    S.base=new SElemType[MAX];
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stsize=MAX;
}

int Push(SqStack &S,SElemType x)
{
    if(S.top-S.base==S.stsize)
        return ERROR;
    *S.top++=x;
}

int Pop(SqStack &S,SElemType &x)
{
    if(S.top==S.base)
        return ERROR;
        x=*--S.top;
}

int DisStack(SqStack S)
{
    int x;
    while(S.top!=S.base)
    {
        Pop(S,x);
        cout<<x<<" ";
    }
}

int  LenStack(SqStack S)
{
    return S.top-S.base;
}

int main()
{
    int i,j;
    cout<<"����������:";
    cin>>i;
    SqStack S;
    SElemType e;
    MakeStack(S);
    for(j=0;j<i;j++)
    {
        cout<<"����������:";
        cin>>e;
        Push(S,e);
    }
    cout<<"��ջ:";
    for(j=0;j<i-2;j++)
    {
        Pop(S,e);
        cout<<e<<" ";
    }
    cout<<endl<<"��ʾ:";
    DisStack(S);
    cout<<endl<<"ջ����Ϊ:";
    cout<<LenStack(S);
}


