/**法1：(可用)
**/
//#include <stdio.h>
//
//#define PAGES 20  /*页面引用页数*/
//#define M 3      /*当前分配给改作业的物理块数*/
////#define M 4
///*页面引用串*/
//int page[PAGES] =  {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
//int rel[M][PAGES];   /*存储结果数组*/
///*内存物理块结构体*/
//typedef struct{
//  int pnum;     /*该块中所存的页面号*/
//  int tm;       /*从最近一次调入所经历的时间*/
//}PBlock;
//
///*初始化物理块数组*/
//void init(PBlock *pb)
//{
//  int i,j;
//  //pb = (PBlock*)malloc(sizeof(PBlock)*M);
//  for(i=0;i<M;i++){
//    pb[i].pnum = -1;
//    pb[i].tm = -1;
//    for(j=0;j<PAGES;j++){
//      rel[i][j] = -1;
//    }
//  }
//}
//
///*打印结果数组*/
//void printRelArr(int rel[M][PAGES])
//{
//  int i,j;
//  for(i=0;i<M;i++){
//    for(j=0;j<PAGES;j++){
//      if(rel[i][j]==-1)
//        printf("* ");
//      else
//        printf("%d ",rel[i][j]);
//    }
//    printf("\n");
//  }
//}
//
///*打印一维数组*/
//void printArr1(int *arr,int n)
//{
//    int i;
//    for(i=0;i<n;i++){
//      printf("%d ",arr[i]);
//    }
//    printf("\n");
//}
//
///*查看页面号为num的页面是否在内存块中,存在返回1*/
//int in_mem(int num,PBlock *pb,int m)
//{
//  int i;
//  int b = 0;
//  for(i=0;i<m;i++){
//      if(pb[i].pnum == num){
//        b = 1;
//        break;
//      }
//  }
//  return b;
//}
//
///*FIFO 算法的实现,无需考虑时间*/
//int fifo(PBlock *pb,int m)
//{
//  int lps=0;   /*缺页次数*/
//  double lpp;   /*缺页率*/
//  int p = 0;    /*替换指针*/
//  int index =0;  /*页面号索引*/
//  while(index<PAGES){
//      if(!in_mem(page[index],pb,M)){    //如果该页面不在物理块中
//        pb[p].pnum = page[index];        /*将该页面放入物理块中*/
//        p = (p+1)%M;                     /*替换指针移动*/
//        lps++;                           /*却也次数加 1*/
//        for(int i=0;i<M;i++){
//          rel[i][index] = pb[i].pnum;
//        }
//      }
//      index++;
//  }
//
//  printf("FIFO算法所得缺页次数为 %d\n",lps);
//  lpp = (double)lps/PAGES;
//  printf("FIFO算法缺页率为 %0.4lf \n",lpp);
//  printf("页面号序列为:\n");
//  printArr1(page,PAGES);
//  printf("结果数列为:\n");
//  printRelArr(rel);
//  return 0;
//}
//
///*获得最近最久的块*/
//int getP(PBlock *pb,int p)
//{
//  int i;
//  bool out = true;  //
//  for(i=0;i<M;i++){
//    if(pb[i].tm == -1){
//      p = i;
//      out = false;
//      break;
//    }
//  }
//  if(out){
//    for(i=0;i<M;i++){
//      if(pb[i].tm>pb[p].tm)
//        p = i;
//    }
//  }
//  return p;
//}
//int getEQnum(int num,PBlock *pb)
//{
//  int i;
//  int in = -1;
//  for(i=0;i<M;i++){
//    if(pb[i].pnum == num){
//      in = i;
//      break;
//    }
//  }
//  return in;
//}
//
///*LRU算法*/
////void lru(PBlock *pb,int m)
////{
////  int lps=0;   /*缺页次数*/
////  double lpp;   /*缺页率*/
////  int p = 0;    /*替换指针*/
////  int index =0;  /*页面号索引*/
////  while(index<PAGES){
////      if(!in_mem(page[index],pb,m)){   /*如果页面不在物理块中*/
////        p = getP(pb,p);
////        pb[p].pnum = page[index];
////        pb[p].tm = 0;
////        lps++;
////        for(int i=0;i<M;i++){
////          rel[i][index] = pb[i].pnum;
////        }
////      }else{                         /*如果页面在物理块中*/
////        int in = getEQnum(page[index],pb);  /*获取该页面在物理块中的索引*/
////          pb[in].tm = 0;
////      }
////      int i;
////      for(i=0;i<M;i++){
////          if(i!=p&&pb[i].tm!=-1){
////            pb[i].tm++;
////          }
////      }
////      index++;
////  }
////  printf("LRU算法所得缺页次数为 %d \n",lps);
////  lpp = 1.0*lps/PAGES;
////  printf("LRU算法缺页率为: %0.4lf\n",lpp);
////  printf("页面号序列为:\n");
////  printArr1(page,PAGES);
////  printf("LRU结果数组为:\n");
////  printRelArr(rel);
////}
//
//int main()
//{
////    printArr(rel);
//  PBlock pb[M];
//  init(pb);
//  fifo(pb,M);
////  init(pb);
////  lru(pb,M);
//  return 0;
//}





/**法2：（好用）
**/
//FILENAME: FIFO.cpp
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int memory[3]={-1,-1,-1}; //-1 means no page in this memory page
//    int page[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};//the test pages
//    int pm=0; //pointer of memory
//    int count=0;//missing page count
//    int replace[20];
//    int pr=0;
//
//    cout<<"######FIFO#######"<<endl;
//    //search begin
//    for (int i=0;i<20;i++)
//    {
//        //check if there is page[i] in memory
//        bool exist = false;
//        for (int j=0;j<3;j++)
//        {
//            if (page[i]==memory[j])
//            {
//                exist=true;
//                break;
//            }
//        }
//        //not exist , replace this memory page
//        if (exist==false)
//        {
//            if(memory[pm]!=-1)
//            {
//                replace[pr]=memory[pm];
//                pr++;
//            }
//
//            count++;
//            memory[pm]=page[i];
//            pm++;
//            if (pm==3) pm=0;
//        }
//        //output
//        cout<<page[i]<<":  [ ";
//        for(int j=0;j<3;j++)
//        {
//            if (memory[j]==-1) cout<<"*  ";
//            else cout<<memory[j]<<"  ";
//        }
//        cout<<"]"<<endl;
//    }
//    //output
//    cout<<"######################"<<endl;
//    cout<<"the lack page count = " <<count<<endl;
//
//    cout<<"repalce pages are  : ";
//    for (int i=0;i<pr;i++)
//    {
//        cout<<replace[i]<<" ";
//    }
//    cout<<endl;
//
//    cout<<"the rate of page lack is "<<count/12.0*100<<"%"<<endl;
//
//    return 0;
//}





/**法3：(可用)
**/
//#include "stdio.h"
//#include "stdlib.h"
//
//typedef struct item
//{
//	int num;		//页号
//	int time;		//等待时间，LRU算法会用到这个属性
//}Pro;
//
//int pageNum;		//系统分配给作业的主存中的页面数
//int memoryNum;		//可用内存页面数
//
//void print(Pro *page1);		//打印当前主存中的页面
//int  Search(int num1, Pro *memory1);	//在页面集memory1中查找num1，如果找到，返回其在memory1中的下标，否则返回-1
//
//int main(void)
//{
//	int i;
//	int curmemory;		//调入内存中的页面个数
//	int missNum;		//缺页次数
//	float missRate;		//缺页率
//	char c;				//得到用户的输入字符，来选择相应的置换算法
//
//	Pro *page;			//作业页面集
//	Pro *memory;		//内存页面集
//
//	printf("输入系统分配给作业的主存中的页面数:");
//	scanf("%d", &pageNum);
//	printf("输入内存页面数:");
//	scanf("%d", &memoryNum);
//
//	page = (Pro*)malloc(sizeof(Pro)*pageNum);
//	memory = (Pro*)malloc(sizeof(Pro)*memoryNum);
//
//	for (i = 0; i<pageNum; i++)
//	{
//		printf("第 %d 个页面号为:", i);
//		scanf("%d", &page[i].num);
//		page[i].time = 0;			//等待时间开始默认为0
//	}
//
//	do {
//		for (i = 0; i<memoryNum; i++)		//初始化内存中页面
//		{
//			memory[i].num = -1;				//页面为空用-1表示
//			memory[i].time = -1;				//
//		}
//
//		printf("*****f:FIFO页面置换*****\n");
//		printf("*****o:OPT页面置换*****\n");
//		printf("*****l:LRU页面置换*****\n");
//		printf("*****请选择操作类型(f,o,l),按其它键结束******\n");
//		//fflush(stdin);
//		getchar();
//		scanf("%c", &c);
//
//		i = 0;
//		curmemory = 0;
//
//		if (c == 'f')			//FIFO页面置换
//		{
//			missNum = 0;
//
//			printf("FIFO页面置换情况:   \n");
//			for (i = 0; i<pageNum; i++)
//			{
//				if (Search(page[i].num, memory)<0)//若在内存中没有找到该页面
//				{
//					missNum++;
//					memory[curmemory].num = page[i].num;
//					print(memory);
//					curmemory = (curmemory + 1) % memoryNum;   //找出最先进入内存的页面
//				}
//			}//end for
//			missRate = (float)missNum / pageNum;
//			printf("缺页次数：%d   缺页率:  %f\n", missNum, missRate);
//
//		}//end if
//
//		if (c == 'o')			//OPT页面置换算法
//		{
//			missNum = 0;
//			curmemory = 0;
//
//			printf("Optimal页面置换情况:   \n");
//			for (i = 0; i<pageNum; i++)
//			{
//				if (Search(page[i].num, memory) < 0)//若在内存中没有找到该页面
//				{
//
//					//找出未来最长时间内不再被访问的页面
//					int tem;
//					int opt = 0;
//					for (int k = 0; k < memoryNum; k++)
//					{
//						if (memory[k].num == -1)
//						{
//							curmemory = k;
//							break;
//						}
//						tem = 0;       //页面k在未来tem时间内不会出现
//						int j;
//						for (j = i+1; j < pageNum; j++)
//						{
//							if (page[j].num == memory[k].num)
//							{
//								if (tem > opt)
//								{
//									opt = tem;
//									curmemory = k;
//								}
//								break;
//							}
//							else tem++;
//						}
//						if (j == pageNum)
//						{
//							opt = tem;
//							curmemory = k;
//						}
//					}
//
//					missNum++;
//					memory[curmemory].num = page[i].num;
//					print(memory);
//				}
//			}//end for
//			missRate = (float)missNum / pageNum;
//				printf("缺页次数：%d   缺页率:  %f\n", missNum, missRate);
//
//		}//end if
//
//		if (c == 'l')			//LRU页面置换算法
//		{
//			missNum = 0;
//			curmemory = 0;
//
//			printf("LRU页面置换情况:   \n");
//			for (i = 0; i<pageNum; i++)
//			{
//				int rec=Search(page[i].num, memory);
//				if (rec < 0)    //若在内存中没有找到该页面
//				{
//					missNum++;
//					for (int j = 0; j<memoryNum; j++)     //找出最近最久未使用的页面
//						if (memory[j].time == -1) {
//							curmemory = j; break;
//						}
//						else if (memory[j].time > memory[curmemory].time)
//							curmemory = j;
//
//					memory[curmemory].num = page[i].num;
//					memory[curmemory].time = 0;
//					print(memory);
//
//				}
//				else memory[rec].time = 0;
//
//				for (int j = 0; j<memoryNum; j++)     //内存中的所有页面等待时间+1
//					if (memory[j].num != -1)
//						memory[j].time++;
//
//			}//end for
//			missRate = (float)missNum / pageNum;
//			printf("缺页次数：%d   缺页率:  %f\n", missNum, missRate);
//		}//end if
//
//	} while (c == 'f' || c == 'l' || c == 'o');
//
//
//	return 0;
//}
//
//
//void print(Pro *memory1)//打印当前的页面
//{
//	int j;
//
//	for (j = 0; j<memoryNum; j++)
//		printf("%d ", memory1[j].num);
//	printf("\n");
//}
//
////在页面集memory1中查找num1，如果找到，返回其在memory1中的下标，否则返回-1
//int  Search(int num1, Pro *memory1)
//{
//	int j;
//
//	for (j = 0; j<memoryNum; j++)
//	{
//		if (num1 == memory1[j].num)
//			return j;
//	}
//	return -1;
//}


/**法4：(可用)
**/
#include <stdio.h>

#define PAGES 20  /*页面引用页数*/
#define M 3      /*当前分配给改作业的物理块数*/
//#define M 4
/*页面引用串*/
int page[PAGES] =  {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int rel[M][PAGES];   /*存储结果数组*/
/*内存物理块结构体*/
typedef struct{
  int pnum;     /*该块中所存的页面号*/
  int tm;       /*从最近一次调入所经历的时间*/
}PBlock;

/*初始化物理块数组*/
void init(PBlock *pb)
{
  int i,j;
  for(i=0;i<M;i++){
    pb[i].pnum = -1;
    pb[i].tm = -1;
    for(j=0;j<PAGES;j++){
      rel[i][j] = -1;
    }
  }
}

/*打印结果数组*/
void printRelArr(int rel[M][PAGES])
{
  int i,j;
  for(i=0;i<M;i++){
    for(j=0;j<PAGES;j++){
      if(rel[i][j]==-1)
        printf("* ");
      else
        printf("%d ",rel[i][j]);
    }
    printf("\n");
  }
}

/*打印一维数组*/
void printArr1(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
}

/*查看页面号为num的页面是否在内存块中,存在返回1*/
int in_mem(int num,PBlock *pb,int m)
{
  int i;
  int b = 0;
  for(i=0;i<m;i++){
      if(pb[i].pnum == num){
        b = 1;
        break;
      }
  }
  return b;
}

/*FIFO 算法的实现,无需考虑时间*/
int fifo(PBlock *pb,int m)
{
  int lps=0;   /*缺页次数*/
  double lpp;   /*缺页率*/
  int p = 0;    /*替换指针*/
  int index =0;  /*页面号索引*/
  while(index<PAGES){
      if(!in_mem(page[index],pb,M)){    //如果该页面不在物理块中
        pb[p].pnum = page[index];        /*将该页面放入物理块中*/
        p = (p+1)%M;                     /*替换指针移动*/
        lps++;                           /*却也次数加 1*/
        for(int i=0;i<M;i++){
          rel[i][index] = pb[i].pnum;
        }
      }
      index++;
  }

  printf("FIFO算法所得缺页次数为 %d\n",lps);
  lpp = (double)lps/PAGES;
  printf("FIFO算法缺页率为 %0.4lf \n",lpp);
  printf("页面号序列为:\n");
  printArr1(page,PAGES);
  printf("结果数列为:\n");
  printRelArr(rel);
  return 0;
}

/*获得最近最久的块*/
int getP(PBlock *pb,int p)
{
  int i;
  bool out = true;
  for(i=0;i<M;i++){
    if(pb[i].tm == -1){
      p = i;
      out = false;
      break;
    }
  }
  if(out){
    for(i=0;i<M;i++){
      if(pb[i].tm>pb[p].tm)
        p = i;
    }
  }
  return p;
}
int getEQnum(int num,PBlock *pb)
{
  int i;
  int in = -1;
  for(i=0;i<M;i++){
    if(pb[i].pnum == num){
      in = i;
      break;
    }
  }
  return in;
}

int main()
{
  PBlock pb[M];
  init(pb);
  fifo(pb,M);
  return 0;
}



