/**************************************************/
/*名称：QSort
/*描述：对数据信息（LINK ID）从小到大顺序进行排序
/*作成日期： 12/05/01 
/*作者：
/***************************************************/
#include<stdio.h>
#include"struct.h"
#include<string.h>

/**************************************************/
/*名称：SelSort
/*描述：采用选择法进行排序
/*作成日期：12/05/01 
/*参数：
        参数1：pslow、参数类型struct map指针、输入/输出参数、结构体变量
        参数2：pfast、参数类型struct map指针、输入/输出参数、结构体变量
		参数3：current、参数类型struct map指针、输入/输出参数、结构体变量
		参数4：tempname、参数类型数组、输出参数、存储道路信息的描述内容
		参数5：temp、参数类型unsigned int、输入/输出参数、存储数据的变量
/*返回值：VOID
/*作者：
/***************************************************/
void SelSort(MAPLINK Head)
{
	MAPLINK pslow;
	MAPLINK pfast;
	MAPLINK current;
	char tempname[30]={'\0'};
	unsigned int temp=0;
	
	/*两个for循环对数据进行排序*/
	printf("请稍等，排序中......");
	for(pslow=Head; (pslow->next) != NULL; pslow=pslow->next)
		{
		   current=pslow;
			for(pfast=pslow->next; (pfast->next) != NULL; pfast=pfast->next)
			{
				if( (current->LinkID) > (pfast->LinkID) )
				{
					current=pfast;
				}
	
				if(current != pslow)
				{		
					temp=pslow->LinkID;
					pslow->LinkID=current->LinkID;
					current->LinkID=temp;
				
					temp=pslow->flag;
					pslow->flag=current->flag;
					current->flag=temp;
	
					temp=pslow->branch;
					pslow->branch=current->branch;
					current->branch=temp;
	
					temp=pslow->roadclass;
					pslow->roadclass=current->roadclass;
					current->roadclass=temp;
					
					strcpy(tempname,pslow->name);
					strcpy(pslow->name,current->name);
					strcpy(current->name,tempname);
				}
		
			}
		}
}