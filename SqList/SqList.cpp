#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX 100
#define ERROR 0
#define OVERFLOW -1
typedef char ElemType;

typedef struct
{
   ElemType *data;
   int length;
}SqList;

int MakeEmpty(SqList &L)
{
   L.data=new ElemType[MAX];
   if(!L.data)
      exit(OVERFLOW);
   L.length=0;
}

int Insert(SqList &L,ElemType x,int i)
{
    int j;
    if(i<1 || i>L.length+1)
        return ERROR;
    for(j=L.length;j>=i-1;j--)
        L.data[j+1]=L.data[j];
    L.data[i-1]=x;
    ++L.length;
}

int DispList(SqList L)
{
    for(int i=0;i<L.length;i++)
        cout<<L.data[i]<<" ";
    cout<<endl;
}

int ListEmpty(SqList L)
{
   if(L.length==0)
      return 1;
   else
      return 0;

}

int Length(SqList L)
{
    return L.length;
}

int GetElem(SqList L,int i,ElemType &x)
{
    if(i<1 || i>L.length)
        return ERROR;
    x=L.data[i-1];
}

int Find(SqList L,ElemType x)
{
    for(int i=0;i<L.length;i++)
        if(L.data[i]==x)
            return i;
}

int Delete(SqList &L,int i)
{
    if(i<1 || i>L.length)
        return ERROR;
    for(int j=i;j<L.length-1;j++)
        L.data[j-1]=L.data[j];
        --L.length;
}




int main()
{
    SqList L;
    ElemType e;
    cout<<"(1)初始化顺序表"<<endl;
    MakeEmpty(L);
    cout<<"(2)一次用尾插法插入a,b,c,d,e元素"<<endl;
    Insert(L,'a',1);
    Insert(L,'b',2);
    Insert(L,'c',3);
    Insert(L,'d',4);
    Insert(L,'e',5);
    cout<<"(3)输出顺序表L:";
    DispList(L);
    cout<<"(4)顺序表长度="<<Length(L)<<endl;
    if(!ListEmpty(L))
        cout<<"(5)顺序表为非空"<<endl;
    GetElem(L,3,e);
    cout<<"(6)顺序表的第三个元素="<<e<<endl;
    cout<<"(7)元素a的位置="<<Find(L,'a')<<endl;
    cout<<"(8)在第4个元素位置插入f元素"<<endl;
    Insert(L,'f',4);
    cout<<"(9)输出顺序表L:";
    DispList(L);
    cout<<"(10)删除L第3个元素"<<endl;
    Delete(L,3);
    cout<<"(11)输出顺序表L:";
    DispList(L);
}
