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
    cout<<"������Ҷ�ӵ�Ȩֵ:";
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
    cout<<"�������������:\n";
    cout<<"���i\tweight\tparent\tlchild\trchild\n";
    for(i=1;i<=(2*n)-1;i++)
    {
        cout<<i<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
    }
    cout<<"��������������!\n\n";
    return 0;
}

int WriteToFile(HuffmanTree HT,int n)
{
    int i;
    FILE *fp;
    if((fp=fopen("HuffmanTree.txt","wt+"))==NULL)
    {
        cout<<"���ı��ļ�ʧ��!\n";
        exit(1);
    }
    cout<<"д���ļ���...��ȴ�...\n";
    fputs("���i\tweight\tparent\tlchild\trchild\n",fp);
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
    cout<<"������Ҷ����:";
    cin>>n;
    cout<<"\n������������!\n";
    CreatHuffmanTree(HT,n);
    cout<<"��������������!\n";
    cout<<"������������ɹ�!\n\n";
    cout<<"�����������������ϸ��Ϣ!\n";
    PutoutHFuTree(HT,n);
    cout<<"������������Ϣд���ı��ļ�!\n";
    WriteToFile(HT,n);
    cout<<"�ѳɹ�д���ı��ļ�!\n";
    return 0;
}
