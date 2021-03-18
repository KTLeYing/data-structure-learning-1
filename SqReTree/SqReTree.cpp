#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX 100
#define ERROR 0
typedef int ElemType;
typedef ElemType SqBiTree[MAX];

int InitiTree(SqBiTree &T,int m)
{
    int i;
    if(m<=1000)
    {
        for(i=1;i<=m;i++)
         {
              T[i]=0;
         }
    }
    else
       return ERROR;

}

int CreateTree(SqBiTree &T,int m)
{
    int i,x;
    int s[m];
    cout<<"输入"<<m<<"个元素:";
    for(i=1;i<=m;i++)
    {
        cin>>x;
        s[i]=x;
        T[i]=s[i];
    }
}

int DealNode(SqBiTree &T,int m,int n)
{
    int a=m,b=n,c=m,d=n;
    if(T[m]!=0 && T[n]!=0)
    {
	    while(m!=n)
		{
           if(m>n)
		   {
              m=m/2;
		   }
           else
			   if(n>m)
			   {
			      n=n/2;
			   }
		} 
		cout<<n<<" "<<T[n];
    }
    else
      if(T[m]==0 && T[n]==0)
     {
        while(m>=1)
        {
           m=m/2;
           if(T[m]==0)
             a=m;
        }
        while(n>=1)
        {
           n=n/2;
           if(T[n]==0)
             b=n;
        }
         if(a<b)
            cout<<"ERROR:T"<<"["<<c<<"]"<<"is NULL";
         else
            cout<<"ERROR:T"<<"["<<d<<"]"<<"is NULL";
     }
     else
        if(T[m]==0)
        {
            while(m>=1)
            {
                m=m/2;
                if(T[m]==0)
                    a=m;
            }
            cout<<"ERROR:T"<<"["<<c<<"]"<<"is NULL";
        }
        else
          if(T[n]==0)
          {
              while(n>=1)
              {
                  n=n/2;
                  if(T[n]==0)
                    b=n;
              }
              cout<<"ERROR:T"<<"["<<d<<"]"<<"is NULL";
          }
}


int main()
{
    int n,i,k,z;
    SqBiTree T,s;
    cout<<"输入n的值:";
    cin>>n;
    InitiTree(T,n);
    CreateTree(T,n);
    for(i=1;i<=n;i++)
        cout<<T[i]<<" ";
    cout<<endl<<"输入k和z:";
    cin>>k>>z;
    DealNode(T,k,z);
}
