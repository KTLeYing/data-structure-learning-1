//��1:(����ö��У����ýṹ�����)
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
}VNode,AdjList[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList vertices;
}ALGraph;

int visited[MVNum];

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

int BFSTraverse(ALGraph G)
{
    int i,j;
    int front=0,rear=0;
    VNode Queue[MVNum];
    ArcNode *p;
    for(i=0;i<G.vexnum;i++)
       visited[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            cout<<G.vertices[i].data<<" "" ";
            Queue[++rear]=G.vertices[i];
            while(front!=rear)
            {
                VNode q=Queue[++front];
                for(p=q.firstarc;p;p=p->nextarc)
                {
                    j=p->adjvex;
                    if(!visited[j])
                    {
                        visited[j]=1;
                        cout<<G.vertices[j].data<<" "" ";
                        Queue[++rear]=G.vertices[j];
                    }
                }
            }
        }
    }


}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    cout<<"�������������������ͼ!\n";
    BFSTraverse(G);
    cout<<"\n�������������������!\n";
    return 0;
}


//��2:(�������Ľṹ�����,���ݵĲ���Ϊָ�����p)
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode,*ArcNode1;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList vertices;
}ALGraph;

typedef struct
{
    ArcNode1 *base;
    int front;
    int rear;
}SqQueue;

int visited[MVNum];

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

int InitQueue(SqQueue &Q)
{
    Q.base=new ArcNode1[MVNum];
    if(!Q.base)
        exit(0);
    Q.front=Q.rear=0;
}

int EnQueue(SqQueue &Q,ArcNode1 p)
{
    if((Q.rear+1)%MVNum==Q.front)
        return 0;
    Q.base[Q.rear]=p;
    Q.rear=(Q.rear+1)%MVNum;
}

int DeQueue(SqQueue &Q,ArcNode1 &p)
{
    if(Q.front=Q.rear)
        return 0;
    p=Q.base[Q.front];
    Q.front=(Q.front+1)%MVNum;
}

int QueueEmpty(SqQueue &Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}

int BreadthFirstSearch(ALGraph G,int i)
{
    SqQueue Q;
    InitQueue(Q);
    ArcNode1 p;
    visited[i]=1;
    cout<<G.vertices[i].data<<" "" ";
    p=G.vertices[i].firstarc;
    while(p || !QueueEmpty(Q))
    {
        while(p)
        {
           if(!visited[p->adjvex])
           {
               cout<<G.vertices[p->adjvex].data<<" "" ";
               visited[p->adjvex]=1;
               EnQueue(Q,p);
               p=p->nextarc;
           }
           else
            p=p->nextarc;
        }
        if(!QueueEmpty(Q))
        {
            DeQueue(Q,p);
            p=G.vertices[p->adjvex].firstarc;
        }
    }
}

int TraverseGraph(ALGraph G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
       visited[i]=0;
    for(i=0;i<G.vexnum;i++)
        if(!visited[i])
          BreadthFirstSearch(G,i);
}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    cout<<"�������������������ͼ!\n";
    TraverseGraph(G);
    cout<<"\n�������������������!\n";
    return 0;
}
*/


//��3:((�������Ľṹ�����,���ݵĲ���Ϊ�����±꣨����ţ�))
/*
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
}VNode,AdjList[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList vertices;
}ALGraph;

typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;

int visited[MVNum];

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

int InitQueue(SqQueue &Q)
{
    Q.base=new int[MVNum];
    if(!Q.base)
        exit(0);
    Q.front=Q.rear=0;
}

int EnQueue(SqQueue &Q,int i)
{
    if((Q.rear+1)%MVNum==Q.front)
        return 0;
    Q.base[Q.rear]=i;
    Q.rear=(Q.rear+1)%MVNum;
}

int DeQueue(SqQueue &Q,int &i)
{
    if(Q.front=Q.rear)
        return 0;
    i=Q.base[Q.front];
    Q.front=(Q.front+1)%MVNum;
}

int QueueEmpty(SqQueue &Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}

int BreadthFirstSearch(ALGraph G,int i)
{
    SqQueue Q;
    InitQueue(Q);
    ArcNode *p;
    visited[i]=1;
    cout<<G.vertices[i].data<<" "" ";
    EnQueue(Q,i);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,i);
        p=G.vertices[i].firstarc;
        while(p)
        {
           if(!visited[p->adjvex])
           {
               cout<<G.vertices[p->adjvex].data<<" "" ";
               visited[p->adjvex]=1;
               EnQueue(Q,p->adjvex);
               p=p->nextarc;
           }
           else
            p=p->nextarc;
        }
    }
}

int TraverseGraph(ALGraph G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
       visited[i]=0;
    for(i=0;i<G.vexnum;i++)
        if(!visited[i])
          BreadthFirstSearch(G,i);
}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    cout<<"�������������������ͼ!\n";
    TraverseGraph(G);
    cout<<"\n�������������������!\n";
    return 0;
}
*/
