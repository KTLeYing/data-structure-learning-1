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
    int j,n,coun=i,MAX=i+1;  //n��¼�ڼ����˱���,sum��¼��Ȧ����
    for(j=1;j<=i;j++)
    {
        EnQueue(Q1,j);    //���������
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
       cout<<"���ӵ���:"<<e<<endl;
       coun--;
    }
    cout<<"\n���һ������:"<<endl;
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
    cout<<"\t\t\t\t��������ϵͳ"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----���\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----��ʾ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----Լɪ����������\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t��ѡ��˵���(0--4)"<<endl<<endl;
    while(choose)
    {
        cout<<"��ѡ��:"<<endl;
        cin>>choose;
        switch(choose)
        {
             case 1:
                cout<<"����:"<<endl<<"������Ԫ��:";
                cin>>e;
                EnQueue(Q,e);
                cout<<endl;
                break;
             case 2:
                cout<<"����:"<<endl;
                DeQueue(Q,e);
                cout<<e<<endl<<endl;
                break;
             case 3:
                cout<<"��ʾ:";
                DisQueue(Q);
                cout<<endl<<endl;
                break;
             case 4:
                cout<<"Լɪ����������:";
                cout<<"����������:";
                cin>>t;
                YueSe(Q1,t);
                cout<<endl<<endl;
                break;
             case 0:
                cout<<"\t\t\t\t��������ϵͳ"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*\t\t1-----���\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t2-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t3-----��ʾ\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t4-----Լɪ����������\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t��ѡ��˵���(0--4)"<<endl<<endl;
                break;
        }
    }

}
