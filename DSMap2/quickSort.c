/**************************************************/
/*名称：QuickSort
/*描述：对数据信息（LINK ID）从小到大顺序进行排序
/*作成日期： 12/05/01 
/*作者：
/***************************************************/
#include"struct.h"
#include<stdio.h>

/**************************************************/
/*名称：BSort
/*描述：采用快速排序法进行排序,把待排序的链表拆分为2个子链表。选择链表的第一个节点作为基准，然后进行比较，
        比基准大节点的放入左面的子链表，比基准大的放入右边的子链表。在对待排序链表扫描一遍之后，左面子链表
		的节点值都小于基准的值，右边子链表的值都大于基准的值，然后把基准插入到链表中，并作为连接两个子链表
		的桥梁。然后根据左右子链表中节点数，选择较小的进行递归快速排序，而对数目较多的则进行跌等待排序，以
		提高性能。
/*作成日期：12/05/01 
/*返回值：VOID
/*作者：
/***************************************************/
void QListSort(MAPLINK *head,MAPLINK end) 
{  
	MAPLINK right;                    /*右边子链表的第一个节点*/
    MAPLINK *left_walk, *right_walk;  /*作为指针，把其指向的节点加入到相应的子链表中*/
    MAPLINK pivot, old;               /*pivot为基准, old为循环整个待排序链表的指针*/
    int count, left_count, right_count;  

    if (*head == end)  
        return;  
    do
	{  
        pivot = *head;     
        left_walk = head;     
        right_walk = &right;  
        left_count = right_count = 0;  
       
		/*取第一个节点作为比较的基准，小于基准的在左面的子链表中,大于基准的在右边的子链表中*/ 
        for(old = (*head)->next; old != end; old = old->next)
		{  
            if (old->LinkID < pivot->LinkID) 
			{                                 /*小于基准,加入到左面的子链表,继续比较*/   
                ++left_count;  
                *left_walk = old;              /*把该节点加入到左边的链表中*/    
               left_walk = &(old->next);  
            } 
			else 
			{                         /*大于基准,加入到右边的子链表，继续比较 */  
                ++right_count;  
                *right_walk = old;             
                right_walk = &(old->next);  
            }  
        }  

       /*合并链表 */  
        *right_walk = end;       /*结束右链表 */   
        *left_walk = pivot;      /*把基准置于正确的位置上 */   
        pivot->next = right;     /*把链表合并 */   

        /*对较小的子链表进行快排序，较大的子链表进行迭代排序*/   
        if(left_walk > right_walk) 
		{  
			QListSort(&(pivot->next), end);  
            end = pivot;  
            count = left_count;  
        }
		else 
		{  
            QListSort(head, pivot);  
            head = &(pivot->next);  
            count = right_count;  
        }  
	} 
	while (count > 1); 
}  
