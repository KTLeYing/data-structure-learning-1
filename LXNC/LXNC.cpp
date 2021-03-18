/**
*方法1:
**/
////动态内存分配
//#include<stdio.h>
//int temp=0;//定义一个全局变量！这个变量起很大作用
//typedef struct _BiTNode//定义 表 的结构体
//{
//	int address;//首地址
//	int length;//空闲区长度
//	bool state;//区域状态 “1”表示已分配， “0”表示未分配
//	int homework; //作业名
//	struct _BiTNode *lchild;//指向左孩子的指针
//	struct _BiTNode *rchild;//右孩子
//}BiTNode,*pBiTree;
//void Init_BiTree(pBiTree l)
//{
//	l->address = 5;
//	l->length = 507;
//	l->state = 0;
//	l->homework=NULL;
//	l->lchild = NULL;
//	l->rchild = NULL;
//	printf("初始化完成！\n");
//}
//int Print(pBiTree p)
//{
//	printf("\n\t\t%d\t%d\t",p->address,p->length);
//	if(p->state==1)
//		printf("Busy  \t");
//	else
//		printf("Free  \t");
//	if(p->homework!=0)
//		printf("%d\n",p->homework);
//	else
//		printf("\n");
//}
////先序遍历
//void PreOrder(pBiTree p)
//{
//	if(p != NULL)
//    {
//        if(!p->lchild&&!p->rchild)
//        	Print(p);  //输出该结点
//	   	PreOrder(p->lchild);  //遍历左子树
//        PreOrder(p->rchild); //遍历右子树
//    }
//}
//void Insert_PreOrder(pBiTree p,int length,int homework)//插入新作业
//{
//	if(p != NULL)
//    {
//		if((p->state==0)&&(length<p->length)&&(!p->lchild)&&(!p->rchild)&&temp==0)//判断节点是否有左右孩子，是否小于空闲区长度，是否状态为0（表示区域无作业运行）
//	   	{
//			pBiTree  x1 =new BiTNode;//进行插入，动态申请两个空间 x1,x2
//			pBiTree  x2 =new BiTNode;
//			x1->homework=homework;//x1为作业
//			x2->homework=NULL;//x2为剩余的空闲区
//		   	x1->address=p->address;//把原空闲区的首地址给作业的首地址
//		   	x1->state=1;//作业的状态改为1
//		   	x1->length=length;//作业的长度为传入的长度
//		   	x2->address=x1->address+length;//新空闲区的首地址为 x1首地址与x1长度之和
//		   	x2->length=p->length-x1->length;
//		   	p->lchild=x1;
//		   	p->rchild=x2;
//		   	x2->state=0;
//		   	x1->lchild=NULL;
//			x1->rchild=NULL;
//			x2->rchild=NULL;
//			x2->lchild=NULL;
//			temp=1;
//		}
//		else
//		{
//			Insert_PreOrder(p->lchild,length,homework);  //遍历左子树
//        	Insert_PreOrder(p->rchild,length,homework); //遍历右子树
//    	}
//	}
//}
//void Delect_PreOrder(pBiTree p,int homework) //遍历修改，将状态修改为0。即为空闲区
//{
//	if(p != NULL)
//    {
//        if(p->homework==homework)//当查询到作业名相同的作业。进行修改
//        {
//			p->homework=NULL;//将作业名修改为空
//			p->state=0;//将作业名状态修改为空闲
//		}
//	Delect_PreOrder(p->lchild,homework);  //遍历左子树
//    Delect_PreOrder(p->rchild,homework); //遍历右子树
//    }
//}
//int main()
//{
//	BiTNode l;
//	Init_BiTree(&l);
//	//初始化
//	printf("\n   初始化:\t首地址\t长度\t状态\t作业名\n");
//
//	PreOrder(&l);
//	//插入作业1
//	temp=0;
//	Insert_PreOrder(&l,300,1);
//	printf("\n插入作业1:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//插入作业2
//	temp=0;
//	Insert_PreOrder(&l,100,2);
//	printf("\n插入作业2:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//释放作业1
// 	Delect_PreOrder(&l,1);
//    printf("\n释放作业1:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//插入作业3
//	temp=0;
//	Insert_PreOrder(&l,150,3);
//	printf("\n插入作业3:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//插入作业4
//	temp=0;
//	Insert_PreOrder(&l,30,4);
//	printf("\n插入作业4:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//插入作业5
//	temp=0;
//	Insert_PreOrder(&l,40,5);
//	printf("\n插入作业5:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//插入作业6
//	temp=0;
//	Insert_PreOrder(&l,60,6);
//	printf("\n插入作业6:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	//释放作业4
//	Delect_PreOrder(&l,4);
//    printf("\n释放作业4:\t首地址\t长度\t状态\t作业名\n");
//	PreOrder(&l);
//	return 0;
//}


/**
*方法2：（好用）
**/
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int pos,n,Size; ///查找位置,分区数量,最小分割大小
struct List
{
    int id;///空闲分区编号
    int sad;///空闲分区首地址
    int rom;///空间
    int state;///状态，0为空，1为未满，2为满；
} L[2000];
struct Task
{
    int id;
    int rom;
    int sad;
} T[2000];
bool cmp(List a,List b)
{
    return a.rom<b.rom;
}
void print()
{
    int i;
    printf("|---------------------------------------------------------------|\n");
    printf("|       分区号    分区始址    分区大小    分区状态       |\n");
    printf("|---------------------------------------------------------------|\n");
    for(i=1; i<=n; i++)
    {
        printf("|        %3d        %3d         %3d         %3d          |\n",
               L[i].id,L[i].sad,L[i].rom,L[i].state);
        printf("|---------------------------------------------------------------|\n");
    }

}
void recycle()
{
    printf("请输入要释放占用空间任务的序号：\n");
    int l;
    int f1=0,f2=0,f3=0;
    int p1,p2;
    cin>>l;
    for(int i=1; i<=n; i++)
    {
        if(T[l].sad==L[i].sad+L[i].rom)
        {
            f1=1;
            p1=i;
        }
        if(T[l].sad+T[l].rom==L[i].sad)
        {
            f2=1;
            p2=i;
        }
    }
    //cout<<f1<<" "<<f2<<endl;
    if(f1==1&&f2==0)
    {
        L[p1].rom=L[p1].rom+T[l].rom;
    }
    else if(f1==0&&f2==1)
    {
        L[p2].rom=L[p2].rom+T[l].rom;
        L[p2].sad=T[l].sad;
    }
    else if(f1==1&&f2==1)
    {
        L[p1].rom=L[p1].rom+T[l].rom+L[p2].rom;
        for(int j=p1+1; j<=n; j++)
            L[j].id--;
        n--;
    }
    else if(f1==0&&f2==0)
    {
        int temp;
        for(int j=1; j<=n; j++)
        {
            if(L[j].sad>T[l].sad+T[l].rom)///实际上大于T[l].sad就可以
            {
                temp=j;
            }
        }
        for(int j=temp; j<=n; j++)
            T[j].id++;
        n++;
        L[temp].id=temp;
        L[temp].rom=T[l].rom;
        L[temp].sad=T[l].sad;
        L[temp].state=0;
    }
    cout<<"内存回收完毕！"<<endl;
}
void NF()///循环首次适应算法
{
    cout<<"选择采用'循环首次适应算法'进行内存分配\n"<<endl;
    int tmp;
    pos=1;///开始从第一个分区查找
    while(1)
    {
        cout<<"      *******************************************"<<endl;
        cout<<"      1: 分配内存             2: 回收内存        "<<endl;
        cout<<endl;
        cout<<"      3: 查看空闲分区表       0: 退出       "<<endl;
        cout<<"      *******************************************"<<endl;
        cout<<"请输入您的操作 ：";
        cin>>tmp;
        int k=0;
        if(tmp==1)
        {
            k++;
            printf("请输入第%d个作业占用空间大小：\n",k);
            cin>>T[k].rom;
            T[k].id=k;
            int num=0;
            for(int i=pos;; i++)
            {
                num++;
                if(num>n)
                {
                    printf("作业请求内存空间过大，空闲分区表不能满足要求，内存分配失败!\n");
                    break;
                }
                if(i>n)
                {
                    i=1;
                    continue;
                }
                if((L[i].state==0||L[i].state==1)&&L[i].rom>=T[i].rom)
                {
                    if(L[i].rom-T[k].rom>Size)
                    {
                        L[i].sad=L[i].sad+T[k].rom;
                        L[i].rom=L[i].rom-T[k].rom;
                        L[i].state=1;
                        T[k].sad=L[i].sad-T[k].rom;
                        printf("内存分配成功！\n作业申请空间为%d\n起始地址为%d\n",T[k].rom,T[k].sad);
                        break;
                    }
                    else
                    {
                        L[i].sad=L[i].sad+Size;
                        L[i].rom=L[i].rom-Size;
                        L[i].state=2;
                        T[k].sad=L[i].sad-Size;
                        printf("内存分配成功！\n作业申请空间为%d\n起始地址为%d\n",L[i].rom,T[k].sad);
                        break;
                    }
                }
                else if(L[i].state=0&&L[i].rom-T[k].rom==Size)
                {
                    L[i].state=2;
                    T[k].sad=L[i].sad;
                    printf("内存分配成功！\n作业申请空间为%d\n起始地址为%d\n",T[k].rom,T[k].sad);
                    break;
                }
            }
        }
        else if(tmp==2)
        {
            recycle();
        }
        else if(tmp==3)
            print();
        else if(tmp==0)
            return;
        else
        {
            printf("输入有误，请重新输入！\n");
            continue;
        }
    }
}
void BF()///最佳适应算法
{
    cout<<"选择采用'最佳适应算法'进行内存分配\n"<<endl;
    sort(L+1,L+n+1,cmp);
    int tmp;
    while(1)
    {
        cout<<"      *******************************************"<<endl;
        cout<<"      1: 分配内存             2: 回收内存        "<<endl;
        cout<<endl;
        cout<<"      3: 查看空闲分区表       0: 退出       "<<endl;
        cout<<"      *******************************************"<<endl;
        cout<<"请输入您的操作 ：";
        cin>>tmp;
        int k=0;
        if(tmp==1)
        {
            k++;
            printf("请输入第%d个作业占用空间大小：\n",k);
            cin>>T[k].rom;
            T[k].id=k;
            int i;
            for(i=1; i<=n; i++)
            {
                if(i>n)
                {
                    i=1;
                    continue;
                }
                if((L[i].state==0||L[i].state==1)&&L[i].rom>=T[i].rom)
                {
                    if(L[i].rom-T[k].rom>Size)
                    {
                        L[i].sad=L[i].sad+T[k].rom;
                        L[i].rom=L[i].rom-T[k].rom;
                        L[i].state=1;
                        T[k].sad=L[i].sad-T[k].rom;
                        printf("内存分配成功！\n作业申请空间为%d\n起始地址为%d\n",T[k].rom,T[k].sad);
                        break;
                    }
                    else
                    {
                        L[i].sad=L[i].sad+Size;
                        L[i].rom=L[i].rom-Size;
                        L[i].state=2;
                        T[k].sad=L[i].sad-Size;
                        printf("内存分配成功！\n作业申请空间为%d\n起始地址为%d\n",L[i].rom,T[k].sad);
                        break;
                    }
                }
                else if(L[i].state=0&&L[i].rom-T[k].rom==Size)
                {
                    L[i].state=2;
                    T[k].sad=L[i].sad;
                    printf("内存分配成功！\n作业申请空间为%d\n起始地址为%d\n",T[k].rom,T[k].sad);
                    break;
                }
            }
            if(i>n)
            {
                printf("作业请求内存空间过大，空闲分区表不能满足要求，内存分配失败!\n");
                break;
            }
        }
        else if(tmp==2)
        {
            recycle();
            sort(L+1,L+n+1,cmp);
        }
        else if(tmp==3)
            print();
        else if(tmp==0)
            return;
        else
        {
            printf("输入有误，请重新输入！\n");
            continue;
        }
    }
}
void init()
{
loop1:
    pos=1;
    printf("请输入空闲分区表分区数量：\n");
    cin>>n;
    printf("请输入每个空闲分区的分区大小，分区始址\n");
    for(int i=1; i<=n; i++)
    {
        printf("请输入第%d个分区的信息：\n",i);
        cin>>L[i].rom>>L[i].sad;
        L[i].id=i;
        L[i].state=0;
    }
    printf("输入完毕，当前空闲分区表状态为：\n");
    print();
    printf("请输入不再切割的剩余空间的大小：\n");
    cin>>Size;
loop2:
    printf("选择内存分配的算法：1.循环首次适应算法  2.最佳适应算法  3.重新编辑空闲分区表  4.退出 \n");
    int tmp;
    cin>>tmp;
    if(tmp==1)NF();
    else if(tmp==2)BF();
    else if(tmp==3)
    {
        goto loop1;
    }
    else if(tmp==4) return;
    else
    {
        printf("输入有误，请重新输入!\n");
        goto loop2;
    }
}

int main()
{
    init();
    return 0;
}

/*
5
50 85
32 155
70 275
60 532
10 980
3
1
1
25
3
2
1
3
0
*/



/**
*方法3：（好用）
**/
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int maxsize;
//int k[50];
//typedef struct memory
//{
//	bool flage;
//	string name;
//	int start;
//	int size;
//	memory *front;
//	memory *next;
//}rd;
//rd *line = new rd;
//
///*
//struct node
//{
//string name;
//string operate;
//int size;
//}node1,node2;
//*/
//
//void init()
//{
//	line->flage = 0;
//	line->name = "空";
//	line->start = 0;
//	line->size = maxsize;
//	line->front = NULL;
//	line->next = NULL;
//}
//
//void display()
//{
//	rd *di = new rd;
//	di = line;
//	while (di != NULL)
//	{
//		cout << di->flage << "  " << di->name << "  " << di->start << "  " << di->size << endl;
//		di = di->next;
//	}
//
//	/*
//	while (q->front != NULL)
//	{
//	cout << q->front->flage << "  " << q->front->name << "  " << q->front->start << "  " << q->front->size << endl;
//	q = q->front;
//	}
//	*/
//}
//
//void firstmethod()
//{
//	cout << "请输入申请的主存大小:  " << endl;
//	cin >> maxsize;
//	init();
//	display();
//	while (true)
//	{
//		string operate;
//		rd *temp = new rd;
//		temp->front = NULL;
//		temp->next = NULL;
//		temp->flage = 1;
//		cout << "请求名称（ shutdown 为结束标识符 ）" << endl;
//		cin >> temp->name;
//		cout << "请求类型（ 申请  完成 ）" << endl;
//		cin >> operate;
//		if (operate == "shutdown")
//		{
//			cout << "此次首次适应算法分配结束！" << endl;
//			return;
//		}
//		else if (operate == "申请")
//		{
//			temp->start = 0;
//			cout << "请求大小" << endl;
//			cin >> temp->size;
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (!p->flage && p->size >= temp->size)
//				{
//					temp->start = p->start + (p->size - temp->size);
//					p->size -= temp->size;
//					if (p->next != NULL)
//					{
//						temp->next = p->next;
//						p->next->front = temp;
//					}
//					temp->front = p;
//					p->next = temp;
//				}
//				p = p->next;
//			}
//			display();
//		}
//		else if (operate == "完成")
//		{
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (p->name == temp->name)
//				{
// 					rd *q = new rd;
//					q->flage = 0;
//					q->name = "空";
//					q->start = 0;
//					q->size = maxsize;
//					q->front = NULL;
//					q->next = NULL;
//
//					if (p->front != NULL)
//					{
//						q = p->front;
//						if (p->front->front != NULL) q->front = p->front->front;
//						else q->front = NULL;
//					}
//					if (!q->flage)
//					{
//						q->size += p->size;
//
//						if (p->next != NULL && !p->next->flage)
//						{
//							q->size += p->next->size;
//							if (q->next->next->next != NULL)
//							{
//								q->next->next->next->front = q;
//								q->next = q->next->next->next;
//							}
//							else
//							{
//								q->next = NULL;
//							}
//						}
//						else if (p->next != NULL)
//						{
//							q->next = p->next;
//						}
//						p = q->next;
//					}
//					else if (p->next != NULL && !p->next->flage)
//					{
//						p->size += p->next->size;
//						if (p->next->next != NULL)
//						{
//							p->next->next->front = p;
//							p->next = p->next->next;
//						}
//					}
//
//					else if (((p->front != NULL && p->front->flage) || (p->front == NULL) && ((p->next != NULL && p->next->flage) || (p->next == NULL))))
//					{
//						p->flage = 0;
//						p->name = "空";
//						if (p->next != NULL)
//						{
//							p->next->front = p->front;
//							p->front->next = p->next;
//						}
//					}
//				}
//				else p = p->next;
//			}
//			display();
//		}
//	}
//}
//
//void bestmethod()
//{
//	cout << "请输入申请的主存大小:  " << endl;
//	cin >> maxsize;
//	init();
//	display();
//	while (true)
//	{
//		string operate;
//		rd *temp = new rd;
//		temp->front = NULL;
//		temp->next = NULL;
//		temp->flage = 1;
//		cout << "请求名称（ shutdown 为结束标识符 ）" << endl;
//		cin >> temp->name;
//		cout << "请求类型（ 申请  完成 ）" << endl;
//		cin >> operate;
//		if (operate == "shutdown")
//		{
//			cout << "此次首次适应算法分配结束！" << endl;
//			return;
//		}
//		else if (operate == "申请")
//		{
//			temp->start = 0;
//			cout << "请求大小" << endl;
//			cin >> temp->size;
//			memset(k, 0, sizeof(k));
//			rd *order = new rd;
//			order = line;
//			int i = 0;
//			int ok;
//			while (order != NULL)
//			{
//				if(!order->flage) k[i++] = order->size;
//			}
//			sort(k, k + i);
//			for (int j = 0; j < i; j++)
//			{
//				if (k[j] >= temp->size)
//				{
//					ok = k[j];
//				}
//			}
//
//			rd *q = new rd;
//			q->front = NULL;
//			q->next = NULL;
//			q->size = 0;
//			q->flage = 0;
//			q->start = 0;
//			q->name = temp->name;
//
//			rd *p = new rd;
//			p = line;
//			i = 0;
//			while (p != NULL)
//			{
//				if (p->size==ok)
//				{
//					q = p;
//					break;
//				}
//				p = p->next;
//			}
//
//			if (q->size >= temp->size)
//			{
//				temp->start = q->start + (q->size - temp->size);
//				q->size -= temp->size;
//				cout << temp->start << "  " << q->size << "  " << line->size << endl;
//				if (q->next != NULL)
//				{
//					temp->next = q->next;
//					q->next->front = temp;
//				}
//				else
//				{
//					temp->next = NULL;
//				}
//				temp->front = q;
//				q->next = temp;
//			}
//			else
//			{
//				cout << "申请失败！！！" << endl;
//			}
//			display();
//		}
//		else if (operate == "完成")
//		{
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (p->name == temp->name)
//				{
//					rd *q = new rd;
//					q->flage = 0;
//					q->name = "空";
//					q->start = 0;
//					q->size = maxsize;
//					q->front = NULL;
//					q->next = NULL;
//
//					if (p->front != NULL)
//					{
//						q = p->front;
//						if (p->front->front != NULL) q->front = p->front->front;
//						else q->front = NULL;
//					}
//					if (!q->flage)
//					{
//						q->size += p->size;
//
//						if (p->next != NULL && !p->next->flage)
//						{
//							q->size += p->next->size;
//							if (q->next->next->next != NULL)
//							{
//								q->next->next->next->front = q;
//								q->next = q->next->next->next;
//							}
//							else
//							{
//								q->next = NULL;
//							}
//						}
//						else if (p->next != NULL)
//						{
//							q->next = p->next;
//						}
//						p = q->next;
//					}
//					else if (p->next != NULL && !p->next->flage)
//					{
//						p->size += p->next->size;
//						if (p->next->next != NULL)
//						{
//							p->next->next->front = p;
//							p->next = p->next->next;
//						}
//					}
//					else if (((p->front != NULL && p->front->flage) || (p->front == NULL) && ((p->next != NULL && p->next->flage) || (p->next == NULL))))
//					{
//						p->flage = 0;
//						p->name = "空";
//						if (p->next != NULL)
//						{
//							p->next->front = p->front;
//							p->front->next = p->next;
//						}
//					}
//				}
//				else p = p->next;
//			}
//			display();
//		}
//	}
//
//
//
//
//}
//
//void badmethod()
//{
//	cout << "请输入申请的主存大小:  " << endl;
//	cin >> maxsize;
//	init();
//	display();
//	while (true)
//	{
//		string operate;
//		rd *temp = new rd;
//		temp->front = NULL;
//		temp->next = NULL;
//		temp->flage = 1;
//		cout << "请求名称（ shutdown 为结束标识符 ）" << endl;
//		cin >> temp->name;
//		cout << "请求类型（ 申请  完成 ）" << endl;
//		cin >> operate;
//		if (operate == "shutdown")
//		{
//			cout << "此次首次适应算法分配结束！" << endl;
//			return;
//		}
//		else if (operate == "申请")
//		{
//			temp->start = 0;
//			cout << "请求大小" << endl;
//			cin >> temp->size;
//
//
//			rd *q = new rd;
//			q->front = NULL;
//			q->next = NULL;
//			q->size = 0;
//			q->flage = 0;
//			q->start = 0;
//			q->name = temp->name;
//
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (!p->flage&&p->size > q->size)
//				{
//					q = p;
//				}
//				p = p->next;
//			}
//
//			if (q->size >= temp->size)
//			{
//				temp->start = q->start + (q->size - temp->size);
//				q->size -= temp->size;
//				cout << temp->start << "  " << q->size <<"  "<<line->size<< endl;
//				if (q->next != NULL)
//				{
//					temp->next = q->next;
//					q->next->front = temp;
//				}
//				else
//				{
//					temp->next = NULL;
//				}
//				temp->front = q;
//				q->next = temp;
//			}
//			else
//			{
//				cout << "申请失败！！！" << endl;
//			}
//			display();
//		}
//		else if (operate == "完成")
//		{
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (p->name == temp->name)
//				{
//					rd *q = new rd;
//					q->flage = 0;
//					q->name = "空";
//					q->start = 0;
//					q->size = maxsize;
//					q->front = NULL;
//					q->next = NULL;
//
//					if (p->front != NULL)
//					{
//						q = p->front;
//						if (p->front->front != NULL) q->front = p->front->front;
//						else q->front = NULL;
//					}
//					if (!q->flage)
//					{
//						q->size += p->size;
//
//						if (p->next != NULL && !p->next->flage)
//						{
//							q->size += p->next->size;
//							if (q->next->next->next != NULL)
//							{
//								q->next->next->next->front = q;
//								q->next = q->next->next->next;
//							}
//							else
//							{
//								q->next = NULL;
//							}
//						}
//						else if (p->next != NULL)
//						{
//							q->next = p->next;
//						}
//						p = q->next;
//					}
//					else if (p->next != NULL && !p->next->flage)
//					{
//						p->size += p->next->size;
//						if (p->next->next != NULL)
//						{
//							p->next->next->front = p;
//							p->next = p->next->next;
//						}
//					}
//					else if(((p->front != NULL && p->front->flage) || (p->front == NULL) &&((p->next != NULL && p->next->flage)||(p->next==NULL))))
//					{
//						p->flage = 0;
//						p->name = "空";
//						if (p->next != NULL)
//						{
//							p->next->front = p->front;
//							p->front->next = p->next;
//						}
//					}
//				}
//				else p = p->next;
//			}
//			display();
//		}
//	}
//}
//
//int  main()
//{
//	cout << "      动态分区式存贮区管理 -- 王爱民      " << endl << endl;
//	cout << "请输入放置策略序号 ①:首次 ②:最佳 ③:最坏" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 1: firstmethod(); break;
//	case 2: bestmethod(); break;
//	case 3: badmethod(); break;
//	default:cout << "请正确输入放置策略序号！！！" << endl; break;
//	}
//	return 0;
//}




