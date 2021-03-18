#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32768
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

int ShortestPath(ALGraph G,int v0)
{
    ArcNode *p,*p1;
    int i,j,n,k,v,w,min,t,sum;
    int S[MVNum],D[MVNum],path[MVNum],temp[MVNum];
    n=G.vexnum;
    for(v=0;v<n;v++)
        S[v]=0;
    for(i=0;i<G.vexnum;i++)
    {
        D[i]=MaxInt;
        path[i]=-1;
    }
    p=G.vertices[v0].firstarc;
    while(p)
    {
        D[p->adjvex]=p->info;
        path[p->adjvex]=v0;
        p=p->nextarc;
    }
    S[v0]=1;
    D[v0]=0;
    cout<<"�������ǰ�Ľ��:\n";
    cout<<"v\t";
    for(i=0;i<n;i++)
        cout<<i<<"    ";
    cout<<endl<<"S\t";
    for(i=0;i<n;i++)
        cout<<S[i]<<"    ";
    cout<<endl<<"D\t";
    for(i=0;i<n;i++)
        if(D[i]==MaxInt)
           cout<<"��   ";
        else
           cout<<D[i]<<"   ";
    cout<<endl<<"path  ";
    for(i=0;i<n;i++)
        cout<<path[i]<<"    ";
    cout<<endl;
    for(i=1;i<n;i++)
    {
        min=MaxInt;
        for(w=0;w<n;w++)
            if(!S[w] && D[w]<min)
            {
                v=w;
                min=D[w];
            }
        S[v]=1;
        p1=G.vertices[v].firstarc;
        while(p1)
        {
            if(!S[p1->adjvex] && (D[v]+p1->info<D[p1->adjvex]))
            {
                 D[p1->adjvex]=D[v]+p1->info;
                 path[p1->adjvex]=v;
            }
            p1=p1->nextarc;
        }
    }
    cout<<"������·��(�±�):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
            cout<<v0<<"��"<<i<<":�����ڴ�·��"<<endl;
        else
        {
            t=path[i];
            j=i;
            cout<<v0<<"��"<<i<<"����̾���Ϊ:"<<D[i]<<";���·����:"<<v0;
            while(t>=0)
            {
                temp[sum++]=j;
                j=t;
                t=path[t];
            }
            for(k=sum-1;k>=0;k--)
              cout<<"->"<<temp[k];
            cout<<endl;
        }
    }
    cout<<"\n������·��(����):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
            cout<<G.vertices[v0].data<<"��"<<G.vertices[i].data<<":�����ڴ�·��"<<endl;
        else
        {
            t=path[i];
            j=i;
            cout<<G.vertices[v0].data<<"��"<<G.vertices[i].data<<"����̾���Ϊ:"<<D[i]<<";���·����:"<<G.vertices[v0].data;
            while(t>=0)
            {
                temp[sum++]=j;
                j=t;
                t=path[t];
            }
            for(k=sum-1;k>=0;k--)
              cout<<"->"<<G.vertices[temp[k]].data;
            cout<<endl;
        }
    }
}

int main()
{
    ALGraph G;
    int v0;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n\n";
    DisGraph(G);
    cout<<"ʵ�����·��!\n";
    cout<<"��������ʼ��Ŀ�궥����±�:";
    cin>>v0;
    ShortestPath(G,v0);
    return 0;
}
