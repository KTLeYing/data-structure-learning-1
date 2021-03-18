#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100
#define MAX 100
#define OVERFLOW -1
#define ERROR 0

typedef int SElemType;

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

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stsize;
}SqStack;

int MakeStack(SqStack &S)
{
    S.base=new SElemType[MAX];
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stsize=MAX;
}

int Push(SqStack &S,SElemType x)
{
    if(S.top-S.base==S.stsize)
        return ERROR;
    *S.top++=x;
}

int Pop(SqStack &S,SElemType &x)
{
    if(S.top==S.base)
        return ERROR;
        x=*--S.top;
}

int StackEmpty(SqStack S)
{
    if(S.top==S.base)
        return 1;
    else
        return 0;
}

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

int FindInDegree(ALGraph G,int indegree[])
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        ArcNode *p;
        p=G.vertices[i].firstarc;
        while(p)
        {
            indegree[p->adjvex]++;
            p=p->nextarc;
        }
    }
    cout<<"indegree[]�����е�����Ϊ:\n";
    for(i=0;i<G.vexnum;i++)
       cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
       cout<<indegree[i]<<" ";
    cout<<endl;
}

int TopoSort(ALGraph G,int topo[])
{
    SqStack S;
    ArcNode *p;
    int i,j,m,k,indegree[MVNum];
    FindInDegree(G,indegree);
    MakeStack(S);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
          Push(S,i);
    m=0;
    while(!StackEmpty(S))
    {
        Pop(S,i);
        topo[m]=i;
        m++;
        p=G.vertices[i].firstarc;
        while(p)
        {
            k=p->adjvex;
            indegree[k]--;
            if(indegree[k]==0)
                Push(S,k);
            p=p->nextarc;
        }
    }

    if(m<G.vexnum)
        cout<<"������ͼ�л�·!����ʵ����������!\n";
    else
    {
        cout<<"�����������Ϊ(���):";
        for(i=0;i<m;i++)
           cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"�����������Ϊ(����):";
        for(i=0;i<m;i++)
           cout<<G.vertices[topo[i]].data<<" ";
        cout<<endl;
    }
    if(m<G.vexnum)
        return 0;
    else
        return 1;
}

int CriticalPath(ALGraph G)
{
    ArcNode *p;
    int i,j,k,z=0,t=0,e,l,n,sum=0;
    int ve[MVNum],vl[MVNum],topo[MVNum],temp[MVNum],temp_1[MVNum];
    if(!TopoSort(G,topo))
        return 0;
    n=G.vexnum;
    for(i=0;i<n;i++)
        ve[i]=0;       //��ÿ���¼����緢��ʱ���ʼ��Ϊ0
    for(i=0;i<n;i++)  //�¼������緢��ʱ��(˳-->>ȡMax)
    {
        k=topo[i];
        p=G.vertices[k].firstarc;
        while(p)
        {
            j=p->adjvex;
            if(ve[j]<ve[k]+p->info)   //ȡMax
                ve[j]=ve[k]+p->info;
            p=p->nextarc;
        }
    }
    for(i=0;i<n;i++)
        vl[i]=ve[n-1];     //��ÿ���¼�����ٷ���ʱ���ʼ��Ϊve[n-1](�����緢��ʱ������һ���¼���ֵ��Ҳ�����緢��ʱ������ֵ)
    for(i=n-1;i>=0;i--)   //�¼�����ٷ���ʱ��(��-->>ȡMin)
    {
        k=topo[i];
        p=G.vertices[k].firstarc;
        while(p)
        {
            j=p->adjvex;
            if(vl[k]>vl[j]-p->info)   //ȡMin
               vl[k]=vl[j]-p->info;
            p=p->nextarc;
        }
    }
    cout<<"ÿ�����Ϊ:";
    for(i=0;i<n;i++)
    {
        p=G.vertices[i].firstarc;
        while(p)
        {
            j=p->adjvex;
            e=ve[i];
            l=vl[j]-p->info;
            if(e==l)
            {
                cout<<G.vertices[i].data<<"-"<<G.vertices[j].data<<"  ";
                temp[z++]=G.vertices[i].data;
                temp[z++]=G.vertices[j].data;
                sum+=p->info;
            }
            p=p->nextarc;
        }
    }
    cout<<endl;
    cout<<"�ؼ�·��Ϊ:";
    for(i=0;i<z;i++)
    {
        for(j=0;j<t;j++)
           if(temp[i]==temp_1[j])
               break;
        if(j==t || i==0)
        {
            cout<<temp[i]<<" ";
            temp_1[t++]=temp[i];
        }
    }
    cout<<"\n�ؼ�·������Ϊ:"<<sum<<endl;
}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    cout<<"ʵ�ֹؼ�·��!\n";
    CriticalPath(G);
    return 0;
}
