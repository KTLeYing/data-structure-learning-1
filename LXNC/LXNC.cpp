/**
*����1:
**/
////��̬�ڴ����
//#include<stdio.h>
//int temp=0;//����һ��ȫ�ֱ��������������ܴ�����
//typedef struct _BiTNode//���� �� �Ľṹ��
//{
//	int address;//�׵�ַ
//	int length;//����������
//	bool state;//����״̬ ��1����ʾ�ѷ��䣬 ��0����ʾδ����
//	int homework; //��ҵ��
//	struct _BiTNode *lchild;//ָ�����ӵ�ָ��
//	struct _BiTNode *rchild;//�Һ���
//}BiTNode,*pBiTree;
//void Init_BiTree(pBiTree l)
//{
//	l->address = 5;
//	l->length = 507;
//	l->state = 0;
//	l->homework=NULL;
//	l->lchild = NULL;
//	l->rchild = NULL;
//	printf("��ʼ����ɣ�\n");
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
////�������
//void PreOrder(pBiTree p)
//{
//	if(p != NULL)
//    {
//        if(!p->lchild&&!p->rchild)
//        	Print(p);  //����ý��
//	   	PreOrder(p->lchild);  //����������
//        PreOrder(p->rchild); //����������
//    }
//}
//void Insert_PreOrder(pBiTree p,int length,int homework)//��������ҵ
//{
//	if(p != NULL)
//    {
//		if((p->state==0)&&(length<p->length)&&(!p->lchild)&&(!p->rchild)&&temp==0)//�жϽڵ��Ƿ������Һ��ӣ��Ƿ�С�ڿ��������ȣ��Ƿ�״̬Ϊ0����ʾ��������ҵ���У�
//	   	{
//			pBiTree  x1 =new BiTNode;//���в��룬��̬���������ռ� x1,x2
//			pBiTree  x2 =new BiTNode;
//			x1->homework=homework;//x1Ϊ��ҵ
//			x2->homework=NULL;//x2Ϊʣ��Ŀ�����
//		   	x1->address=p->address;//��ԭ���������׵�ַ����ҵ���׵�ַ
//		   	x1->state=1;//��ҵ��״̬��Ϊ1
//		   	x1->length=length;//��ҵ�ĳ���Ϊ����ĳ���
//		   	x2->address=x1->address+length;//�¿��������׵�ַΪ x1�׵�ַ��x1����֮��
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
//			Insert_PreOrder(p->lchild,length,homework);  //����������
//        	Insert_PreOrder(p->rchild,length,homework); //����������
//    	}
//	}
//}
//void Delect_PreOrder(pBiTree p,int homework) //�����޸ģ���״̬�޸�Ϊ0����Ϊ������
//{
//	if(p != NULL)
//    {
//        if(p->homework==homework)//����ѯ����ҵ����ͬ����ҵ�������޸�
//        {
//			p->homework=NULL;//����ҵ���޸�Ϊ��
//			p->state=0;//����ҵ��״̬�޸�Ϊ����
//		}
//	Delect_PreOrder(p->lchild,homework);  //����������
//    Delect_PreOrder(p->rchild,homework); //����������
//    }
//}
//int main()
//{
//	BiTNode l;
//	Init_BiTree(&l);
//	//��ʼ��
//	printf("\n   ��ʼ��:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//
//	PreOrder(&l);
//	//������ҵ1
//	temp=0;
//	Insert_PreOrder(&l,300,1);
//	printf("\n������ҵ1:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//������ҵ2
//	temp=0;
//	Insert_PreOrder(&l,100,2);
//	printf("\n������ҵ2:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//�ͷ���ҵ1
// 	Delect_PreOrder(&l,1);
//    printf("\n�ͷ���ҵ1:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//������ҵ3
//	temp=0;
//	Insert_PreOrder(&l,150,3);
//	printf("\n������ҵ3:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//������ҵ4
//	temp=0;
//	Insert_PreOrder(&l,30,4);
//	printf("\n������ҵ4:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//������ҵ5
//	temp=0;
//	Insert_PreOrder(&l,40,5);
//	printf("\n������ҵ5:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//������ҵ6
//	temp=0;
//	Insert_PreOrder(&l,60,6);
//	printf("\n������ҵ6:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	//�ͷ���ҵ4
//	Delect_PreOrder(&l,4);
//    printf("\n�ͷ���ҵ4:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
//	PreOrder(&l);
//	return 0;
//}


/**
*����2�������ã�
**/
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int pos,n,Size; ///����λ��,��������,��С�ָ��С
struct List
{
    int id;///���з������
    int sad;///���з����׵�ַ
    int rom;///�ռ�
    int state;///״̬��0Ϊ�գ�1Ϊδ����2Ϊ����
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
    printf("|       ������    ����ʼַ    ������С    ����״̬       |\n");
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
    printf("������Ҫ�ͷ�ռ�ÿռ��������ţ�\n");
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
            if(L[j].sad>T[l].sad+T[l].rom)///ʵ���ϴ���T[l].sad�Ϳ���
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
    cout<<"�ڴ������ϣ�"<<endl;
}
void NF()///ѭ���״���Ӧ�㷨
{
    cout<<"ѡ�����'ѭ���״���Ӧ�㷨'�����ڴ����\n"<<endl;
    int tmp;
    pos=1;///��ʼ�ӵ�һ����������
    while(1)
    {
        cout<<"      *******************************************"<<endl;
        cout<<"      1: �����ڴ�             2: �����ڴ�        "<<endl;
        cout<<endl;
        cout<<"      3: �鿴���з�����       0: �˳�       "<<endl;
        cout<<"      *******************************************"<<endl;
        cout<<"���������Ĳ��� ��";
        cin>>tmp;
        int k=0;
        if(tmp==1)
        {
            k++;
            printf("�������%d����ҵռ�ÿռ��С��\n",k);
            cin>>T[k].rom;
            T[k].id=k;
            int num=0;
            for(int i=pos;; i++)
            {
                num++;
                if(num>n)
                {
                    printf("��ҵ�����ڴ�ռ���󣬿��з�����������Ҫ���ڴ����ʧ��!\n");
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
                        printf("�ڴ����ɹ���\n��ҵ����ռ�Ϊ%d\n��ʼ��ַΪ%d\n",T[k].rom,T[k].sad);
                        break;
                    }
                    else
                    {
                        L[i].sad=L[i].sad+Size;
                        L[i].rom=L[i].rom-Size;
                        L[i].state=2;
                        T[k].sad=L[i].sad-Size;
                        printf("�ڴ����ɹ���\n��ҵ����ռ�Ϊ%d\n��ʼ��ַΪ%d\n",L[i].rom,T[k].sad);
                        break;
                    }
                }
                else if(L[i].state=0&&L[i].rom-T[k].rom==Size)
                {
                    L[i].state=2;
                    T[k].sad=L[i].sad;
                    printf("�ڴ����ɹ���\n��ҵ����ռ�Ϊ%d\n��ʼ��ַΪ%d\n",T[k].rom,T[k].sad);
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
            printf("�����������������룡\n");
            continue;
        }
    }
}
void BF()///�����Ӧ�㷨
{
    cout<<"ѡ�����'�����Ӧ�㷨'�����ڴ����\n"<<endl;
    sort(L+1,L+n+1,cmp);
    int tmp;
    while(1)
    {
        cout<<"      *******************************************"<<endl;
        cout<<"      1: �����ڴ�             2: �����ڴ�        "<<endl;
        cout<<endl;
        cout<<"      3: �鿴���з�����       0: �˳�       "<<endl;
        cout<<"      *******************************************"<<endl;
        cout<<"���������Ĳ��� ��";
        cin>>tmp;
        int k=0;
        if(tmp==1)
        {
            k++;
            printf("�������%d����ҵռ�ÿռ��С��\n",k);
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
                        printf("�ڴ����ɹ���\n��ҵ����ռ�Ϊ%d\n��ʼ��ַΪ%d\n",T[k].rom,T[k].sad);
                        break;
                    }
                    else
                    {
                        L[i].sad=L[i].sad+Size;
                        L[i].rom=L[i].rom-Size;
                        L[i].state=2;
                        T[k].sad=L[i].sad-Size;
                        printf("�ڴ����ɹ���\n��ҵ����ռ�Ϊ%d\n��ʼ��ַΪ%d\n",L[i].rom,T[k].sad);
                        break;
                    }
                }
                else if(L[i].state=0&&L[i].rom-T[k].rom==Size)
                {
                    L[i].state=2;
                    T[k].sad=L[i].sad;
                    printf("�ڴ����ɹ���\n��ҵ����ռ�Ϊ%d\n��ʼ��ַΪ%d\n",T[k].rom,T[k].sad);
                    break;
                }
            }
            if(i>n)
            {
                printf("��ҵ�����ڴ�ռ���󣬿��з�����������Ҫ���ڴ����ʧ��!\n");
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
            printf("�����������������룡\n");
            continue;
        }
    }
}
void init()
{
loop1:
    pos=1;
    printf("��������з��������������\n");
    cin>>n;
    printf("������ÿ�����з����ķ�����С������ʼַ\n");
    for(int i=1; i<=n; i++)
    {
        printf("�������%d����������Ϣ��\n",i);
        cin>>L[i].rom>>L[i].sad;
        L[i].id=i;
        L[i].state=0;
    }
    printf("������ϣ���ǰ���з�����״̬Ϊ��\n");
    print();
    printf("�����벻���и��ʣ��ռ�Ĵ�С��\n");
    cin>>Size;
loop2:
    printf("ѡ���ڴ������㷨��1.ѭ���״���Ӧ�㷨  2.�����Ӧ�㷨  3.���±༭���з�����  4.�˳� \n");
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
        printf("������������������!\n");
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
*����3�������ã�
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
//	line->name = "��";
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
//	cout << "����������������С:  " << endl;
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
//		cout << "�������ƣ� shutdown Ϊ������ʶ�� ��" << endl;
//		cin >> temp->name;
//		cout << "�������ͣ� ����  ��� ��" << endl;
//		cin >> operate;
//		if (operate == "shutdown")
//		{
//			cout << "�˴��״���Ӧ�㷨���������" << endl;
//			return;
//		}
//		else if (operate == "����")
//		{
//			temp->start = 0;
//			cout << "�����С" << endl;
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
//		else if (operate == "���")
//		{
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (p->name == temp->name)
//				{
// 					rd *q = new rd;
//					q->flage = 0;
//					q->name = "��";
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
//						p->name = "��";
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
//	cout << "����������������С:  " << endl;
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
//		cout << "�������ƣ� shutdown Ϊ������ʶ�� ��" << endl;
//		cin >> temp->name;
//		cout << "�������ͣ� ����  ��� ��" << endl;
//		cin >> operate;
//		if (operate == "shutdown")
//		{
//			cout << "�˴��״���Ӧ�㷨���������" << endl;
//			return;
//		}
//		else if (operate == "����")
//		{
//			temp->start = 0;
//			cout << "�����С" << endl;
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
//				cout << "����ʧ�ܣ�����" << endl;
//			}
//			display();
//		}
//		else if (operate == "���")
//		{
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (p->name == temp->name)
//				{
//					rd *q = new rd;
//					q->flage = 0;
//					q->name = "��";
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
//						p->name = "��";
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
//	cout << "����������������С:  " << endl;
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
//		cout << "�������ƣ� shutdown Ϊ������ʶ�� ��" << endl;
//		cin >> temp->name;
//		cout << "�������ͣ� ����  ��� ��" << endl;
//		cin >> operate;
//		if (operate == "shutdown")
//		{
//			cout << "�˴��״���Ӧ�㷨���������" << endl;
//			return;
//		}
//		else if (operate == "����")
//		{
//			temp->start = 0;
//			cout << "�����С" << endl;
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
//				cout << "����ʧ�ܣ�����" << endl;
//			}
//			display();
//		}
//		else if (operate == "���")
//		{
//			rd *p = new rd;
//			p = line;
//			while (p != NULL)
//			{
//				if (p->name == temp->name)
//				{
//					rd *q = new rd;
//					q->flage = 0;
//					q->name = "��";
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
//						p->name = "��";
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
//	cout << "      ��̬����ʽ���������� -- ������      " << endl << endl;
//	cout << "��������ò������ ��:�״� ��:��� ��:�" << endl;
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 1: firstmethod(); break;
//	case 2: bestmethod(); break;
//	case 3: badmethod(); break;
//	default:cout << "����ȷ������ò�����ţ�����" << endl; break;
//	}
//	return 0;
//}




