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
    //��1:ʵ��������·�����㷨
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
            cout<<G.vexs[v0]<<"��"<<G.vexs[i]<<":�����ڴ�·��"<<endl;
        else
        {
            t=path[i];
            j=i;
            cout<<G.vexs[v0]<<"��"<<G.vexs[i]<<"����̾���Ϊ:"<<D[i]<<";���·����:"<<G.vexs[v0];
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
    //��2:ʵ��������·�����㷨
    cout<<"������·��(�±�):\n";
    for(i=0;i<G.vexnum;i++)
    {
        sum=0;
        if(D[i]==MaxInt)
           cout<<v0<<"��"<<i<<":�����ڴ�·��"<<endl;
        else
        {
            cout<<v0<<"��"<<i<<"����̾���Ϊ:"<<D[i]<<";���������·��Ϊ:";
            for(j=i;path[j]>=0;j=path[j])
            {
                temp[sum++]=j;
                cout<<j<<"<-";
            }
            cout<<v0<<";";
            cout<<"���������·��Ϊ:"<<v0;
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
           cout<<G.vexs[v0]<<"��"<<G.vexs[i]<<":�����ڴ�·��"<<endl;
        else
        {
            cout<<G.vexs[v0]<<"��"<<G.vexs[i]<<"����̾���Ϊ:"<<D[i]<<";���������·��Ϊ:";
            for(j=i;path[j]>=0;j=path[j])
            {
                temp[sum++]=j;
                cout<<G.vexs[j]<<"<-";
            }
            cout<<G.vexs[v0]<<";";
            cout<<"���������·��Ϊ:"<<G.vexs[v0];
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
    cout<<"�����ڽӾ���!\n";
    CreateGraph(G);
    cout<<"\n\n����ڽӾ���!\n";
    PutGraph(G);
    cout<<"ʵ�������·��!\n";
    cout<<"��������ʼ��Ŀ�궥����±�:";
    cin>>v;
    ShortPath(G,v);
    return 0;
}
