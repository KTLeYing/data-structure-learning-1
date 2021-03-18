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

int ShortPath(AMGraph G,int v0)
{
    int i,j,k,n,w,v,min,t,sum;
    int S[MVNum],D[MVNum],path[MVNum],temp[MVNum];
    n=G.vexnum;
    for(v=0;v<n;v++)
    {
        S[v]=0;
        D[v]=G.arcs[v0][v];
        if(D[v]<MaxInt)
           path[v]=v0;
        else
            path[v]=-1;
    }
    S[v0]=1;
    D[v0]=0;
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
       for(w=0;w<n;w++)
         if(!S[w] && (D[v]+G.arcs[v][w]<D[w]))
         {
             D[w]=D[v]+G.arcs[v][w];
             path[w]=v;
         }
    }
    /*
    //法1:实现输出最短路径的算法
    cout<<"输出最短路径(下标):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
            cout<<v0<<"到"<<i<<":不存在此路径"<<endl;
        else
        {
            t=path[i];
            j=i;
            cout<<v0<<"到"<<i<<"的最短距离为:"<<D[i]<<";最短路径是:"<<v0;
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
    cout<<"\n输出最短路径(顶点):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
            cout<<G.vexs[v0]<<"到"<<G.vexs[i]<<":不存在此路径"<<endl;
        else
        {
            t=path[i];
            j=i;
            cout<<G.vexs[v0]<<"到"<<G.vexs[i]<<"的最短距离为:"<<D[i]<<";最短路径是:"<<G.vexs[v0];
            while(t>=0)
            {
                temp[sum++]=j;
                j=t;
                t=path[t];
            }
            for(k=sum-1;k>=0;k--)
              cout<<"->"<<G.vexs[temp[k]];
            cout<<endl;
        }
    }
    */
    //法2:实现输出最短路径的算法
    cout<<"输出最短路径(下标):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
           cout<<v0<<"到"<<i<<":不存在此路径"<<endl;
        else
        {
            cout<<v0<<"到"<<i<<"的最短距离为:"<<D[i]<<";反方向最短路径为:";
            for(j=i;path[j]>=0;j=path[j])
            {
                temp[sum++]=j;
                cout<<j<<"<-";
            }
            cout<<v0<<";";
            cout<<"正方向最短路径为:"<<v0;
            for(k=sum-1;k>=0;k--)
                cout<<"->"<<temp[k];
            cout<<endl;
        }

    }
    cout<<"\n输出最短路径(顶点):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
           cout<<G.vexs[v0]<<"到"<<G.vexs[i]<<":不存在此路径"<<endl;
        else
        {
            cout<<G.vexs[v0]<<"到"<<G.vexs[i]<<"的最短距离为:"<<D[i]<<";反方向最短路径为:";
            for(j=i;path[j]>=0;j=path[j])
            {
                temp[sum++]=j;
                cout<<G.vexs[j]<<"<-";
            }
            cout<<G.vexs[v0]<<";";
            cout<<"正方向最短路径为:"<<G.vexs[v0];
            for(k=sum-1;k>=0;k--)
                cout<<"->"<<G.vexs[temp[k]];
            cout<<endl;
        }

    }
}

int main()
{
    AMGraph G;
    int v;
    cout<<"创建邻接矩阵!\n";
    CreateGraph(G);
    cout<<"\n\n输出邻接矩阵!\n";
    PutGraph(G);
    cout<<"实现求最短路径!\n";
    cout<<"请输入起始的目标顶点的下标:";
    cin>>v;
    ShortPath(G,v);
    return 0;
}
