/***************************************************************************
 /*名称：searchfind.c
 /*描述：该文件实现对文件内容的检索功能                
 /*作成日期：  2012-04-23
 /*函数：void search(MAP *head);
         int LinkIDfind(MAP *hl);
         int Brunchfind(MAP *hb,int number);
         int Namefind(MAP *hn);                           
/*作者：   
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "struct.h"

extern void search(MAPLINK head);
int LinkIDfind(MAPLINK hl);
int Brunchfind(MAPLINK hb,int number);
int Namefind(MAPLINK hn);

/***************************************************************************
 /*名称: void search( MAP* head)
 /*描述: 实现检索功能
                1. 输入检索方法
				   1:根据 LinkID检索; 
				   2:根据 road number检索;
				   3:根据 road name检索;
				   4:根据 class number检索;
				   5:根据 flag检索;
                2. 每种方法都有一个函数
                3. 检索到之后输出或者保存到.txt文件中
 /*作成日期:          2012-04-23
 /*参数： 参数1：MAP* head   自定义的结构体类型指针           
 /*返回值：无返回值                            
 /*作者：
*******************************************************************************/
void search(MAPLINK head)
{	  
	  MAPLINK nowp;                                        
	  int method;
	  int result;
	  extern void Choose();
	  extern void PrintEndFunction();
	
	  printf("   欢迎进入检索功能界面   \n");
	  while(1)
	  {
		  nowp = head;  
	  
	      printf("\n");
	      printf("        请选择所需要的功能\n");	  
	      printf("           1、根据LinkID检索...\n");
          printf("           2、根据岔路数检索...\n");
	  printf("           3、根据道路名称检索...\n");
          printf("           4、根据交叉Link列表示Class番号检索...\n");
          printf("           5、根据flag数检索...\n");
	  printf("\n");
          printf(" /****************************************************************************\\ \n");
	  printf("    请输入要检索的方法序号:");
	      
		  scanf("%d",&method);
          printf("\n");


	      switch(method)
	      {
              case 1:
			 
			      result = LinkIDfind(nowp);		               //按照LinkID检索		       			         				  
				  break;
			
              case 2:
			
			      result = Brunchfind(nowp,2);					   //按照岔路数检索			 
				  break;
			
	          case 3:

		          result = Namefind(nowp);                         //按照道路名称检索					  				 
				  break;
	          case 4:

		          result = Brunchfind(nowp,4);					   //按照class番号检索
				  break;
			  case 5:

                  result = Brunchfind(nowp,5);					  	//按照flag数检索			  
				  break;
              default:

				 printf("无此选择序号,请重新选择 \n");
				 search(head);
		         break;
		 }
		 if(2 == result)
		 {
			 continue;                                          //继续检索循环
		 }
         		else if(3 == result)
		 {
              		PrintEndFunction();
			Choose(&head);                                  //返回主函数
		 }
		 else
		 {
			 ;
		 }	
	  }
}

/***************************************************************************
/*名称: int LinkIDfind(  map* head)
/*描述: 根据LinkID检索
                1. 输入 LinkID头指针
                2. 顺序查找
                3. 查找后输出 
 /*作成日期:          2012-04-23
 /*参数:   参数1：struct map* head  自定义的结构体类型指针               
 /*返回值: 返回值为2：整型 表面返回检索界面
           返回值为3：整型 表面返回主函数                            
 /*作者:     
*******************************************************************************/
int LinkIDfind(MAPLINK hl)
{
	MAPLINK p;   
	FILE* fp;
	int ID,menunow;                                       
	int count = 0;
    int node;
	int save = 0;
	char roadname[50];
	
	fp = fopen("d:\\ResultSearchLinkID.txt","w+");                               //要保存的文件指针
    if(NULL == fp)
	{
		  printf("文件打开失败\n");
	      exit(1);
	}

	while(1)
	{	
	    printf("请输入要检索的LinkID号:");
	    scanf("%d",&node);
	    p = hl;
	   	   	   
	    while(p!=NULL)
		{		
		    ID = p->LinkID;                     
		    if(node == ID)                                                  //检索到如果为要查找的LinkID就执行输出...
			{					
			    count++;

			    printf("LinkID:%d\n",p->LinkID);
			    printf("flag:%d\n",p->flag);
			    printf("岔路数:%d\n",p->branch);
			    printf("交叉Link列表示Class番号:%d\n",p->roadclass);
			    printf("道路名称:%s\n",p->name);
			
		        printf("\n");
			    printf("请选择是否将输出信息保存在d:\\ResultSearchLinkID.txt文本文档中\n\n");
				printf("1:是 2:否 \n");
			    printf("请选择:");
			    scanf("%d",&save);

			    if(1==save)			
				{	
			        fprintf(fp,"LinkID:%d\n",p->LinkID);
			        fprintf(fp,"flag:%d\n",p->flag);
                    fprintf(fp,"岔路数:%d\n",p->branch);
			        fprintf(fp,"交叉Link列表示Class番号:%d\n",p->roadclass);
			   
                    fprintf(fp,"道路名称:");
			        strcpy(roadname,p->name);		
				    fwrite(roadname,(strlen(roadname)),1,fp);

			        fprintf(fp,"\n\n");
			        printf("保存完毕!\n");
				}
				else if(2==save)
				{
					printf("输出信息没有保存到文本文档中,仅输出 \n");
					printf("\n");
				}
				else
				{
					printf("输入错误,未保存 \n");
					printf("\n");
				}
				break;
			}
			else 
				p = p->next;
		}
	    if(0 == count)
		{	
			printf("无此道路编号,请核对后重新检索 \n");  
			printf("\n");
		}
		else 
		{
			printf("此LinkID检索完毕\n");
			printf("\n");
		}  
        
		printf(" /****************************************************************************\\ \n");
		printf("请选择: \n");
		printf("1、继续根据LinkID检索...\n");
		printf("2、返回检索目录\n");
		printf("3、返回主目录\n");
		printf("请输入序号:");
		scanf("%d",&menunow);
		if(1 == menunow)
			continue;
		else if(2 == menunow)
			return 2;
		else if(3 == menunow)
			return 3;
		else
		{
			printf("输入错误!返回检索目录\n");
			printf("\n");
			return 2;
		}
	}
}

/***************************************************************************
/*名称: Brunchfind(MAP *hb,int number)
/*描述: 根据岔路数、class番号、flag数检索
                1. 输入要检索的头指针与检索方法
                2. 顺序查找
                3. 查找后输出并保存 
 /*作成日期:          2012-04-23
 /*参数:   参数1：struct map* head  自定义的结构体类型指针 
           参数2：number 整型 检索方法： 2 根据岔路数检索；
				                         4 根据class番号检索；
							             5 根据flag数检索；
 /*返回值: 返回值为2：整型 表面返回检索界面
           返回值为3：整型 表面返回主函数                            
 /*作者:     
*******************************************************************************/
int Brunchfind(MAPLINK hb,int number)
{	
	MAPLINK p;  
	MAPLINK findcurrent;
    MAPLINK findhead;
    MAPLINK findnew;
    MAPLINK findprintf;
    MAPLINK findprintfdos;
	int ID,menunow;                                       
	int count = 0,countp = 0;
    int node;
	int numbera = 0;
	FILE *fp;
	char roadname[50];
	
	if(number == 2)
	{
	      fp = fopen("d:\\ResultSearchbrunch.txt","w+");                                          //要保存的文件指针
	}
	else if(number == 4)
	{
          fp = fopen("d:\\ResultSearchclass.txt","w+");
	}
	else if(number == 5)
	{
          fp = fopen("d:\\ResultSearchflag.txt","w+");
	}
	if(NULL == fp)
	{
		  printf("文件打开失败\n");
		  exit(1);
	}
	
	while(1)
	{		
	    count = 0;
	    numbera = number;
	    if(numbera == 2)
		{	
			printf("请输入要检索的岔路数:");
		}
		else if(numbera == 4)
		{
			printf("请输入要检索的class番号:");
		}
		else if(numbera == 5)
		{
			printf("请输入要检索的flag数:");
		}
		scanf("%d",&node);
		p = hb;
	 	   
		findhead = (MAPLINK)malloc(sizeof(MAP));                                         //根据检索到的道路信息新建一个单链表
		findprintf = findhead;
		findprintfdos = findhead;
		findcurrent = findhead;
		findnew = findhead;
		while(p!=NULL)
		{	
			if(numbera == 2)
			{		
	            ID = p->branch;
			}
			else if(numbera == 4)
			{
				ID = p->roadclass;
			}
			else if(numbera == 5)
			{
				ID = p->flag;
			}
	
			if(node == ID)
			{	
				count++;           

				findnew->LinkID = (p->LinkID);
                findnew->flag = (p->flag);
			    findnew->branch = (p->branch);
			    findnew->roadclass = (p->roadclass);
                strcpy(findnew->name,(p->name));

			    findcurrent->next = findnew;
	    	    findnew->next = NULL;
		        findcurrent = findnew;
		        findnew = (MAPLINK)malloc(sizeof(struct map));
			    p = p->next;
			}
			else
			{
				p = p->next;
			}
		}
	
	
		if(0==count)
		{	
			if(numbera ==2)
			{
				printf("无此岔路数,请核对后重新检索 \n");  
			}
			else if(numbera ==4)
			{
				printf("无此class番号,请核对后重新检索 \n");
			}
			else if(numbera ==5)
			{
				printf("无此flag数,请核对后重新检索.\n");
			}
		
			printf("\n");
		}
	   
		else if((0<count)&&(count<6))
		{
			if(numbera ==2)
			{
				printf("此岔路数检索完毕\n");
			}
			else if(numbera ==4)
			{
				printf("此class番号检索完毕\n");
			}
			else if(numbera ==5)
			{
				printf("此flag数检索完毕\n");
			}
			printf("\n");
			printf("共检索到%d条信息\n",count);
			printf("\n");
			printf("检索到的信息小于五条,所以仅输出 \n");

			if(findhead!=NULL)                                                                        //输出时按照单链表输出
			{
				do
				{
					printf("LinkID:%d\n",findprintfdos->LinkID);
					printf("flag:%d\n",findprintfdos->flag);
					printf("岔路数:%d\n",findprintfdos->branch);
					printf("交叉Link列表示Class番号:%d\n",findprintfdos->roadclass);
					printf("道路名称:%s\n",findprintfdos->name);
					printf("\n");
					countp++;
					findprintfdos=findprintfdos->next;
				}while((findprintfdos!=NULL)&&(countp<5));
			}
		}
	   
		else
		{
			printf("共检索到%d条信息\n",count);
			printf("\n");
			if(numbera ==2)
			{
				printf("此岔路数检索完毕\n");
			}
			else if(numbera ==4)
			{
				printf("此class番号检索完毕\n");
			}
			else if(numbera ==5)
			{
				printf("此flag数检索完毕\n");
			}
	
			printf("\n");
			printf("检索到的信息大于五条,所以执行保存操作.\n");
			if(findhead!=NULL)
			{
				do
				{
					fprintf(fp,"LinkID：%d\n",findprintf->LinkID);
					fprintf(fp,"flag:%d\n",findprintf->flag);
					fprintf(fp,"岔路数:%d\n",findprintf->branch);
					fprintf(fp,"交叉Link列表示Class番号:%d\n",findprintf->roadclass);
		     
					fprintf(fp,"道路名称:");
					strcpy(roadname,findprintf->name);		
					fwrite(roadname,(strlen(roadname)),1,fp);
			
					fprintf(fp,"\n\n");

					findprintf=findprintf->next;
				}while(findprintf!=NULL);
			}

			printf("\n");

			if(numbera ==2)
			{
				printf("已将检索到的信息保存在d:\\ResultSearchbrunch.txt文本文档中\n");
			}
			else if(numbera ==4)
			{
				printf("已将检索到的信息保存在d:\\ResultSearchclass.txt文本文档中\n");
			}
			else if(numbera ==5)
			{
				printf("已将检索到的信息保存在d:\\ResultSearchflag.txt文本文档中\n");
			}
		} 
	   	   
		printf("请选择: \n");

		if(numbera ==2)
		{
			printf("1:继续根据岔路数检索...\n");
		}
		else if(numbera ==4)
		{
            printf("1:继续根据class番号检索...\n");
		}
		else if(numbera ==5)
		{
            printf("1:继续根据flag数检索...\n");
		}

		printf("2:返回检索目录\n");
		printf("3:返回主目录\n");
		printf("请输入序号:");
		scanf("%d",&menunow);
		if(1==menunow)
			continue;
		else if(2==menunow)
			return 2;
		else if(3==menunow)
			return 3;
		else
		{
			printf("输入错误!返回检索目录\n");
			printf("\n");
       		return 2;
		}
	}
}

/***************************************************************************
/*名称: Namefind(MAP *hn)
/*描述: 根据道路名称检索
                1. 输入要检索的头指针
                2. 顺序查找
                3. 查找后输出并保存 
 /*作成日期:          2012-04-23
 /*参数:   参数1：struct map* head  自定义的结构体类型指针 
 /*返回值: 返回值为2：整型 表面返回检索界面
           返回值为3：整型 表面返回主函数                            
 /*作者:     
*******************************************************************************/
int Namefind(MAP *hn)
{
	MAPLINK p;  
	MAPLINK findcurrent;
    MAPLINK findhead;
    MAPLINK findnew;
    MAPLINK findprintf;
    MAPLINK findprintfdos;
	int menunow;  
	char ID[20];
	int count = 0,countp = 0;
	char node[20] = {0};
	FILE *fp;
	char ar[20] = "１＝";
    char ab[20] = {0};
	char roadname[50];
	
	fp = fopen("d:\\ResultSearchname.txt","w+");                                               //根据检索到的道路信息新建一个单链表
    if(NULL == fp)
	{	
		 printf("文件打开失败\0");
		 exit(1);
	}
    while(1)
	{
		count = 0;	   
		countp = 0;
		strcpy(ab,ar);
		printf("请输入要检索的道路名称:");  
	   
		scanf("%s",node);
		strcat(ab,node);
		p = hn;	   
	   
	    findhead = (MAPLINK)malloc(sizeof(MAP));
	    findprintf = findhead;
	    findprintfdos = findhead;
	    findcurrent = findhead;
        findnew = findhead;

	    while(p!=NULL)
		{	
			strcpy(ID,p->name);	
		  
			if(strcmp(ID,ab) == 0)
			{	
				count++;           

				findnew->LinkID = (p->LinkID);
				findnew->flag = (p->flag);
				findnew->branch = (p->branch);
				findnew->roadclass = (p->roadclass);
				strcpy(findnew->name,(p->name));

				findcurrent->next = findnew;
	    		findnew->next = NULL;
				findcurrent = findnew;
				findnew = (MAPLINK)malloc(sizeof(struct map));
				p = p->next;
			}
			else
			{
				p=p->next;
			}
		}
	
	
		if(0==count)
		{		  	      
			printf("无此道路名称,请核对后重新检索 \n");  	      
			printf("\n");
		}	   
		else if((0<count)&&(count<6))
		{
			printf("共检索到%d条信息\n",count);
			printf("\n");
          
			printf("此道路名称检索完毕\n");
			printf("\n");
			printf("检索到的信息小于五条,所以仅输出 \n");
			if(findhead!=NULL)                                                                   //输出时按照单链表输出
			{
				do
				{
					printf("LinkID:%d\n",findprintfdos->LinkID);
					printf("flag:%d\n",findprintfdos->flag);
					printf("岔路数:%d\n",findprintfdos->branch);
					printf("交叉Link列表示Class番号:%d\n",findprintfdos->roadclass);
					printf("道路名称:%s\n",findprintfdos->name);
					printf("\n");
					countp++;
					findprintfdos=findprintfdos->next;
				}while((findprintfdos!=NULL)&&(countp<5));
			}
		}	   
		else
		{
			printf("共检索到%d条信息\n",count);
			printf("\n");
		  
			printf("此道路名称检索完毕\n");
			printf("\n");
			printf("检索到的信息大于五条,所以执行保存操作.\n");

			if(findhead!=NULL)
			{
				do
				{
					fprintf(fp,"LinkID：%d\n",findprintf->LinkID);
					fprintf(fp,"flag:%d\n",findprintf->flag);
					fprintf(fp,"岔路数:%d\n",findprintf->branch);
					fprintf(fp,"交叉Link列表示Class番号%d\n",findprintf->roadclass);
		     
					fprintf(fp,"道路名称:");
					strcpy(roadname,findprintf->name);		
					fwrite(roadname,(strlen(roadname)),1,fp);
		
					fprintf(fp,"\n\n");

					findprintf=findprintf->next;
				}while(findprintf!=NULL);	
			}

			printf("\n");
			printf("已将检索到的信息保存在d:\\ResultSearchname.txt文本文档中\n");
		} 

		printf("请选择: \n");
		printf("1:继续根据道路名称检索...\n");
		printf("2:返回检索目录\n");
		printf("3:返回主目录\n");
		printf("请输入序号:");
		scanf("%d",&menunow);
		if(1==menunow)
			continue;
		else if(2==menunow)
			return 2;
		else if(3==menunow)
			return 3;
		else
		{
			printf("输入错误!返回检索目录\n");
			printf("\n");
       		return 2;
		}
	}
}






















