//法1:edgd[]的赋值用另外一个函数实现

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100
#define MANum 100

typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

struct Edge
{
    int head;
    int tail;
    int lowcost;
}edge[MANum];

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

int GetEdge(AMGraph G,struct Edge edge[])
{
   int i,j,index=0;
   for(i=0;i<G.vexnum;i++)
     for(j=i;j<G.vexnum;j++)
       if(G.arcs[i][j]!=MaxInt)
       {
            edge[index].head=G.vexs[i];
            edge[index].tail=G.vexs[j];
            edge[index].lowcost=G.arcs[i][j];
            index++;
       }
}

int Sort(AMGraph G,struct Edge edge[])
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

int LocateVex(AMGraph G,int v)
{
    int i,flag;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int MinSpanTree(AMGraph G)
{
    int vexset[MANum],resulvex[MVNum],flag[MVNum],temp[MVNum];
    int i,j,v1,v2,vs1,vs2,arc,z=0,sum=0,k=0;
    GetEdge(G,edge);
    Sort(G,edge);
    for(i=0;i<G.vexnum;i++)
        vexset[i]=i;
    cout<<"每次输出为:"<<endl;
    for(i=0;i<G.arcnum;i++)
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
        flag[i]=G.vexs[i];
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
    AMGraph G;
    cout<<"创建邻接矩阵!\n";
    CreateGraph(G);
    cout<<"\n\n输出邻接矩阵!\n";
    PutGraph(G);
    cout<<"实现最小生成树!\n";
    MinSpanTree(G);
    return 0;
}


/*
//法2:edgd[]的赋值直接在创建邻接矩阵时实现
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100
#define MANum 100

typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

struct Edge
{
    int head;
    int tail;
    int lowcost;
}edge[MANum];

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
    int i,j,weight,v1,v2,v1_1,v2_1,index=0;
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
        v1_1=v1;
        v2_1=v2;
        LocateVertex(G,v1,v2);
        G.arcs[v1][v2]=weight;
        G.arcs[v2][v1]=weight;
        edge[index].head=v1_1;
        edge[index].tail=v2_1;
        edge[index].lowcost=weight;
        index++;
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

int Sort(AMGraph G,struct Edge edge[])
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

int LocateVex(AMGraph G,int v)
{
    int i,flag;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int MinSpanTree(AMGraph G)
{
    int vexset[MANum],resulvex[MVNum],flag[MVNum],temp[MVNum];
    int i,j,v1,v2,vs1,vs2,arc,z=0,sum=0,k=0;
    Sort(G,edge);
    for(i=0;i<G.vexnum;i++)
        vexset[i]=i;
    cout<<"每次输出为:"<<endl;
    for(i=0;i<G.arcnum;i++)
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
        flag[i]=G.vexs[i];
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
    AMGraph G;
    cout<<"创建邻接矩阵!\n";
    CreateGraph(G);
    cout<<"\n\n输出邻接矩阵!\n";
    PutGraph(G);
    cout<<"实现最小生成树!\n";
    MinSpanTree(G);
    return 0;
}
*/
