#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100
#define MANum 100
#define MAX 100
#define OVERFLOW -1
#define MAXSIZE 100
#define ERROR 0;

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

int visited[MaxInt];

int bound(char c,int z)
{
    while(z--)
        cout<<c;
    cout<<endl;
}

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
    cout<<G.vexs[i]<<"  ";
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
            cout<<G.vexs[i]<<"  ";
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

struct CloseEdge
{
    int adjvex;
    int lowcost;
}closedge[MVNum];

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

int Prim_AM(AMGraph G,int start)
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

struct Edge
{
    int head;
    int tail;
    int lowcost;
}edge[MANum];

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

int LocateVex_1(AMGraph G,int v)
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

int Kruskal_AM(AMGraph G)
{
    int vexset[MANum],resulvex[MVNum],flag[MVNum],temp[MVNum];
    int i,j,v1,v2,vs1,vs2,arc,z=0,sum=0,k=0;
    GetEdge(G,edge);
    Sort(G,edge);
    for(i=0;i<G.vexnum;i++)
        vexset[i]=i;
    cout<<"ÿ�����Ϊ:"<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        v1=LocateVex_1(G,edge[i].head);
        v2=LocateVex_1(G,edge[i].tail);
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
    cout<<"����������ȨֵΪ:"<<sum<<endl;
    for(i=0;i<G.vexnum;i++)
        flag[i]=G.vexs[i];
    cout<<"����С������Ϊ:";
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

int MinSpanTree(AMGraph G)
{
    int choose=1,start;
    bound('*',50);
    cout<<"\n\t  ��С������(�ڽӾ���)\n\n";
    cout<<"\t    1.��Primʵ��\n";
    cout<<"\t    2.��Kruskalʵ��\n";
    cout<<"\t    0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
           case 1:
              cout<<"��Primʵ��!\n";
              cout<<"��������С�������ĵ�һ����(���):";
              cin>>start;
              Prim_AM(G,start);
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t��С������(�ڽӾ���)\n\n";
              cout<<"\t    1.��Primʵ��\n";
              cout<<"\t    2.��Kruskalʵ��\n";
              cout<<"\t    0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 2:
              cout<<"��Kruskalʵ��!\n";
              Kruskal_AM(G);
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t��С������(�ڽӾ���)\n\n";
              cout<<"\t    1.��Primʵ��\n";
              cout<<"\t    2.��Kruskalʵ��\n";
              cout<<"\t    0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 0:
              cout<<"�˳���ϵͳ!\n";
              return 0;
           default :
              cout<<"��������!������ѡ��!\n\n";
              bound('*',50);
              cout<<"\n\t��С������(�ڽӾ���)\n\n";
              cout<<"\t    1.��Primʵ��\n";
              cout<<"\t    2.��Kruskalʵ��\n";
              cout<<"\t    0.�˳�\n\n";
              bound('*',50);
        }
    }
}



typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph_1;

int LocateVertex_2(AMGraph_1 G,int &v1,int &v2)
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

int CreateGraph_1(AMGraph_1 &G)
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
        LocateVertex_2(G,v1,v2);
        G.arcs[v1][v2]=weight;
    }
    return 0;
}

int PutGraph_1(AMGraph_1 G)
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

int ShortPath_AM(AMGraph_1 G,int v0)
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
    cout<<endl;
}

typedef int SElemType;

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

int FindInDegree(AMGraph_1 G,int indegree[])
{
    int i,j,k;
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++)
       for(j=0;j<G.vexnum;j++)
           if(G.arcs[i][j]!=MaxInt)
               indegree[j]++;
    cout<<"indegree[]�����е�����Ϊ:\n";
    for(i=0;i<G.vexnum;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
        cout<<indegree[i]<<" ";
    cout<<endl;
}

int StackEmpty(SqStack S)
{
    if(S.top==S.base)
        return 1;
    else
        return 0;
}

int TopoSort_AM_Stack(AMGraph_1 G)
{
    SqStack S;
    int i,j,k,z,m,indegree[MVNum],topo[MVNum];
    FindInDegree(G,indegree);
    MakeStack(S);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
       {
           Push(S,i);
           indegree[i]=-1;
       }
    m=0;
    while(!StackEmpty(S))
    {
        Pop(S,i);
        topo[m]=i;
        m++;
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]!=MaxInt)
               indegree[j]--;
            if(indegree[j]==0)
            {
                Push(S,j);
                indegree[j]=-1;
            }
        }
    }
    if(m<G.vexnum)
        cout<<"������ͼ�л�·!����ʵ����������!\n";
    else
    {
        cout<<"�����������(�±�)Ϊ:";
        for(i=0;i<G.vexnum;i++)
            cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"�����������(����)Ϊ:";
        for(i=0;i<G.vexnum;i++)
            cout<<G.vexs[topo[i]]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

typedef int ElemType;

typedef struct
{
    ElemType *base;
    int fron;
    int rear;
}SqQueue_1;

int CreateQueue(SqQueue_1 &Q)
{
    Q.base=new ElemType{MAXSIZE};
    if(!Q.base)
        exit(OVERFLOW);
    Q.fron=Q.rear=0;
}

int EnQueue(SqQueue_1 &Q,ElemType x)
{
    if((Q.rear+1)%MAXSIZE==Q.fron)
        return ERROR;
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
}

int DeQueue(SqQueue_1 &Q,ElemType &x)
{
    if(Q.fron==Q.rear)
        return ERROR;
    x=Q.base[Q.fron];
    Q.fron=(Q.fron+1)%MAXSIZE;
}

int QueueEmpty(SqQueue_1 Q)
{
    if(Q.fron==Q.rear)
        return 1;
    else
        return 0;
}

int TopoSort_AM_SqQueue(AMGraph_1 G)
{
    SqQueue_1 Q;;
    int i,j,k,z,m,indegree[MVNum],topo[MVNum];
    FindInDegree(G,indegree);
    CreateQueue(Q);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
       {
           EnQueue(Q,i);
           indegree[i]=-1;
       }
    m=0;
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,i);
        topo[m]=i;
        m++;
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]!=MaxInt)
               indegree[j]--;
            if(indegree[j]==0)
            {
                EnQueue(Q,j);
                indegree[j]=-1;
            }
        }
    }
    if(m<G.vexnum)
        cout<<"������ͼ�л�·!����ʵ����������!\n";
    else
    {
        cout<<"�����������(�±�)Ϊ:";
        for(i=0;i<G.vexnum;i++)
            cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"�����������(����)Ϊ:";
        for(i=0;i<G.vexnum;i++)
            cout<<G.vexs[topo[i]]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int TopoSort_AM(AMGraph_1 G)
{
    int choose=1;
    bound('*',50);
    cout<<"\n\t ��������(�ڽӾ���)\n\n";
    cout<<"\t   1.��ջʵ��(�ڽӾ���)\n";
    cout<<"\t   2.�ö���ʵ��(�ڽӾ���)\n";
    cout<<"\t   0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
            case 1:
               cout<<"��ջʵ��(�ڽӾ���)!\n";
               TopoSort_AM_Stack(G);
               cout<<endl;
               bound('*',50);
               cout<<"\n\t ��������(�ڽӾ���)\n\n";
               cout<<"\t   1.��ջʵ��(�ڽӾ���)\n";
               cout<<"\t   2.�ö���ʵ��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 2:
               cout<<"\n\n�ö���ʵ��(�ڽӾ���)!\n";
               TopoSort_AM_SqQueue(G);
               cout<<endl;
               bound('*',50);
               cout<<"\n\t ��������(�ڽӾ���)\n\n";
               cout<<"\t   1.��ջʵ��(�ڽӾ���)\n";
               cout<<"\t   2.�ö���ʵ��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 0:
               cout<<"�ɹ��˳���ϵͳ!\n\n\n";
               return 0;
            default :
               cout<<"��������!������ѡ��!\n\n";
               bound('*',50);
               cout<<"\n\t ��������(�ڽӾ���)\n\n";
               cout<<"\t   1.��ջʵ��(�ڽӾ���)\n";
               cout<<"\t   2.�ö���ʵ��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
        }
    }
}

int CreateWithPositionGraph_AM()
{
    int choose=1;
    AMGraph_1 G;
    int v;
    bound('*',50);
    cout<<"\n\t  ������(�ڽӾ���)\n\n";
    cout<<"\t   1.��������ͼ(�ڽӾ���)\n";
    cout<<"\t   2.�������ͼ(�ڽӾ���)\n";
    cout<<"\t   3.ʵ�����·��(�ڽӾ���)\n";
    cout<<"\t   4.ʵ����������(�ڽӾ���)\n";
    cout<<"\t   0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
            case 1:
               cout<<"��������ͼ(�ڽӾ���)!\n";
               CreateGraph_1(G);
               cout<<"����ͼ(�ڽӾ���)�����ɹ�!\n\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӾ���)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӾ���)\n";
               cout<<"\t   2.�������ͼ(�ڽӾ���)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӾ���)\n";
               cout<<"\t   4.ʵ����������(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 2:
               cout<<"�������ͼ(�ڽӾ���)!\n";
               PutGraph_1(G);
               bound('*',50);
               cout<<"\n\t  ������(�ڽӾ���)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӾ���)\n";
               cout<<"\t   2.�������ͼ(�ڽӾ���)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӾ���)\n";
               cout<<"\t   4.ʵ����������(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 3:
               cout<<"ʵ�������·��!\n";
               cout<<"��������ʼ��Ŀ�궥����±�:";
               cin>>v;
               ShortPath_AM(G,v);
               cout<<endl;
               bound('*',50);
               cout<<"\n\t ������(�ڽӾ���)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӾ���)\n";
               cout<<"\t   2.�������ͼ(�ڽӾ���)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӾ���)\n";
               cout<<"\t   4.ʵ����������(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 4:
               cout<<"ʵ����������!\n";
               TopoSort_AM(G);
               bound('*',50);
               cout<<"\n\t  ������(�ڽӾ���)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӾ���)\n";
               cout<<"\t   2.�������ͼ(�ڽӾ���)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӾ���)\n";
               cout<<"\t   4.ʵ����������(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 0:
               cout<<"�ɹ��˳���ϵͳ!\n";
               return 0;
            default :
               cout<<"��������!������ѡ��!\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӾ���)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӾ���)\n";
               cout<<"\t   2.�������ͼ(�ڽӾ���)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӾ���)\n";
               cout<<"\t   4.ʵ����������(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
        }
    }
}

int AMSystem()
{
    int choose=1;
    AMGraph G;
    bound('*',50);
    cout<<"\n\tͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
    cout<<"\t   1.�����ڽӾ���(����)\n";
    cout<<"\t   2.����ڽӾ���(����)\n";
    cout<<"\t   3.���������������(����)\n";
    cout<<"\t   4.���������������(����)\n";
    cout<<"\t   5.ʵ����С������(����)\n";
    cout<<"\t   6.����������(ʵ�����·������������)\n";
    cout<<"\t   0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
            case 1:
               cout<<"�����ڽӾ���!\n";
               CreateGraph(G);
               cout<<"�ڽӾ��󴴽��ɹ�!\n\n\n";
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 2:
               cout<<"����ڽӾ���!\n";
               PutGraph(G);
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 3:
               cout<<"�������������������ͼ!\n";
               TraverseGraph(G);
               cout<<"����������������ɹ�!\n\n\n";
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 4:
               cout<<"�������������������ͼ!\n";
               BreadthFirstSearch(G);
               cout<<"\n����������������ɹ�!\n\n\n";
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 5:
               cout<<"ʵ����С������!\n";
               MinSpanTree(G);
               cout<<"\n\n";
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 6:
               cout<<"����������(ʵ�����·�����������򡢹ؼ�·��)!\n";
               CreateWithPositionGraph_AM();
               cout<<"\n\n";
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 0:
               cout<<"�ɹ��˳���ϵͳ!\n";
               return 0;
            default :
               cout<<"��������!������ѡ��!\n\n";
               bound('*',50);
               cout<<"\n\t  ͼ(�ڽӾ���)���ӱ�ϵͳ\n\n";
               cout<<"\t   1.�����ڽӾ���(����)\n";
               cout<<"\t   2.����ڽӾ���(����)\n";
               cout<<"\t   3.���������������(����)\n";
               cout<<"\t   4.���������������(����)\n";
               cout<<"\t   5.ʵ����С������(����)\n";
               cout<<"\t   6.����������(ʵ�����·������������)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
        }
    }
}


/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/


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

struct Edge_1
{
    int head;
    int tail;
    int lowcost;
}edge_1[MVNum];
/*typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;*/

//int visited[MVNum];

int LocateVex(ALGraph G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
}

int CreateGraph_1(ALGraph &G)
{
    int i,j,s,t,k=0,key,v1,v2,weight;
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
        edge_1[k].head=v1;
        edge_1[k].tail=v2;
        edge_1[k].lowcost=weight;
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
    cout<<endl;
    return 0;
}

int DepthFirstSearch_1(ALGraph G,int i)
{
    ArcNode *p;
    int j;
    cout<<G.vertices[i].data<<"  ";
    visited[i]=1;
    for(p=G.vertices[i].firstarc;p;p=p->nextarc)
    {
        j=p->adjvex;
        if(!visited[j])
           DepthFirstSearch_1(G,j);
    }
    return 0;
}

int DTraverseGraph(ALGraph G)
{
    cout<<"�����������:\n";
    int i,j;
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            DepthFirstSearch_1(G,i);
    }
}

/*int InitQueue(SqQueue &Q)
{
    Q.base=new int[MVNum];
    if(!Q.base)
        exit(0);
    Q.front=Q.rear=0;
}

int EnQueue(SqQueue &Q,int i)
{
    if((Q.rear+1)%MVNum==Q.front)
        return 0;
    Q.base[Q.rear]=i;
    Q.rear=(Q.rear+1)%MVNum;
}

int DeQueue(SqQueue &Q,int &i)
{
    if(Q.front=Q.rear)
        return 0;
    i=Q.base[Q.front];
    Q.front=(Q.front+1)%MVNum;
}

int QueueEmpty(SqQueue &Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}*/

int BreadthFirstSearch_1(ALGraph G,int i)
{
    SqQueue Q;
    InitQueue(Q);
    ArcNode *p;
    visited[i]=1;
    cout<<G.vertices[i].data<<"  ";
    EnQueue(Q,i);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,i);
        p=G.vertices[i].firstarc;
        while(p)
        {
           if(!visited[p->adjvex])
           {
               cout<<G.vertices[p->adjvex].data<<"  ";
               visited[p->adjvex]=1;
               EnQueue(Q,p->adjvex);
               p=p->nextarc;
           }
           else
            p=p->nextarc;
        }
    }
}

int BTraverseGraph(ALGraph G)
{
    int i;
    cout<<"�����������:\n";
    for(i=0;i<G.vexnum;i++)
       visited[i]=0;
    for(i=0;i<G.vexnum;i++)
        if(!visited[i])
          BreadthFirstSearch_1(G,i);
}

int Min(ALGraph G,struct CloseEdge closedge[])
{
    int i,k,min;
    min=MaxInt;
    for(i=1;i<G.vexnum;i++)
        if(closedge[i].lowcost && closedge[i].lowcost<min)
        {
            min=closedge[i].lowcost;
            k=i;
        }
    return k;
}

int Prim_AL(ALGraph G,int start)
{
    int i,j,t,k,m,n,u0,v0,sum=0,index=0;
    int resulvex[MVNum];
    ArcNode *p,*p1;
    t=LocateVex(G,start);
    resulvex[index++]=start;
    closedge[t].lowcost=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(i!=t)
        {
            closedge[i].adjvex=start;
            p=G.vertices[i].firstarc;
            while(p)
            {
                if(p->adjvex==t)
                    closedge[i].lowcost=p->info;
                else
                    closedge[i].lowcost=MaxInt;
                p=p->nextarc;
            }
        }
    }
    cout<<"ÿ�����Ϊ:\n";
    for(i=1;i<G.vexnum;i++)
    {
        k=Min(G,closedge);
        u0=closedge[k].adjvex;
        v0=G.vertices[k].data;
        cout<<u0<<" "<<v0<<endl;
        resulvex[index++]=v0;
        sum+=closedge[k].lowcost;
        closedge[k].lowcost=0;
        p1=G.vertices[k].firstarc;
        while(p1)
        {
            if(p1->info<closedge[p1->adjvex].lowcost)
            {
                 closedge[p1->adjvex].lowcost=p1->info;
                 closedge[p1->adjvex].adjvex=G.vertices[k].data;
            }
            p1=p1->nextarc;
        }
    }
    cout<<"��С������Ϊ:";
    for(i=0;i<G.vexnum;i++)
       cout<<resulvex[i]<<" ";
    cout<<endl;
    cout<<"����С��������ȨֵΪ:"<<sum<<endl;
}

int Sort(ALGraph G,struct Edge_1 edge_1[])
{
    int j,m;
    Edge_1 t;
    m=G.arcnum-1;
    while(m>0)
    {
        for(j=0;j<m;j++)
           if(edge_1[j].lowcost>edge_1[j+1].lowcost)
           {
               t=edge_1[j];
               edge_1[j]=edge_1[j+1];
               edge_1[j+1]=t;
           }
           m--;
    }
}

int Kruskal_AL(ALGraph G)
{
    int i,j,v1,v2,vs1,vs2,arc,z=0,sum=0,k=0;
    int vexset[MVNum],resulvex[MVNum],flag[MVNum],temp[MVNum];;
    ArcNode *p;
    cout<<"��lowcost����ǰ�ĵĽ��:\n";
    for(i=0;i<G.arcnum;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge_1[i].head<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge_1[i].tail<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge_1[i].lowcost<<" ";
    cout<<endl;
    Sort(G,edge_1);
    cout<<"��lowcost����ǰ�ĵĽ��:\n";
    for(i=0;i<G.arcnum;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge_1[i].head<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge_1[i].tail<<" ";
    cout<<endl;
    for(i=0;i<G.arcnum;i++)
        cout<<edge_1[i].lowcost<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
        vexset[i]=i;
    cout<<"ÿ�����Ϊ:\n";
    for(i=0;i<G.vexnum;i++)
    {
        v1=LocateVex(G,edge_1[i].head);
        v2=LocateVex(G,edge_1[i].tail);
        vs1=vexset[v1];
        vs2=vexset[v2];
        if(vs1!=vs2)
        {
            cout<<edge[i].head<<" "<<edge_1[i].tail<<endl;
            resulvex[z++]=edge_1[i].lowcost;
            temp[k++]=edge_1[i].head;
            temp[k++]=edge_1[i].tail;
            for(j=0;j<G.vexnum;j++)
                if(vexset[j]==vs2)
                    vexset[j]=vs1;
        }
    }
    for(i=0;i<z;i++)
        sum+=resulvex[i];
    cout<<"����������ȨֵΪ:"<<sum<<endl;
    for(i=0;i<G.vexnum;i++)
        flag[i]=G.vertices[i].data;
    cout<<"����С������Ϊ:";
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

int MinSpanTree_1(ALGraph G)
{
    int choose=1,start;
    bound('*',50);
    cout<<"\n\t  ��С������(�ڽӱ�)\n\n";
    cout<<"\t    1.��Primʵ��\n";
    cout<<"\t    2.��Kruskalʵ��\n";
    cout<<"\t    0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
           case 1:
              cout<<"��Primʵ��!\n";
              cout<<"��������С�������ĵ�һ����(���):";
              cin>>start;
              Prim_AL(G,start);
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t  ��С������(�ڽӱ�)\n\n";
              cout<<"\t    1.��Primʵ��\n";
              cout<<"\t    2.��Kruskalʵ��\n";
              cout<<"\t    0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 2:
              cout<<"��Kruskalʵ��!\n";
              Kruskal_AL(G);
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t  ��С������(�ڽӱ�)\n\n";
              cout<<"\t    1.��Primʵ��\n";
              cout<<"\t    2.��Kruskalʵ��\n";
              cout<<"\t    0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 0:
              cout<<"�ɹ��˳���ϵͳ!\n";
              return 0;
           default :
              cout<<"��������!������ѡ��!\n\n";
              bound('*',50);
              cout<<"\n\t  ��С������(�ڽӱ�)\n\n";
              cout<<"\t    1.��Primʵ��\n";
              cout<<"\t    2.��Kruskalʵ��\n";
              cout<<"\t    0.�˳���ϵͳ\n\n";
              bound('*',50);
        }
    }
}

typedef struct ArcNode_1
{
    int adjvex;
    int info;    //�ߵ�Ȩֵ
    struct ArcNode_1 *nextarc;
}ArcNode_1;

typedef struct VNode_1
{
    int data;
    ArcNode_1 *firstarc;
}AdjList_1[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList_1 vertices;
}ALGraph_1;

int LocateVex_2(ALGraph_1 G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
}

int CreateGraph_2(ALGraph_1 &G)
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
        s=LocateVex_2(G,v1);
        t=LocateVex_2(G,v2);
        ArcNode_1 *p1=new ArcNode_1;
        p1->adjvex=t;
        p1->info=weight;
        p1->nextarc=G.vertices[s].firstarc;
        G.vertices[s].firstarc=p1;
    }
    return 0;
}

int DisGraph_2(ALGraph_1 G)
{
    int i;
    cout<<"�ڽӱ��������:\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i;
        ArcNode_1 *p;
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

int ShortestPath_AL(ALGraph_1 G,int v0)
{
    ArcNode_1 *p,*p1;
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
    cout<<endl;
}

int FindInDegree_1(ALGraph_1 G,int indegree[])
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        ArcNode_1 *p;
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

int TopoSort_AL_Stack(ALGraph_1 G)
{
    SqStack S;
    ArcNode_1 *p;
    int i,j,m,k,indegree[MVNum],topo[MVNum];
    FindInDegree_1(G,indegree);
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
}

int TopoSort_AL_SqQueue(ALGraph_1 G)
{
    SqQueue_1 Q;
    ArcNode_1 *p;
    int i,j,m,k,indegree[MVNum],topo[MVNum];
    FindInDegree_1(G,indegree);
    CreateQueue(Q);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
          EnQueue(Q,i);
    m=0;
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,i);
        topo[m]=i;
        m++;
        p=G.vertices[i].firstarc;
        while(p)
        {
            k=p->adjvex;
            indegree[k]--;
            if(indegree[k]==0)
                EnQueue(Q,k);
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
}

int TopoSort_AL(ALGraph_1 G)
{
    int choose=1;
    bound('*',50);
    cout<<"\n\t ��������(�ڽӱ�)\n\n";
    cout<<"\t   1.��ջʵ��(�ڽӱ�)\n";
    cout<<"\t   2.�ö���ʵ��(�ڽӱ�)\n";
    cout<<"\t   0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
            case 1:
               cout<<"��ջʵ��(�ڽӱ�)!\n";
               TopoSort_AL_Stack(G);
               cout<<endl<<endl;
               bound('*',50);
               cout<<"\n\t ��������(�ڽӱ�)\n\n";
               cout<<"\t   1.��ջʵ��(�ڽӱ�)\n";
               cout<<"\t   2.�ö���ʵ��(�ڽӱ�)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 2:
               cout<<"\n\n�ö���ʵ��(�ڽӱ�)!\n";
               TopoSort_AL_SqQueue(G);
               cout<<endl<<endl;
               bound('*',50);
               cout<<"\n\t ��������(�ڽӱ�)\n\n";
               cout<<"\t   1.��ջʵ��(�ڽӱ�)\n";
               cout<<"\t   2.�ö���ʵ��(�ڽӱ�)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 0:
               cout<<"�ɹ��˳���ϵͳ!\n";
               return 0;
            default :
               cout<<"��������!������ѡ��!\n\n";
        }
    }
}

int TopoSort_1(ALGraph_1 G,int topo[])
{
    SqStack S;
    ArcNode_1 *p;
    int i,j,m,k,indegree[MVNum];
    FindInDegree_1(G,indegree);
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

int CriticalPath(ALGraph_1 G)
{
    ArcNode_1 *p;
    int i,j,k,z=0,t=0,e,l,n,sum=0;
    int ve[MVNum],vl[MVNum],topo[MVNum],temp[MVNum],temp_1[MVNum];
    if(!TopoSort_1(G,topo))
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

int CreateWithPositionGraph_AL()
{
    int choose=1;
    ALGraph_1 G;
    int v0;
    bound('*',50);
    cout<<"\n\t  ������(�ڽӱ�)\n\n";
    cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
    cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
    cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
    cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
    cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
    cout<<"\t   0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
            case 1:
               cout<<"�����ڽӱ�!\n";
               CreateGraph_2(G);
               cout<<"�ɹ������ڽӱ�!\n\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӱ�)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
               cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
               cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
               cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 2:
               cout<<"����ڽӱ�(������)!\n";
               DisGraph_2(G);
               cout<<"\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӱ�)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
               cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
               cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
               cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 3:
               cout<<"ʵ�����·��!\n";
               cout<<"��������ʼ��Ŀ�궥����±�:";
               cin>>v0;
               ShortestPath_AL(G,v0);
               cout<<"\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӱ�)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
               cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
               cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
               cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 4:
               cout<<"ʵ����������!\n";
               TopoSort_AL(G);
               cout<<"\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӱ�)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
               cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
               cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
               cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 5:
               cout<<"ʵ�ֹؼ�·��!\n";
               CriticalPath(G);
               cout<<"\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӱ�)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
               cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
               cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
               cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
               break;
            case 0:
               cout<<"�ɹ��˳���ϵͳ!\n";
               return 0;
            default :
               cout<<"��������!������ѡ��!\n\n";
               bound('*',50);
               cout<<"\n\t  ������(�ڽӱ�)\n\n";
               cout<<"\t   1.��������ͼ(�ڽӱ�)\n";
               cout<<"\t   2.�������ͼ(�ڽӱ�)\n";
               cout<<"\t   3.ʵ�����·��(�ڽӱ�)\n";
               cout<<"\t   4.ʵ����������(�ڽӱ�)\n";
               cout<<"\t   5.ʵ�ֹؼ�·��(�ڽӾ���)\n";
               cout<<"\t   0.�˳���ϵͳ\n\n";
               bound('*',50);
        }
    }
}

int ALSystem()
{
    int choose=1;
    ALGraph G;
    bound('*',50);
    cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
    cout<<"\t   1.�����ڽӱ�(����)\n";
    cout<<"\t   2.����ڽӱ�(����)\n";
    cout<<"\t   3.���������������(����)\n";
    cout<<"\t   4.���������������(����)\n";
    cout<<"\t   5.ʵ����С������(����)\n";
    cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
    cout<<"\t   0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
           case 1:
              cout<<"�����ڽӱ�!\n";
              CreateGraph_1(G);
              cout<<"�ɹ������ڽӱ�!\n\n\n";
              bound('*',50);
              cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
              cout<<"\t   1.�����ڽӱ�(����)\n";
              cout<<"\t   2.����ڽӱ�(����)\n";
              cout<<"\t   3.���������������(����)\n";
              cout<<"\t   4.���������������(����)\n";
              cout<<"\t   5.ʵ����С������(����)\n";
              cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
              cout<<"\t   0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 2:
              cout<<"����ڽӱ�(������)!\n";
              DisGraph(G);
              cout<<endl;
              bound('*',50);
              cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
              cout<<"\t   1.�����ڽӱ�(����)\n";
              cout<<"\t   2.����ڽӱ�(����)\n";
              cout<<"\t   3.���������������(����)\n";
              cout<<"\t   4.���������������(����)\n";
              cout<<"\t   5.ʵ����С������(����)\n";
              cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
              cout<<"\t   0.�˳���ϵͳ\n\n";
              bound('*',50);
              cout<<endl;
              break;
           case 3:
              cout<<"�������������������ͼ!\n";
              DTraverseGraph(G);
              cout<<"\n����������������ɹ�!\n\n\n";
              bound('*',50);
              cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
              cout<<"\t   1.�����ڽӱ�(����)\n";
              cout<<"\t   2.����ڽӱ�(����)\n";
              cout<<"\t   3.���������������(����)\n";
              cout<<"\t   4.���������������(����)\n";
              cout<<"\t   5.ʵ����С������(����)\n";
              cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
              cout<<"\t   0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 4:
              cout<<"�������������������ͼ!\n";
              BTraverseGraph(G);
              cout<<"\n����������������ɹ�!\n\n\n";
              bound('*',50);
              cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
              cout<<"\t   1.�����ڽӱ�(����)\n";
              cout<<"\t   2.����ڽӱ�(����)\n";
              cout<<"\t   3.���������������(����)\n";
              cout<<"\t   4.���������������(����)\n";
              cout<<"\t   5.ʵ����С������(����)\n";
              cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
              cout<<"\t   0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 5:
              cout<<"ʵ����С������!\n";
              MinSpanTree_1(G);
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
              cout<<"\t   1.�����ڽӱ�(����)\n";
              cout<<"\t   2.����ڽӱ�(����)\n";
              cout<<"\t   3.���������������(����)\n";
              cout<<"\t   4.���������������(����)\n";
              cout<<"\t   5.ʵ����С������(����)\n";
              cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
              cout<<"\t   0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 6:
              cout<<"����������(ʵ�����·�����������򡢹ؼ�·��)!\n";
              CreateWithPositionGraph_AL();
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t  ͼ(�ڽӱ�)���ӱ�ϵͳ\n\n";
              cout<<"\t   1.�����ڽӱ�(����)\n";
              cout<<"\t   2.����ڽӱ�(����)\n";
              cout<<"\t   3.���������������(����)\n";
              cout<<"\t   4.���������������(����)\n";
              cout<<"\t   5.ʵ����С������(����)\n";
              cout<<"\t   6.����������(ʵ�����·�����������򡢹ؼ�·��)\n";
              cout<<"\t   0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 0:
              cout<<"�ɹ��˳���ϵͳ!\n";
              return 0;
           default :
              cout<<"��������!������ѡ��!\n";
        }
    }
}

int main()
{
    int choose=1;
    bound('*',50);
    cout<<"\n\t ϵͳ����\n\n";
    cout<<"\t1.�ڽӾ���\n";
    cout<<"\t2.�ڽӱ�\n";
    cout<<"\t0.�˳���ϵͳ\n\n";
    bound('*',50);
    while(choose)
    {
        cout<<"��ѡ��:";
        cin>>choose;
        switch(choose)
        {
           case 1:
              cout<<"���ڽӾ���ʵ��!\n";
              AMSystem();
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t ϵͳ����\n\n";
              cout<<"\t1.�ڽӾ���\n";
              cout<<"\t2.�ڽӱ�\n";
              cout<<"\t0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 2:
              cout<<"���ڽӱ�ʵ��!\n";
              ALSystem();
              cout<<"\n\n";
              bound('*',50);
              cout<<"\n\t ϵͳ����\n\n";
              cout<<"\t1.�ڽӾ���\n";
              cout<<"\t2.�ڽӱ�\n";
              cout<<"\t0.�˳���ϵͳ\n\n";
              bound('*',50);
              break;
           case 0:
              cout<<"�ɹ��˳�ͼ����ϵͳ!��л����ʹ��!\n";
              return 0;
           default :
              cout<<"��������!������ѡ��!\n";
        }
    }
}
