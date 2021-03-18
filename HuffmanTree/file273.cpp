#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

int Select(HuffmanTree HT,int len,int &s1,int &s2)
{
    int temp,i,min1,min2;
    min1=2147483647;
    min2=2147483647;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min1 && HT[i].parent==0)
        {
            min1=HT[i].weight;
            s1=i;
        }
    }
    temp=HT[s1].weight;
    HT[s1].weight=2147483647;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min2 && HT[i].parent==0)
        {
             min2=HT[i].weight;
             s2=i;
        }
    }
    HT[s1].weight=temp;
}

int CreatHuffmanTree(HuffmanTree &HT,int n)
{
    int i,key,s1,s2;
    HT=new HTNode[2*n];
    for(i=1;i<2*n;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    cout<<"请输入叶子的权值:";
    for(i=1;i<=n;i++)
        cin>>HT[i].weight;
    for(i=n+1;i<=(2*n)-1;i++)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    return 0;
}

int PutoutHFuTree(HuffmanTree &HT,int n)
{
    int i;
    cout<<"请输出哈夫曼树:\n";
    cout<<"结点i\tweight\tparent\tlchild\trchild\n";
    for(i=1;i<=(2*n)-1;i++)
    {
        cout<<i<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
    }
    cout<<"哈夫曼树输出完毕!\n\n";
    return 0;
}

int WriteToFile(HuffmanTree HT,int n)
{
    int i;
    FILE *fp;
    if((fp=fopen("HuffmanTree.txt","wt+"))==NULL)
    {
        cout<<"打开文本文件失败!\n";
        exit(1);
    }
    cout<<"写入文件中...请等待...\n";
    fputs("结点i\tweight\tparent\tlchild\trchild\n",fp);
    for(i=1;i<2*n;i++)
    {
        fprintf(fp,"%d\t%d\t%d\t%d\t%d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
    }
    fclose(fp);
    return 0;
}

int main()
{
    HuffmanTree HT;
    int n,key;
    cout<<"请输入叶子数:";
    cin>>n;
    cout<<"\n构建哈夫曼树!\n";
    CreatHuffmanTree(HT,n);
    cout<<"哈夫曼树构造中!\n";
    cout<<"哈夫曼树构造成功!\n\n";
    cout<<"请输出哈夫曼树的详细信息!\n";
    PutoutHFuTree(HT,n);
    cout<<"将哈夫曼树信息写入文本文件!\n";
    WriteToFile(HT,n);
    cout<<"已成功写入文本文件!\n";
    return 0;
}
