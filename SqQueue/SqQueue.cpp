#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -1
typedef int ElemType;

typedef struct
{
    ElemType *base;
    int fron;
    int rear;
}SqQueue;

int CreateQueue(SqQueue &Q)
{
    Q.base=new ElemType{MAXSIZE};
    if(!Q.base)
        exit(OVERFLOW);
    Q.fron=Q.rear=0;
}

int EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MAXSIZE==Q.fron)
        return ERROR;
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
}

int DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.fron==Q.rear)
        return ERROR;
    x=Q.base[Q.fron];
    Q.fron=(Q.fron+1)%MAXSIZE;
}

int DisQueue(SqQueue Q)
{
    int x;
    while(Q.fron!=Q.rear)
    {
        DeQueue(Q,x);
        cout<<x<<" ";
    }
}

int GetHead(SqQueue &Q,ElemType x)
{
    if(Q.fron!=Q.rear)
        return Q.base[Q.fron];
}

int LenQueue(SqQueue Q)
{
    if(Q.rear>Q.fron)
        return Q.rear-Q.fron;
    else
        return MAXSIZE-Q.fron+Q.rear;
}

int main()
{
    SqQueue Q;
    ElemType e;
    int choose=1;
    CreateQueue(Q);
    while(choose)
    {
        cout<<"请选择:"<<endl;
        cin>>choose;
        switch(choose)
        {
             case 1:
                cout<<"进队:"<<endl<<"请输入元素:";
                cin>>e;
                EnQueue(Q,e);
                cout<<endl;
                break;
             case 2:
                cout<<"出队:"<<endl;
                DeQueue(Q,e);
                cout<<e<<endl<<endl;
                break;
             case 3:
                cout<<"显示:";
                DisQueue(Q);
                cout<<endl<<endl;
                break;
             case 4:
                cout<<"取队头元素为:";
                GetHead(Q,e);
                cout<<e<<endl<<endl;
             case 5:
                cout<<"队列长度为:";
                cout<<LenQueue(Q);
        }
    }
}


