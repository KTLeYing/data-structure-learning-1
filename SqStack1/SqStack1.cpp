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
        cout<<"请输入数据:";
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
    cout<<"\t\t\t\t单链表子系统"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----进栈\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----出栈\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----显示\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----求长度\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t5-----数制转换\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----返回\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t请选择菜单号(0--5)"<<endl<<endl;

    int choose=1,i;
    CreateStack(S);
    CreateStack(S1);
    while(choose)
    {
        cout<<"请选择:"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
                cout<<"进栈:"<<endl;
                Push(S,5);
                cout<<endl;
                break;
            case 2:
                cout<<"出栈:"<<endl<<endl;
                break;
            case 3:
                cout<<"显示出栈结果:"<<endl;
                Pop(S,5);
                cout<<endl<<endl;
                break;
            case 4:
                cout<<"数制转换:"<<endl;
                cout<<"请输入一个数:";
                cin>>e;
                Transf(S1,e);
                cout<<endl<<endl;
                break;
            case 0:
                cout<<"返回!请重新选择!"<<endl;
                cout<<"\t\t\t\t单链表子系统"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*\t\t1-----进栈\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t2-----出栈\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t3-----显示\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t4-----求长度\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t5-----数制转换\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t0-----返回\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t请选择菜单号(0--5)"<<endl<<endl;

                break;
        }
    }
}

