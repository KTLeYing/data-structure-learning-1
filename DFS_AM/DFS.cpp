#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100

int visited[MaxInt];

typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

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
    cout<<"�����붥�����ͱ���:";
    cin>>G.vexnum>>G.arcnum;
    int i,j,weight,v1,v2;
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=MaxInt;
    cout<<"������"<<G.vexnum<<"��������Ϣ:";
    for(i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    cout<<"������Ŀ�����Ϣ:\n";
    for(i=0;i<G.arcnum;i++)
    {
        cout<<"�����"<<i+1<<"����(�ֱ���:��1 ��2 ��Ȩ):";
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
    cout<<G.vexnum<<"������Ϣ�ֱ�Ϊ:";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<G.vexs[i]<<" ";
    }
    cout<<"\n�ڽӾ�������:\n";
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
                cout<<"��\t";
            else
                cout<<G.arcs[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }
    return 0;
}

int DepthFirstSearch(AMGraph G,int i)
{
    int j;
    cout<<G.vexs[i]<<" "" "" ";
    visited[i]=1;
    for(j=0;j<G.vexnum;j++)
    {
        if(G.arcs[i][j]!=MaxInt && !visited[j])
            DepthFirstSearch(G,j);
    }
}

int TraverseGraph(AMGraph G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
           DepthFirstSearch(G,i);
    }
    cout<<endl;
}

int main()
{
    AMGraph G;
    cout<<"�����ڽӾ���!\n";
    CreateGraph(G);
    cout<<"\n\n����ڽӾ���!\n";
    PutGraph(G);
    cout<<"�������������������ͼ!\n";
    TraverseGraph(G);
    cout<<"�������������������!\n\n";
    return 0;
}
