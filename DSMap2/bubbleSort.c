/**************************************************/
/*名称：BubbleSort
/*描述：对数据信息（LINK ID）从小到大顺序进行排序
/*作成日期： 12/05/01 
/*作者：
/***************************************************/
#include<stdio.h>
#include"struct.h"
#include<string.h>

/**************************************************/
/*名称：BSort
/*描述：采用冒泡法进行排序
/*作成日期：12/05/01 
/*参数：
        参数1：current、参数类型struct map指针、输入/输出参数、连接链表前后节点的参数
        参数2：pre、    参数类型struct map指针、输入/输出参数、连接链表前后节点的参数
		参数3：tempname、参数类型数组、输出参数、存储道路信息描述内容
		参数4：temp、参数类型unsigned int、输入/输出参数、存储数据的变量
/*返回值：VOID
/*作者：
/***************************************************/
void BSort(MAPLINK Head)
{
	MAPLINK current;
	MAPLINK pre;
	char tempname[30]={'\0'};
	unsigned int temp=0;
	
	/*两个for循环对数据进行排序*/
	printf("请稍等，排序中......");
	for(current=Head; (current->next) != NULL; current=current->next)
	{
		for(pre=current->next; (pre->next) != NULL; pre=pre->next)
		{
			if( (current->LinkID) > (pre->LinkID) )
			{
				temp=current->LinkID;
				current->LinkID=pre->LinkID;
				pre->LinkID=temp;

				temp=current->flag;
				current->flag=pre->flag;
				pre->flag=temp;

				temp=current->branch;
				current->branch=pre->branch;
				pre->branch=temp;

				temp=current->roadclass;
				current->roadclass=pre->roadclass;
				pre->roadclass=temp;

				strcpy(tempname,current->name);
				strcpy(current->name,pre->name);
				strcpy(pre->name,tempname);
			}
		}
	}
	
}