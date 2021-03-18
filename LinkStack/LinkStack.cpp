#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define OVERFLOW -1
#define ERROR 0
#define MAX 100
typedef int ElemType;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

int MakeStack(LinkStack &S)
{
    S=NULL;
}

int Push(LinkStack &S,ElemType x)
{
    LinkStack p;
    p=new StackNode;
    p->data=x;
    p->next=S;
    S=p;
}

int Pop(LinkStack &S,ElemType &x)
{
    LinkStack p;
    if(S==NULL)
        return ERROR;
    x=S->data;
    p=S;
    S=S->next;
    delete p;
}

int DisStack(LinkStack S)
{
    int x;
    while(S!=NULL)
    {
        Pop(S,x);
        cout<<x<<" ";
    }
}

int LenStack(LinkStack S)
{
    int i=0;
    while(S!=NULL)
    {
        i++;
        S=S->next;
    }
    return i;
}

int Transf(LinkStack &S1,int x)
{

    int m=x,n;
    while(m)
    {
        n=m%2;
        Push(S1,n);
        m=m/2;
    }
    cout<<"�����Ķ�����λ:";
    DisStack(S1);
}

int main()
{
   LinkStack S;
   LinkStack S1;
   int choose=1;
   ElemType e,t,z;
   MakeStack(S);
   MakeStack(S1);
   cout<<endl;
    cout<<"\t\t\t\t��������ϵͳ"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----��ջ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----��ջ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----��ʾ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----����ת��\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t��ѡ��˵���(0--4)"<<endl<<endl;

   while(choose)
   {
       cout<<"��ѡ��"<<endl;
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
               Pop(S,t);
                  cout<<t;
              cout<<endl<<endl;
              break;
           case 3:
              cout<<"��ʾ:";
              DisStack(S);
              cout<<endl<<endl;
              break;
           case 4:
            cout<<"����Ϊ:"<<LenStack(S)<<endl<<endl;
            break;
           case 5:
              cout<<"����ת��:"<<endl;
              cout<<"����һ����:";
              cin>>z;
              Transf(S1,z);
              cout<<endl<<endl;
              break;
           case 0:
              cout<<"\t\t\t\t��������ϵͳ"<<endl;
              cout<<"\t\t*******************************************"<<endl;
              cout<<"\t\t*\t\t1-----��ջ\t\t"<<" "" "<<"*"<<endl;
              cout<<"\t\t*\t\t2-----��ջ\t\t"<<" "" "<<"*"<<endl;
              cout<<"\t\t*\t\t3-----��ʾ\t\t"<<" "" "<<"*"<<endl;
              cout<<"\t\t*\t\t4-----����ת��\t\t"<<" "" "<<"*"<<endl;
              cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
              cout<<"\t\t*******************************************"<<endl;
              cout<<"\t\t��ѡ��˵���(0--4)"<<endl<<endl;
       }
   }
   return 0;
}
