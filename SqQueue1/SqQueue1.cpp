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


int YueSe(SqQueue Q1,int i)
{
    ElemType e;
    int j,n,coun=i,MAX=i+1;  //n记录第几个人报数,sum记录出圈人数
    for(j=1;j<=i;j++)
    {
        EnQueue(Q1,j);    //所有人入队
    }
    while(coun!=2)
    {
       n=1;
       while(n!=3)
       {
           Q1.fron=(Q1.fron+1)%(MAX-1);
           if(Q1.base[Q1.fron]!=0)
            n++;
       }
       DeQueue(Q1,e);
       while(Q1.base[Q1.fron]==0)
           Q1.fron=(Q1.fron+1)%(MAX-1);
       cout<<"出队的是:"<<e<<endl;
       coun--;
    }
    cout<<"\n最后一个数是:"<<endl;
    while(coun!=0)
    {
        DeQueue(Q1,e);
        cout<<e<<" ";
        coun--;
    }

}

int main()
{
    SqQueue Q,Q1;
    ElemType e;
    int choose=1,t;
    CreateQueue(Q);
    CreateQueue(Q1);
    cout<<endl;
    cout<<"\t\t\t\t单链表子系统"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----入队\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----出队\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----显示\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----约瑟夫生死问题\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----返回\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t请选择菜单号(0--4)"<<endl<<endl;
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
                cout<<"约瑟夫生死问题:";
                cout<<"输入总人数:";
                cin>>t;
                YueSe(Q1,t);
                cout<<endl<<endl;
                break;
             case 0:
                cout<<"\t\t\t\t单链表子系统"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*\t\t1-----入队\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t2-----出队\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t3-----显示\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t4-----约瑟夫生死问题\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t0-----返回\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t请选择菜单号(0--4)"<<endl<<endl;
                break;
        }
    }

}
