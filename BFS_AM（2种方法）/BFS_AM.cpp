//法1:(广度优先搜索用一个函数的情况，初始化和操作部分放在一起)【正常，操作稳定】
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;

int visited[MVNum];

int LocateVertex(AMGraph G,int &v1,int &v2)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v1)
        {
            v1=i;
            break;
        }
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v2)
        {
            v2=i;
            break;
        }
    }
}

int CreateGraph(AMGraph &G)
{
    cout<<"请输入顶点数和边数:";
    cin>>G.vexnum>>G.arcnum;
    int i,j,weight,v1,v2;
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=MaxInt;
    cout<<"请输入"<<G.vexnum<<"个顶点信息:";
    for(i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    cout<<"请输入目标边信息:\n";
    for(i=0;i<G.arcnum;i++)
    {
        cout<<"输入第"<<i+1<<"条边(分别是:边1 边2 边权):";
        cin>>v1>>v2>>weight;
        LocateVertex(G,v1,v2);
        G.arcs[v1][v2]=weight;
        G.arcs[v2][v1]=weight;
    }
    return 0;
}

int PutGraph(AMGraph G)
{
    int i,j;
    cout<<G.vexnum<<"个点信息分别为:";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<G.vexs[i]<<" ";
    }
    cout<<"\n邻接矩阵如下:\n";
    cout<<"\t";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i+1<<"\t";
    }
    cout<<"\n\n\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i+1<<"\t";
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]==MaxInt)
                cout<<"∞\t";
            else
                cout<<G.arcs[i][j]<<"\t";
        }
        cout<<"\n\n\n";
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

int EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MVNum==Q.front)
        return 0;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MVNum;
}

int DeQueue(SqQueue &Q,int &e)
{
    if(Q.front=Q.rear)
        return 0;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MVNum;
}

int QueueEmpty(SqQueue &Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}

int BreadthFirstSearch(AMGraph G)
{
    int e,j,mark,i;
    SqQueue Q;
    InitQueue(Q);
    for(i=0;i<G.vexnum;i++)
       visited[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            cout<<G.vexs[i]<<" "" ";
            EnQueue(Q,G.vexs[i]);
            while(!QueueEmpty(Q))
            {
                DeQueue(Q,e);
                for(j=0;j<G.vexnum;j++)
                if(G.vexs[j]==e)
                     mark=j;
                for(j=0;j<G.vexnum;j++)
                {
                    if(G.arcs[mark][j]!=MaxInt && !visited[j])
                    {
                        visited[j]=1;
                        cout<<G.vexs[j]<<" "" ";
                        EnQueue(Q,G.vexs[j]);
                    }
                }
           }
        }
    }
}


int main()
{
    AMGraph G;
    cout<<"创建邻接矩阵!\n";
    CreateGraph(G);
    cout<<"\n\n输出邻接矩阵!\n\n";
    PutGraph(G);
    cout<<"广度优先搜索遍历无向图!\n";
    BreadthFirstSearch(G);
    cout<<"\n广度优先搜索遍历结束!\n";
    return 0;
}





//法2:(广度优先搜索用两个函数的情况，初始化和操作部分分开处理)【操作不稳定，一些情况不行】
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;

int visited[MVNum];

int LocateVertex(AMGraph G,int &v1,int &v2)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v1)
        {
            v1=i;
            break;
        }
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v2)
        {
            v2=i;
            break;
        }
    }
}

int CreateGraph(AMGraph &G)
{
    cout<<"请输入顶点数和边数:";
    cin>>G.vexnum>>G.arcnum;
    int i,j,weight,v1,v2;
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=MaxInt;
    cout<<"请输入"<<G.vexnum<<"个顶点信息:";
    for(i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    cout<<"请输入目标边信息:\n";
    for(i=0;i<G.arcnum;i++)
    {
        cout<<"输入第"<<i+1<<"条边(分别是:边1 边2 边权):";
        cin>>v1>>v2>>weight;
        LocateVertex(G,v1,v2);
        G.arcs[v1][v2]=weight;
        G.arcs[v2][v1]=weight;
    }
    return 0;
}

int PutGraph(AMGraph G)
{
    int i,j;
    cout<<G.vexnum<<"个点信息分别为:";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<G.vexs[i]<<" ";
    }
    cout<<"\n邻接矩阵如下:\n";
    cout<<"\t";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i+1<<"\t";
    }
    cout<<"\n\n\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i+1<<"\t";
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]==MaxInt)
                cout<<"∞\t";
            else
                cout<<G.arcs[i][j]<<"\t";
        }
        cout<<"\n\n\n";
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

int EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MVNum==Q.front)
        return 0;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MVNum;
}

int DeQueue(SqQueue &Q,int &e)
{
    if(Q.front=Q.rear)
        return 0;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MVNum;
}

int QueueEmpty(SqQueue &Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}

int BreadthFirstSearch(AMGraph G,int i)
{
    int e,j,mark;
    SqQueue Q;
    InitQueue(Q);
    visited[i]=1;
    cout<<G.vexs[i]<<" "" ";
    EnQueue(Q,G.vexs[i]);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,e);
        for(j=0;j<G.vexnum;j++)
            if(G.vexs[j]==e)
                mark=j;
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[mark][j]!=MaxInt && !visited[j])
            {
                visited[j]=1;
                cout<<G.vexs[j]<<" "" ";
                EnQueue(Q,G.vexs[j]);
            }
        }
    }
}

int TraverseGraph(AMGraph G)
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
    AMGraph G;
    cout<<"创建邻接矩阵!\n";
    CreateGraph(G);
    cout<<"\n\n输出邻接矩阵!\n\n";
    PutGraph(G);
    cout<<"广度优先搜索遍历无向图!\n";
    TraverseGraph(G);
    cout<<"\n广度优先搜索遍历结束!\n";
    return 0;
}
*/
