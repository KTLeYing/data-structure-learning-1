/**
*����һ��
*/
#include<dos.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//����string Ϊ����10���ַ�Ԫ�ص��ַ���������
typedef char string[10];
struct task
{
	int	ID;				//���̺�
	string	name;		    //������
	int		arrivetime;		//����ʱ��
	int		servicetime;	//����ʱ��
	int     waittime;		//�ȴ�ʱ��
	int		starttime;		//��ʼ����ʱ��
	int		finishtime;		//��������ʱ��
	float	turnaroundtime;	//��תʱ��
	float	weightedturnaroundtime;	//��Ȩ��תʱ��
	int		priority;		//����Ȩ
	int     finish;			//�Ƿ��Ѿ����
}PCB[10];
int num;
void input()
{
	int i;
	system("cls");
	printf("\n��������ҵ������");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("\n���������%d:\n",i);
		printf("������ ����ʱ�� ����ʱ��\n");
		scanf("%s%9d%9d",PCB[i].name,&PCB[i].arrivetime,&PCB[i].servicetime);
		PCB[i].priority=0;
		PCB[i].finish=0;
	}
}
int HRN(int pre)
{
	int current=1,i,j;	//����Ȩ=(�ȴ�ʱ��+Ҫ�����ʱ��)/Ҫ�����ʱ��
	for(i=0;i<num;i++)
	{
		PCB[i].waittime=PCB[i].finishtime-PCB[i].arrivetime;	//�ȴ�ʱ��=��һ�����̵����ʱ��-����ʱ��
		PCB[i].priority=(PCB[i].waittime+PCB[i].servicetime)/PCB[i].servicetime;
	}
	for(i=0;i<num;i++)
	{
		if(!PCB[i].finish)
		{
			current=i;	//�ҵ���һ����û��ɵ���ҵ
			break;
		}
	}
	for(j=i;j<num;j++)	//�ͺ������ҵ�Ƚ�
	{
		if(!PCB[i].finish)	//��û��ɣ����У�
		{
			if(PCB[current].arrivetime<=PCB[pre].finishtime)	//�����������һ���������֮ǰ����
			{
				if(PCB[j].arrivetime<=PCB[pre].finishtime && PCB[j].priority>PCB[current].priority)
				current=j;	//�ҳ�����ʱ������һ���������֮ǰ������Ȩ�ߵĽ���
			}
			else	//�������������һ���������֮�󵽴�
			{
				if(PCB[j].arrivetime<PCB[current].arrivetime)
					current=j;	//�ҳ��Ƚ��絽���һ��
				if(PCB[j].arrivetime==PCB[current].arrivetime)	//���ͬʱ����
				if(PCB[j].priority>PCB[current].priority)
					current=j;	//�ҳ�����ʱ��Ƚ϶̵�һ��
			}
		}
	}
	return current;	//���ص�ǰ����
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
		printf("ID	������ ����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��\n");
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
	printf("(����ƽ��ֵ)                %9d%9d%9d%9d\n",NULL,sumturtime,aveturtime,avewtutime);
	printf("\n");
}
int main()
{
	char again;
	do{
		system("cls"); //����
		printf("������4�����ݣ�\n");
		input();
		check();
		printf("continue(y/n):");
		do{
			again=getch();
		}while(again!='Y'&&again!='y'&&again!='N'&&again!='n');
	}while(again=='Y' || again=='y');
}



/**
*��������
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
//    double hrrf_run;  //����ʱ��
//    time hrrf_entertime; //����ʱ��
//    int enter;
//    time hrrf_needtime;  //����ʱ��
//    int needtime;
//    time hrrf_endtime;   //����ʱ��
//    int endtime;
//    int hrrf_longtime;  //��תʱ��
//    int hrrf_waittime;   //�ȴ�ʱ��
//    double hrrf_pjlongtime; //ƽ����תʱ��
//    double hrrf_rate;       //��Ӧ��
//
//    struct hrrf* next;
//}HRRF;
////������ҵ��Ϣ
//void hrrfinput(HRRF s[N],int k)
//{
//    printf("\t�������%d����ҵ����",k+1);
//    scanf("%s",&s[k].hrrf_id);
//    printf("\t������%s��ҵ����ʱ��:",s[k].hrrf_id);
//    scanf("%d:%d",&s[k].hrrf_entertime.hour,&s[k].hrrf_entertime.min);
//    s[k].enter=s[k].hrrf_entertime.hour*60+s[k].hrrf_entertime.min;
//    printf("\t������%s��ҵ����ʱ�䣺",s[k].hrrf_id);
//    scanf("%lf",&s[k].hrrf_run);
//}
////������ҵ����Ӧ��
//void rate(HRRF s[N],int k,int m)
//{
//    double ratenum;
//    ratenum = (s[k].hrrf_run+(double)(s[m].endtime-s[k].enter))/(s[k].hrrf_run);
//    s[k].hrrf_rate=ratenum;
//    printf("\n\tÿ������Ӧ�ȣ�%s---%f\n",s[k].hrrf_id,s[k].hrrf_rate);
//}
////����Ӧ�ȴ�С����ҵ�������򣨽�������
//void ratesort(HRRF s[N],int k,int m)
//{
//    int maxratenum;
//    HRRF temp;
//    int i,j;
//    for(i=k;i<m;i++)         //��ѡ������
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
////��ӡ��
//void print(HRRF s[N],int k)
//{
//    printf("\t���\t��ҵ��\t����ʱ��\t����ʱ��\t����ʱ��\t����ʱ��\t�ȴ�ʱ��\t��תʱ��\n");
//    int i,j;
//    for(i=0;i<k;i++)
//        printf("\t%d\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\t\t%.0f min\t\t%d\t\t%d min\n",i+1,s[i].hrrf_id,(s[i].enter/60),(s[i].enter%60),(s[i].needtime/60),(s[i].needtime%60),(s[i].endtime/60),(s[i].endtime%60),s[i].hrrf_run,s[i].hrrf_waittime,s[i].hrrf_longtime);
//
//}
//
////hrrf�㷨
//void HRRF_run(HRRF s[N],int k)
//{
//    int i,j=k,n;
//    double sum;
//    HRRF temp;
//    //������ʱ���������
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
//    printf("\n\t--------------------------------------------��ʼ״̬------------------------------------------------\n");
//    print(s,k);
//    j=0;
//    //ִ��
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
//            j++;  //���˵ڼ�����ҵ
//            //������Ӧ��
//            n=j-1;  //�˴��Ѿ�ִ�������ҵ���-1����Ϊ�����0��ʼ
//            for(i=j;i<k;i++)
//            {
//                rate(s,i,n);    //������Ӧ��
//            }
//            ratesort(s,j,k);    //����Ӧ���ɴ�С����
//            printf("\n\t-----------------------------------------ÿ����Ӧ������---------------------------------------------\n");
//            print(s,k);
//
//    }while(j<k);
//
//    printf("\n\t--------------------------------------------��ҵ����------------------------------------------------\n");
//    print(s,k);
//    for(i=0;i<k;i++)
//    {
//        sum+=(double)(s[i].hrrf_longtime);
//    }
//
//    printf("\n\tƽ����תʱ��Ϊ��%.2f\n",sum/k);
//}
//
//int main()
//{
//    HRRF a[N]={0};
//    int i,j;
//    printf("�����봴����ҵ��Ŀ��");
//    scanf("%d",&i);
//    for(j=0;j<i;j++)  //������ҵ��Ϣ
//        hrrfinput(a,j);
//    //HRRF�㷨
//    HRRF_run(a,j);
//
//    return 0;
//}



/**
*��������
**/
//#include<stdio.h>
//
//#define    MAX   100
//
//typedef struct JCB
//{
//     char    job_id[10];     //��ҵID
//     float   Arr_time;       //����ʱ��
//     float   Fun_time;       //��������ʱ��
//     float   Wait_time;      //�ȴ�ʱ��
//     float   Start_time;     //��ʼʱ��
//     float   Fin_time;       //���ʱ��
//     float   Tur_time;       //��תʱ��
//     float   WTur_time;      //��Ȩ��תʱ��
//     int     Order;          //���ȱ��
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
//void fcfs(list *p,int count)    //�����ȷ����㷨
//{
//    list temp;                 //��ʱ�ṹ�����
//    int i;
//    int j;
//
//    for(i = 1;i < count;i++)       //������ʱ��ֱ�Ӳ�������
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
//    for(i = 0;i < count;i++)                   //ѭ�����������ҵ��ʱ��ֵ
//    {
//        if(i == 0)
//        {
//            p[i].Start_time = p[i].Arr_time;
//        }
//        else
//        {
//            p[i].Start_time = p[i-1].Fin_time;    //��ʼʱ��==ǰһ����ҵ�����ʱ��
//        }
//        p[i].Wait_time  = p[i].Start_time - p[i].Arr_time;   //�ȴ�==��ʼ-����
//        p[i].Fin_time   = p[i].Start_time + p[i].Fun_time;   //���==��ʼ+����
//        p[i].Tur_time   = p[i].Fin_time   - p[i].Arr_time;   //��ת=���-����
//        p[i].WTur_time  = p[i].Tur_time   / p[i].Fun_time;   //��Ȩ��ת=��ת/����
//    }
//
//   return;
//}
//
//void sjf(list *p,int count)                   //�����ҵ�����㷨��sjf��
//{
//    list item;            //�ṹ�����
//    int i = 0;
//    int j = 0;
//    int k = 0;           //�������ʱ����ҵ���±�
//    int flag = 0;        //���ȼ�����
//    float min = 0;       //�������ʱ��
//    float temp;          //��ʼ��ʱ��
//
//    temp = p[0].Arr_time;
//
//    for(i = 0;i < count;i++)    //��������ȵ�����ҵ��ʱ��
//    {
//        if(temp > p[i].Arr_time)
//        {
//            temp = p[i].Arr_time;        //�������ȵ������ҵ��ʱ��
//            k = i;                       //���ȵ������ҵ���±꣬Ĭ��Ϊp[0]
//        }
//    }
//
//    for(i = 0;i < count;i++)
//    {
//        p[k].Order = ++flag;        //�������ȼ�Ϊ1��������ȼ�
//
//        p[k].Start_time = temp;
//        p[k].Wait_time  = temp - p[k].Arr_time;        //�������ʱ��
//        p[k].Fin_time   = temp + p[k].Fun_time;
//        p[k].Tur_time   = p[k].Fin_time - p[k].Arr_time;
//        p[k].WTur_time  = p[k].Tur_time / p[k].Fun_time;
//
//
//        min = 100;
//
//            temp = p[k].Fin_time;                  //��һ����ҵ�Ŀ�ʼʱ����ǰһ����ҵ�����ʱ��
//
//        for(j = 0;j < count;j++)
//        {
//            if(p[j].Order != 0 || temp - p[j].Arr_time <= 0)  //���������������ģ����������ȼ��� �� ����ʱ��Ҫ����ǰһ����ҵ�����ʱ�̵ģ�
//              continue;
//            if(min > p[j].Fun_time)
//            {
//                min = p[j].Fun_time;
//                k = j;          //������������������ʱ�����ҵ���±�
//            }
//        }
//
//
//    }
//
//   for(i = 1;i < count;i++)       //�����ȼ�����
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
//void hrn(list *p,int count)              //�����Ӧ�������㷨
//{
//    list item;            //�ṹ�����
//    int i = 0;
//    int j = 0;
//    int k = 0;           //�����Ӧ����ҵ���±�
//    int flag = 0;        //���ȼ�����
//    float max = 0;       //�����Ӧ�ȵ�ֵ
//    float temp;          //��ʼ��ʱ��
//
//    temp = p[0].Arr_time;
//
//                                      //��������ȵ�����ҵ��ʱ��
//    for(i = 0;i < count;i++)
//    {
//        if(temp > p[i].Arr_time)
//        {
//            temp = p[i].Arr_time;
//            k = i;                       //���ȵ������ҵ���±꣬Ĭ��Ϊp[0]
//        }
//    }
//
//   for(i = 0;i < count;i++)
//     {
//         p[k].Order = ++flag;        //�������ȼ�
//
//         p[k].Start_time = temp;                           //���������ҵ��ʱ��
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
//            if(p[j].Order != 0 || temp - p[j].Arr_time <= 0)        //�ų����ȼ������� �� ������ҵ���ʱ�̵����
//              continue;                                              //��һ���жϿ��Բ��ӣ�������Ļ��������if������ȥ
//            if(max < (temp - p[j].Arr_time) / p[j].Fun_time)
//                {
//                    max = (temp - p[j].Arr_time) / p[j].Fun_time;
//                    k = j;          //���ʣ����Ӧ����ߵ���ҵ���±�
//                }
//        }
//
//
//     }
//
//    for(i = 1;i < count;i++)       //�����ȼ�����
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
//void print(list *p,int count)          //���������ҵ����ϸ��Ϣ
//{
//    int i;
//
//    printf("*****************************************************************\n");
//    printf("ID\t����\t����\t�ȴ�\t��ʼ\t���\t��ת\t��Ȩ��ת\n");
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
//    float AvgTur1;        //ƽ����ת
//    float AvgTur2;        //ƽ����Ȩ��ת
//    float t1 = 0;
//    float t2 = 0;
//    int i;
//
//    for(i = 0;i < count;i++)
//    {
//        t1 += p[i].Tur_time;                //��תʱ���
//        t2 += p[i].WTur_time;               //��Ȩ��ת��
//    }
//
//    AvgTur1 = t1/count;
//    AvgTur2 = t2/count;
//
//    printf("\nƽ����תʱ��Ϊ��%f\tƽ����Ȩ��תʱ��Ϊ��%f\n",AvgTur1,AvgTur2);
//    printf("\n*****************************************************************\n");
//
//   return;
//}
//
//int main()
//{
//    list st[MAX];                  //������һ�ٸ���ҵ
//    int job_count = 0;             //��ҵ����
//    int flag = 1;                  //�㷨���
//    int i = 0;
//
//    printf("��������ҵ������");
//    scanf("%d",&job_count);
//
//    printf("��������ҵID������ʱ�̣���������ʱ��(�ÿո����)��\n");
//
//     do
//       {
//          scanf("%s %f %f",st[i].job_id,&st[i].Arr_time,&st[i].Fun_time);
//          st[i].Order = 0;     //���ȼ���ʼ��
//
//       }while(++i < job_count);
//
//
//
//    printf("��ѡ���㷨��\n1,   �����ȷ����㷨��\n2,   �����ҵ�����㷨��\n3,   �����Ӧ�������㷨!\n");
//    scanf("%d",&flag);
//
//    switch(flag)
//     {
//         case 1 :  {
//                    fcfs(st,job_count);
//                    printf("\n*******************************************\n\n");
//                    printf("�����ȷ����㷨\n");
//                   }  break;
//
//         case 2 :  {
//                    sjf(st,job_count);
//                    printf("\n*******************************************\n\n");
//                    printf("�����ҵ�����㷨\n");
//                   }  break;
//         case 3 :  {
//                    hrn(st,job_count);
//                    printf("\n*******************************************\n\n");
//                    printf("�����Ӧ�������㷨\n");
//                   }  break;
//     }
//
//    print(st,job_count);
//    avg(st,job_count);
//
//return 0;
//}
//




