/******************************************************************************************
*FunctionName:Header                                                                      *
*                                                                                         *
*Description:在头文件里定义所需的宏、结构体和函数                                       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:马振乐                                                                             *
******************************************************************************************/


#ifndef HEADER_H_INCLUDED      //重复包含（重复定义）
#define HEADER_H_INCLUDED

#define MAXSIZE 64000         //宏定义数组的最大值的MAXSIZE


typedef struct RoadRecord          //结构体RoadRecord（道路记录）存储路的8个信息（8个成员变量）
{
    unsigned short int recordSize;      //记录的大小
    unsigned int LinkID;                 //道路的ID
    unsigned int roadInfo;                 //道路信息
    unsigned short roadNameLen;            //道路名字的长度
    char roadName[30];                     //数组存储道路名，只运行名字长度不能30个

    unsigned int disclass;             //番号信息
    unsigned int brunch;                 //分支
    int flag;                            //用flag表示道路是否有名称（1代表有，0代表无）
}RoadRecord;

typedef struct ElecMap           //结构体ElecMap存储全部道路的信息（3个成员变量），包括道路记录信息，路的数量和道路是否排序好的标志
{
    RoadRecord roadRecord[MAXSIZE];      //结构体数组存储道路的记录信息，而且数组的最大存储空间为6400
    int roadNum,roadSort;               //roadNum表示道路的数量；roadSort表示是否排序好（1代表已排序，0代表未排序）
}ElecMap;

#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //反转短整形的16位进制码
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//反转长整型的16进制码
#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //获取是否有道路名称
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //获取分支数
#define GET_DISPCLASS(__data__) (__data__&0x0f)                    //获取分类号


//把后面函数模块所要用到的函数在头文件里定义一次
int ReadFile(ElecMap *eMap);     //读取二进制文件，并转换存储在文本文档中
int TotalSort(ElecMap *eMap);      //排序
int Search(ElecMap *eMap);       //检索

int Sort(ElecMap *eMap);
int QSort(ElecMap *eMap,int left,int high);      //快速排序
int Partition(ElecMap *eMap,int left,int high);     //进行一趟排序，找到并返回枢轴位置
int BubbleSort(ElecMap *eMap);
int DirectInsertSort(ElecMap *eMap);
int BinarySort(ElecMap *eMap);
int SimpleElectSort(ElecMap *eMap);
int ToWriteSort(ElecMap *eMap);                    //把排序好的道路信息写入文本文档中

int BinarySearch_LinkID(ElecMap *eMap);         //用二叉排序对道路LinkID进行检索
int LinearSearch_RoadName(ElecMap *eMap);     //用直接插入排序对路名进行检索
int LinearSearch_RoadBrunchNum(ElecMap *eMap,int key);       //用直接插入排序对道路分支数进行检索
int LinearSearch_Class(ElecMap *eMap,int key);               //用直接插入排序对番号进行检索


#endif HEADER_H_INCLUDED
