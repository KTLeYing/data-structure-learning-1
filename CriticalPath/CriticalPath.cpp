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
    cout<<"请输入顶点数和边数:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入"<<G.vexnum<<"个顶点的值:";
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"请输入"<<G.arcnum<<"边的信息:\n";
    for(j=0;j<G.arcnum;j++)
    {
        cout<<"输入第"<<j+1<<"条边信息(边1 边2 边权):";
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
    cout<<"邻接表输出如下:\n";
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
    cout<<"indegree[]数组中的数据为:\n";
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
        cout<<"该有向图有回路!不能实现拓扑排序!\n";
    else
    {
        cout<<"输出拓扑序列为(序号):";
        for(i=0;i<m;i++)
           cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"输出拓扑序列为(顶点):";
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
        ve[i]=0;       //给每个事件最早发生时间初始化为0
    for(i=0;i<n;i++)  //事件的最早发生时间(顺-->>取Max)
    {
        k=topo[i];
        p=G.vertices[k].firstarc;
        while(p)
        {
            j=p->adjvex;
            if(ve[j]<ve[k]+p->info)   //取Max
                ve[j]=ve[k]+p->info;
            p=p->nextarc;
        }
    }
    for(i=0;i<n;i++)
        vl[i]=ve[n-1];     //给每个事件的最迟发生时间初始化为ve[n-1](即最早发生时间的最后一个事件的值，也是最早发生时间的最大值)
    for(i=n-1;i>=0;i--)   //事件的最迟发生时间(逆-->>取Min)
    {
        k=topo[i];
        p=G.vertices[k].firstarc;
        while(p)
        {
            j=p->adjvex;
            if(vl[k]>vl[j]-p->info)   //取Min
               vl[k]=vl[j]-p->info;
            p=p->nextarc;
        }
    }
    cout<<"每轮输出为:";
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
    cout<<"关键路径为:";
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
    cout<<"\n关键路径长度为:"<<sum<<endl;
}

int main()
{
    ALGraph G;
    cout<<"创建邻接表!\n";
    CreateGraph(G);
    cout<<"成功创建邻接表!\n\n";
    cout<<"输出邻接表(输出序号)!\n";
    DisGraph(G);
    cout<<"实现关键路径!\n";
    CriticalPath(G);
    return 0;
}
