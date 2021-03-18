#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef struct ArcNode
{
    int adjvex;
    int info;    //边的权值
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

struct Edge
{
    int head;
    int tail;
    int lowcost;
}edge[MVNum];

int LocateVex(ALGraph G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
}

int CreateGraph(ALGraph &G)
{
    int i,j,s,t,k=0,key,v1,v2,weight;
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
        edge[k].head=v1;
        edge[k].tail=v2;
        edge[k].lowcost=weight;
        k++;
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

int Sort(ALGraph G,struct Edge edge[])
{
    int j,m;
    Edge t;
    m=G.arcnum-1;
    while(m>0)
    {
        for(j=0;j<m;j++)
           if(edge[j].lowcost>edge[j+1].lowcost)
           {
               t=edge[j];
               edge[j]=edge[j+1];
               edge[j+1]=t;
           }
           m--;
    }
}

int MinSpanTree(ALGraph G)
{
    int i,j,v1,v2,vs1,vs2,arc,z=0,sum=0,k=0;
    int vexset[MVNum],resulvex[MVNum],flag[MVNum],temp[MVNum];;
    ArcNode *p;
    cout<<"用lowcost排序前的的结果:\n";
    for(i=0;i<G.arcnum;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge[i].head<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge[i].tail<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge[i].lowcost<<" ";
    cout<<endl;
    Sort(G,edge);
    cout<<"用lowcost排序前的的结果:\n";
    for(i=0;i<G.arcnum;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge[i].head<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge[i].tail<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge[i].lowcost<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
        vexset[i]=i;
    cout<<"每轮输出为:\n";
    for(i=0;i<G.vexnum;i++)
    {
        v1=LocateVex(G,edge[i].head);
        v2=LocateVex(G,edge[i].tail);
        vs1=vexset[v1];
        vs2=vexset[v2];
        if(vs1!=vs2)
        {
            cout<<edge[i].head<<" "<<edge[i].tail<<endl;
            resulvex[z++]=edge[i].lowcost;
            temp[k++]=edge[i].head;
            temp[k++]=edge[i].tail;
            for(j=0;j<G.vexnum;j++)
                if(vexset[j]==vs2)
                    vexset[j]=vs1;
        }
    }
    for(i=0;i<z;i++)
        sum+=resulvex[i];
    cout<<"该生成树的权值为:"<<sum<<endl;
    for(i=0;i<G.vexnum;i++)
        flag[i]=G.vertices[i].data;
    cout<<"该最小生成树为:";
    for(i=0;i<k;i++)
       for(j=0;j<G.vexnum;j++)
       {
           if(temp[i]==flag[j])
           {
               cout<<temp[i]<<" ";
               flag[j]=MaxInt;
           }
       }
   cout<<endl;
}

int main()
{
    ALGraph G;
    cout<<"创建邻接表!\n";
    CreateGraph(G);
    cout<<"成功创建邻接表!\n\n";
    cout<<"输出邻接表(输出序号)!\n";
    DisGraph(G);
    cout<<"实现最小生成树!\n";
    MinSpanTree(G);
    return 0;
}
