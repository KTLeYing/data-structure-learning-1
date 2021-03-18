#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define ERROR 0
typedef char ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


int MakeEmpty(LinkList &L)
{
    L=new LNode;
    L->next=NULL;
}

int CreateList(LinkList &L,int n)
{
    int i;
    LinkList p,r;
    L=new LNode;
    L->next=NULL;
    r=L;
    for(i=0;i<n;i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}


int Insert(LinkList &L,int i,ElemType x)
{
    LinkList p,s;
    p=L;
    int j=0;
    while(p && (j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i-1)
        return ERROR;
    s=new LNode;
    s->data=x;
    s->next=p->next;
    p->next=s;
}

int Delete(LinkList &L,int i)
{
    LinkList p;
    LinkList q;
    int j=0;
    p=L;
    while((p->next) && (j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next) || (j>i-1))
        return ERROR;
    q=p->next;
    p->next=q->next;
    delete q;
}

int DispList(LinkList L)
{
    LinkList p;
    p=L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

LNode *LocateElem(LinkList L,int i)
{
    LinkList p;
    int j=1;
    p=L->next;
    while(j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

int Length(LinkList L)
{
    int sum=0;
    LinkList p;
    p=L->next;
    while(p)
    {
        sum++;
        p=p->next;
    }
    return sum;
}


int main()
{
    LinkList L,p;
    cout<<endl;
    cout<<"\t\t\t\t��������ϵͳ"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----ɾ��\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----��ʾ\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t5-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t6-----���\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t��ѡ��˵���(0--6)"<<endl<<endl;

    MakeEmpty(L);
    int choose=1,a;
    while(choose)
    {
        cout<<"��ѡ��:"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
                cout<<"����:"<<endl;
                cout<<"���������ݵ�����:";
                cin>>a;
                cout<<"����������:";
                CreateList(L,a);
                cout<<endl;
                break;
            case 2:
                cout<<"����ɹ���"<<endl<<endl;
                Insert(L,4,'f');
                break;
            case 3:
                cout<<"ɾ���ɹ���"<<endl<<endl;
                Delete(L,2);
                break;
            case 4:
                cout<<"��ʾΪ:";
                DispList(L);
                cout<<endl;
                break;
            case 5:
                cout<<"���ҵĵ�3��Ԫ��Ϊ:";
                cout<<LocateElem(L,3)->data<<endl<<endl;
                break;
            case 6:
                cout<<"�󳤶�Ϊ:";
                cout<<Length(L)<<endl<<endl;
                break;
            case 0:
                cout<<"����!������ѡ��!"<<endl;
                cout<<"\t\t\t\t��������ϵͳ"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*\t\t1-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t2-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t3-----ɾ��\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t4-----��ʾ\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t5-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t6-----���\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t0-----����\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t��ѡ��˵���(0--6)"<<endl<<endl;
                break;
        }
    }

    return 0;
}



