//���1:�����ڷ���ͼ(������Ҫ��Ȩ)

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
}AdjList[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList vertices;
}ALGraph;

int LocateVex(ALGraph G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
}

int CreateGraph(ALGraph &G)
{
    int i,j,s,t,key,v1,v2;
    cout<<"�����붥�����ͱ���:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"������"<<G.vexnum<<"�������ֵ:";
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"������"<<G.arcnum<<"�ߵ���Ϣ:\n";
    for(j=0;j<G.arcnum;j++)
    {
        cout<<"�����"<<j+1<<"������Ϣ(��1 ��2):";
        cin>>v1>>v2;
        s=LocateVex(G,v1);
        t=LocateVex(G,v2);
        ArcNode *p1=new ArcNode;
        p1->adjvex=t;
        p1->nextarc=G.vertices[s].firstarc;
        G.vertices[s].firstarc=p1;
        ArcNode *p2=new ArcNode;
        p2->adjvex=s;
        p2->nextarc=G.vertices[t].firstarc;
        G.vertices[t].firstarc=p2;
    }
    return 0;
}

int DisGraph(ALGraph G)
{
    int i;
    cout<<"�ڽӱ��������:\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i;
        ArcNode *p;
        p=G.vertices[i].firstarc;
        while(p)
        {
            cout<<"->";
            cout<<p->adjvex;
            p=p->nextarc;
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    return 0;
}


//���2:��������ͼ(������Ҫ��Ȩ)
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100

typedef struct ArcNode
{
    int adjvex;
    int info;    //�ߵ�Ȩֵ
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
}AdjList[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList vertices;
}ALGraph;

int LocateVex(ALGraph G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
}

int CreateGraph(ALGraph &G)
{
    int i,j,s,t,key,v1,v2,weight;
    cout<<"�����붥�����ͱ���:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"������"<<G.vexnum<<"�������ֵ:";
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"������"<<G.arcnum<<"�ߵ���Ϣ:\n";
    for(j=0;j<G.arcnum;j++)
    {
        cout<<"�����"<<j+1<<"������Ϣ(��1 ��2 ��Ȩ):";
        cin>>v1>>v2>>weight;
        s=LocateVex(G,v1);
        t=LocateVex(G,v2);
        ArcNode *p1=new ArcNode;
        p1->adjvex=t;
        p1->info=weight;
        p1->nextarc=G.vertices[s].firstarc;
        G.vertices[s].firstarc=p1;
        ArcNode *p2=new ArcNode;
        p2->adjvex=s;
        p2->info=weight;
        p2->nextarc=G.vertices[t].firstarc;
        G.vertices[t].firstarc=p2;
    }
    return 0;
}

int DisGraph(ALGraph G)
{
    int i;
    cout<<"�ڽӱ��������:\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i;
        ArcNode *p;
        p=G.vertices[i].firstarc;
        while(p)
        {
            cout<<"->";
            cout<<p->adjvex;
            cout<<"("<<p->info<<")";
            p=p->nextarc;
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    return 0;
}
*/
