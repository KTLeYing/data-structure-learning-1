/******************************************************************************************
*FunctionName:Sort                                                                        *
*                                                                                         *
*Description:������ɶ�ȡ�ʹ洢�Ķ������ļ��Ļ����ϣ����ı��е��������ݽ�������       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include "Header.h"

using namespace std;

int Partition(ElecMap *eMap,int low,int high)
{
    int pivot;
    eMap->roadRecord[0]=eMap->roadRecord[low];
    pivot=eMap->roadRecord[low].recordSize;
    while(low<high)
    {
        while(low<high && eMap->roadRecord[high].recordSize>=pivot)
            --high;
        eMap->roadRecord[low]=eMap->roadRecord[high];
        while(low<high && eMap->roadRecord[low].recordSize<=pivot)
            ++low;
        eMap->roadRecord[high]=eMap->roadRecord[low];
    }
    eMap->roadRecord[low]=eMap->roadRecord[0];
    return low;
}

int QSort(ElecMap *eMap,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(&eMap,low,high);
        QSort(eMap,low,pivot-1);
        QSort(eMap,pivot+1,high);
    }
}

int Sort(ElecMap *eMap)
{
     cout<<"Sort start......\n";
     Qsort(&eMap,1,eMap->num);
     cout<<"Sort success!";
}
