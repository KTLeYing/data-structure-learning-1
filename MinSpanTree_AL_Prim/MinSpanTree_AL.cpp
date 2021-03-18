#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100
#define MaxInt 32767

typedef struct ArcNode
{
    int adjvex;
    int info;
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

struct CloseEdge
{
    int adjvex;
    int lowcost;
}closedge[MVNum];


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

int Min(ALGraph G,struct CloseEdge closedge[])
{
    int i,k,min;
    min=MaxInt;
    for(i=1;i<G.vexnum;i++)
        if(closedge[i].lowcost && closedge[i].lowcost<min)
        {
            min=closedge[i].lowcost;
            k=i;
        }
    return k;
}

int MinSpanTree(ALGraph G,int start)
{
    int i,j,t,k,m,n,u0,v0,sum=0,index=0;
    int resulvex[MVNum];
    ArcNode *p,*p1;
    t=LocateVex(G,start);
    resulvex[index++]=start;
    closedge[t].lowcost=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(i!=t)
        {
            closedge[i].adjvex=start;
            p=G.vertices[i].firstarc;
            while(p)
            {
                if(p->adjvex==t)
                    closedge[i].lowcost=p->info;
                else
                    closedge[i].lowcost=MaxInt;
                p=p->nextarc;
            }
        }
    }
    cout<<"ÿ�����Ϊ:\n";
    for(i=1;i<G.vexnum;i++)
    {
        k=Min(G,closedge);
        u0=closedge[k].adjvex;
        v0=G.vertices[k].data;
        cout<<u0<<" "<<v0<<endl;
        resulvex[index++]=v0;
        sum+=closedge[k].lowcost;
        closedge[k].lowcost=0;
        p1=G.vertices[k].firstarc;
        while(p1)
        {
            if(p1->info<closedge[p1->adjvex].lowcost)
            {
                 closedge[p1->adjvex].lowcost=p1->info;
                 closedge[p1->adjvex].adjvex=G.vertices[k].data;
            }
            p1=p1->nextarc;
        }
    }
    cout<<"��С������Ϊ:";
    for(i=0;i<G.vexnum;i++)
       cout<<resulvex[i]<<" ";
    cout<<endl;
    cout<<"����С��������ȨֵΪ:"<<sum<<endl;
}

int main()
{
    ALGraph G;
    int start;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    cout<<"ʵ����С������!\n";
    cout<<"�������һ����(���):";
    cin>>start;
    MinSpanTree(G,start);
    return 0;
}
