#include<stdio.h>
#include"struct.h"
#include"QuickSort.h"
#include"Qsort.h"
#include"BubbleSort.h"

void Msort(MAPLINK *H)
{
	int userChoose;
	char quickfname[30] = "d:\\QuickSortedResult.txt";
	char Selfname[30] = "d:\\SelSortedResult.txt";
	char Bubfname[30] = "d:\\BudSortedResult.txt";

	printf("\n");
    printf(" /****************************************************************************\\ \n");
	printf("           请选择排序方式：\n");
	printf("               1、快速排序\n");
	printf("               2、选择排序\n");
	printf("               3、冒泡排序\n\n");
	printf("           请输入所选数字：");
	scanf("%d",&userChoose);
	switch(userChoose)
	{
	case 1:
		QListSort(H, NULL);
		tofwrite(H, quickfname);
		printf("保存成功，存储在D盘QuickSortedResult.txt文件中！\n");
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		break;
	case 2:
		SelSort(*H);
		tofwrite(H, Selfname);
		printf("保存成功，存储在D盘SelSortedResult.txt文件中！\n");
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		break;
	case 3:
		BSort(*H);
		tofwrite(H, Bubfname);
		printf("保存成功，存储在D盘BudSortedResult.txt文件中！");
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		break;
	default :
		printf("无此项服务，请重新输入：\n");
		Msort(H);
	}
}