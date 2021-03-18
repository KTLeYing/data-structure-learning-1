/**************************************************/
/*���ƣ�BubbleSort
/*��������������Ϣ��LINK ID����С����˳���������
/*�������ڣ� 12/05/01 
/*���ߣ�
/***************************************************/
#include<stdio.h>
#include"struct.h"
#include<string.h>

/**************************************************/
/*���ƣ�BSort
/*����������ð�ݷ���������
/*�������ڣ�12/05/01 
/*������
        ����1��current����������struct mapָ�롢����/�����������������ǰ��ڵ�Ĳ���
        ����2��pre��    ��������struct mapָ�롢����/�����������������ǰ��ڵ�Ĳ���
		����3��tempname�������������顢����������洢��·��Ϣ��������
		����4��temp����������unsigned int������/����������洢���ݵı���
/*����ֵ��VOID
/*���ߣ�
/***************************************************/
void BSort(MAPLINK Head)
{
	MAPLINK current;
	MAPLINK pre;
	char tempname[30]={'\0'};
	unsigned int temp=0;
	
	/*����forѭ�������ݽ�������*/
	printf("���Եȣ�������......");
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