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

    int choose=1;
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
                cout<<"请输入数据:";
                cin>>e;
                Push(S,e);
                cout<<endl;
                break;
            case 2:
                cout<<"出栈:"<<endl;
                Pop(S,e);
                cout<<e<<endl<<endl;
                break;
            case 3:
                cout<<"显示:"<<endl;
                DisStack(S);
                cout<<endl<<endl;
                break;
            case 4:
                cout<<"长度为:"<<LenStack(S)<<endl<<endl;
                break;
            case 5:
                cout<<"数制转换:"<<endl;
                cout<<"请输入一个数:";
                cin>>e;
                Transf(S1,e);
                cout<<endl<<endl;
                break;
            case 0:
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

