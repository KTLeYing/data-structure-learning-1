/**
*方法一：
*/
#include<dos.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//定义string 为含有10个字符元素的字符数组类型
typedef char string[10];
struct task
{
	int	ID;				//进程号
	string	name;		    //进程名
	int		arrivetime;		//到达时间
	int		servicetime;	//服务时间
	int     waittime;		//等待时间
	int		starttime;		//开始运行时间
	int		finishtime;		//结束运行时间
	float	turnaroundtime;	//周转时间
	float	weightedturnaroundtime;	//带权周转时间
	int		priority;		//优先权
	int     finish;			//是否已经完成
}PCB[10];
int num;
void input()
{
	int i;
	system("cls");
	printf("\n请输入作业数量：");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("\n请输入进程%d:\n",i);
		printf("进程名 到达时间 服务时间\n");
		scanf("%s%9d%9d",PCB[i].name,&PCB[i].arrivetime,&PCB[i].servicetime);
		PCB[i].priority=0;
		PCB[i].finish=0;
	}
}
int HRN(int pre)
{
	int current=1,i,j;	//优先权=(等待时间+要求服务时间)/要求服务时间
	for(i=0;i<num;i++)
	{
		PCB[i].waittime=PCB[i].finishtime-PCB[i].arrivetime;	//等待时间=上一个进程的完成时间-到达时间
		PCB[i].priority=(PCB[i].waittime+PCB[i].servicetime)/PCB[i].servicetime;
	}
	for(i=0;i<num;i++)
	{
		if(!PCB[i].finish)
		{
			current=i;	//找到第一个还没完成的作业
			break;
		}
	}
	for(j=i;j<num;j++)	//和后面的作业比较
	{
		if(!PCB[i].finish)	//还没完成（运行）
		{
			if(PCB[current].arrivetime<=PCB[pre].finishtime)	//如果进程在上一个进程完成之前到达
			{
				if(PCB[j].arrivetime<=PCB[pre].finishtime && PCB[j].priority>PCB[current].priority)
				current=j;	//找出到达时间在上一个进程完成之前，优先权高的进程
			}
			else	//如果进程是在上一个进程完成之后到达
			{
				if(PCB[j].arrivetime<PCB[current].arrivetime)
					current=j;	//找出比较早到达的一个
				if(PCB[j].arrivetime==PCB[current].arrivetime)	//如果同时到达
				if(PCB[j].priority>PCB[current].priority)
					current=j;	//找出服务时间比较短的一个
			}
		}
	}
	return current;	//返回当前进程
}
void running(int i,int times,int pre,int statime,int endtime)
{
	if(times==0)
	{
		PCB[i].starttime=PCB[i].arrivetime;
		PCB[i].finishtime=PCB[i].starttime+PCB[i].servicetime;
		PCB[i].turnaroundtime=PCB[i].servicetime;
		PCB[i].weightedturnaroundtime=1.0;
		statime=PCB[i].starttime;
	}
	else
	{
		if(PCB[i].arrivetime>PCB[pre].finishtime)
			PCB[i].starttime=PCB[i].arrivetime;
		else
			PCB[i].starttime=PCB[pre].finishtime;
		PCB[i].finishtime=PCB[i].starttime+PCB[i].servicetime;
		PCB[i].turnaroundtime=PCB[i].finishtime-PCB[i].arrivetime;
		PCB[i].weightedturnaroundtime=PCB[i].turnaroundtime/PCB[i].servicetime;
	}
	if(times==num-1)
		endtime=PCB[i].finishtime;
	PCB[i].finish=1;
}
void print(int i,int times)
{
	if(times==0)
	{
		printf("ID	进程名 到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间\n");
	}
		printf("%d%9s%9d%9d%9d%9d%10.1f%10.2f\n",PCB[i].ID,PCB[i].name,PCB[i].arrivetime,PCB[i].servicetime,
				PCB[i].starttime,PCB[i].finishtime,PCB[i].turnaroundtime,PCB[i].weightedturnaroundtime);
}
void check()
{
	int i;
	int statime,endtime,sumturtime=0.00,sumwtutime=0.00,aveturtime,avewtutime;
	int current=0,times=0,pre=0;
	PCB[pre].finishtime=0;
	for(i=0;i<num;i++)
	{
		PCB[i].finish=0;
	}
	statime,endtime,sumturtime=0.00,sumwtutime=0.00,aveturtime,avewtutime;
	current=0;times=0;pre=0;
	PCB[pre].finishtime=0;
	printf("\n");
	for(i=0;i<num;i++)
	{
		PCB[i].finish=0;
	}
	statime,endtime,sumturtime=0.00,sumwtutime=0.00,aveturtime,avewtutime;
	current=0;times=0;pre=0;
	PCB[pre].finishtime=0;
	printf("\n");
	for(times=0;times<num;times++)
	{
		current=HRN(pre);
		running(current,times,pre,statime,endtime);
		print(current,times);
		pre=current;
	}
	for(i=0;i<num;i++)
	{
		sumturtime+=PCB[i].turnaroundtime;
		sumwtutime+=PCB[i].weightedturnaroundtime;
	}
	aveturtime=sumturtime/num;
	avewtutime=sumwtutime/num;
	printf("(计与平均值)                %9d%9d%9d%9d\n",NULL,sumturtime,aveturtime,avewtutime);
	printf("\n");
}
int main()
{
	char again;
	do{
		system("cls"); //清屏
		printf("请输入4组数据：\n");
		input();
		check();
		printf("continue(y/n):");
		do{
			again=getch();
		}while(again!='Y'&&again!='y'&&again!='N'&&again!='n');
	}while(again=='Y' || again=='y');
}



/**
*方法二：
**/
//#include <stdio.h>
//#define N 10
//
//typedef struct {
//    int hour;
//    int min;
//}time;
//typedef struct hrrf{
//    char hrrf_id[20];
//    double hrrf_run;  //运行时间
//    time hrrf_entertime; //进入时间
//    int enter;
//    time hrrf_needtime;  //调度时间
//    int needtime;
//    time hrrf_endtime;   //结束时间
//    int endtime;
//    int hrrf_longtime;  //周转时间
//    int hrrf_waittime;   //等待时间
//    double hrrf_pjlongtime; //平均周转时间
//    double hrrf_rate;       //响应比
//
//    struct hrrf* next;
//}HRRF;
////输入作业信息
//void hrrfinput(HRRF s[N],int k)
//{
//    printf("\t请输入第%d个作业名：",k+1);
//    scanf("%s",&s[k].hrrf_id);
//    printf("\t请输入%s作业进入时间:",s[k].hrrf_id);
//    scanf("%d:%d",&s[k].hrrf_entertime.hour,&s[k].hrrf_entertime.min);
//    s[k].enter=s[k].hrrf_entertime.hour*60+s[k].hrrf_entertime.min;
//    printf("\t请输入%s作业运行时间：",s[k].hrrf_id);
//    scanf("%lf",&s[k].hrrf_run);
//}
////计算作业的响应比
//void rate(HRRF s[N],int k,int m)
//{
//    double ratenum;
//    ratenum = (s[k].hrrf_run+(double)(s[m].endtime-s[k].enter))/(s[k].hrrf_run);
//    s[k].hrrf_rate=ratenum;
//    printf("\n\t每次算响应比：%s---%f\n",s[k].hrrf_id,s[k].hrrf_rate);
//}
////按响应比大小对作业进行排序（降序排序）
//void ratesort(HRRF s[N],int k,int m)
//{
//    int maxratenum;
//    HRRF temp;
//    int i,j;
//    for(i=k;i<m;i++)         //简单选择排序
//    {
//        maxratenum=i;
//        for(j=i+1;j<m;j++)
//            if(s[j].hrrf_rate>s[maxratenum].hrrf_rate)
//                maxratenum=j;
//        if(maxratenum!=i)
//        {
//            temp=s[i];
//            s[i]=s[maxratenum];
//            s[maxratenum]=temp;
//        }
//
//    }
//}
////打印表单
//void print(HRRF s[N],int k)
//{
//    printf("\t序号\t作业名\t进入时间\t调度时间\t结束时间\t运行时间\t等待时间\t周转时间\n");
//    int i,j;
//    for(i=0;i<k;i++)
//        printf("\t%d\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\t\t%.0f min\t\t%d\t\t%d min\n",i+1,s[i].hrrf_id,(s[i].enter/60),(s[i].enter%60),(s[i].needtime/60),(s[i].needtime%60),(s[i].endtime/60),(s[i].endtime%60),s[i].hrrf_run,s[i].hrrf_waittime,s[i].hrrf_longtime);
//
//}
//
////hrrf算法
//void HRRF_run(HRRF s[N],int k)
//{
//    int i,j=k,n;
//    double sum;
//    HRRF temp;
//    //按到达时间进行排序
//    while(j>1)
//    {
//        for(i=0;i<j-1;i++)
//        {
//            if(s[i+1].enter<s[i].enter)
//            {
//                temp=s[i];
//                s[i]=s[i+1];
//                s[i+1]=temp;
//            }
//        }
//        j--;
//    }
//    printf("\n\t--------------------------------------------初始状态------------------------------------------------\n");
//    print(s,k);
//    j=0;
//    //执行
//    do{
//            if(j==0)
//            {
//                s[j].needtime=s[j].enter;
//                s[j].hrrf_waittime=0;
//                s[j].endtime=s[j].enter+s[j].hrrf_waittime+(int)(s[j].hrrf_run);
//                s[j].hrrf_longtime=s[j].endtime-s[j].enter;
//            }
//            else
//            {
//                s[j].needtime=s[j-1].endtime;
//                s[j].hrrf_waittime=s[j-1].endtime-s[j].enter;
//                s[j].endtime=s[j].needtime+(int)(s[j].hrrf_run);
//                s[j].hrrf_longtime=s[j].endtime-s[j].enter;
//            }
//            j++;  //到了第几个作业
//            //计算响应比
//            n=j-1;  //此次已经执行完的作业序号-1，因为数组从0开始
//            for(i=j;i<k;i++)
//            {
//                rate(s,i,n);    //计算响应比
//            }
//            ratesort(s,j,k);    //按响应比由大到小排序
//            printf("\n\t-----------------------------------------每次响应比排序---------------------------------------------\n");
//            print(s,k);
//
//    }while(j<k);
//
//    printf("\n\t--------------------------------------------作业调度------------------------------------------------\n");
//    print(s,k);
//    for(i=0;i<k;i++)
//    {
//        sum+=(double)(s[i].hrrf_longtime);
//    }
//
//    printf("\n\t平均周转时间为：%.2f\n",sum/k);
//}
//
//int main()
//{
//    HRRF a[N]={0};
//    int i,j;
//    printf("请输入创建作业数目：");
//    scanf("%d",&i);
//    for(j=0;j<i;j++)  //输入作业信息
//        hrrfinput(a,j);
//    //HRRF算法
//    HRRF_run(a,j);
//
//    return 0;
//}



/**
*方法三：
**/
//#include<stdio.h>
//
//#define    MAX   100
//
//typedef struct JCB
//{
//     char    job_id[10];     //作业ID
//     float   Arr_time;       //到达时刻
//     float   Fun_time;       //估计运行时间
//     float   Wait_time;      //等待时间
//     float   Start_time;     //开始时刻
//     float   Fin_time;       //完成时刻
//     float   Tur_time;       //周转时间
//     float   WTur_time;      //带权周转时间
//     int     Order;          //优先标记
//}list;
//
//void fcfs(list *p,int count);
//
//void sjf(list *p,int count);
//
//void hrn(list *p,int count);
//
//void print(list *p,int count);
//
//void avg(list *p,int count);
//
//void fcfs(list *p,int count)    //先来先服务算法
//{
//    list temp;                 //临时结构体变量
//    int i;
//    int j;
//
//    for(i = 1;i < count;i++)       //按到达时刻直接插入排序
//    {
//        temp = p[i];
//        j = i-1;
//
//          while(temp.Arr_time < p[j].Arr_time && j >= 0)
//          {
//              p[j+1] = p[j];
//               --j;
//          }
//            p[j+1] = temp;
//    }
//
//    for(i = 0;i < count;i++)                   //循环计算各个作业的时间值
//    {
//        if(i == 0)
//        {
//            p[i].Start_time = p[i].Arr_time;
//        }
//        else
//        {
//            p[i].Start_time = p[i-1].Fin_time;    //开始时刻==前一个作业的完成时刻
//        }
//        p[i].Wait_time  = p[i].Start_time - p[i].Arr_time;   //等待==开始-到达
//        p[i].Fin_time   = p[i].Start_time + p[i].Fun_time;   //完成==开始+运行
//        p[i].Tur_time   = p[i].Fin_time   - p[i].Arr_time;   //周转=完成-到达
//        p[i].WTur_time  = p[i].Tur_time   / p[i].Fun_time;   //带权周转=周转/运行
//    }
//
//   return;
//}
//
//void sjf(list *p,int count)                   //最短作业优先算法（sjf）
//{
//    list item;            //结构体变量
//    int i = 0;
//    int j = 0;
//    int k = 0;           //最短运行时间作业的下标
//    int flag = 0;        //优先级设置
//    float min = 0;       //最短运行时间
//    float temp;          //开始的时刻
//
//    temp = p[0].Arr_time;
//
//    for(i = 0;i < count;i++)    //先求出最先到达作业的时刻
//    {
//        if(temp > p[i].Arr_time)
//        {
//            temp = p[i].Arr_time;        //保存最先到达的作业的时刻
//            k = i;                       //最先到达的作业的下标，默认为p[0]
//        }
//    }
//
//    for(i = 0;i < count;i++)
//    {
//        p[k].Order = ++flag;        //设置优先级为1，最高优先级
//
//        p[k].Start_time = temp;
//        p[k].Wait_time  = temp - p[k].Arr_time;        //计算各个时间
//        p[k].Fin_time   = temp + p[k].Fun_time;
//        p[k].Tur_time   = p[k].Fin_time - p[k].Arr_time;
//        p[k].WTur_time  = p[k].Tur_time / p[k].Fun_time;
//
//
//        min = 100;
//
//            temp = p[k].Fin_time;                  //后一个作业的开始时刻是前一个作业的完成时刻
//
//        for(j = 0;j < count;j++)
//        {
//            if(p[j].Order != 0 || temp - p[j].Arr_time <= 0)  //跳过不满足条件的（已设置优先级的 和 到达时刻要晚于前一个作业的完成时刻的）
//              continue;
//            if(min > p[j].Fun_time)
//            {
//                min = p[j].Fun_time;
//                k = j;          //求出满足条件最短运行时间的作业的下标
//            }
//        }
//
//
//    }
//
//   for(i = 1;i < count;i++)       //按优先级排序
//    {
//        item = p[i];
//        j = i-1;
//
//          while(item.Order < p[j].Order && j >= 0)
//          {
//              p[j+1] = p[j];
//               --j;
//          }
//            p[j+1] = item;
//    }
//
// return;
//}
//
//void hrn(list *p,int count)              //最高响应比优先算法
//{
//    list item;            //结构体变量
//    int i = 0;
//    int j = 0;
//    int k = 0;           //最高响应比作业的下标
//    int flag = 0;        //优先级设置
//    float max = 0;       //最大响应比的值
//    float temp;          //开始的时刻
//
//    temp = p[0].Arr_time;
//
//                                      //先求出最先到达作业的时刻
//    for(i = 0;i < count;i++)
//    {
//        if(temp > p[i].Arr_time)
//        {
//            temp = p[i].Arr_time;
//            k = i;                       //最先到达的作业的下标，默认为p[0]
//        }
//    }
//
//   for(i = 0;i < count;i++)
//     {
//         p[k].Order = ++flag;        //设置优先级
//
//         p[k].Start_time = temp;                           //计算各个作业的时间
//         p[k].Wait_time  = temp - p[k].Arr_time;
//         p[k].Fin_time   = temp + p[k].Fun_time;
//         p[k].Tur_time   = p[k].Fin_time - p[k].Arr_time;
//         p[k].WTur_time  = p[k].Tur_time / p[k].Fun_time;
//
//
//        max = 0;
//
//            temp = p[k].Fin_time;
//
//        for(j = 0;j < count;j++)
//        {
//            if(p[j].Order != 0 || temp - p[j].Arr_time <= 0)        //排除优先级已设置 和 晚于作业完成时刻到达的
//              continue;                                              //后一个判断可以不加，如果晚到的话，下面的if语句进不去
//            if(max < (temp - p[j].Arr_time) / p[j].Fun_time)
//                {
//                    max = (temp - p[j].Arr_time) / p[j].Fun_time;
//                    k = j;          //求出剩下响应比最高的作业的下标
//                }
//        }
//
//
//     }
//
//    for(i = 1;i < count;i++)       //按优先级排序
//    {
//        item = p[i];
//        j = i-1;
//
//        while(item.Order < p[j].Order && j >= 0)
//        {
//            p[j+1] = p[j];
//            --j;
//        }
//            p[j+1] = item;
//    }
//
//
//  return;
//}
//
//void print(list *p,int count)          //输出各个作业的详细信息
//{
//    int i;
//
//    printf("*****************************************************************\n");
//    printf("ID\t到达\t运行\t等待\t开始\t完成\t周转\t带权周转\n");
//
//    for(i = 0;i < count;i++)
//    {
//        printf("%s\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",p[i].job_id,p[i].Arr_time,p[i].Fun_time,p[i].Wait_time,p[i].Start_time,p[i].Fin_time,p[i].Tur_time,p[i].WTur_time);
//
//    }
//
// return;
//}
//
//void avg(list *p,int count)
//{
//    float AvgTur1;        //平均周转
//    float AvgTur2;        //平均带权周转
//    float t1 = 0;
//    float t2 = 0;
//    int i;
//
//    for(i = 0;i < count;i++)
//    {
//        t1 += p[i].Tur_time;                //周转时间和
//        t2 += p[i].WTur_time;               //带权周转和
//    }
//
//    AvgTur1 = t1/count;
//    AvgTur2 = t2/count;
//
//    printf("\n平均周转时间为：%f\t平均带权周转时间为：%f\n",AvgTur1,AvgTur2);
//    printf("\n*****************************************************************\n");
//
//   return;
//}
//
//int main()
//{
//    list st[MAX];                  //最多可以一百个作业
//    int job_count = 0;             //作业数量
//    int flag = 1;                  //算法标记
//    int i = 0;
//
//    printf("请输入作业数量：");
//    scanf("%d",&job_count);
//
//    printf("请输入作业ID，到达时刻，估计运行时间(用空格隔开)：\n");
//
//     do
//       {
//          scanf("%s %f %f",st[i].job_id,&st[i].Arr_time,&st[i].Fun_time);
//          st[i].Order = 0;     //优先级初始化
//
//       }while(++i < job_count);
//
//
//
//    printf("请选择算法：\n1,   先来先服务算法！\n2,   最短作业优先算法！\n3,   最高响应比优先算法!\n");
//    scanf("%d",&flag);
//
//    switch(flag)
//     {
//         case 1 :  {
//                    fcfs(st,job_count);
//                    printf("\n*******************************************\n\n");
//                    printf("先来先服务算法\n");
//                   }  break;
//
//         case 2 :  {
//                    sjf(st,job_count);
//                    printf("\n*******************************************\n\n");
//                    printf("最短作业优先算法\n");
//                   }  break;
//         case 3 :  {
//                    hrn(st,job_count);
//                    printf("\n*******************************************\n\n");
//                    printf("最高响应比优先算法\n");
//                   }  break;
//     }
//
//    print(st,job_count);
//    avg(st,job_count);
//
//return 0;
//}
//




