/******************************************************************************************
*FunctionName:Header                                                                      *
*                                                                                         *
*Description:在头文件里定义所需的宏、结构体和函数                                       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAXSIZE 64000

typedef struct RoadRecord
{
    unsigned short int recordSize;
    unsigned int LinkID;
    unsigned int roadInfo;
    char roadName[30];

    unsigned int classInfo;
    unsigned int brunch;
    int roadFlag;
}RoadRecord;

typedef struct ElecMap
{
    RoadRecord roadRecord[MAXSIZE];
    int num,sorted;
}ElecMap;

#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //反转短整形的16位进制码
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//反转长整型的16进制码
#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //获取是否有道路名称
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //获取分支数
#define GET_DISPCLASS(__data__) (__data__&0x0f)                    //获取分类号

int ReadFile(ElecMap *eMap);
int Sort(ElecMap *eMap);
int Search(ElecMap *eMap);

int QSort(ElecMap *eMap,int left,int high);
int Partition(ElecMap *eMap,int left,int high);
int BinarySearch_LinkID(ElecMap *eMap,int key);
int LinearSearch_RoadName(ElecMap *eMap,char name[]);
int LinearSearch_RoadBrunchNum(ElecMap *eMap,int key);
int LinearSearch_Class(ElecMap *eMap,int key);

int Assign(RoadRecord *desk,RoadRecord *source);

#endif HEADER_H_INCLUDED
