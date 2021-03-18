#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX 100
#define ERROR 0
#define OVERFLOW -1

typedef struct
{
    int key;
    int other;
}ElemType;

typedef struct
{
   ElemType *data;
   int length;
}SqList;

int InitList(SqList &L)
{
   L.data=new ElemType[MAX];
   if(!L.data)
      exit(OVERFLOW);
   L.length=0;
}

int CreateList(SqList &L)
{
    int i,n;
    cout<<"输入数据的数量:";
    cin>>n;
    cout<<"请输入数据:";
    for(i=1;i<=n;i++)
    {
        cin>>L.data[i].key;
        L.length++;
    }
}

int BubbleSort(SqList L)
{
    int i,n=L.length-1;
    ElemType temp;
    while(n>0)
    {
        for(i=1;i<=n;i++)
        {
            if(L.data[i].key>L.data[i+1].key)
            {
                temp=L.data[i];
                L.data[i]=L.data[i+1];
                L.data[i+1]=temp;
            }
        }
        n--;
    }
    cout<<"输出结果:";
    for(i=1;i<=L.length;i++)
    {
        cout<<L.data[i].key<<" ";
    }
}

int SimpleSort(SqList L)
{
    int i,j,k;
    ElemType t;
    for(i=1;i<L.length;i++)
    {
        k=i;
        for(j=i+1;j<=L.length;j++)
            if(L.data[j].key<L.data[k].key)
                k=j;
        if(k!=i)
        {
            t=L.data[i];
            L.data[i]=L.data[k];
            L.data[k]=t;
        }
    }
    cout<<"输出结果:";
    for(i=1;i<=L.length;i++)
    {
        cout<<L.data[i].key<<" ";
    }
}

int DirectSort(SqList L)
{
    int i,j;
    for(i=2;i<=L.length;i++)
       if(L.data[i].key<L.data[i-1].key)
       {
           L.data[0]=L.data[i];
           L.data[i]=L.data[i-1];
           for(j=i-2;L.data[0].key<L.data[j].key;j--)
              L.data[j+1]=L.data[j];
            L.data[j+1]=L.data[0];
       }
    cout<<"输出结果:";
    for(i=1;i<=L.length;i++)
    {
        cout<<L.data[i].key<<" ";
    }
}

int Partition(SqList L,int low,int high)
{
    int pivot;
    L.data[0]=L.data[low];
    pivot=L.data[low].key;
    while(low<high)
    {
        while(low<high && L.data[high].key>=pivot)
            high--;
        L.data[low]=L.data[high];
        while(low<high && L.data[low].key<=pivot)
            low++;
        L.data[high]=L.data[low];
    }
    L.data[low]=L.data[0];
    return low;
}


int QSort(SqList L,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(L,low,high);
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}


int QuickSort(SqList L)
{
    int i;
    QSort(L,1,L.length);
    cout<<"输出结果:";
    for(i=1;i<=L.length;i++)
    {
        cout<<L.data[i].key<<" ";
    }
}

int BinarySort(SqList L)
{
    int i,j,low,high,mid;
    for(i=2;i<=L.length;i++)
    {
        L.data[0]=L.data[i];
        low=1;
        high=i-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(L.data[0].key<L.data[mid].key)
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=high+1;--j)
            L.data[j+1]=L.data[j];
        L.data[high+1]=L.data[0];
    }
    cout<<"输出结果:";
    for(i=1;i<=L.length;i++)
    {
        cout<<L.data[i].key<<" ";
    }
}

int main()
{
    SqList L;
    int choose=1;
    cout<<endl;
    cout<<"\t\t\t\t排序子系统"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-----冒泡排序\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-----简单选择\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-----直接插入\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-----快速排序\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t5-----折半排序\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-----返回\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t请选择菜单号(0--5)"<<endl<<endl;
    InitList(L);
    CreateList(L);
    while(choose)
    {
        cout<<"请选择:\n";
        cin>>choose;
        switch(choose)
        {
           case 1:
              cout<<"冒泡排序:\n";
              BubbleSort(L);
              cout<<endl<<endl;
              break;
           case 2:
              cout<<"简单选择:\n";
              SimpleSort(L);
              cout<<endl<<endl;
              break;
           case 3:
             cout<<"直接排序:\n";
             DirectSort(L);
             cout<<endl<<endl;
             break;
           case 4:
             cout<<"快速排序\n";
             QuickSort(L);
             cout<<endl<<endl;
             break;
           case 5:
             cout<<"折半插入排序\n";
             BinarySort(L);
             cout<<endl<<endl;
             break;
           case 0:
             cout<<"返回!退出子系统:\n";
             cout<<"\t\t\t\t排序子系统"<<endl;
             cout<<"\t\t*******************************************"<<endl;
             cout<<"\t\t*\t\t1-----冒泡排序\t\t"<<" "" "<<"*"<<endl;
             cout<<"\t\t*\t\t2-----简单选择\t\t"<<" "" "<<"*"<<endl;
             cout<<"\t\t*\t\t3-----直接插入\t\t"<<" "" "<<"*"<<endl;
             cout<<"\t\t*\t\t4-----快速排序\t\t"<<" "" "<<"*"<<endl;
             cout<<"\t\t*\t\t5-----折半排序\t\t"<<" "" "<<"*"<<endl;
             cout<<"\t\t*\t\t0-----返回\t\t"<<" "" "<<"*"<<endl;
             cout<<"\t\t*******************************************"<<endl;
             cout<<"\t\t请选择菜单号(0--5)"<<endl<<endl;
        }
    }



}
