#include<stdio.h>
#include"struct.h"
#include"insert.h"
#include"delect.h"

void update(MAPLINK H)
{
	int userchoose;

	printf("\n");
	printf("        1、插入");
	printf("        2、删除\n\n");
	printf("      请输入所选项目：");

	scanf("%d", &userchoose);

	switch(userchoose)
	{
	case 1:
		insert(H);
		PrintEndFunction();
		Choose(H);
		break;
	case 2:
		delect(H);
		PrintEndFunction();
		Choose(H);
		break;
	default :
		printf("无此项服务，请重新输入：\n");
		update(H);
	}
}