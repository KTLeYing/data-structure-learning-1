/********************************************************************************************
* 文件名称:	readfile.c																    	*	
* 作成日期:	12/04/23																	    * 
* 作者:																					*
* 样式:		读取地图信息文件																*
* 描述:	    创建单链表结点，并在地图信息文件中取出数据										*
            分别存入结点中的变量中，并将新结点联入单链										*
			表																				*
*********************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
#include<windows.h>
#include"struct.h"
#include<stdlib.h>
#include<BASETSD.H>
#include"header.h"

/***************************************************************************
函数名称: MAPLINK readfile(MAPLINK *Head)
描述:   按照一定规则读取地图信息文件，并创建单链表
                1、 读取地图信息文件
				   1:读取道路ID存入roadID; 
				   2:读取道路信息数据存入uiinfo;
				   3:将道路信息数据uiinfo利用宏定义取出道路有无flag;
				   4:将道路信息数据uiinfo利用宏定义取出道路brunch;
				   5:将道路信息数据uiinfo利用宏定义取出道路番号class;
				   6:读取道路名称存入roadname[]数组中
                2、 创建单链表
				   1:创建单链表结点
				   2:将新创建的单链表结点联入单链表中
作成日期:     12/04/23
参数:        名称:Sourcep 类型:FILE * 地图信息文件指针

             名称:Resultp 类型:FILE * 译文文件指针

			 名称:roadname 类型:char数组 道路名称

			 名称:def 类型:char数组 无道路名称

			 名称:infosize 类型:unsigned short 信息大小

			 名称:roadID 类型:unsigned int 道路ID

			 名称:roadflag 类型:unsigned int 道路flag值

  			 名称:uibrunch 类型:unsigned int 道路岔路数

    		 名称:marker 类型:unsigned int 记录道路名称大小

      		 名称:uiinfo 类型:unsigned int 道路信息数据

      		 名称:roadClass 类型:unsigned int 道路番号

        	 名称:temp 类型:int 临时变量

        	 名称:count 类型:long int 计数器

          	 名称:newnodep 类型:MAPLINK 新结点指针
输入:        H: 单链表的头结点指针               
输出:        VOID
返回值:      Head   
                            
作者:    
*******************************************************************************/
void readfile(MAPLINK *head)
{
	FILE *Sourcep;
	FILE *Resultp;
	char roadname[3000] = {'\0'};
	char def[20] = "无此道路信息";
	unsigned short infosize = 0;
	unsigned int roadID = 0;
	unsigned int roadflag = 0;
	unsigned int a = 0;
	unsigned int uibrunch = 0;
	unsigned int marker = 0;
	unsigned int uiinfo = 0; 
	unsigned int roadClass = 0;
	int i = 0,j = 0;
	int temp = 0;
	long int count = 0;

	MAPLINK newnodep;
	MAPLINK current;

	*head = (MAPLINK)malloc(sizeof(MAP));
	current = *head;
	newnodep = *head;
	Sourcep = fopen("d:\\GTBL.dat", "rb");
	Resultp = fopen("d:\\Result.txt", "w+");  //指向文件的指针
	printf("读地图信息取中...\n");
	//从地图信息文件中读取数据
	while(!feof(Sourcep))
	{
		for(i=0;i<22;i++)
		{
			newnodep->name[i] = '\0';
		}
		count++;
		fread(&infosize, 2, 1, Sourcep);
		infosize = GET_SHORT(infosize);
		marker = infosize;
		fprintf(Resultp, "信息大小： %d    ", infosize);//读取信息大小

		fread(&roadID, 4, 1, Sourcep);
		roadID = GET_INT(roadID);
		fprintf(Resultp, "LinkID：%d   ", roadID);//读取道路ID

		newnodep->LinkID=roadID;

		fread(&a, 2, 1, Sourcep);
		a = GET_SHORT(a);


		fread(&uiinfo, 4, 1, Sourcep);
		roadflag=GET_FLAG(GET_INT(uiinfo));//读取地图信息
		fprintf(Resultp, "Flag: %d   ", roadflag);

		newnodep->flag = roadflag;

		uibrunch = GET_CROSS(GET_INT(uiinfo));
		fprintf(Resultp, "岔路数: %d   ", uibrunch);

		newnodep->branch = uibrunch;

		roadClass = GET_CLASS(GET_INT(uiinfo));
		fprintf(Resultp, "交叉Link列表示Class番号: %d   ", roadClass);

		newnodep->roadclass = roadClass;

		fprintf(Resultp,"道路名称:");

		/*		             读取道路名称                  */
		if((marker-12) == 0)
		{
		  fwrite(def, 12, 1, Resultp);
		  fprintf(Resultp, "\n\n");
		  strcpy(newnodep->name, def);
		}
		else
		{
			fread(roadname, (marker-12), 1, Sourcep);
			fwrite(roadname, (marker-12), 1, Resultp);
			fprintf(Resultp, "\n\n");
			strcpy(newnodep->name, roadname);
		}
		/*                   单链表连接                    */
		current->next = newnodep;
		newnodep->next = NULL;
		current = newnodep;
		newnodep = (MAPLINK)malloc(sizeof(struct map));
	}
	printf(".........\n");
	printf(".........\n");
	printf("读取完...\n");
	printf("\n");
	printf(" /****************************************************************************\\ \n");
}