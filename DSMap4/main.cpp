#include<stdio.h>
#include"header.h"
Map map;
int main()
{
	int choose;
	map.RGather=new Road[MAXSIZE];
	while(1)
	{
		printf("��ѡ���������\n");
		printf("\t1.��ȡ�ļ�GTBL.dat\n");
		printf("\t2.���򣨿������򣩲����������\n");
		printf("\t3.����\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:cunjinMap(map) ;break;
			/*case 2:{
				InsertSort(map);
				write(map);
				printf("�������Դ��txt\n");
			}break;*/

		}
	}
}
