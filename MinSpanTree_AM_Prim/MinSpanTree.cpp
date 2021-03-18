//��1:����ṹ��CloseEdge���в�������(�鱾���㷨)

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

struct CloseEdge
{
    int adjvex;
    int lowcost;
}closedge[MVNum];

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

int LocateVertex_1(AMGraph G,int v0)
{
    int i,flag;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int Min(AMGraph G,struct CloseEdge closedge[])
{
     int k=1,i;
     while(closedge[k].lowcost==0)
        k++;
     for(i=1;i<G.vexnum;i++)
         if(closedge[i].lowcost && closedge[i].lowcost<closedge[k].lowcost)
            k=i;
     return k;
}

int MinSpanTree(AMGraph G,int start)
{
    int t,k,i,j,m,n,sum=0,u0,v0,index=0;
    int resulvex[MVNum];
    t=LocateVertex_1(G,start);
    closedge[t].lowcost=0;
    resulvex[index++]=start;
    for(i=0;i<G.vexnum;i++)
        if(i!=t)
        {
            closedge[i].adjvex=start;
            closedge[i].lowcost=G.arcs[t][i];
        }
    cout<<"ÿ�����Ϊ:"<<endl;
    for(i=1;i<G.vexnum;i++)
    {
        k=Min(G,closedge);
        u0=closedge[k].adjvex;
        v0=G.vexs[k];
        resulvex[index++]=v0;
        cout<<u0<<" "<<v0<<endl;
        sum+=closedge[k].lowcost;
        closedge[k].lowcost=0;
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[k][j]<closedge[j].lowcost)
            {
                closedge[j].adjvex=v0;  //v0����G.vexs[k]����
                closedge[j].lowcost=G.arcs[k][j];
            }
        }
    }
    cout<<"��ӡ��С������:";
    for(i=0;i<index;i++)
        cout<<resulvex[i]<<"  ";
    cout<<endl;
    cout<<"����С��������ȨֵΪ:"<<sum<<endl;
    return 0;
}


int main()
{
    AMGraph G;
    int start;
    cout<<"�����ڽӾ���!\n";
    CreateGraph(G);
    cout<<"\n\n����ڽӾ���!\n";
    PutGraph(G);
    cout<<"ʵ����С������!\n";
    cout<<"��������С�������ĵ�һ����(���):";
    cin>>start;
    MinSpanTree(G,start);
    return 0;
}


//��2:�����ⶨ��һ���ṹ��CloseEdge��ֱ����Ŀ�꺯������в�������
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

int LocateVertex_1(AMGraph G,int v0)
{
    int i,flag;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int MinSpanTree(AMGraph G,int start)
{
    int t,k,i,j,z,m,n,sum,min,index=0;
    int vexResul[MVNum];
    int weights[MVNum];
    t=LocateVertex_1(G,start);
    vexResul[index++]=start;
    for(i=0;i<G.vexnum;i++)
        weights[i]=G.arcs[t][i];
    weights[t]=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(t==i)
            continue;
        z=0;
        k=0;
        min=MaxInt;
        while(z<G.vexnum)
        {
            if(weights[z]!=0 && weights[z]<min)
            {
                min=weights[z];
                k=z;
            }
            z++;
        }
        vexResul[index++]=G.vexs[k];
        weights[k]=0;
        for(j=0;j<G.vexnum;j++)
        {
            if(weights[j]!=0 && G.arcs[k][j]<weights[j])
                weights[j]=G.arcs[k][j];
        }
    }
    cout<<"��ӡ��С������:";
    for(i=0;i<index;i++)
        cout<<vexResul[i]<<"  ";
    cout<<endl;
    sum=0;
    for(i=1;i<index;i++)
    {
        min=MaxInt;
        n=LocateVertex_1(G,vexResul[i]);
        for(j=0;j<i;j++)
        {
            m=LocateVertex_1(G,vexResul[j]);
            if(G.arcs[m][n]<min)
                min=G.arcs[m][n];
        }
        sum+=min;
    }
    cout<<"����С��������ȨֵΪ:"<<sum<<endl;
    return 0;
}


int main()
{
    AMGraph G;
    int start;
    cout<<"�����ڽӾ���!\n";
    CreateGraph(G);
    cout<<"\n\n����ڽӾ���!\n";
    PutGraph(G);
    cout<<"ʵ����С������!\n";
    cout<<"��������С�������ĵ�һ����(���):";
    cin>>start;
    MinSpanTree(G,start);
    return 0;
}
*/

/*
//��3:���ⶨ��һ���ṹ��CloseEdge���в�������(�뷨1��ԭ��һ��)
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

struct CloseEdge
{
    int adjvex;
    int lowcost;
}closedge[MVNum];

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

int LocateVertex_1(AMGraph G,int v0)
{
    int i,flag;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int Min(AMGraph G,struct CloseEdge closedge[])
{
     int z=0,k=0,min=MaxInt;
     while(z<G.vexnum)
     {
        if(closedge[z].lowcost!=0 && closedge[z].lowcost<min)
        {
            min=closedge[z].lowcost;
            k=z;
         }
         z++;
     }
     return k;
}

int MinSpanTree(AMGraph G,int start)
{
    int t,k,i,j,m,n,sum,min,index=0;
    t=LocateVertex_1(G,start);
    closedge[index++].adjvex=start;
    for(i=0;i<G.vexnum;i++)
          closedge[i].lowcost=G.arcs[t][i];
    closedge[t].lowcost=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(t==i)
            continue;
        k=Min(G,closedge);
        closedge[index++].adjvex=G.vexs[k];
        closedge[k].lowcost=0;
        for(j=0;j<G.vexnum;j++)
        {
            if(closedge[j].lowcost!=0 && G.arcs[k][j]<closedge[j].lowcost)
                closedge[j].lowcost=G.arcs[k][j];
        }
    }
    cout<<"��ӡ��С������:";
    for(i=0;i<index;i++)
        cout<<closedge[i].adjvex<<"  ";
    cout<<endl;
    sum=0;
    for(i=1;i<index;i++)
    {
        min=MaxInt;
        n=LocateVertex_1(G,closedge[i].adjvex);
        for(j=0;j<i;j++)
        {
            m=LocateVertex_1(G,closedge[j].adjvex);
            if(G.arcs[m][n]<min)
                min=G.arcs[m][n];
        }
        sum+=min;
    }
    cout<<"����С��������ȨֵΪ:"<<sum<<endl;
    return 0;
}


int main()
{
    AMGraph G;
    int start;
    cout<<"�����ڽӾ���!\n";
    CreateGraph(G);
    cout<<"\n\n����ڽӾ���!\n";
    PutGraph(G);
    cout<<"ʵ����С������!\n";
    cout<<"��������С�������ĵ�һ����(���):";
    cin>>start;
    MinSpanTree(G,start);
    return 0;
}
*/


