/************************************************************************************************
* 名称：删除
* 功能：通过输入道路ID，在链表中删除一组道路信息，并写回二进制文件
* 作成日期：4-26
* 参数：参数1：p1、MAPLINK、链表指针
*       参数2：p2、MAPLINK、链表指针
* 返回值 VOID
* 作者：
*************************************************************************************************/
#include<stdio.h>
#include"struct.h"
#include"write.h"

void delect(MAPLINK Head)
{
   MAPLINK p1,p2;
   int delID,n;
   char fname[30]="d:\\deleteResult.txt";			//删除结点后写入文本文档的路径
   
   printf("请输入要删除的道路ID:");

   scanf("%d",&delID);

   p1=Head;
   n=0;
   p2=p1;
	   
   if (delID==p1->LinkID)      /*    利用循环找到用户所要删除的ID，进行删除    */
   {
	   Head=p2;
   }
   else
   {
		while(p1->next!=NULL)
		{
		 if (delID==p2->LinkID)
         p1->next=p2->next;
         p1=p2;

         p2=p2->next;
		}
		p1=p1->next;
	}
   tobfwrite(Head);					//写入到地图信息文件中
   tofwrite(&Head,fname);			//写入到排序好的文本文档中
}