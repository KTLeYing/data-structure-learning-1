/******************************************************************************************
*FunctionName:Sort                                                                        *
*                                                                                         *
*Description:在已完成读取和存储的二进制文件的基础上，对文本中的所有数据进行排序       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include "header.h"        //引用头文件

using namespace std;

int Partition(ElecMap *eMap,int low,int high)           //进行一趟排序，找到并返回枢轴位置
{
    int pivot;
    eMap->roadRecord[0]=eMap->roadRecord[low];
    pivot=eMap->roadRecord[low].LinkID;
    while(low<high)
    {
        while(low<high && eMap->roadRecord[high].LinkID>=pivot)
            --high;
        eMap->roadRecord[low]=eMap->roadRecord[high];
        while(low<high && eMap->roadRecord[low].LinkID<=pivot)
            ++low;
        eMap->roadRecord[high]=eMap->roadRecord[low];
    }
    eMap->roadRecord[low]=eMap->roadRecord[0];
    return low;                //返回枢轴位置
}

int QSort(ElecMap *eMap,int low,int high)        //快速排序
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(eMap,low,high);
        QSort(eMap,low,pivot-1);
        QSort(eMap,pivot+1,high);
    }
}

int Sort(ElecMap *eMap)                    //对已完成读取并存入文本文档的道路信息进行排序
{
     if(eMap->roadNum==0)
        cout<<"请先进行二进制文件的读取!";

     if(eMap->roadSort==1)
        cout<<"道路已完成排序!\n";
     else
        if(eMap->roadSort==0)
        {
            cout<<"Sort start(Using LinkID to QuickSort)......\n";
            QSort(eMap,1,eMap->roadNum);
            ToWriteSort(eMap);
            cout<<"\nSort success!\n\n";
        }

}


int BubbleSort(ElecMap *eMap)
{
	int i,n=eMap->roadNum-1;
    RoadRecord temp;
	if(eMap->roadNum==0)
        cout<<"请先进行二进制文件的读取!";

    if(eMap->roadSort==1)
        cout<<"道路已完成排序!\n";
    else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to BubbleSort)......\n";
              while(n>0)
              {
                  for(i=1;i<=n;i++)
                  {
                      if(eMap->roadRecord[i].LinkID>eMap->roadRecord[i+1].LinkID)
                      {
                          temp=eMap->roadRecord[i];
                          eMap->roadRecord[i]=eMap->roadRecord[i+1];
                          eMap->roadRecord[i+1]=temp;
                      }
                  }
                  n--;
              }

              ToWriteSort(eMap);
              cout<<"\nSort success!\n\n";
        }
}

int DirectInsertSort(ElecMap *eMap)
{
    int i,j;
    if(eMap->roadNum==0)
        cout<<"请先进行二进制文件的读取!";

    if(eMap->roadSort==1)
        cout<<"道路已完成排序!\n";
    else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to DirectInsertSort)......\n";
        	  for(i=2;i<=eMap->roadNum;i++)
                  if(eMap->roadRecord[i].LinkID<eMap->roadRecord[i-1].LinkID)
                  {
                      eMap->roadRecord[0]=eMap->roadRecord[i];
                      eMap->roadRecord[i]=eMap->roadRecord[i-1];
                      for(j=i-2;eMap->roadRecord[0].LinkID<eMap->roadRecord[j].LinkID;j--)
                      eMap->roadRecord[j+1]=eMap->roadRecord[j];
                      eMap->roadRecord[j+1]=eMap->roadRecord[0];
                  }

               ToWriteSort(eMap);
               cout<<"\nSort success!\n\n";
        }
}

int BinarySort(ElecMap *eMap)
{
    int i,j,low,high,mid;
    if(eMap->roadNum==0)
        cout<<"请先进行二进制文件的读取!";

    if(eMap->roadSort==1)
        cout<<"道路已完成排序!\n";
    else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to BinarySort)......\n";
        	  for(i=2;i<=eMap->roadNum;i++)
              {
                   eMap->roadRecord[0]=eMap->roadRecord[i];
                   low=1;
                   high=i-1;
                   while(low<=high)
                   {
                      mid=(low+high)/2;
                      if(eMap->roadRecord[0].LinkID<eMap->roadRecord[mid].LinkID)
                          high=mid-1;
                      else
                         low=mid+1;
                   }
                   for(j=i-1;j>=high+1;--j)
                       eMap->roadRecord[j+1]=eMap->roadRecord[j];
                   eMap->roadRecord[high+1]=eMap->roadRecord[0];
              }
              ToWriteSort(eMap);
              cout<<"\nSort success!\n\n";
        }
}


int SimpleElectSort(ElecMap *eMap)
{
	 int i,j,k;
     RoadRecord t;
     if(eMap->roadNum==0)
        cout<<"请先进行二进制文件的读取!";

     if(eMap->roadSort==1)
        cout<<"道路已完成排序!\n";
     else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to SimpleElectSort)......\n";
        	  for(i=1;i<eMap->roadNum;i++)
              {
                  k=i;
                  for(j=i+1;j<=eMap->roadNum;j++)
                      if(eMap->roadRecord[j].LinkID<eMap->roadRecord[k].LinkID)
                         k=j;
                      if(k!=i)
                      {
                          t=eMap->roadRecord[i];
                          eMap->roadRecord[i]=eMap->roadRecord[k];
                          eMap->roadRecord[k]=t;
                      }
             }

			 ToWriteSort(eMap);
             cout<<"\nSort success!\n\n";
        }
}


int ToWriteSort(ElecMap *e_eMap)               //把排序好的道路信息写入另一个文本文件中
{
    FILE *fileWrite;                 //定义指向FILE结构的指针变量fileWrite
    int  i=1;
    fileWrite=fopen("d:\\sortedresult.txt","wb");        //文件指针指向目标文本文件

    while(i<=e_eMap->roadNum)                 //判断结构体数组是否为空（即文本文件是否文空）
    {
        fprintf(fileWrite,"%d\t信息大小:%d\tLinkID:%d\t有无Flag:%d\t分岔路数:%d\t番号:%d\t",
         e_eMap->roadNum,e_eMap->roadRecord[i].recordSize,e_eMap->roadRecord[i].LinkID,e_eMap->roadRecord[i].flag,
         e_eMap->roadRecord[i].brunch,e_eMap->roadRecord[i].disclass);

        if(e_eMap->roadRecord[i].recordSize>12)
           fprintf(fileWrite,"道路名称:%s\n",e_eMap->roadRecord[i].roadName);
        else
            fprintf(fileWrite,"无道路名称\n");
        i++;
        fprintf(fileWrite,"\n\n\n");
    }
     cout<<"排序结果已成功存储在文本文件!";
     return 0;

}


int TotalSort(ElecMap *eMap)
{
	int choose=1;
	cout<<"排序方式如下:\n";
	cout<<"\t1.快速排序\n\t2.冒泡排序\n\t3.直接插入排序\n\t4.折半排序\n\t5.简单选择排序\n\t0.返回\n\n";
	while(choose)
	{
		cout<<"请选择排序方式:";
		cin>>choose;
		switch(choose)
		{
			case 1:
			  Sort(eMap);
			  break;
			case 2:
			  BubbleSort(eMap);
			  break;
			case 3:
			  DirectInsertSort(eMap);
			  break;
			case 4:
			  BinarySort(eMap);
			  break;
			case 5:
			  SimpleElectSort(eMap);
			  break;
			case 0:
				cout<<"退出排序!\n";
				break;
			default:
				cout<<"输入有错，请重新选择!\n\n";
		}
	}
}





