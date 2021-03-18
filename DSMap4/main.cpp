#include<stdio.h>
#include"header.h"
Map map;
int main()
{
	int choose;
	map.RGather=new Road[MAXSIZE];
	while(1)
	{
		printf("请选择服务种类\n");
		printf("\t1.读取文件GTBL.dat\n");
		printf("\t2.排序（快速排序）并输出排序结果\n");
		printf("\t3.检索\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:cunjinMap(map) ;break;
			/*case 2:{
				InsertSort(map);
				write(map);
				printf("排序结果以存进txt\n");
			}break;*/

		}
	}
}
