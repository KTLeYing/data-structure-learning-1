/************************************************************************************************/
//名称：插入
//功能：在链表中插入一个节点，存储要插入地图信息的数据，并调用write中的tobfwrite函数写回二进制文件
//作成日期：4-26
//参数：参数1：head、MAPLINK、输入、接收链表头结点
//      参数2：newnode、MAPLINK、输入、新节点
//      参数3：linkp、MAPLINK、输入、指向链表每个节点，用于判断
//返回值 VOID
//作者：
//修改日期  12/05/01
/************************************************************************************************/
#include<stdio.h>
#include<malloc.h>
#include"struct.h"
#include"header.h"
#include"write.h"

void insert(MAPLINK head)
{
	MAPLINK newnode;
	MAPLINK linkp;
	char fname[30]="d:\\insertResult.txt";//保存插入结果文件路径

	linkp=head;
	newnode=(MAPLINK)malloc(sizeof(MAP));
	printf("           请输入道路ID：");
	scanf("%d",&(newnode->LinkID));
	while(linkp!=NULL)
	{
		if(newnode->LinkID==linkp->LinkID)
		{
			printf("\n");
			printf("        此ID已存在！        ");//判断输入的ID号是否存在
			printf("请重新输入：\n");
			printf("\n");
			insert(head);
			break;
		}
		linkp=linkp->next;
	}
	printf("           0、无flag  1、有flag\n          请选择：");
	scanf("%d",&(newnode->flag));
	if(newnode->flag==1||newnode->flag==0)
	{
		printf("           请输入道路岔路数：");/*输入道路信息*/
		scanf("%d",&(newnode->branch));
		printf("           请输入道路番号：");
		scanf("%d",&(newnode->roadclass));
		printf("           请输入道路名称：");
		scanf("%s",(newnode->name));

		linkp=head;
		while(linkp!=NULL)					/*       按ID排序       */
		{
			if(newnode->LinkID>linkp->LinkID&&newnode->LinkID<linkp->next->LinkID)
			{
				newnode->next=linkp->next;
				linkp->next=newnode;
				break;
			}
			linkp=linkp->next;
		}
		tobfwrite(head);			//写入到地图信息文件中
		tofwrite(&head,fname);		//写入到排序好的文本文档中
	}
	else
	{
		printf("				请输入0或1\n");
		insert(head);
	}
}