/********************************************************************************************
* 文件名称:	write.c																	    	*	
* 作成日期:	12/04/25																	    * 
* 作者:																					*
* 样式:		对地图信息文件进行写操作														*
* 描述:	    有两种写地图信息文件的方式														*													*
				1:对地图信息文件本身写														*
				2:对排序文件（.txt）写														*
* 修改日期  12/05/01											          																				*
*********************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"struct.h"
#include"header.h"

/***************************************************************************
函数名称: void tobfwrite(MAPLINK H)
描述:   向地图信息二进制文件中进行写操作
作成日期:     12/04/25
参数:        名称:current 类型:MAPLINK 指向当前结点的指针
			 
			 名称:fp, tp 类型:FILE *  指向文件的指针

			 名称:m, mm 类型:short int 信息大小

			 名称:id 类型:int 道路ID

输入:        H: 单链表的头结点指针               
输出:        用户提示信息
返回值:      VOID   
                            
作者:    
*******************************************************************************/
void tobfwrite(MAPLINK H)
{
	MAPLINK current;
	FILE *fp, *tp;
	int k;
    short int m, mm;
	short int size;
	int id;

	current = H;

	fp = fopen("e:\\GTBL.dat", "wb");
	tp = fopen("e:\\GTBL.dat", "ab");

	while(current!=NULL)
	{
		m = (short)strlen(current->name);//获取道路名字大小
		mm = m+1;
		size = (short)(12+strlen(current->name)+1);//获取信息大小
		k = ((current->flag << 7) | (current->branch << 4) | current->roadclass);//将flag，brunch，roadclass转换为道路信息

		size = GET_SHORT(size);//转换为两字节
		id = GET_INT(current->LinkID);//转换为四字节
		m = GET_SHORT(m);//转换为两字节
		k = GET_INT(k);//转换为四字节

		//进行写入操作
		fwrite(&size, 2, 1, tp);
		fwrite(&id, 4, 1, tp);
		fwrite(&m, 2, 1, tp);
		fwrite(&k, 4, 1, tp);
		fwrite((current->name), mm, 1, tp);

		current = current->next;
	}
	printf("          恭喜你！    更新成功！\n");
	fclose(fp);
	fclose(tp);
}

/***************************************************************************
函数名称: void tofwrite(MAPLINK* head, char fname[])
描述:   向地图信息排序文件中进行写操作
作成日期:     12/04/25
参数:        名称:current 类型:MAPLINK 指向当前结点的指针
			 
			 名称:Resultp 类型:FILE * 指向文件的指针

输入:        head: 保存单链表的头结点指针的指针
			 fname: 保存地图信息的文件名               
输出:        用户提示信息
返回值:      VOID   
                            
作者:    
*******************************************************************************/
void tofwrite(MAPLINK* head, char fname[])
{
	FILE *Resultp;
	MAPLINK current;

	current = *head;

	Resultp = fopen(fname, "w");
	if(Resultp == NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	//向文本文档中存入信息
	while(current->next != NULL)
	{
		fprintf(Resultp, "LinkID: %d   ", current->LinkID);
		fprintf(Resultp, "Flag: %d    ", current->flag);
		fprintf(Resultp, "岔路数: %d   ", current->branch);
		fprintf(Resultp, "交叉Link列表示Class番号: %d   ", current->roadclass);
		fprintf(Resultp, "道路名称: %s  ", current->name);
		fprintf(Resultp, "\n\n");
		current = current->next;
	}
	fclose(Resultp);
}
