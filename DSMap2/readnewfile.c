/********************************************************************************************
* 文件名称:	readnewfile.c															    	*	
* 作成日期:	12/04/24																	    * 
* 作者:																					*
* 样式:		供用户选择服务																	*
* 描述:	  	读取用户地图信息文件															*
* 修改日期  12/05/01																		*
            																				*
*********************************************************************************************/
#include<stdio.h>
#include<windows.h>
#include"struct.h"
#include"readfile.h"

/***************************************************************************
函数名称: void readnewfile(MAPLINK *head)
描述:   让用户自己输入所要读取的地图信息文件的目录
                1、 判断输入的地图信息文件的目录是否正确
				   1:先判断输入的盘符是否存在; 
				   2:判断输入的目录格式是否正确;
				   3:判断输入的文件是否存在;
                2、 调用readfile(head)函数读取地图信息文件
作成日期:     12/04/24
参数:        名称:path[100] 类型:char 存储用户输入的地图路径

			 名称:newfilep 类型:FILE * 指向所在路径的文件的指针

			 名称:i 类型:int 循环变量

输入:        head: 保存了单链表的头结点指针的指针               
输出:        用户提示信息
返回值:      VOID   
                            
作者:    
修改日期  12/05/01
*******************************************************************************/
void readnewfile(MAPLINK *head)
{
	char path[100] = {'\0'};
	FILE *newfilep;
	int i = 0;

	printf("\n");
	printf(" /****************************************************************************\\ \n");
	printf("         请输入地图信息文件路径：");
	scanf("%s", path);

	//判断路径是否有效
	if(path[0] != 'c'||path[0] != 'd'||path[0] != 'e')
	{
		if(path[1] == ':')//判断盘符符号是否正确
		{
			if(path[2] == '\\')
			{
				if(path[3] != '\\')//判断盘符符号是否正确
				{
					for(i=3; path[i] != '\0'; i++);
					for(i=i+1; path[i] != '\\'; i--)
					{
						path[i+1] = path[i];
					}
					path[3]='\\';

					newfilep = fopen(path, "r");

					if(newfilep == NULL)
					{
						printf("打开文件失败！");
						printf("输入的目录不正确！请重新输入：");
						readnewfile(head);
					}
					readfile(head);    //读取地图信息文件
				}
				else
				{
					newfilep = fopen(path, "r");

					if(newfilep == NULL)
					{
						printf("打开文件失败！");
						printf("输入的目录不正确！请重新输入：");
						readnewfile(head);
					}
					readfile(head);
				}
			}
			else
			{
				printf("输入的目录不正确！请重新输入：");
				readnewfile(head);
			}
		}
		else
		{
			printf("输入的目录不正确！请重新输入：");
			readnewfile(head);
		}
	}
	else
	{
		printf("输入的盘符不存在！请重新输入：");
		readnewfile(head);
	}
}