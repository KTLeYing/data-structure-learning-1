#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

 #define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //反转短整形的16位进制码
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//反转长整型的16进制码

#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //获取是否有道路名称
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //获取分支数
#define GET_DISPCLASS(__data__) (__data__&0x0f)

#define MAXSIZE 70000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct Road
{
unsigned short int informationSize;
unsigned int LinKID;
unsigned short int RoadnameSize;
unsigned int RoadInfor;
 char RoadName[30];
short int brunch;
short int dispclass;
short int flag;
}Road;

typedef struct map{
 Road *RGather;//路的集合
 int num,sorted;
}Map;

int cunjinMap(map &m);
int write(Map &m);
int Partition(Map &L,int low,int high);
void QSort(Map &L,int low,int high);
void QuickSort(Map &L);
void InsertSort(Map &L);

#endif // HEADER_H_INCLUDED
