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

int CreatList(SqList &L)
{
    int i,n;
    cout<<"请输入数据的数量:";
    cin>>n;
    cout<<"\n请输入数据:";
    for(i=0;i<n;i++)
    {
        cin>>L.data[i].key;
        ++L.length;
    }
}

int QuickSort(SqList &L)
{
    QSort(L,1,L.length);
}

int QSort(SqList &L,int low,int high)
{
    int pivotloc;
    if(low<high)
    {
        pivotloc=Partition(L,low,high);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);
    }
}

int Partition(SqList &L,int low,int high)
{
    int pivotkey;
    L.data[0]=L.data[low];
    pivotkey=L.data[low].key;
    while(low<high)
    {
        while(low<high && L.data[high].key>=pivotkey)
            --high;
        L.data[low]=L.data[high];
        while(low<high && L.data[low].key<=pivotkey)
            ++low;
        L.data[high]=L.data[low];
    }
    L.data[low]=L.data[0];
    return low;
}

int DispList(SqList L)
{
    int i;
    for(i=1;i<=L.length;i++)
    {
        cout<<L.data[i].key<<" ";
    }
}

int main()
{
    SqList L;
    cout<<"1.初始化顺序表"<<endl;
    InitList(L);
    cout<<"2.建立顺序表:";
    CreatList(L);
    cout<<endl;
    cout<<"3.快速排序数据:";
    QuickSort(L);
    cout<<endl;
    cout<<"4.输出顺序表L:";
    DispList(L);
    cout<<endl;

}
