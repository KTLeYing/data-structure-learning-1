 /*int shiliuzhuanshi(int z)16转10进制
{ int c,s,quan;
     s=0;quan=1;
 while(z)
 {
  c=z%10;
  s=s+c*quan;
  z=z/16;
  quan=quan*16;
 }
 return s;
}*/
#include<stdio.h>
#include"header.h"
int cunjinMap(Map &m)
{
 int i=1;
 m.num=0;
 FILE *fpr,*fpw;
 fpw=fopen("d:\\Map4.txt","wt");
 fpr=fopen("d:\\GTBL.dat","rb");
 if(fpw==NULL)
	{
		printf("打开文件夹1失败\n");
		exit(0);
	 }
	if(fpr==NULL)
	{
		printf("打开文件夹2失败\n");
		exit(0);
	}
for(i=1;!feof(fpr);i++) // while(!feof(fpr))
 {
  fread(&m.RGather[i].informationSize,2,1,fpr);
  m.RGather[i].informationSize=M_CHG_INT16(m.RGather[i].informationSize);

  fread(&m.RGather[i].LinKID,4,1,fpr);
  m.RGather[i].LinKID=M_CHG_INT32(m.RGather[i].LinKID);

  fread(&m.RGather[i].RoadnameSize,2,1,fpr);
  m.RGather[i].RoadnameSize=M_CHG_INT16(m.RGather[i].RoadnameSize);

  fread(&m.RGather[i].RoadInfor,4,1,fpr);
  m.RGather[i].RoadInfor=M_CHG_INT32(m.RGather[i].RoadInfor);

  m.RGather[i].brunch=GET_BRUNCH(m.RGather[i].RoadInfor);
  m.RGather[i].dispclass=GET_DISPCLASS(m.RGather[i].RoadInfor);
  m.RGather[i].flag=GET_FLAG(m.RGather[i].RoadInfor);

  fprintf(fpw,"%d 信息大小：%d\t LinKID:%d\t 有无flag：%d\t 岔路数：%d\t 交叉Link列表示Class番号:%d\t",
  		  i,m.RGather[i].informationSize,m.RGather[i].LinKID,m.RGather[i].flag,m.RGather[i].brunch,m.RGather[i].dispclass);
	if(m.RGather[i].flag==0)
	{
		fprintf(fpw,"无道路名称\t");
		fprintf(fpw,"无名路");
	}
	else{
		fprintf(fpw,"有道路名称\t");
		fread(&m.RGather[i]. RoadName,m.RGather[i].informationSize-12,1,fpr);
		fprintf(fpw,"道路名称：%s",m.RGather[i]. RoadName);
	}
	fprintf(fpw,"\n");
	m.num++;

 }
 	fclose(fpr);
	fclose(fpw);
}

int write(Map &m)
{
	FILE *fpw;
	int i;
	fpw=fopen("排序后.txt","wt");
	for(i=1;i<=m.num;i++)
	{
		fprintf(fpw,"%d 信息大小：%d\t LinKID:%d  \t有无flag：%d\t 岔路数：%d\t 交叉Link列表示Class番号:%d\t",
  		  i,m.RGather[i].informationSize,m.RGather[i].LinKID,m.RGather[i].flag,m.RGather[i].brunch,m.RGather[i].dispclass);
  		  	if(m.RGather[i].flag==0)
	{
		fprintf(fpw,"无道路名称\t");
		fprintf(fpw,"无名路");
	}
	else{
		fprintf(fpw,"有道路名称\t");
		fprintf(fpw,"道路名称：%s",m.RGather[i]. RoadName);
	}
	fprintf(fpw,"\n");

	 }
}


