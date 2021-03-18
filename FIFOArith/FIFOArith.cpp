/**��1��(����)
**/
//#include <stdio.h>
//
//#define PAGES 20  /*ҳ������ҳ��*/
//#define M 3      /*��ǰ���������ҵ���������*/
////#define M 4
///*ҳ�����ô�*/
//int page[PAGES] =  {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
//int rel[M][PAGES];   /*�洢�������*/
///*�ڴ������ṹ��*/
//typedef struct{
//  int pnum;     /*�ÿ��������ҳ���*/
//  int tm;       /*�����һ�ε�����������ʱ��*/
//}PBlock;
//
///*��ʼ�����������*/
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
///*��ӡ�������*/
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
///*��ӡһά����*/
//void printArr1(int *arr,int n)
//{
//    int i;
//    for(i=0;i<n;i++){
//      printf("%d ",arr[i]);
//    }
//    printf("\n");
//}
//
///*�鿴ҳ���Ϊnum��ҳ���Ƿ����ڴ����,���ڷ���1*/
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
///*FIFO �㷨��ʵ��,���迼��ʱ��*/
//int fifo(PBlock *pb,int m)
//{
//  int lps=0;   /*ȱҳ����*/
//  double lpp;   /*ȱҳ��*/
//  int p = 0;    /*�滻ָ��*/
//  int index =0;  /*ҳ�������*/
//  while(index<PAGES){
//      if(!in_mem(page[index],pb,M)){    //�����ҳ�治���������
//        pb[p].pnum = page[index];        /*����ҳ������������*/
//        p = (p+1)%M;                     /*�滻ָ���ƶ�*/
//        lps++;                           /*ȴҲ������ 1*/
//        for(int i=0;i<M;i++){
//          rel[i][index] = pb[i].pnum;
//        }
//      }
//      index++;
//  }
//
//  printf("FIFO�㷨����ȱҳ����Ϊ %d\n",lps);
//  lpp = (double)lps/PAGES;
//  printf("FIFO�㷨ȱҳ��Ϊ %0.4lf \n",lpp);
//  printf("ҳ�������Ϊ:\n");
//  printArr1(page,PAGES);
//  printf("�������Ϊ:\n");
//  printRelArr(rel);
//  return 0;
//}
//
///*��������õĿ�*/
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
///*LRU�㷨*/
////void lru(PBlock *pb,int m)
////{
////  int lps=0;   /*ȱҳ����*/
////  double lpp;   /*ȱҳ��*/
////  int p = 0;    /*�滻ָ��*/
////  int index =0;  /*ҳ�������*/
////  while(index<PAGES){
////      if(!in_mem(page[index],pb,m)){   /*���ҳ�治���������*/
////        p = getP(pb,p);
////        pb[p].pnum = page[index];
////        pb[p].tm = 0;
////        lps++;
////        for(int i=0;i<M;i++){
////          rel[i][index] = pb[i].pnum;
////        }
////      }else{                         /*���ҳ�����������*/
////        int in = getEQnum(page[index],pb);  /*��ȡ��ҳ����������е�����*/
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
////  printf("LRU�㷨����ȱҳ����Ϊ %d \n",lps);
////  lpp = 1.0*lps/PAGES;
////  printf("LRU�㷨ȱҳ��Ϊ: %0.4lf\n",lpp);
////  printf("ҳ�������Ϊ:\n");
////  printArr1(page,PAGES);
////  printf("LRU�������Ϊ:\n");
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





/**��2�������ã�
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





/**��3��(����)
**/
//#include "stdio.h"
//#include "stdlib.h"
//
//typedef struct item
//{
//	int num;		//ҳ��
//	int time;		//�ȴ�ʱ�䣬LRU�㷨���õ��������
//}Pro;
//
//int pageNum;		//ϵͳ�������ҵ�������е�ҳ����
//int memoryNum;		//�����ڴ�ҳ����
//
//void print(Pro *page1);		//��ӡ��ǰ�����е�ҳ��
//int  Search(int num1, Pro *memory1);	//��ҳ�漯memory1�в���num1������ҵ�����������memory1�е��±꣬���򷵻�-1
//
//int main(void)
//{
//	int i;
//	int curmemory;		//�����ڴ��е�ҳ�����
//	int missNum;		//ȱҳ����
//	float missRate;		//ȱҳ��
//	char c;				//�õ��û��������ַ�����ѡ����Ӧ���û��㷨
//
//	Pro *page;			//��ҵҳ�漯
//	Pro *memory;		//�ڴ�ҳ�漯
//
//	printf("����ϵͳ�������ҵ�������е�ҳ����:");
//	scanf("%d", &pageNum);
//	printf("�����ڴ�ҳ����:");
//	scanf("%d", &memoryNum);
//
//	page = (Pro*)malloc(sizeof(Pro)*pageNum);
//	memory = (Pro*)malloc(sizeof(Pro)*memoryNum);
//
//	for (i = 0; i<pageNum; i++)
//	{
//		printf("�� %d ��ҳ���Ϊ:", i);
//		scanf("%d", &page[i].num);
//		page[i].time = 0;			//�ȴ�ʱ�俪ʼĬ��Ϊ0
//	}
//
//	do {
//		for (i = 0; i<memoryNum; i++)		//��ʼ���ڴ���ҳ��
//		{
//			memory[i].num = -1;				//ҳ��Ϊ����-1��ʾ
//			memory[i].time = -1;				//
//		}
//
//		printf("*****f:FIFOҳ���û�*****\n");
//		printf("*****o:OPTҳ���û�*****\n");
//		printf("*****l:LRUҳ���û�*****\n");
//		printf("*****��ѡ���������(f,o,l),������������******\n");
//		//fflush(stdin);
//		getchar();
//		scanf("%c", &c);
//
//		i = 0;
//		curmemory = 0;
//
//		if (c == 'f')			//FIFOҳ���û�
//		{
//			missNum = 0;
//
//			printf("FIFOҳ���û����:   \n");
//			for (i = 0; i<pageNum; i++)
//			{
//				if (Search(page[i].num, memory)<0)//�����ڴ���û���ҵ���ҳ��
//				{
//					missNum++;
//					memory[curmemory].num = page[i].num;
//					print(memory);
//					curmemory = (curmemory + 1) % memoryNum;   //�ҳ����Ƚ����ڴ��ҳ��
//				}
//			}//end for
//			missRate = (float)missNum / pageNum;
//			printf("ȱҳ������%d   ȱҳ��:  %f\n", missNum, missRate);
//
//		}//end if
//
//		if (c == 'o')			//OPTҳ���û��㷨
//		{
//			missNum = 0;
//			curmemory = 0;
//
//			printf("Optimalҳ���û����:   \n");
//			for (i = 0; i<pageNum; i++)
//			{
//				if (Search(page[i].num, memory) < 0)//�����ڴ���û���ҵ���ҳ��
//				{
//
//					//�ҳ�δ���ʱ���ڲ��ٱ����ʵ�ҳ��
//					int tem;
//					int opt = 0;
//					for (int k = 0; k < memoryNum; k++)
//					{
//						if (memory[k].num == -1)
//						{
//							curmemory = k;
//							break;
//						}
//						tem = 0;       //ҳ��k��δ��temʱ���ڲ������
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
//				printf("ȱҳ������%d   ȱҳ��:  %f\n", missNum, missRate);
//
//		}//end if
//
//		if (c == 'l')			//LRUҳ���û��㷨
//		{
//			missNum = 0;
//			curmemory = 0;
//
//			printf("LRUҳ���û����:   \n");
//			for (i = 0; i<pageNum; i++)
//			{
//				int rec=Search(page[i].num, memory);
//				if (rec < 0)    //�����ڴ���û���ҵ���ҳ��
//				{
//					missNum++;
//					for (int j = 0; j<memoryNum; j++)     //�ҳ�������δʹ�õ�ҳ��
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
//				for (int j = 0; j<memoryNum; j++)     //�ڴ��е�����ҳ��ȴ�ʱ��+1
//					if (memory[j].num != -1)
//						memory[j].time++;
//
//			}//end for
//			missRate = (float)missNum / pageNum;
//			printf("ȱҳ������%d   ȱҳ��:  %f\n", missNum, missRate);
//		}//end if
//
//	} while (c == 'f' || c == 'l' || c == 'o');
//
//
//	return 0;
//}
//
//
//void print(Pro *memory1)//��ӡ��ǰ��ҳ��
//{
//	int j;
//
//	for (j = 0; j<memoryNum; j++)
//		printf("%d ", memory1[j].num);
//	printf("\n");
//}
//
////��ҳ�漯memory1�в���num1������ҵ�����������memory1�е��±꣬���򷵻�-1
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


/**��4��(����)
**/
#include <stdio.h>

#define PAGES 20  /*ҳ������ҳ��*/
#define M 3      /*��ǰ���������ҵ���������*/
//#define M 4
/*ҳ�����ô�*/
int page[PAGES] =  {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int rel[M][PAGES];   /*�洢�������*/
/*�ڴ������ṹ��*/
typedef struct{
  int pnum;     /*�ÿ��������ҳ���*/
  int tm;       /*�����һ�ε�����������ʱ��*/
}PBlock;

/*��ʼ�����������*/
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

/*��ӡ�������*/
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

/*��ӡһά����*/
void printArr1(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
}

/*�鿴ҳ���Ϊnum��ҳ���Ƿ����ڴ����,���ڷ���1*/
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

/*FIFO �㷨��ʵ��,���迼��ʱ��*/
int fifo(PBlock *pb,int m)
{
  int lps=0;   /*ȱҳ����*/
  double lpp;   /*ȱҳ��*/
  int p = 0;    /*�滻ָ��*/
  int index =0;  /*ҳ�������*/
  while(index<PAGES){
      if(!in_mem(page[index],pb,M)){    //�����ҳ�治���������
        pb[p].pnum = page[index];        /*����ҳ������������*/
        p = (p+1)%M;                     /*�滻ָ���ƶ�*/
        lps++;                           /*ȴҲ������ 1*/
        for(int i=0;i<M;i++){
          rel[i][index] = pb[i].pnum;
        }
      }
      index++;
  }

  printf("FIFO�㷨����ȱҳ����Ϊ %d\n",lps);
  lpp = (double)lps/PAGES;
  printf("FIFO�㷨ȱҳ��Ϊ %0.4lf \n",lpp);
  printf("ҳ�������Ϊ:\n");
  printArr1(page,PAGES);
  printf("�������Ϊ:\n");
  printRelArr(rel);
  return 0;
}

/*��������õĿ�*/
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



