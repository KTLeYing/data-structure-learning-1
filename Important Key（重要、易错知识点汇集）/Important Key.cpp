һ�����õ�˳���Ľṹ���塢��ʼ�������������������
(1)��һ�����ڲ��ҡ������㷨��
typedef struct
{
    int key;
    int other;
}ElemType;

typedef struct
{
   ElemType *data;  
   int length;
}SqList;

int InitList(SqList &L)
{                               //��L�з�װ��dataָ�루��ַ������Ϊ����data[],�ͱ�ĳ���
   L.data=new ElemType[MAX];   //dataָ��ElemType��һ�����飬����dataҲ��һ�����飬����ʾΪ("data[]"),data�����������׵�ַ��Ȼ��ElemType��һ���Զ�����������;
   if(!L.data)                //ElemType���ְ�����int��key�����ݡ��ؼ��֣���int���������ݣ�����ʾΪ("L.data[].key")
      exit(OVERFLOW);          //����Ƕ�ף���SqList L������װ���ݵ�data���飬data���飨��Ϊ����ElemType����ÿ��Ԫ���а�����key�ؼ��֣���������֣�
   L.length=0;
}

int CreatList(SqList &L)
{
    int i,n;
    cout<<"�������ݵ�����:";
    cin>>n;
    cout<<"����������:";
    for(i=1;i<=n;i++)
    {
        cin>>L.data[i].key;
        L.length++;
    }
}

int main()
{
      SqList L;
	  InitList(L);
      CreatList(L);
}



(2)����(1)���ƣ���key��
typedef struct
{
  int key;
  char *otherinfo;
}ElemType;
//˳���Ĵ洢�ṹ
typedef struct
{
    ElemType *r;                //�洢�ռ�Ļ���ַ
    int  length;                  //˳�����
}SqList;           //˳�������


void Create_Sq(SqList &L)
{
  int i,n;
  cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
  cin>>n;           //�������
  cout<<"����������������:\n";
 while(n>MAXSIZE)
 {
   cout<<"�����������ޣ����ܳ���"<<MAXSIZE<<"������������"<<endl;
   cin>>n;
 }
 for(i=1;i<=n;i++)
 {
   cin>>L.r[i].key;
   L.length++;
 }

  int main()
  {
   SqList L;
   L.r=new ElemType[MAXSIZE+1];
   L.length=0;
    Create_Sq(L);
}


(3)����(2)���ƣ����˶���InitList�����Ĳ��衿
typedef struct
{
  int key;
  char *otherinfo;
}ElemType;
//˳���Ĵ洢�ṹ
typedef struct
{
    ElemType *r;                //�洢�ռ�Ļ���ַ
    int  length;                  //˳�����
}SqList;           //˳�������


void Create_Sq(SqList &L)
{
  L.r=new ElemType[MAXSIZE+1];
   L.length=0;
   int i,n;
  cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
  cin>>n;           //�������
  cout<<"����������������:\n";
 while(n>MAXSIZE)
 {
   cout<<"�����������ޣ����ܳ���"<<MAXSIZE<<"������������"<<endl;
   cin>>n;
 }
 for(i=1;i<=n;i++)
 {
   cin>>L.r[i].key;
   L.length++;
 }

  int main()
  {
   SqList L;
    Create_Sq(L);
}



(4)��һ��ģ���key��һ�����뱣���������ڱ��У���forѭ������һ��������ͨ�����Ա�洢��
Typedef int ElemType;
Typedef struct
{
   ElemType *data;    //SqList��װ��data���飨data[]���ͳ��ȣ�dataָ��==���飬*data==data[];ָ���׵�ַ
   int length;
}SqList;

int InitList(SqList &L)
{
   L.data=new ElemType[MAX];      //dataָ��ElemType�������͵�������׵�ַ����data[]Ϊһ�����飬����data����ҲΪElemType���������ͣ��˴�����һ�����MAX�ĳ���
   if(!L.data)                    //�����飬Ȼ��ElemTypeҲ������Ϊint����
      exit(OVERFLOW);
   L.length=0;
}

int CreatList(SqList &L)
{
    int j;
    if(i<1 || i>L.length+1)
        return ERROR;
    for(j=L.length;j>=i-1;j--)
        L.data[j+1]=L.data[j];
    L.data[i-1]=x;
    ++L.length;
}

int main()
{
    SqList L;
	ElemType e;
    CreatList(L);
	InitList(L)
}

(5)���루4�����ƣ�����һ�α���һ�������ڱ��С�
typedef char ElemType;

typedef struct
{
   ElemType *data;
   int length;
}SqList;

int InitList(SqList &L)
{
   L.data=new ElemType[MAX];
   if(!L.data)
      exit(OVERFLOW);
   L.length=0;
}

int CreatList(SqList &L,ElemType x,int i)
{
    int j;
    if(i<1 || i>L.length+1)
        return ERROR;
    for(j=L.length;j>=i-1;j--)
        L.data[j+1]=L.data[j];
    L.data[i-1]=x;
    ++L.length;
}

int main()
{
    SqList L;
    ElemType e;
    cout<<"(1)��ʼ��˳���"<<endl;
    InitList(L);
    cout<<"(2)һ����β�巨����a,b,c,d,eԪ��"<<endl;
    CreatLis(L,'a',1);
    CreatLis(L,'b',2);
    CreatLis(L,'c',3);
    CreatLis(L,'d',4);
    CreatLis(L,'e',5);
}



����C++��C���Ե��ַ������ַ����飩����������
(1)C++:
��
char str[20];                            //PS:����ʽֻ�������ַ����ͣ��ַ����飬������������int
cin>>str; //���ַ������������ַ���
cout<<str; //���ַ�����������ַ���

����������һ���ַ������磺China
���ڴ��У�����str��״̬��ͼ5.9��ʾ����5���ַ��ĺ����Զ�����һ��������'\0'��
���ʱ���������ַ�ֱ������������\0�䣬��ֹͣ�����������Ϊ��China
��
// char str[5] = "hello";//����ʧ�ܡ���ʾ�ַ���̫��
char str[] = { '1', '2', '3', '4' }; //���Ա���ͨ��, ���Ǵ�ӡֱ������\0�Ž���
cout << str << " " << sizeof(str) << endl;

��ӡ���: 12340@ 4
str �ĳ���Ϊ 4
���Ǵ�ӡ��ʱ�������⣬֪������\0�Ż����
��
char str[] = "hello world";
cout << str << " " << sizeof(str) << endl;
cout << "������һ���ַ���" << endl;
4 cin >> str;  // 123 hello worl
cout << "str��ֵΪ " << str << endl; //str��ֵΪ heelo (������һ��[�ո��Ʊ�������з�]����������)
cin.getline(str, 20); //�������19���ַ�, ���һ���ַ���\0  ����str����ĳ���Ϊ12,
cout << "str��ֵΪ" << str << " " << sizeof(str) << endl;

str�ĳ���Ϊ12 ĩβ�Զ���һ���հ׷�\0
�ڵ��������� 123 hello world
Ȼ��str��ֵΪ 123
Ȼ�����cin.getLine 
str=" hello worl" ע��helloǰ��Ŀո�һ�����뵽str���ˡ����ʱ�� str�ĳ����Ѿ�Ϊ12�ˡ�����ڽ�����������ַ������������쳣

(2)C����:
��scanf���룬printf���:
scanf���ַ�����������%s��%c���ָ�ʽ��%c��ʽ�������뵥���ַ������ܹ�ʶ��ո�ͻ��з������䱣�浽�ַ������У�%s��ʽ��������һ���ַ�������ͨ���ո�ͻ�����ʶ��һ���ַ����Ľ�����Ҳ����˵ʹ��%s��ʽ���벢���浽�ַ������е��ַ����ǲ����ո�ġ�������һ��ʵ����

#include <stdio.h>
int main(){
    char str[10];
    scanf("%s", str);
    printf("%s", str);
    return 0;
}

�����ַ�����abc def ghi��������Ľ��Ϊ��abc�������Կ�����%sʶ��ո���Ϊ�ַ����Ľ�β����˵�һ���ո������ַ������ᱻ���롣
��getchar���룬putchar���:
getchar��putchar�ֱ������������������ַ���getchar����ʶ���з��Ϳո񲢽��䱣�档������һ�����ӣ�

#include <stdio.h>
int main(){
    char c1, c2, c3;
    c1 = getchar();     //getcharֻ�����뵥���ַ� 
    c2 = getchar();
    c3 = getchar();		    
    putchar(c1);
    putchar(c2);
    putchar(c3);
    return 0;
}

����������������롰a����Ȼ���ûس���Ȼ�����롱bc�������ûس�������Ľ������������a b
��������getchar����ʶ���з�������c2ʵ���ϴ洢���ǻ��з�������ַ�cû�б����룬�ַ�ab֮�����һ�����г��֡�

��gets���룬puts���:
gets��������һ���ַ�������������һά���飨���ά�����һά���У���ȡ�ַ���ֱ�����з������������з��ᱻ������Ȼ����ĩβ��ӡ�\0��������scanf(��%s��, s)���ƣ�������ȫ��ͬ��gets��ʶ��ո񲢽������롣puts�������Զ����С�������һ������:

#include <stdio.h>
int main(){
    char str1[20];
    char str2[5][10];
    gets(str1);
    for(int i = 0; i < 3; i ++){
        gets(str2[i]);
    }
    puts(str1);
    for(int i = 0; i < 3; i ++){
        puts(str2[i]);
    }
    return 0;
}

�������漸���ַ�����
abc def
QAQ
T_T
WoAiNi



�������������������������㷨

(1)һ������ַ����������:
while((ch=getchar())!='\n')
{

}
��(2)
while(cin>>a)
{

}
//����
#include <iostream>
using namespace std;
int main()
{
    for(int i;cin>>i;)
    {
        cout << i << endl;
    }
    return 0;
}

(3)
��while(1)
{
	......
	if(a == -1 && b == -1) //�˳����Ե�����
		break;
}
(4)��forѭ��:
for(i=1;i<n;i++)
{
}
��(5)
while(scanf("%d",&n)!=EOF,n)     
{
}
//����д��
while(scanf("%d",&n)!=EOF)     //��Ϊwhile((cin>>n)!=EOF)�ǲ����Եģ��˴�������cin�����⣩
{
	.....
    if(n==0)
		break;
}
//Ȼ����ѭ�����һ��if(n==0)break;
//����
int main()
{
    char a[3],t;
    int i,j;
    while(scanf(" %c %c %c",&a[0],&a[1],&a[2])!=EOF)//��������Ԫ��ǰӦ�ü�&
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2 - i; j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }
    printf("%c %c %c\n", a[0], a[1], a[2]);
 
    }
	return 0;
}
��(6)
int main()
{
   int a,b;
   while( scanf("%d%d",&a��&b )!= EOF ) //����ֱ���ļ�������������EOFʱ����������
   {
        printf("%d\n\n",a+b ); //һ��һ�����������������һ���س�
   }
   return 0;
}
��(7)
int main()
{
    int n,sum;
    while( scanf( "%d" , &n ) != EOF ) //������ļ���β
	{
        int x;
        sum = 0;
        while( n-- ) //���Ƹ����������
		{
           scanf( "%d" , &x );
           sum += x;
		}
        printf( "%d\n" , sum ); //һ��һ�����
	}
     return 0;
}
(8)
while( scanf( "%d%d" , &a , &b ) && (a||b) ) //����ֱ������a��b��Ϊ0����
{
    printf( "%d\n" , a+b ); //һ��һ�����
}
//����(ԭ��һ��)
int main()
{
   int n,sum;
   while( scanf( "%d" , &n ) && n ) //ÿ��caseǰ��һ�����Ƹ����������ݵ�����Ϊ0����
   {
       int x;
       sum = 0;
       while( n-- ) //���Ƹ����������
	   {
           scanf( "%d" , &x );
           sum += x;
	   }
       printf( "%d\n" , sum ); //һ��һ�����
   }
   return 0;
}
��(9)
while(scanf("%d",&n)==1)  //Ϊ��
{
   if(n==0)     //�˳����Ե�����
	   break;
   sum=0;      //��ͨ���Դ���
   for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
     sum+=a[i];
     if(i==n-1)
       printf("%d\n",sum);
   }
}
(10)
int main()
{
   char buf[100000]={0};//�����������
   char buf0[10];//�м�������
   int a=1,b=1,c;//��ʼ��������ȫ0�Ϳ���

   while(a||b)   //�������ж�����Ե�����(��a��b����Ϊ����ʱ)
   {
      scanf("%d%d",&a,&b);//��ȡ��������,���ڱ���a��b��
      fflush(stdin);//��ռ������뻺���� ��֤һ�����ȡ������ ����Ļ����������ֵı�����
      sprintf(buf0,"%d\n",a+b);//���a+b����ӻس���\n �浽��buf0
      if(a||b)//���������һ����
          strcat(buf,buf0);//׷�ӵ��������������
   }
   printf("\n%s",buf);//������ս��
}


(11)��ACM���á�:����
����C++д:
#include <iostream>
using namespace std;
int a,b;
while(cin>>a>>b)
{
    cout<<a+b<<endl;
}
//����(����һ������)
while(cin>>a)
{
    cout<<a<<endl;
}
����Cд:                           
#include <stdio.h>
int a,b;                                   //����EOF�Ľ���:������scanf���뺯���С�
while(scanf("%d%d",&a,&b)!=EOF)            //ʹ��istream������Ϊѭ�����ж��������������״̬�����������Ч�ģ�����δ����������ô���ɹ���
{ //��Ϊwhile((cin>>n)!=EOF)�ǲ����Եģ�  //�������ļ���������EOF����������һ����Ч����ʱistream�����״̬�ͻ��Ϊ��Ч��������Ч״̬��istream�����ʹ�������
	//�˴�������cin�����⣩               //��C���Եĵķ����������������Ϊwhileѭ�����ж����������������ݲ����ļ���������EOF����ʱ�򣬾Ϳ���ʵ����������      
    printf("%d+%d\n",a+b);                                 
}  
//����
while(~scanf("%d", &n))
{
    /*
     *code
    */
}                               




�ġ������ַ���(string)���ַ�������

C++�ṩ��һ���µ��������͡����ַ�������(string����),��ʹ�÷�����,����char?int����һ��,���������������,������ַ�������������һ�����ִ���һ���ַ�����

ʵ����,string������C++���Ա�����еĻ�������,������C++��׼����������һ���ַ�����,����������Զ������?ÿһ���ַ�����������string���һ������

(1)�ַ��������Ķ��������
1. �����ַ�������
���������ͱ���һ��,�ַ������������ȶ����ʹ��,�����ַ�������Ҫ������string
��:
string string1; //����string1Ϊ�ַ�������
string string2=��China��; //����string2ͬʱ�����ʼ��
Ӧ��ע��: Ҫʹ��string��Ĺ���ʱ,�����ڱ��ļ��Ŀ�ͷ��C++��׼���е�stringͷ�ļ���������,��Ӧ����
#include <string> //ע��ͷ�ļ�������string.h

2. ���ַ��������ĸ�ֵ
�ڶ������ַ���������,�����ø�ֵ����������һ���ַ�������,��
string1=��Canada��;
�ȿ������ַ����������ַ���������ֵ,Ҳ������һ���ַ�����������һ���ַ���������ֵ?��
string2=string1; //����string2��string1���Ѷ���Ϊ�ַ�������
��Ҫ��string2��string1������ͬ,����string2ԭ���ǡ�China��,string1ԭ���ǡ�Canada��,��ֵ��string2Ҳ��ɡ�Canada��?�ڶ����ַ�������ʱ����ָ������,
���������е��ַ������ȶ��ı�

���Զ��ַ���������ĳһ�ַ����в���,��
string word=��Then��; //���岢��ʼ���ַ�������word
word[2]=��a��; //�޸����Ϊ2���ַ�,�޸ĺ�word��ֵΪ��Than��

3. �ַ����������������
���������������������ַ���������,��������ַ���,��
cin>> string1; //�Ӽ�������һ���ַ������ַ�������string1
cout<< string2; //���ַ���string2���

 

(2)�ַ�������������
����һ���п��Կ���: �����ַ��������ַ���ʱ,�ַ���������Ҫ���ַ�������,��strcat(����) strcmp(�Ƚ�) strcpy(����),����string�����,���Բ�����Щ����,
��ֱ���ü򵥵������

 

�ַ��������ø�ֵ��
string1=string2;
�������롰strcpy(string1,string2);����ͬ
�ַ��������üӺ�
string string1=��C++��; //����string1������ֵ
string string2=��Language��;//����string2������ֵ
string1=string1 + string2;//����string1��string2
���Ӻ�string1Ϊ��C++ Language��
�ַ����Ƚ�ֱ���ù�ϵ�����
����ֱ���� ==(����)>(����)<(С��)!=(������)>=(���ڻ����)<=(С�ڻ����)�ȹ�ϵ������������ַ����ıȽ�
ʹ����Щ�������ʹ��5.5.5���н��ܵ��ַ�������ֱ�۶�����?
 

(3)�ַ�������
����������string�����ַ�������,Ҳ������string�����ַ�������
��:
string name[5]; //����һ���ַ�������,������5���ַ���Ԫ��
string name[5]={��Zhang��,��Li��,��Fun��,��Wang��,��Tan��};
//����һ���ַ������鲢��ʼ��


�����ַ�������ļ���˵����

��һ���ַ��������а������ɸ�(��Ϊ5��)Ԫ��,ÿ��Ԫ���൱��һ���ַ�������
����Ҫ��ÿ���ַ���Ԫ�ؾ�����ͬ�ĳ���,��ʹ��ͬһ��Ԫ�ض���,���ĳ���Ҳ�ǿ��Ա仯��,����ĳһ��Ԫ�����¸�ֵ,�䳤�ȾͿ��ܷ����仯
���ַ��������ÿһ��Ԫ���д��һ���ַ���,������һ���ַ�,�����ַ����������ַ����������?������ַ��������ַ���,һ��Ԫ��ֻ�ܴ��һ���ַ�,
��һ��һά�ַ�������һ���ַ���

ÿһ���ַ���Ԫ����ֻ�����ַ���������ַ�����������\0��

�ɼ����ַ����������ַ����Լ����ַ������д����Ǻܷ����?

�ڶ����ַ�������ʱ�������������洢�ռ���?ʵ����,����ϵͳΪÿһ���ַ�����������4���ֽ�,������洢��Ԫ��,������ֱ�Ӵ���ַ�������,
���Ǵ���ַ����ĵ�ַ,�ڱ�����,���ǰ��ַ�����Zhang��ĵ�ַ�����name[0],���ַ�����Li�� �ĵ�ַ�����name[1],���ַ�����Fun��ĵ�ַ�����name[2]

(4)�ַ������Ӻ��� strcat
�亯��ԭ��Ϊ
strcat(char[],const char[]);
strcat��string catenate(�ַ�������)����д?�ú����������ַ�����Ĳ���,������������:���ڶ����ַ������е��ַ������ӵ�ǰ���ַ�������ַ����ĺ���,
�ڶ����ַ����鱻ָ��Ϊconst,�Ա�֤�������е����ݲ����ں��������ڼ��޸�?���Ӻ���ַ������ڵ�һ���ַ�������,�������ú�õ��ĺ���ֵ,���ǵ�һ���ַ�����ĵ�ַ
����:
char str1[30]="People" s Republic of ��;
char str2[]="China";
cout<<strcat(str1,str2));//����strcat����
���:
People" s Republic of China


(5)�ַ������ƺ���strcpy
�亯��ԭ��Ϊ
strcpy(char[],const char[]);
strcpy��string copy(�ַ�������)����д?���������ǽ��ڶ����ַ������е��ַ������Ƶ���һ���ַ�������ȥ,����һ���ַ������е���Ӧ�ַ�����?����
char str1[10],str2[]=��China��;
strcpy(str1,str2);
ִ�к�,str2�е�5���ַ���China��͡�\0��(��6���ַ�)���Ƶ�����str1��

�����ַ������ƺ���strcpy�ļ���˵����

�ڵ���strcpy����ʱ,��һ������������������(��str1),�ڶ��������������ַ�������,Ҳ������һ���ַ�������?
������strcpy������һ���ַ�����ǰ���ɸ��ַ����Ƶ��ַ�������ȥ?
ֻ��ͨ������strcpy������ʵ�ֽ�һ���ַ�������һ���ַ�����,�������ø�ֵ��佫һ���ַ����������ַ�����ֱ�Ӹ���һ���ַ�����
 

(6)�ַ����ȽϺ���strcmp
�亯��ԭ��Ϊ
strcmp(const char[],const char[]);
strcmp��string compare(�ַ����Ƚ�)����д�����ǱȽ������ַ���,�����������ַ�����ֻ�μӱȽ϶���Ӧ�ı�������,�����������������const����,����д���ǺϷ���:
strcmp(str1,str2);            // =0,��str1=str2;  >0,��str1>str2;  <0,��str1<str2
strcmp("China","Korea");
strcmp(str1,"Beijing");

�ȽϵĽ���ɺ���ֵ����:
����ַ���1=�ַ���2,����ֵΪ0
����ַ���1>�ַ���2,����ֵΪһ������
����ַ���1<�ַ���2,����ֵΪһ������

�ַ����ȽϵĹ��������������еĹ�����ͬ,���������ַ���������������ַ����(��ASCII��ֵ��С�Ƚ�),ֱ�����ֲ�ͬ���ַ���������\0��Ϊֹ?��ȫ���ַ���ͬ,����Ϊ���;
�����ֲ���ͬ���ַ�,���Ե�һ������ͬ���ַ��ıȽϽ��Ϊ׼

ע��:�������ַ����Ƚ�,������������ʽ:
if(str1>str2) cout<<��yes��;
�ַ�������str1��str2���������ַ,����д����ʾ�����������ַ���бȽ�,�����Ƕ������е��ַ������бȽ�,�������ַ����Ƚ�Ӧ���� 
if(strcmp(str1,str2)>0) cout<<��yes��;

 

(7)�ַ������Ⱥ���strlen
����ԭ��Ϊ:
strlen(const char[]);
strlen��string length(�ַ�������)����д?���ǲ����ַ������ȵĺ���?�亯����ֵΪ�ַ����е�ʵ�ʳ���,��������\0������
��:
char str[10]="China";
cout<<strlen(str);
����������10,Ҳ����6,����5




�塢С�˺ʹ��ģʽ:

 ��1��ʲô�Ǵ�˺�С��
 Big-Endian��Little-Endian�Ķ������£�
   1.Little-Endian���ǵ�λ�ֽ��ŷ����ڴ�ĵ͵�ַ�ˣ���λ�ֽ��ŷ����ڴ�ĸߵ�ַ�ˡ�
   2.Big-Endian���Ǹ�λ�ֽ��ŷ����ڴ�ĵ͵�ַ�ˣ���λ�ֽ��ŷ����ڴ�ĸߵ�ַ�ˡ�
��һ�����ӣ���������0x12 34 56 78���ڴ��еı�ʾ��ʽΪ��
1)���ģʽ��

�͵�ַ -----------------> �ߵ�ַ
0x12 ?| ?0x34 ?| ?0x56 ?| ?0x78
2)С��ģʽ��

�͵�ַ ------------------> �ߵ�ַ
0x78 ?| ?0x56 ?| ?0x34 ?| ?0x12
�ɼ������ģʽ���ַ����Ĵ洢ģʽ���ơ�

3.�����������������ӣ�

16bit�����0x1234��Little-endianģʽ���Լ�Big-endianģʽ��CPU�ڴ��еĴ�ŷ�ʽ������ӵ�ַ0x4000��ʼ��ţ�Ϊ��

�ڴ��ַ	С��ģʽ�������	���ģʽ�������
0x4000	0x34	0x12
0x4001	0x12	0x34
32bit�����0x12345678��Little-endianģʽ�Լ�Big-endianģʽ��CPU�ڴ��еĴ�ŷ�ʽ������ӵ�ַ0x4000��ʼ��ţ�Ϊ��

�ڴ��ַ	С��ģʽ�������	���ģʽ�������
0x4000	0x78	0x12
0x4001	0x56	0x34
0x4002	0x34	0x56
0x4003	0x12	0x78

 4.���С��û��˭��˭�ӣ��������Ʊ��ǶԷ����ƣ�

С��ģʽ ��ǿ��ת�����ݲ���Ҫ�����ֽ����ݣ�1��2��4�ֽڵĴ洢��ʽһ����
���ģʽ ������λ���ж��̶�Ϊ��һ���ֽڣ������ж�������

(2)�����ڴ��С������µĴ洢��
������unsigned int value = 0x12345678Ϊ�����ֱ𿴿��������ֽ�������洢��������ǿ�����unsigned char buf[4]����ʾvalue��
����Big-Endian: �͵�ַ��Ÿ�λ�����£�
�ߵ�ַ
 ---------------
 buf[3] (0x78) -- ��λ
 buf[2] (0x56)
 buf[1] (0x34)
 buf[0] (0x12) -- ��λ
 ---------------
 �͵�ַ
Little-Endian: �͵�ַ��ŵ�λ�����£�
�ߵ�ַ
 ---------------
 buf[3] (0x12) -- ��λ
 buf[2] (0x34)
 buf[1] (0x56)
 buf[0] (0x78) -- ��λ
 --------------
�͵�ַ


(3).Ϊʲô���д�С��ģʽ֮����
   ������Ϊ�ڼ����ϵͳ�У����������ֽ�Ϊ��λ�ģ�ÿ����ַ��Ԫ����Ӧ��һ���ֽڣ�һ���ֽ�Ϊ8bit��������C�����г���8bit��char֮�⣬����16bit��short�ͣ�32bit��long�ͣ�Ҫ������ı������������⣬����λ������8λ�Ĵ�����������16λ����32λ�Ĵ����������ڼĴ�����ȴ���һ���ֽڣ���ô��Ȼ������һ�����������ֽڰ��ŵ����⡣��˾͵����˴�˴洢ģʽ��С�˴洢ģʽ������һ��16bit��short��x�����ڴ��еĵ�ַΪ0x0010��x��ֵΪ0x1122����ô0x11Ϊ���ֽڣ�0x22Ϊ���ֽڡ����ڴ��ģʽ���ͽ�0x11���ڵ͵�ַ�У���0x0010�У�0x22���ڸߵ�ַ�У���0x0011�С�С��ģʽ���պ��෴�����ǳ��õ�X86�ṹ��С��ģʽ����KEIL C51��Ϊ���ģʽ���ܶ��ARM��DSP��ΪС��ģʽ����ЩARM��������������Ӳ����ѡ���Ǵ��ģʽ����С��ģʽ��

(4).����жϻ������ֽ���
���Ա�дһ��С�Ĳ��Գ������жϻ������ֽ���
BOOL IsBigEndian()
{
	int a = 0x1234;
	char b =  *(char *)&a;  //ͨ����intǿ������ת����char���ֽڣ�ͨ���ж���ʼ�洢λ�á������� ȡb����a�ĵ͵�ַ����
	if( b == 0x12)
	{
		return TRUE;
	}
	return FALSE;
}
������union�Ĵ��˳�������г�Ա���ӵ͵�ַ��ʼ��ţ����ø����Կ������ɵػ����CPU���ڴ����Little-endian����Big-endianģʽ��д��
BOOL IsBigEndian()
{
	union NUM
	{
		int a;
		char b;
	}num;
	num.a = 0x1234;
	if( num.b == 0x12 )
	{
		return TRUE;
	}
	return FALSE;

 (5).�������ֽ���
һ�����ϵͳ����С�ˣ���ͨѶЭ���Ǵ�˵ġ�
 1. ����CPU���ֽ���
Big Endian : PowerPC��IBM��Sun
Little Endian : x86��DEC
ARM�ȿ��Թ����ڴ��ģʽ��Ҳ���Թ�����С��ģʽ��

 2. �����ļ����ֽ���
Adobe PS �C Big Endian
BMP �C Little Endian
DXF(AutoCAD) �C Variable
GIF �C Little Endian
JPEG �C Big Endian
MacPaint �C Big Endian
RTF �C Little Endian

(6).��ν���ת��
���������ݣ�16λ����
#define BigtoLittle16(A)   (( ((uint16)(A) & 0xff00) >> 8)    ||
                                       (( (uint16)(A) & 0x00ff) << 8))
����˫�����ݣ�32λ����


#define BigtoLittle32(A)   ((( (uint32)(A) & 0xff000000) >> 24) ||
                                       (( (uint32)(A) & 0x00ff0000) >> 8)   ||
                                       (( (uint32)(A) & 0x0000ff00) << 8)   ||
                                       (( (uint32)(A) & 0x000000ff) << 24))

eg1:(���ӵ�ͼʵѵ�õ�)
 #define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //��ת�����ε�16λ������
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//��ת�����͵�16������

#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //��ȡ�Ƿ��е�·����
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //��ȡ��֧��
#define GET_DISPCLASS(__data__) (__data__&0x0f)                //��ȡ�����

(7)��������ĽǶ�����ģʽ
 ������ĽǶ��ϣ���ͬ��ģʽ�Ĵ������������ݴ���ʱ����Ҫ���Ƕ�ģʽ�Ĳ�ͬ��������������ݴ���ʱ������Ҫ���Ƕ�ģʽ��ת������Socket�ӿڱ���У����¼����������ڴ�С���ֽ����ת����
#define ntohs(n)     //16λ�������������ֽ�˳�������ֽ�˳���ת��
#define htons(n)     //16λ�������������ֽ�˳�������ֽ�˳���ת��
#define ntohl(n)      //32λ�������������ֽ�˳�������ֽ�˳���ת��
#define htonl(n)      //32λ�������������ֽ�˳�������ֽ�˳���ת��

���л�����ʹ�õ������ֽ�˳����ô��ģʽ���б�ַ���������ֽ�˳����ݴ������Ĳ�ͬ����ͬ����PowerPC������ʹ�ô��ģʽ����Pentuim������ʹ��С��ģʽ��
���ģʽ���������ֽ��������ֽ�����Ҫת������ʱntohs(n)=n��ntohl = n����С��ģʽ���������ֽ��������ֽڱ���Ҫ����ת������ʱntohs(n) = __swab16(n)��ntohl = __swab32(n)��__swab16��__swab32��������������ʾ��
#define ___swab16(x)
{
            __u16 __x = (x);
            ((__u16)(
                        (((__u16)(__x) & (__u16)0x00ffU) << 8) |
                        (((__u16)(__x) & (__u16)0xff00U) >> 8) ));
}
 
 
#define ___swab32(x)
{
            __u32 __x = (x);
            ((__u32)(
                        (((__u32)(__x) & (__u32)0x000000ffUL) << 24) |
                        (((__u32)(__x) & (__u32)0x0000ff00UL) << 8) |
                        (((__u32)(__x) & (__u32)0x00ff0000UL) >> 8) |
                        (((__u32)(__x) & (__u32)0xff000000UL) >> 24) ));
}
 PowerPC�������ṩ��lwbrx��lhbrx��stwbrx��sthbrx����ָ�����ڴ����ֽ����ת�����Ż�__swab16��__swap32���ຯ��������PowerPC�������е�rlwimiָ��Ҳ��������ʵ��__swab16��__swap32���ຯ����
�ڶ���ͨ�ļ����д���Ҳ��Ҫ���Ƕ�ģʽ���⡣�ڴ��ģʽ�Ĵ������¶��ļ���32��16λ��д�������õ��Ľ����С��ģʽ�Ĵ�������ͬ������������ĽǶ������ԶԶ������������С��ģʽ��������ʵ�ϣ�����������С��ģʽ�����𣬱���Ҫ��ϵͳ�ĽǶȣ���ָ����Ĵ���������������������⣬��С��ģʽ������




������д�ļ���һЩ���ú���������

(1)
fread(buffer,size,count,fp) ��һ����char�ַ��������á�    
��fp��ָ ���ļ�����һ�����ݿ顣size��������ֽ�����count��������ٸ�size�ֽ����ݣ� buffer���������ݴ���ڴ����ʼ��ַ����������count��ֵ��
eg1:(��ȡһ��Ĵ���)��������д���ļ���eg1��fwrite��ԡ�
#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE * fp;
    int buffer[4];
    if((fp=fopen("myfile.txt","rb"))==NULL)
    {
      printf("cant open the file");
      exit(0);
    }
    if(fread(buffer,sizeof(int),4,fp)!=4)   //����һ�ζ�ȡ
    {
        printf("file read error\n");
        exit(0);
    }
    
    for(int i=0;i<4;i++)
        printf("%d\n",buffer[i]);
    return 0;
}

eg2:(��ȡ�ṹ��)��������д���ļ���eg2��fwrite��ԡ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int age;
    char name[30];
}people;

int main ()
{
    FILE * fp;
    people per;
    if((fp=fopen("myfile.txt","rb"))==NULL)
    {
      printf("cant open the file");
      exit(0);
    }

    while(fread(&per,sizeof(people),1,fp)==1)   //����������ݣ�����ʾ�������˳�
    {
        printf("%d %s\n",per.age,per.name);
    }
    return 0;
}


fwrite(buffer,size, count,fp)   ��һ����char�ַ��������á�
��fp��ָ�ļ�д��һ�����ݿ顣size��д����ֽ�����count��д����ٸ�size�ֽ����ݣ�buffer��д���������ڴ���׵�ַ����������count ��ֵ��
eg1:(д��һ��Ĵ���)
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE * pFile;
   char buffer[] = {1, 2, 3, 4};
   if((pFile = fopen ("myfile.txt", "wb"))==NULL)
   {
       printf("cant open the file");
       exit(0);
   }
   //����д�������������(����һ��д4��)
   fwrite (buffer , sizeof(char), 4, pFile);   //�����buffer������������ȡַ����&,�Ѿ��ǵ�ַ���׵�ַ;
   //��
	/*
     for(i=0;i<4;i++)
	    fwrite(&buffer[i],sizeof(int),1,pFile);    //�����buffer[i],��Ҫ&����ȡ��ַ����&buffer[i]
  */
   fclose (pFile);
   return 0;
}

eg2:(д��ṹ��)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct	
{
   int age;
   char name[30];
}people;
  
int main ()
{
     FILE * pFile;
     int i;
     people per[3];
     per[0].age=20;strcpy(per[0].name,"li");
     per[1].age=18;strcpy(per[1].name,"wang");
     per[2].age=21;strcpy(per[2].name,"zhang");
 
     if((pFile = fopen ("myfile.txt", "wb"))==NULL)
     {
        printf("cant open the file");
         exit(0);
	 }
 
     for(i=0;i<3;i++)
     {
         if(fwrite(&per[i],sizeof(people),1,pFile)!=1)
             printf("file write error\n");
    }
     fclose (pFile);
     return 0;
}



fprintf(fp, ��ʽ���ƴ����������)  �����κ��������ͣ�char��int��float�����ö��С�
��������е����ݣ�����ʽ���ƴ� �ĸ�ʽд����fp��ָ���ļ���


fscanf(fp,��ʽ���ƴ�, �������)   �����κ��������ͣ�char��int��float�����ö��С�
��fp��ָ�ļ�����ʽ���ƴ��ĸ�ʽ �������ݣ����θ��������������Ӧ����


(2)����
C���԰��ļ�����һ���ַ����ֽڣ������У�����һ��һ���ַ����ֽڣ�������˳����ɡ��������ݵ���֯��ʽ���ɷ�ΪASCII�ļ��Ͷ������ļ�.
ASCII�ļ��ֳ�Ϊ�ı���text���ļ�������ÿ���ֽڷ�һ��ASCII���룬����һ���ַ����������ļ��ǰ��ڴ��е����ݰ����������еĴ洢��ʽԭ������������ϴ�š�

fprintf(fp, "%d", buffer); �ǽ���ʽ��������д���ļ�
fprintf(�ļ�ָ��,��ʽ�ַ���,�������);

fwrite(&buffer, sizeof(int), 1, fp);���Զ���λ��ʽд���ļ�
fwrite(���ݣ��������ʹ�С���ֽ�������д�����ݵ�����������ļ�ָ��);

����fprintfд��ʱ������������˵��һλռһ���ֽڣ�����1��ռ1���ֽڣ�10��ռ2���ֽڣ�100��ռ3���ֽڣ�10000��ռ5���ֽ�
�����ļ��Ĵ�С�������ݵĴ�С���ı䣬�Դ����ݿռ�ռ�úܴ�
��fwrite�ǰ�������д�룬����д��������ռ�ռ��Ǹ�������������ȷ��������int�Ĵ�СΪ4���ֽڣ�һ��32λ�£�����ô����10��ռ�ռ�Ϊ4���ֽڣ�
100��10000��ռ�ռ�Ҳ��4���ֽڡ����Զ�����д��ȸ�ʽ��д���ʡ�ռ䡣


(3)�������ļ���صĺ���:

1.fopen()������
a.����:
��C������fopen()�������ڴ�ָ��·�����ļ�����ȡָ����ļ���ָ�롣

b.����ԭ�ͣ�
FILE * fopen(const char * path,const char * mode);

-- path: �ļ�·�����磺"F:\Visual Stdio 2012\test.txt"

-- mode: �ļ��򿪷�ʽ�����磺

r:��ֻ����ʽ���ļ������ļ�������ڡ�
r+:�Զ�/д��ʽ���ļ������ļ�������ڡ�
rb:�Զ�/д��ʽ��һ���������ļ���ֻ��������ݡ����Ƚϳ��ã�
rb+:�Զ�/д��ʽ��һ���������ļ���ֻ�����/д���ݡ�
rt+:�Զ�/д��ʽ��һ���ı��ļ����������д��
w:��ֻд�ļ������ļ������򳤶���Ϊ 0�������ļ�������ʧ�����������򴴽����ļ���
w+:�򿪿ɶ�/д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������������ļ���
a:�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ������EOF����������
a+:�Ը��ӷ�ʽ�򿪿ɶ�/д���ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ���д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������ԭ���� EOF ������������
wb:��ֻд��ʽ�򿪻��½�һ���������ļ���ֻ����д���ݡ�
wb+:�Զ�/д��ʽ�򿪻���һ���������ļ����������д��
wt+:�Զ�/д��ʽ�򿪻���һ���ı��ļ��������д��
at+:�Զ�/д��ʽ��һ���ı��ļ�������������ı�ĩ׷�����ݡ�
ab+:�Զ�/д��ʽ��һ���������ļ�������������ļ�ĩ׷�����ݡ�

��"+":�ɶ�д
��"+":ֻ�ɶ���ֻ��д
t:�ı��ļ�
b:�������ļ�
--����ֵ: �ļ�˳���򿪺�ָ��������ļ�ָ��ͻᱻ���ء�����ļ���ʧ���򷵻�NULL�����Ѵ���������errno�С�


2.fwrite()������
a.���ã�
��C������fwrite()���������ｫһ���ڴ������е�����д�뵽�����ı���

b.����ԭ�ͣ�
size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);

-- buffer:ָ�����ݿ��ָ��

-- size:ÿ�����ݵĴ�С����λΪByte(���磺sizeof(int)����4)

-- count:���ݸ���

-- stream:�ļ�ָ��

c.ע�⣺����ֵ���ŵ��ø�ʽ�Ĳ�ͬ����ͬ��
 ���ø�ʽ1��fwrite(buf,sizeof(buf),1,fp);
 �ɹ�д�뷵��ֵΪ1(��count)

���ø�ʽ2��fwrite(buf,1,sizeof(buf),fp);
�ɹ�д���򷵻�ʵ��д������ݸ���(��λΪByte)

 ע������:
 д�����ݺ�Ҫ����fclose()�ر��������ر���������£��ļ���ʼ�մ��ڴ�״̬ռ���ڴ棩��ÿ�ζ���д���ݺ��ļ�ָ�붼��ָ����һ����д���߶�����λ�õ�ָ�롣


3.fprintf()������
a.���ã�
���͸�ʽ�������һ���ļ���

b.�� ��
#include <stdio.h>
int fprintf( FILE *stream, const char *format, ... );
fprintf()��������ָ����format(��ʽ)(��ʽ)������Ϣ(����)����stream(��)ָ�����ļ�.???

c.����ֵ
�ɹ�ʱ����ת�����ֽ�����ʧ��ʱ����һ������.
��LINUX/UNIX��ϵͳ�гɹ�����0��ʧ�ܷ���-1������errnoֵ.

4.fgets()����:
 char *fgets(char *s, int size, FILE *stream);    //��ȡ�����ַ��������硰ajkjc��
���У�s ����Ҫ���浽���ڴ�ռ���׵�ַ���������ַ���������Ҳ������ָ���ַ�������ַ�ָ���������size ������Ƕ�ȡ�ַ����ĳ��ȡ�stream ��ʾ�Ӻ������ж�ȡ��
�����Ǳ�׼������ stdin��Ҳ�������ļ���������ĳ���ļ��ж�ȡ��
eg1:
# include <stdio.h>
int main(void)
{
    char str[20];  /*����һ����󳤶�Ϊ19, ĩβ��'\0'���ַ��������洢�ַ���*/
    printf("������һ���ַ���:");
    fgets(str, 7, stdin);  /*��������stdin�����뻺�����ж�ȡ7���ַ����ַ�����str��*/��Ҳ���Դ��ļ��ж�ȡ��Ҳ�ɴӱ�׼��(������)�ж�ȡ��
    printf("%s\n", str);
    return 0;
}


eg2:
#include <stdio.h>
 
int main()
{
   FILE *fp;
   char str[60];
 
   /* �����ڶ�ȡ���ļ� */
   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("���ļ�ʱ��������");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL )    /*���ļ��ж�ȡ60���ַ����ַ�����str��*/
   {
      /* ���׼��� stdout д������ */
      puts(str);
   }
   fclose(fp);
   return(0);
}


eg3:
#include<stdio.h>
/**
*���󣺰�����ļ���Դ�����ӡ�����test.c��
*/
int main(void){
   FILE * file��
   char c;
   //���ļ�
   file = fopen("test,c","r");
   if (!file){
       printf("�ļ���ʧ��\n");
       return 1;
    }
    while (1){
       c=fgetc(file);
       if(c==EOF) {      //EOF==-1
          break��
       }
       printf("%c",c);
    }
    /*while(c=fgets(file)!=EOF){
    *          printf("%c",c);
    */  } 
    return 0;
}


5.fgetc()����:
��ȡ����һ�����ַ�������'c',��������streamָ����ļ��ж�ȡһ���ַ�����ȡһ���ֽں󣬹��λ�ú���һ���ֽڡ�
��ʽ��int fgetc(FILE *stream);

fgets()��fgetc()ʵ��:
#include <string.h>
#include <stdio.h>
int main(void)
{
 FILE *stream;
 char string[100],c; 
 stream = fopen("fan.txt", "r+");  /* ��һ���ı�*/
 fgets(string,99, stream);  /* ��ȡ�ı��е�һ�� */
 printf("%s", string); /* �ڿ���̨��ʾ�������� */
 c = fgetc(stream);//��ȡ�ı��ڶ��е�һ���ַ�
 putchar(c); //�ڿ���̨��ʾ���ַ�
 fclose(stream); //�ر��ļ�
 return 0;
}

6.fputs()����:  
int fputs(buffer, fp)             
���ļ�������ַ���

eg:                     //fputs��fgets����Ҫ����һ������
#include <stdio.h>

#define MYPWD "/home/chenw/c/test.txt"
#define SIZE 1000

int 
main(void)
{
  FILE *fp;
  char buffer[SIZE];��//�����ڴ�ռ�

  if ((fp = fopen(MYPWD, "a")) == NULL) {
  ����printf("can't open the file\n");
  }
  while (fgets(buffer, SIZE, stdin) != NULL) {��//�ӱ�׼���뽫size-1���ַ����ַ�������
  ����fputs(buffer, fp);��//���ַ���������ļ���
  ����fputs(buffer, stdout);��//���ַ����������׼���
  }
  fclose(fp);
  return 0;
}


7.fputc()����:
���ļ������뵥���ַ�

eg:
#include <stdio.h>

#define MYPWD��"/home/chenw/c/test.txt"

int main(void)
{
  FILE *fp;
  char c;

  if ((fp = fopen(MYPWD, "a")) == NULL)
  {
  ����printf("can't open the file\n");
  }
  while ((c=getchar()) != EOF) 
  {��//�ӱ�׼��������ַ�
  ����fputc(c,fp);��//���ַ�������ļ���
  ����putchar(c);��//���ַ��������׼���
  }
  fclose(fp);
  return 0;
}


8.ftell()����
ftellһ�����ڶ�ȡ�ļ��ĳ��ȣ�ftell�������ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽڡ�

long len = ftell(fp)   //ftell���ڶ�ȡ�ļ��ĳ���

eg1��
#include <stdio.h>
int main( void )
{
 FILE *stream;
 stream = fopen( "MYFILE.TXT", "w+" );
 fprintf( stream, "This is a test" );
 printf( "The file pointer is at byte \
%ld\n", ftell( stream ) );
 fclose( stream );
 return(0);
}

eg2:
#include <stdio.h>
main()
{
   FILE *myf;
   long f1;      /* �˴���f1����Ϊlong ���Զ�ȡ�������ļ� */
   myf = fopen( "1.txt", "rb" );
   fseek( myf, 0, SEEK_END );
   f1 = ftell( myf );
   fclose( myf );
   printf( " % d \ n ", f1 );
}

9.fseek()����
int fseek(FILE * stream, long offset, int whence);
����˵����
fseek()�����ƶ��ļ����Ķ�дλ��.

a������stream Ϊ�Ѵ򿪵��ļ�ָ��,
b������offset Ϊ���ݲ���whence ���ƶ���дλ�õ�λ������
c������ whence Ϊ��������һ��:
     SEEK_SET �Ӿ��ļ���ͷoffset λ����Ϊ�µĶ�дλ��. SEEK_CUR ��Ŀǰ�Ķ�дλ����������offset ��λ����.
     SEEK_END ����дλ��ָ���ļ�β��������offset ��λ����. ��whence ֵΪSEEK_CUR ��
     SEEK_END ʱ, ����offset ����ֵ�ĳ���.

�����ǽ��ر��ʹ�÷�ʽ:
a��������дλ���ƶ����ļ���ͷʱ:fseek(FILE *stream, 0, SEEK_SET);
b�� ������дλ���ƶ����ļ�βʱ:fseek(FILE *stream, 0, 0SEEK_END);

����ֵ�������óɹ�ʱ�򷵻�0, ���д����򷵻�-1, errno ���Ŵ������.

����˵����fseek()����lseek()�᷵�ض�дλ��, ��˱���ʹ��ftell()��ȡ��Ŀǰ��д��λ��.

����:
#include <stdio.h>
main()
{
  FILE * stream;
  long offset;
  fpos_t pos;
  stream = fopen("/etc/passwd", "r");
  fseek(stream, 5, SEEK_SET);
  printf("offset = %d\n", ftell(stream));
  rewind(stream);
  fgetpos(stream, &pos);
  printf("offset = %d\n", pos);
  pos = 10;
  fsetpos(stream, &pos);
  printf("offset = %d\n", ftell(stream));
  fclose(stream);
}
ִ�У�
offset = 5
offset = 0
offset = 10




(4)ʵ��:
a.fwrite,fread ��д��ʱ���ҷ��ֲ���ʹ��FILE* pFile = fopen(��myfile.bin��, ��wb��);������ʹ�á�wb�����ǡ�w��,���д�������ݾ������룬���������ǲ��ɶ��ġ�
���ǰ�ȫ�Ժã����Ǻ�����ʹ��fwrite,fread ��дmodel.�� fprintf,fscanf�ǿ��ӵġ� 
b. ʹ��fwrite,fread ��д�ļ���ʱ���м�ע������ĸ�ʽ���ٸ����ӣ�

#include <stdio.h>
#include <string.h>


int main()
{
    FILE * pFile;
    pFile = fopen("myfile.bin", "wb");
    double  a = 5.1615665161;
    fwrite(&a, sizeof(float), 1, pFile);
    rewind(pFile);
    pFile = fopen("myfile.bin", "rb");
    double b ;
    fread(&b, sizeof(float), 1, pFile);
    return 0;
}


�Ҷ���һ��double�������ݣ���������float��д���ļ���Ȼ������float���룬���ֶ���������b�Ǵ�ġ�ԭ������һ��double���ͣ�����sizeof(float)���ֽڣ��ᷢ���ضϣ�
���������Ǵ���ġ�Ӧ�ø�Ϊ��

#include <stdio.h>
#include <string.h>


int main()
{
    FILE * pFile;
    pFile = fopen("myfile.bin", "wb");
    double  a = 5.1615665161; 
    float  atemp = a;                            //��double��aת��Ϊfloat��a   
    fwrite(&atemp, sizeof(float), 1, pFile);
    rewind(pFile);
    pFile = fopen("myfile.bin", "rb");
    double b ;
    float btemp;                               //��double��bת��Ϊfloat��b
    fread(&btemp, sizeof(float), 1, pFile);
    b = btemp;
    return 0;
}
Ҳ���Ǳ�������ԭ���ݵ�ԭ�и�ʽȥ��д�� 

c. ��δ��ļ���д���ݵķ�ʽ 
һ������ʹ�ã�

FILE *fp = NULL;
fp = fopen(saved_file_name.txt, "ab");

a�����ӵ���˼������ʱ����������ȶ��벿�����ݣ��ٽ��ļ��ص���Ȼ���ٴ��ļ�����������һ�е����ݣ�����ʹ�� 
long offset = ftell(fp); 
�ȼ���֮ǰ���ı���ָ��λ��ƫ������Ȼ����һ�δ��ļ������ļ�ָ���ͷƫ��offset�����ɡ�

FILE *fp = fopen(forest_file_name.txt, "rb");
fseek(fp, offset, 0);


10.putw()����
����:putw()�����������ļ�����д������
ͷ�ļ�:#include<stdio.h>
ԭ��Ϊ:int putw( int w, FILE *stream );
��������wΪҪд���������streamΪ�ļ�ָ��
������ֵ���ɹ��������������򷵻�EOF


eg:���ļ�д��һ��������Ȼ���ȡ����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int ch;
    int len;
    int i=0;
    FILE* fstream;
    /*w+���򿪿ɶ�д�ļ������ļ��������ļ�������Ϊ�㣬
    �����ļ����ݻ���ʧ�����ļ��������������ļ�*/
    fstream=fopen("testputw.txt","w+");
    if(fstream==NULL)
    {
        printf("read file test.txt failed!\n");
        exit(1);
    }
   
    len = 56;
    putw(len,fstream);
    if(ferror(fstream))
    {
        printf("Error writing to file.\n");
    }
    else
    {
        printf("Success writing to file.\n");
    }
    fclose(fstream);
   
    return 0;
}


12.getw()����
����: ������ȡһ����,fp��ָ���ļ���ȡ��һ���֣�������
ԭ��: int getw(FILE *strem);
����ֵ:�������������,����ļ��������߳�����-1

eg: 
#include <stdio.h>
#include <stdlib.h> 

#define FNAME "test.$$$"; 

int main(void)
{
   FILE *fp;
   int word; 

   /* place the word in a file */
   fp = fopen(FNAME, "wb");
   if (fp == NULL)
   {
      printf("Error opening file %s\n", FNAME);
      exit(1);
   } 

   word = 94;
   putw(word,fp);
   if (ferror(fp))
       printf("Error writing to file\n");
   else
       printf("Successful write\n");
   fclose(fp); 

   /* reopen the file */
   fp = fopen(FNAME, "rb");
   if (fp == NULL)
   {
      printf("Error opening file %s\n", FNAME);
      exit(1);
   } 

   /* extract the word */
   word = getw(fp);
   if (ferror(fp))
       printf("Error reading file\n");
   else
       printf("Successful read: word = %d\n", word); 

   /* clean up */
   fclose(fp);
   unlink(FNAME); 

   return 0;
}




�ߡ���ȡ�ļ����ж��Ƿ�����ļ���β�ķ���

[��feof(fp)���� �� EOF��ʵ��]

(1)
while(!feof(fp))    
{
            ...                              //������ȡ�ļ�����  
}           

(2)
while((ch=fgetc(fp))!=EOF)
{
    putchar(ch);
}

(3)
while (1) 
{
  a=fgetc(f);
  if (feof(f)) break;
  //...
  b=fgetc(f);
  if (feof(f)) break;
  //...
}


(4)
int c; 
c=fgetc(fp);     
while( !feof(fp) ) 
{    
    printf("%c: %x \n", c, c); 
    c=fgetc(fp); 
} 



�ߡ���������ķ���:������������洢�ټ�Ӵ���

eg1:(һ����ȡ��)
#define N 1000

using namespace std;

int main()
{
     char str[N];
     int len,i;

     while(cin>>str)
     {
         long long sum=0;             //�ȶ���Ϊ��������
         len=strlen(str);           //��������洢
         for(i=0;i<len;i++)        //�������Ӵ���
         {
             sum=(sum*10+str[i]-'0')%3;     //�˴��Ǽ���һ����ģ3��Ľ���ļ��㷽��
         }
         sum=(int)sum;        //�ѳ������ͻ�λ����
         cout<<sum<<endl;
     }
    return 0;
}


eg2:(һ�����׳�ȡ��)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define LL long long

const int mod = 2009;   //�˴���mod����Ϊ�κ���
int main()
{
    LL n;
    while(~scanf("%lld",&n))
	{
        if(n >= mod)    //ǰ����n<=mod�ſ�����������
			puts("0");//�˴�mod���Ը�Ϊ41����Ϊ֮ǰ�Ѿ��и�����������
        else 
		{				// 2009,7*7*41=2009;
            LL ans = 1;
            for(int i = n; i>1; i--)
			{
                ans = (ans*(i%mod))%mod;//��ans=(ans%mod*i%mod)%mod;     //�׳�ȡ��Ĺ�ʽ(�����ڽ׳˵����)
            }
            printf("%lld\n",ans);           //�׳�ȡ��Ľ��
        }

    }
    return 0;
}




�ˡ�"."��"->"������

��ͬ�㣺���߶��Ƕ�Ԫ�������������ұߵĲ��������ǳ�Ա�����ơ�
��ͬ�㣺�������( . )����߲�������һ�����Ϊ�ṹ�ı��ʽ; ��ͷ�����( -> )����ߵĲ�������һ��ָ��ṹ���ָ�롣


����:
typedef struct          // ����һ���ṹ�����ͣ�DATA
{
    char key[10];       // �ṹ���Ա��key
    char name[20];      // �ṹ���Ա��name
    int age;            // �ṹ���Ա��age
}DATA;
 
 
(1)"."  ��ȡ���ݣ�����>һ��Ľṹ�����
DATA data;     // ����һ���ṹ�������Ŀ�꣺ȡ���ݣ�
// �������ݲ������£�
data.age = 24;          // �ṹ�����ͨ���������( . )���ʡ�����(����)��


(2)"->"��ȡ��ַ������>�ṹ��ָ���ṹ������
1.DATA *pdata;            // ����һ��ָ��ṹ���ָ�루Ŀ�꣺ȡ��ַ��          [PS��ָ��==���飬����ȡ��ַ���ڽṹ���о�ʹ��"->"]
2.DATA  pdata[MAXSIZE]      //����һ��ָ��ṹ��Ľṹ�����飨Ŀ�꣺ȡ��ַ��
// �������ݲ������£�
pdata->age = 24;        // ָ��ṹ���ָ��ͨ����ͷ�����( -> )�����䡾��ַ��




�š��ṹ�嶨������ַ���

(1)�ȶ���ṹ�壬Ȼ���ڶ���ṹ�����
struct stu       //stuΪ�ṹ����������
{ /*����ѧ���ṹ������*/
    char name[20]; //ѧ������
    char sex; //�Ա�
    long num; //ѧ��
    float score[3]; //���ƿ��Գɼ�
};
struct stu student1,student2; //����ṹ�����ͱ���
struct stu student3,student4;
//�ô˽ṹ�����ͣ����Զ������ĸýṹ�����ͱ�����

 

(2)����ṹ������ͬʱ����ṹ�����ͱ���
struct data
{
    int day;
    int month;
    int year;
} time1,time2;
//Ҳ�����ڶ������±���:
struct data time3,time4;
//�ô˽ṹ�����ͣ�ͬ�����Զ������ĸýṹ�����ͱ�����

 

(3)ֱ�Ӷ���ṹ�����ͱ���
struct
{
    char name[20]; //ѧ������
    char sex; //�Ա�
    long num; //ѧ��
    float score[3]; //���ƿ��Գɼ�
} person1,person2; //����ýṹ�����ͱ���
//�ö��巽�������޷���¼�ýṹ�����ͣ����Գ�ֱ�Ӷ����⣬�����ٶ���ýṹ�����ͱ�����

 

(4)��C�ж���һ���ṹ������Ҫ��typedef����typedef�������
1.
typedef struct (Student)    //�˴���Student��ʡ��
{
   int a;
}Stu;     //Stu���������Զ��������
//����������������ʱ��Ϳɣ� Stu  stu1;������ + �������������Stu, ʵ���Ͼ��� struct Student���滻��һ���ġ�
//���û��typedef�ͱ�����struct Student stu1������(1)�е����֡�;������;��typedef�Ϳ���ֱ����Stu stu1����������


2.
typedef struct
{
   int a;
}Stu;
 /*���û��typedef�ͱ�����struct Student stu1;������
�����Stu, ʵ���Ͼ��� struct Student�ı���
��������Ҳ���Բ�дStudent������Ҳ����struct Student stu1;�ˣ�*/



ʮ����̬�����ڴ�;�̬�����ڴ�

(1)��̬�����ڴ�:(��ָ�������Ķ�̬�ڴ�����г���)

1.malloc()��free()��ʽ��һ������C�У�
void *malloc(size_t size);     //����
void *free(void *pointer);     //�ͷ�   (PS:�������ͷ�����)

eg1:
int *p=(int*) malloc(sizeof(int));         //�洢1��intֵ���ڴ�
int *p=(int*) malloc(100);          �������� //����100�ֽ��ڴ�
int *p=(int*) malloc(sizeof(int)*25);        //�洢25��intֵ���ڴ�(����һ��25x4=100���ֽڵ������ڴ��)
//�� int p;
//   p=(int*) malloc(sizeof(int)*25);
free(p);

eg2:
char *p;       
p=(char*) malloc(sizeof(char)*25);            //�洢25��charֵ���ڴ�(����һ��50(25x2)���ֽڵ��ַ����ڴ��)
//�� char *p=(char*) malloc(sizeof(char)*25);
free(p);

��������ʵ��:
int main()
{
   int count,*array; /*count��һ����������array��һ������ָ�룬Ҳ�������Ϊָ��һ������������׵�ַ*/
   if((array(int *) malloc(10*sizeof(int)))==NULL)  //����10�����͵������洢�ռ䣬������һ��ָ������ʼ��ַ������ָ��;�Ѵ�����ָ���ַ����array;
   {                                                //��ⷵ��ֵ�Ƿ�ΪNULL
       printf("���ܳɹ�����洢�ռ�:");
       exit(1);
   }
   for (count=0;count<10;count++) /*�����鸳ֵ*/
      array[count]=count;
   for(count=0;count<10;count++) /*��ӡ����Ԫ��*/
      printf("%2d",array[count]);
}


2.new()��delete()��ʽ(һ������C++��)
int *p = new int[MAX];  //����
//�� int *p;
//   p=new int[MAX];
����ʱp����һ����ͨ�����ˣ�����ֱ����p[MAX]��������

delete p;     //�ͷ�   (PS:�������ͷ�����)

eg1:
int *p=new int[10]; //��̬����Ĵ�С�����Ǳ�����������һ��ֱ����������ʱ�������С�����ǳ���
eg2:
char *p1;
p1=new char[12];
eg3:
double *p2;
p2=new double[100];
����ʱp����һ����ͨ�����ˣ�����ֱ����p[MAX]��������

eg4:���Զ���Ľṹ�����ͣ�
typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

int main()
{
    HuffmanTree HT;
    HT=new HTNode[MAX];
    ....... 
}
����ʱHT����һ����ͨ�����ˣ�����ֱ����HT[MAX]��������


(2)��̬�����ڴ�(ƽʱ�õġ���ͨ�������ָ��)
char str[80];

eg:
char *str,s[80];
str=s;
cout<<"������һ���ַ���:";
cin>>str;



ʮһ��Ƕ�׵Ľṹ���г��õ�һЩ���ϡ�һ���ڽṹ��������ʹ�á�(*��&���޷���)���ο�ʵѵ���ӵ�ͼ��Ŀ�Ľṹ���ʵ��(��*��&���)��

1."*" (ȡ��ַ����ʾ���������ȫ�����ݣ�ȡ��ַ��������ʱ��"->"������Ҳ����"->",��ʾȡ��ַ)
eg1:��*��&��ԣ��ṹ�����ʱ���á�
typedef struct{ //����Ȩ���ڽӾ���ĵĶ���
    int Vertices[MaxVertices];  //������Ϣ������
    int Edge[MaxVertices][MaxVertices]; //�ߵ�Ȩ��Ϣ������
    int numV; //��ǰ�Ķ�����
    int numE; //��ǰ�ı���
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //ͼ�����ɺ���      //����(*��&���)��" & "��ʵ��ʱ���βεĶ���Ҫ����" * "��ָ�룩��
{
     G->numV=n;G->numE=e;         //������Ϊ������β����Ͷ�����AdjMatrix *G, ��"*"ָ�루����Ҳһ����,����ȡ��ַ,����Ҫ��"->"��������ַ��Ȼ����ȡ���ݡ�
}

int main()
{
    AdjMatrix G;
    CreateGraph(&G);     //����(*��&���)��" & "��ʵ��ʱ���βεĶ���Ҫ����" * "��ָ�룩��
}



2."&"(��ʾ������󷵻������ȫ�����ݣ����÷���)
eg:
typedef struct{ //����Ȩ���ڽӾ���ĵĶ���
    int Vertices[MaxVertices];  //������Ϣ������
    int Edge[MaxVertices][MaxVertices]; //�ߵ�Ȩ��Ϣ������
    int numV; //��ǰ�Ķ�����
    int numE; //��ǰ�ı���
}AdjMatrix;

void InsertGraph(AdjMatrix &G) //����ڽӾ������Ϣ      //����ʹ�����÷���"&"�����ز������ȫ�����ݣ��β�Ҫ����"&"��
{
     for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);                      //������ΪAdjMatrix &G��G��һ��Ľṹ�����������ָ������飩��������"."��ֱ��ȡ���ݡ�
}

int main()
{
    AdjMatrix G;
    InsertGraph(G);                        //�����βεĽṹ�����Ͷ��������÷���&ʱ��ֱ�Ӵ�ʵ�νṹ�����G ��                           
}



3.�޷���(��ʾ������󲻷�����������ݣ�����ԭ����ʼ��������Ӱ��)
typedef struct{ //����Ȩ���ڽӾ���ĵĶ���
    int Vertices[MaxVertices];  //������Ϣ������
    int Edge[MaxVertices][MaxVertices]; //�ߵ�Ȩ��Ϣ������
    int numV; //��ǰ�Ķ�����
    int numE; //��ǰ�ı���
}AdjMatrix;

void DispGraph(AdjMatrix G) //����ڽӾ������Ϣ         //��ʲô����Ҳ���ã���ʾ�������������ݣ�Ҳ��Ӱ��֮ǰ�����������飬һ���Ƕ�����������չʾʱ�á�
{
     for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);                     //����ΪAdjMatrix G��G��һ��Ľṹ�����������ָ������飩��������"."��ֱ��ȡ���ݡ�
}

int main()
{
    AdjMatrix G;
    DispGraph(G);                            //��ֱ�Ӵ�ʵ�νṹ�����G��
}



ʮ���������������͵�ȡֵ��Χ

short int 1���ֽڴ���
unsigned   short int    0��255
short int   -128��127
int 2���ֽڴ���
unsigned   int    0��4294967295   
int   2147483648��2147483647
long 4���ֽڴ��� 
unsigned long 0��4294967295
long   2147483648��2147483647
long long int 8���ֽڴ��� ��VC6.0++��֧��long long ���͡�
long long�����ֵ��9223372036854775807
long long����Сֵ��-9223372036854775808
unsigned long long�����ֵ��1844674407370955161
__int64�����ֵ�� 9223372036854775807
__int64����Сֵ��-9223372036854775808
unsigned __int64�����ֵ��18446744073709551615
unsigned __int64�����ֵ��18446744073709551615

��������        �ֽ���    ȡֵ��Χ
signed char       1        -128��+127
short int         2        -32768��+32767
int               4        -2147483648��+2147483647
long int          4        -2147483648��+2141483647
long long long int  8      -9223372036854775808��+9223372036854775807
unsigned long long�����ֵ��1844674407370955161

unsigned int (unsigned long)
4�ֽ�8λ�ɱ��λ����2^32=4294967296  
��Χ��0 �� 4294967295 (42*10^8)  

int ��long��
4�ֽ�8λ�ɱ��λ����2^32=4294967296  
��Χ��-2147483648 �� 2147483647 (21*10^8)

long long (__int64)
8�ֽ�8λ�ɱ��λ����2^64=18446744073709600000  
��Χ��-9223372036854775808 �� 9223372036854775807 (922*10^16)

unsigned long (unsigned __int64)
8�ֽ�8λ�ɱ��λ����2^64=18446744073709600000  
��Χ��0 �� 18446744073709551615 (1844*10^16)



ʮ�����ַ�����ĸ�ֵ(��ʼ��)�Լ��ַ�������ص��״��

(1)�����ʱ��ֱ�����ַ�����ֵ
char a[10]="hello";   ����" "˫���ŵ��ǰ�˳������ֵ����0���꿪ʼ��ֵ��ֱ������Ԫ��ʹ���꡿
char a[]="hello";   �����ݺ�����ʵ��ֵ��Ԫ�ظ������Զ�ȷ�������С��������5����a[5]��
char str[]={"I am happy"}; == char str[]="I am happy";(�����ſ���ʡ��)
��C++�п���:
char a[20];   ��ֻ�����ַ��������͡�
cin>>a;

!!!ע�⣺�����ȶ����ٸ�����ֵ!!!
��:
char a[10];
a[10]="hello";  !�����Ǵ����!
����Ϊ�ַ�����ĸ�ֵֻ�ܰ�Ԫ��һһ��ֵ(�����ԭ�� C���Բ�û���ṩ����ֱ�Ӳ����ַ��������������=���������������������͵ĸ�ֵ�����ǲ�����ֱ�Ӹ��ַ�����ֵ)��


(2)���������ַ������ֵ
1. char a[10]={'h','e','l','l','o'};����{}�ŵ��ǰ�˳������ֵ����0���꿪ʼ��ֵ��ֱ������Ԫ��ʹ���꡿
2. char charr[] = { 'z','i','f','u','c','h','u','a','n','s','h','u','z','u' }; �����ݺ�����ʵ��ֵ��Ԫ�ظ������Զ�ȷ�������С��������14����charr[14]��
3. ��forѭ�������ֵ:
char a[20];
for(i=0;i<20;i++)
   cin>>a[i];
4. 
��
��!!!
����:Ҳ���Ը�ֵ��ĳ��λ�õ�Ԫ��:(���ַ�������ַ���һ���Ը�ֵ��ͬ,�ַ���һ���Ը�ֵ��Ҫ{}��˫����,���ﲻ��һ���Ը�ֵ��,ֻ�Ǹ�ֵ��ĳһ��λ��,һ��ֻ��ֵһ��λ��)
eg1:(�ַ���)
char array[5];
array[2]='a';
cout<<array[2];
(�˴�ֻ��ֵ���±�Ϊ2��λ�õ�Ԫ�أ�û��ֵ������λ��)
eg2:(����)
 int array[5];
 array[2]='5';
 cout<<array[2];
(�˴�ֻ��ֵ���±�Ϊ2��λ�õ�Ԫ�أ�û��ֵ������λ��)
��
��

(3)���ַ�ָ�븳ֵ:(�洢�ַ���)��ֻ�����ַ��������͡�
char* str="zifuchuanshuzu";   ��ָ���൱�����飬��ַ�����ڴ洢���ݡ�
��
char *str;      //ֻ�ǰ��ַ����׵�ַ��ֵ��str(��Ϊָ����ָ���׵�ַ��ϵͳ�������strָ����ַ��������Լ�1��ֱ��������\0��;������������ʽ��ͬ��)
str="zifuzhizhen";    !!!�����ַ�ָ�����ָ�ֵ��ʽ����ȷ�ġ����ַ�����(����(1)��)��ͬ!!!                                      //printf("%s",str);


(4)����strcpy���Ƽ�Ӹ�ֵ
char a[10]; 
strcpy(a, "hello");


(5)!!!���״����(ע���)��!!!
1.char a[10]; a[10]=��hello��;���Ǵ���ġ� //һ���ַ���ô������һ���ַ���������a[10]Ҳ�ǲ����ڵ�

2.char a[10]; a=��hello��;���Ǵ���ġ� //����������׳��֣�a��Ȼ��ָ�룬�������Ѿ�ָ���ڶ�ջ�з����10���ַ��ռ䣬����������a��ָ���������е�hello��������
���ָ��a���ֻ��ң�������

3.C���Ե�����������޷������ַ�������C�����а��ַ�������������������ˣ����ַ��������Ʒ�ʽ�Ͷ������һ�����ر��ǣ����Ƕ�������C���Եġ�����������и��ƺ�
�Ƚϲ�����

ֱ�ӳ��Զ��ַ������С����ƻ�Ƚϡ�������ʧ�ܡ���Ҫʹ���ַ����ĸ��ƺ���strcpy()�ͱȽϺ���strcmp()��
���磬�ٶ�str1��str2������������
char str1[10],str2[10];
str1 = "abc"; /*** WRONG ***/  //������=����������ַ��������ơ����ַ��������ǲ����ܵ�[�Ǵ����]��
str2 = str1; /***Ҫ�����ֱ�ӽ��и��� WRONG ***/
C���԰���Щ������Ϊһ��ָ������һ��ָ��֮��ģ��Ƿ��ģ���ֵ���㡣

��!!!PS: 
   ���ǣ�ʹ��=####��ʼ��###�ַ������ǺϷ���
   char str1[10] = "abc";   //�˴���###��ʼ��###���顾�Ϸ�����ȷ�ġ�
!!!��


4.��ͼʹ�ù�ϵ��������е��������***�Ƚ�***�ַ����ǺϷ��ģ����������Ԥ�ڵĽ����

if (str1==str2)  /*** WRONG ***/ .... //str1��str2�в�ͬ�ĵ�ַ�����Ա��ʽstr1 == str2��ֵһ��Ϊ0(����)��Ҫ��strcmp()������
//����������str1��str2��Ϊ**ָ��(��ַ)**�����бȽϣ������ǱȽ����������**����(����)**����Ϊstr1��str2�в�ͬ�ĵ�ַ�����Ա��ʽstr1 == str2��ֵһ��Ϊ0��




ʮ�ġ�memset()��������ȷʹ�ú�ע���(����ͳһ��һ����ֵ;��char��������ʱ����ȷ����ʹ������ֵ;����������������ʱ������ȷ����ʹ������ֵ,���ܸ�0��-1,��������)
(1)
memset()����ԭ����:extern void *memset(void *buffer, �������� c, int count) 
buffer:Ϊָ���������, c:�Ǹ���buffer��ֵ, count:��buffer�ĳ���
(2)�����״�,Ҫ����ѡ��ʹ�á�
1.����:��������ͳһ��һ����ֵ(һ�㳣��������)
2.c����������Ϊcharʱ��������ȷ����ʹ��memset()���� ; 
3.�������������(int��float...)�����ݾͲ�����ȷ����ʹ���ˣ���ֻ�ܸ�0��-1ֵ(�����������ͳһ��������(�����ֵȫΪ��),��������ֵ���׳���),����͵���ƽ����ѭ��
�ṹ��ʵ��
4.Ҫʹ��#include<string.h>ͷ�ļ�

����memset()����һ�㳣��������,���������ֵ��ա�

eg1:(�ַ���)
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

int main()
{
    int i,j��
	char array[3][3];     //Ϊ�ַ�����,����ȷ����ʹ��
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
           cin>>array[i][j];
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    memset(array, 'c', sizeof(array));    //Ϊ�ַ�����,����ȷ����ʹ��
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
}
���н��Ϊ:
1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

c c c      //Ϊ�ַ�����,����ȷ����ʹ��,�����ȷ
c c c
c c c

eg2:(������������)
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include <string.h>

using namespace std;

int main()
{
    int i,j��
	int array[3][3];      //Ϊ��������,������ȷ����ʹ��
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
           cin>>array[i][j];
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    memset(array, 0, sizeof(array));    //Ϊ��������,������ȷ����ʹ��
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
}
���н��Ϊ:
1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

892679477 892679477 892679477     //Ϊ��������,������ȷ����ʹ��,�������
892679477 892679477 892679477
892679477 892679477 892679477

eg3:(һ�㳣��������)
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include <string.h>

using namespace std;

int main()
{
    int i,j;
    char array[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cin>>array[i][j];
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    memset(array,0, sizeof(array));
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
}
���н��Ϊ:
1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

//���������,����ȫ��Ϊ��,�������û�������



ʮ�塢STL��֮ջ��stack���Ͷ��У�queue���Ķ���������÷�
(1)ջ(stack)
ͷ�ļ�:#include<stack>
����һ��ջ:stack <��������> ������  �磺stack <int> a
˵��:stack ģ������Ҫ����ģ�������һ����Ԫ�����ͣ�һ���������ͣ���ֻ��Ԫ�������Ǳ�Ҫ�ģ��ڲ�ָ����������ʱ��Ĭ�ϵ���������Ϊdeque
�����÷���
a.push();   //��ջ��ѹ��һ����Ա
a.pop();   //��ջ������һ����Ա
a.empty();   //Ϊ�շ���true�����򷵻�false
a.top();   //����ջ��������ɾ����Ա
a.size();   //����ջ�Ĵ�С

eg:
#include<iostream>
#include<string>
#include<stack>    //ͷ�ļ�
using namespace std;
int main()
{
    int t,i,num;
    string a,b;
    stack <int> stk;    //��������һ��ջ
    cin>>t;
    for(i=1;i<=t;i++)
    {
        if(i>1)
            cout<<endl;
        cin>>a>>b;
        int l1=a.size(),l2=b.size();   //����ջ��С
        int j=0;
        while(l1>0||l2>0)
        {
            num=j;
            if(l1>0)
            {
                num+=a[l1-1]-'0';
                l1--;
            }
            if(l2>0)
            {
               num+=b[l2-1]-'0';
               l2--;
            }
            j=num/10;
            stk.push(num%10);   //ѹջ
        }
        if(j)
            stk.push(j);       //ѹջ
        cout<<"Case "<<i<<':'<<endl;
        cout<<a<<" + "<<b<<" = ";
        while(!stk.empty())
        {
            cout<<stk.top();   //����ջ��Ԫ��
            stk.pop();    //��ջ
        }
        cout<<endl;
    }
    return 0;
}


(2)����(queue)
ͷ�ļ�:#include<queue>
����һ������:queue <��������> ������ �磺queue <int> q
˵��:queue ģ����Ҳ��Ҫ����ģ�������һ����Ԫ�����ͣ�һ���������ͣ�Ԫ�������Ǳ�Ҫ�ģ����������ǿ�ѡ�ģ�Ĭ��Ϊdeque ����
�����÷���
q.push();  //�ڶ�β��������  
q.pop();  //�ڶ���ɾ������   
q.empty();  //Ϊ�շ���true�����򷵻�false
q.front(); //���ض���Ԫ��   
q.back();  //���ض�β��Ԫ�� 
q.size();  //���ض��еĴ�С

eg:
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int e,n,m;
    queue<int> q1;     //��������һ������
    for(int i=0;i<10;i++)
      q1.push(i);         //����
    if(!q1.empty())      //�ж��Ƿ�ӿ�
    cout<<"dui lie??bu kong\n";
    n=q1.size();      //���ضӵĴ�С
    cout<<n<<endl;
    m=q1.back();      //���ض�βԪ��
    cout<<m<<endl;
    for(int j=0;j<n;j++)
	{
       e=q1.front();     //���ض���Ԫ��
       cout<<e<<" ";
       q1.pop();       //����
	}
    cout<<endl;
    if(q1.empty())
    cout<<"dui lie??bu kong\n";
    system("PAUSE");
    return 0;
}


(3)���ȶ���(priority_queue) 
1.�ص㣺 
�Զ�����(Ĭ�ϴӴ�С) 

2.����:priority_queue<int>  p_queue;    //ϵͳĬ��Ϊ�Ӵ�С����

3.ͷ�ļ�:#include<queue> 

4.�������������:
priority_queue<Type, Container, Functional>   TypeΪ��������, ContainerΪ�������ݵ�����,FunctionalΪԪ�رȽϷ�ʽ
(�����д��������������ô����Ĭ���õ���vector,�ȽϷ�ʽĬ����operator<,Ҳ�������ȶ����Ǵ󶥶ѣ���ͷԪ�����)

5.��ϵͳĬ�����ȶ��еĲ���:
//node�ǽṹ�壬�������Ҫ����"<" 
priority_queue <node> q;
//����>>��Ҫд��һ��>>����������� 
priority_queue <int,vector<int>,greater<int> > q;  //��С���� (С����)
priority_queue <int,vector<int>,less<int> > q;      //�Ӵ�С(�󶥶�)


eg1:ϵͳĬ��Ϊ�Ӵ�С����(����)
#include<iostream>
#include<queue>
using namespace std;
 
int main(){
	priority_queue<int> p;
	p.push(1);
	p.push(2);
	p.push(8);
	p.push(5);
	p.push(43);
	for(int i=0;i<5;i++){
		cout<<p.top()<<endl;
		p.pop();
	}
	return 0;
}


eg2:���нṹ�壬����<
#include<bits/stdc++.h>
using namespace std;
//����С�ں� 
struct node{
    int x,y;
    bool operator <(const node &a) const{
        return x>a.x;
    }
}k;
priority_queue <node> q;
//priority_queue <int,vector<int>,greater > q;
int main()
{
    k.x=1;k.y=2;  q.push(k);
    k.x=2;k.y=1;  q.push(k);
    k.x=3;k.y=4;  q.push(k);
    while(!q.empty())
	{
        node t;
        t=q.top();
        q.pop();
        cout<<"("<<t.x<<","<<t.y<<")"<<endl;
    }

    return 0;
}


eg3:
int data[]={1,3,2,5,6,4,9,8,7,10};
    priority_queue<int>  p_queue;    //ϵͳĬ��Ϊ�Ӵ�С����
    for(int i=0;i<sizeof(data)/sizeof(*data);++i)
    {
        p_queue.push(data[i]);//�������� 
    }


    cout<<"����Ѷ�Ԫ�أ�";
    for(int i=0;i<sizeof(data)/sizeof(*data);++i)
    {
        cout<<p_queue.top()<<" ";//���:10 9 8 7 6 5 4 3 2 1 
        p_queue.pop();
	}




ʮ����C++��string���÷�����(�����ã���;��Χ��)

����֪��string���Թ���һ���ַ�����������ô���Ĳ�������Щ�ء���������string���У�����string.hû��.h���������ԺͶ���һ���ַ�һ������һ���ַ���������
����ǿ���C++�������˸��ֺ���������ʵ�ֲ�������д�������������ҿ��Խ����ֵ���ıȽϺʹ�������

(1)���Խ���:

1.��λ�ͶԴ�����:
��λ���string���е�ĳһλ�ַ��أ�����ʹ����������ķ�ʽ�Ϳ��Է��ʡ�
����:
string s = "abcdef";
cout << s[0] << endl;
�����Ӧ����������ַ�'a'��ͬʱstring����Ҳ����ֱ�Ӽ�����һ���ַ�����
����:
string a = "abc", b = "bcd";
a = a + b;
cout << a << endl;
���Ӧ������ַ�����abcbcd����

2.��ʼ����ʽ:
string test1;    //�մ�
string test2 = "����"; //ʹ��=
string test3("����");   //ʹ�������ַ�������Ϊ�����������캯��
string test4(test2); //��һ��string��ʼ����һ��string
string test5(test2,pos,num); //��test2�еĵ�pos��λ�ÿ�ʼ����������Ϊnum���ַ�
string test6 = test2 + "����" + test3 //��ϳ�ʼ��
string test7 = test2.substr(pos,num); //��test2�еĵ�pos��λ�ÿ�ʼ����������Ϊnum���ַ�
string test8 = test2.substr(); //�����б�Ϊ����´��test2���������󣨸���test2�ļ�㷽����
string test9(num,ch); //����num���ַ���ch��test9

3.���ú���:
��string��������ʵ�����˺ܶຯ����
����:
 1     string s = "a";
 2     s.append(2,'b');//s.append(n,c);��s���������n��c�ַ���append���������÷�������ɰٶȣ�
 3     s.erase(s.begin(),s.begin()+2);//s.erase(l,r);ɾ��ĳ�����䣬l,r��Ϊ������
 4     s.erase(it);//ɾ��һ���ַ���itΪ������
 5     s.size();//�����ַ���s�ĳ��ȴ�С
 6     s.begin();//������λ�õĵ�����
 7     s.end();//����ĩλ�õĵ�����
 8     s.insert(it,ch);//��itλ�ò���ch�ַ���itΪ������
 9     s.resize(len,c);//���ַ�����ǰ��С��Ϊlen������c��䲻��Ĳ���
10     s.empty();//�ж��Ƿ�Ϊ�մ�
11     s.length();//�����ַ����ĳ���
12     s.max_size();//���ص�ǰϵͳstring����ɴ�ŵ���󳤶�
13     s.capacity();//���ص�ǰ����
14     s.at(k);//���ص�k+1���ַ������÷������Ƿ�Խ�磩
15     s.c_str();//����C�ַ�����ָ�룬����Ϊs��
16     s.find(s1);//����s���Ƿ����s1��������ͷλ�ã��Ҳ����򷵻�string::npos
17     s.replace(k,x,ch);//��kλ�ÿ�ʼ���Ѻ����x��Ԫ���滻Ϊch�����кܶ������÷���
18     s.swap(s2);//��������string�ַ���
����string��֧��ֱ�ӱȽ������ַ����Ĵ�С�������ֵ���ȽϷ�ʽ������������д�˵��⣬string��ʵ���кܶຯ����




(2)string�������:����

֮��������char*���ַ�����ѡ��C++��׼������е�string�࣬����Ϊ����ǰ�߱Ƚ����������ص����ڴ��Ƿ��㹻���ַ������ȵȵȣ�������Ϊһ����������֣������ɵĲ���
��������������Ǵ���������(������100%)����Ҫ�����ǿ����� = ���и�ֵ������== ���бȽϣ�+ ���������ǲ��Ǻܼ�?�������Ǿ����԰���������C++�Ļ����������͡�

C++�ж���strinig�Ķ���Ϊ��typedef basic_string string; Ҳ����˵C++�е�string����һ�������࣬��ģ���ʵ������һ����׼�࣬�����ϲ���һ����׼�������͡�
���ˣ��������⡭����
���ȣ�Ϊ�������ǵĳ�����ʹ��string���ͣ����Ǳ������ͷ�ļ� �����£�
#include //ע�����ﲻ��string.h string.h��C�ַ���ͷ�ļ�

using namespace std;  //�����ز����٣������еı������޷�ʶ��

1.����һ��C++�ַ���
����һ���ַ��������ܼ򵥣�string Str;
�������Ǿ�������һ���ַ�������������Ȼ��һ���࣬���й��캯�����������������������û�д�����������Ծ�ֱ��ʹ����string��Ĭ�ϵĹ��캯����������������ľ��ǰ�
Str��ʼ��Ϊһ�����ַ�����String��Ĺ��캯���������������£�
a)    string s;  //����һ�����ַ���s
b)    string s(str) //�������캯�� ����str�ĸ���Ʒ
c)    string s(str,stridx) //���ַ���str�ڡ�ʼ��λ��stridx���Ĳ��ֵ����ַ����ĳ�ֵ
d)    string s(str,stridx,strlen) //���ַ���str�ڡ�ʼ��stridx�ҳ��ȶ���strlen���Ĳ�����Ϊ�ַ����ĳ�ֵ
e)    string s(cstr) //��C�ַ�����Ϊs�ĳ�ֵ
f)    string s(chars,chars_len) //��C�ַ���ǰchars_len���ַ���Ϊ�ַ���s�ĳ�ֵ��
g)    string s(num,c) //����һ���ַ���������num��c�ַ�
h)    string s(beg,end) //������beg;end(������end)�ڵ��ַ���Ϊ�ַ���s�ĳ�ֵ
i)    s.~string() //���������ַ����ͷ��ڴ�


2���ַ�����������:
������C++�ַ������ص㣬���ȰѸ��ֲ����������г�������ϲ�������к�����������˿������������Լ�ϲ���ĺ������ٵ����濴������ϸ���͡�
a) =,assign()   //������ֵ
b) swap()   //���������ַ���������
c) +=,append(),push_back() //��β������ַ�
d) insert() //�����ַ�
e) erase() //ɾ���ַ�
f) clear() //ɾ��ȫ���ַ� 
g) replace() //�滻�ַ�
h) + //�����ַ���
i) ==,!=,<,<=,>,>=,compare()  //�Ƚ��ַ���
j) size(),length()  //�����ַ�����
k) max_size() //�����ַ��Ŀ���������
l) empty()  //�ж��ַ����Ƿ�Ϊ��
m) capacity() //�������·���֮ǰ���ַ�����
n) reserve() //����һ�����ڴ�������һ���������ַ�
o) [ ], at() //��ȡ��һ�ַ�
p) >>,getline() //��stream��ȡĳֵ
q) <<  //��ıֵд��stream
r) copy() //��ĳֵ��ֵΪһ��C_string
s) c_str() //��������C_string����
t) data() //���������ַ�������ʽ����
u) substr() //����ĳ�����ַ�������ȡ�ַ�����
v)���Һ���
w)begin() end() //�ṩ����STL�ĵ�����֧��
x) rbegin() rend() //���������
y) get_allocator() //����������


3.������ϸ����ϸ���Լ������÷�:

��C++�ַ�����C�ַ�����ת��:
C++�ṩ����C++�ַ����õ���Ӧ��C_string�ķ�����ʹ��data()��c_str()��copy()�����У�data()���ַ��������ʽ�����ַ������ݣ���������ӡ�\0����c_str()����һ��
�ԡ�\0����β���ַ����飬��copy()����ַ��������ݸ��ƻ�д����е�c_string���ַ������ڡ�C++�ַ��������ԡ�\0����β���ҵĽ������ڳ�������ʹ��C++�ַ�����ʹ�ã�
�����򲻵��Ѳ�ѡ��c_string������ֻ�Ǽ򵥽��ܣ���ϸ�����ӹ���˭���һ���˽�ʹ���е�ע��������Ը�������(���ҵ��ռ���)������ϸ���͡�

�ڴ�С����������:
һ��C++�ַ����������ִ�С��a)���е��ַ�����������size()��length()�����ǵ�Ч��Empty()��������ַ����Ƿ�Ϊ�ա�b)max_size() �����С��ָ��ǰC++�ַ��������
�������ַ������ܿ��ܺͻ�����������ƻ����ַ�������λ�������ڴ�Ĵ�С�й�ϵ������һ������²��ù�������Ӧ�ô�С�㹻�����õġ����ǲ����õĻ�������
��length_error�쳣c)capacity()���·����ڴ�֮ǰ string���ܰ���������ַ�����������һ����Ҫָ������reserve()�������������Ϊstring���·����ڴ档���·���Ĵ�С
�������������Ĭ�ϲ���Ϊ0����ʱ����string���з�ǿ����������

��ע��:���б�Ҫ���ظ�һ��C++�ַ�����C�ַ���ת�������⣬����˻��������������⣬�Լ����ĳ���Ҫ���ñ��˵ĺ�������ʲô�ģ��������ݿ�����
����Connect(char*,char*)���������˵ĺ��������õ���char*��ʽ�ģ�������֪����c_str()��data()���ص��ַ������ɸ��ַ���ӵ�У�������һ��const char*,Ҫ����Ϊ������
���ĺ����Ĳ����������뿽����һ��char*,�����ǵ�ԭ�����ܲ�ʹ��C�ַ����Ͳ�ʹ�á���ô����ʱ�����ǵĴ���ʽ�ǣ�����˺����Բ���(Ҳ����char*)�����ݲ��޸ĵĻ�����
�ǿ�������Connect((char*)UserID.c_str(), (char*)PassWD.c_str()),������ʱ���Ǵ���Σ�յģ���Ϊ����ת������ַ�����ʵ�ǿ����޸ĵģ�����Ȥ�ؿ����Լ���һ�ԣ�����
����ǿ�����Ǻ������õ�ʱ�򲻶Բ��������޸ģ�������뿽����һ��char*��ȥ����Ȼ�������׵İ취������ʲô�����������һ��char*��ȥ��ͬʱ����Ҳ��������Ȼʹ��C��
�������б�̵ĸ����ǣ�˵�����Ǹ���һ���Ҳ��Ϊ����Ҳ�������ǻ������ɿ��ʱ�����ǾͿ�ʼ����ˣ���������д�ĺ������ȽϹ淶���������ǾͲ��ؽ���ǿ��ת���ˡ���

��Ԫ�ش�ȡ:
 ���ǿ���ʹ���±������[]�ͺ���at()��Ԫ�ذ������ַ����з��ʡ�����Ӧ��ע����ǲ�����[]������������Ƿ���Ч����Ч����0~str.length()�����������ʧЧ��������δ��
 �����Ϊ����at()���飬���ʹ��at()��ʱ��������Ч�����׳�out_of_range�쳣��
 ��һ�����ⲻ�ò�˵��const string a;�Ĳ�����[]������ֵ��a.length()��Ȼ��Ч���䷵��ֵ�ǡ�\0���������ĸ��������a.length()����������Ч�ġ��������£�
const string Cstr(��const string��);
string Str(��string��);

Str[3];    //ok
Str.at(3);  //ok

Str[100]; //δ�������Ϊ
Str.at(100);  //throw out_of_range

Str[Str.length()]  //δ������Ϊ
Cstr[Cstr.length()] //���� ��\0��
Str.at(Str.length());//throw out_of_range
Cstr.at(Cstr.length()) ////throw out_of_range

�Ҳ��޳���������������û�ָ�븳ֵ��
char& r=s[2];
char* p= &s[3];
��Ϊһ���������·��䣬r,p����ʧЧ������ķ������ǲ�ʹ�á�

�ܱȽϺ���:
    C++�ַ���֧�ֳ����ıȽϲ�������>,>=,<,<=,==,!=��������֧��string��C-string�ıȽ�(�� str<��hello��)����ʹ��>,>=,<,<=��Щ��������ʱ���Ǹ���
	����ǰ�ַ����ԡ����ַ����ֵ�˳�������һ�ñȽϡ��ֵ�����ǰ���ַ�С���Ƚϵ�˳���Ǵ�ǰ���Ƚϣ���������ȵ��ַ��Ͱ����λ���ϵ������ַ��ıȽϽ��ȷ��
	�����ַ����Ĵ�С��ͬʱ��string(��aaaa��)
    ��һ������ǿ��ıȽϺ����ǳ�Ա����compare()����֧�ֶ��������֧��������ֵ�ͳ��ȶ�λ�Ӵ������бȽϡ�������һ����������ʾ�ȽϽ��������ֵ�������£�
	0-��ȡ�0-���� <0-С�ڡ�
	�������£�
    string s(��abcd��);
    s.compare(��abcd��); //����0
    s.compare(��dcba��); //����һ��С��0��ֵ
    s.compare(��ab��); //���ش���0��ֵ
  
    s.compare(s); //���
    s.compare(0,2,s,2,2); //�á�ab���͡�cd�����бȽ� С����
    s.compare(1,2,��bcx��,2); //�á�bc���͡�bc���Ƚϡ�

�ݸ�������:
�����ַ����Ĳ�����ռ�˺ܴ�һ���֡�
���Ƚ���ֵ����һ����ֵ������Ȼ��ʹ�ò�����=����ֵ������string(�磺s=ns) ��c_string(�磺s=��gaint��)������һ�ַ����磺s=��j������������ʹ�ó�Ա����assign()��
�����Ա��������ʹ������Ķ��ַ�����ֵ��
���Ǿ���˵���ɣ�
s.assign(str); //��˵
s.assign(str,1,3);//���str�ǡ�iamangel�� ���ǰѡ�ama�������ַ���
s.assign(str,2,string::npos);//���ַ���str������ֵ2��ʼ����β����s
s.assign(��gaint��); //��˵
s.assign(��nico��,5);//�ѡ�n�� ��I�� ��c�� ��o�� ��\0�������ַ���
s.assign(5,��x��);//�����x�����ַ���
���ַ�����յķ�����������s=����;s.clear();s.erase();(��Խ��Խ���þ�����˵���ñ������׶���)��
string�ṩ�˺ܶຯ�����ڲ��루insert����ɾ����erase�����滻��replace���������ַ���
��˵�����ַ�������˵����������β���ϣ��������� +=��append()��push_back()���������£�
s+=str;//�Ӹ��ַ���
s+=��my name is jiayp��;//�Ӹ�C�ַ���
s+=��a��;//�Ӹ��ַ�

s.append(str);
s.append(str,1,3);//�������� ͬǰ��ĺ�������assign�Ľ���
s.append(str,2,string::npos)//��������

s.append(��my name is jiayp��);
s.append(��nico��,5);
s.append(5,��x��);

s.push_back(��a��);//�������ֻ�����ӵ����ַ� ��STL��Ϥ����������ܼ�

Ҳ������Ҫ��string�м��ĳ��λ�ò����ַ�������ʱ���������insert()���������������Ҫ��ָ��һ������λ�õ���������������ַ�����������������ĺ��档
    s.insert(0,��my name��);
    s.insert(1,str);
������ʽ��insert()������֧�ִ��뵥���ַ�����ʱ�ĵ����ַ�����д���ַ�����ʽ(���˶���)����Ȼ����ö��ģ��ǾͲ��ò�����������һ�λ���Ϊ�˲��뵥���ַ���
insert()�����ṩ�������Բ��뵥���ַ����������غ�����insert(size_type index,size_type num,chart c)��insert(iterator pos,size_type num,chart c)������size_type
���޷���������iterator��char*,���ԣ�����ô����insert�����ǲ��еģ�insert(0,1,��j��);��ʱ���һ��������ת������һ���أ������������
ôд��insert((string::size_type)0,1,��j��)���ڶ�����ʽָ����ʹ�õ����������ַ�����ʽ���ں�����ἰ��˳����һ�£�string�кܶ������ʹ��STL�ĵ������ģ���Ҳ��
�����ú�STL������
ɾ������erase()����ʽҲ�кü��֣��淳�������滻����replace()Ҳ�кü�����
�����ɣ�
string s=��il8n��;
s.replace(1,2,��nternationalizatio��);//������1��ʼ��2���滻�ɺ����C_string
s.erase(13);//������13��ʼ����ȫɾ��
s.erase(7,5);//������7��ʼ����ɾ5��

����ȡ�Ӵ����ַ�������:
��ȡ�Ӵ��ĺ����ǣ�substr(),��ʽ���£�
s.substr();//����s��ȫ������
s.substr(11);//������11������Ӵ�
s.substr(5,6);//������5��ʼ6���ַ�
�������ַ�����������ĺ�����+����˭���������µ�120��

�������������:
1��>> ����������ȡһ��string��
2��<< ��һ��stringд���������
��һ����������getline(),������������ȡһ�����ݣ�ֱ���������з������ļ�β��

�����������:
���Һ����ܶ࣬����Ҳ��ǿ�󣬰����ˣ�
    find()
    rfind()
    find_first_of()
    find_last_of()
    find_first_not_of()
    find_last_not_of()
��Щ�������ط��������������ַ������ڵĵ�һ���ַ���������û�ҵ�Ŀ��ͷ���npos�����еĺ����Ĳ���˵�����£�
��һ�������Ǳ���Ѱ�Ķ��󡣵ڶ������������п��ޣ�ָ��string�ڵ���Ѱ������������������������п��ޣ�ָ����Ѱ���ַ��������Ƚϼ򵥣�����˵�����Ŀ������������
������ϸ�Ľ�𡣵�Ȼ������ǿ���STL��Ѱ�ں�������ἰ��
�����˵˵npos�ĺ��壬string::npos��������string::size_type,���ԣ�һ����Ҫ��һ��������npos��ȣ��������ֵ������string::size)type���͵ģ����������£�
���ǿ���ֱ�ӰѺ�����npos���бȽϣ��磺if(s.find(��jia��)==string::npos)����

��string �����б�:
������	����
begin	�õ�ָ���ַ�����ͷ��Iterator
end	�õ�ָ���ַ�����β��Iterator
rbegin	�õ�ָ�����ַ�����ͷ��Iterator
rend	�õ�ָ�����ַ�����β��Iterator
size	�õ��ַ����Ĵ�С(��length������ͬ)
length	��size����������ͬ
max_size	�ַ������ܵ�����С
capacity	�ڲ����·����ڴ������£��ַ������ܵĴ�С
empty	�ж��Ƿ�Ϊ��
operator[]	ȡ�ڼ���Ԫ�أ��൱������
c_str	ȡ��C����const char* �ַ���
data	ȡ���ַ������ݵ�ַ
operator=	��ֵ������
reserve	Ԥ���ռ�
swap	��������
insert	�����ַ�
append	׷���ַ�
push_back	׷���ַ�
operator+=	+= ������
erase	ɾ���ַ���
clear	����ַ���������������
resize	���·���ռ�
assign	�͸�ֵ������һ��
replace	���
copy	�ַ������ռ�
find	����
rfind	�������
find_first_of	���Ұ����Ӵ��е��κ��ַ������ص�һ��λ��
find_first_not_of	���Ҳ������Ӵ��е��κ��ַ������ص�һ��λ��
find_last_of	���Ұ����Ӵ��е��κ��ַ����������һ��λ��
find_last_not_of	���Ҳ������Ӵ��е��κ��ַ����������һ��λ��
substr	�õ��ִ�
compare	�Ƚ��ַ���
operator+	�ַ�������
operator==	�ж��Ƿ����
operator!=	�ж��Ƿ񲻵���
operator<</td>	�ж��Ƿ�С��
operator>>	���������ж����ַ���
operator<<	�ַ���д�������
getline	���������ж���һ��


ʵ��:
#include<iostream>
#include<string> 
using namespace std;
int main()
{
    //��������,����ʼ�� 
    string str("abddassas");
    string str2("ab");
    //���� 
    cin>>str;
    //���str������1
    cout<<str<<endl;
    //�������2�� 
    cout<<str.c_str()<<endl;
    //���ĳһ���ض�Ԫ��
    cout<<str[2];
    //ָ���±�λ�ò���ĳ���ַ��� 
    str.insert(2,str2);
    //β������
    str.insert(str.length(),str2); 
    cout<<str<<endl;
    //ָ��λ��ɾ��
    str.erase(2,2);//���±�2��ʼɾ��������
    cout<<str<<endl; 

	string str("1234567");
    cout << "size=" << str.size() << endl;         // size=7
    cout << "length=" << str.length() << endl;     // length=7
    cout << "max_size=" << str.max_size() << endl; // max_size=4294967294
    cout << "capacity=" << str.capacity() << endl; // capacity=15

    //�ȽϺ���
    cout<<(str1>str2)<<endl;//str1>str2,����1�����򷵻�0��
    //���ƺ��������ַ����еĺ������Ƶ���һ���ַ������С� 
    char ss[8]={0};
    str2.copy(ss,3,0);//��str2�е��ַ����±�0��ʼ����3����ss�� 
    //�����ִ�
    str.find(str2,2)//��str�д��±�2��ʼ����str���Ƿ���str2�����з����ִ��ڴ����±�λ�ã����򷵻�-1.
     //��ӡ�ִ�
     cout<<str.substr(2,4)<<endl;//��2λ�ÿ�ʼ������ӡ4���ַ�
     //�����ַ���
     str.swap(str2);//����str��str2 
     //����ж�һ��string���͵��ַ��������Ƿ�����һ��string���͵��ַ���
    string str1="sda_hello_sds";
    string str2="hello";
    string::size_type idx=str1.find(str2);
    if(idx!=string::npos)
    {
     cout<<"�ַ�������"<<str2��
    }
    else
    cout<<"�ַ���û��"<<str2;
    return 0;
}




ʮ�ߡ�ȡģ����
1��ȡģ��ʽ
(1)ȡģ���㣺a % p��a mod p������ʾa����p��������
(2)ģp�ӷ���(a + b) % p = (a%p + b%p) % p
(3)ģp������(a - b) % p = (a%p - b%p) % p
(4)ģp�˷���(a * b) % p = ((a % p)*(b % p)) % p
(5)��ģp �� (a^b) % p = ((a % p)^b) % p
(6)ģ�����������ɡ������ɺͷ����ɡ�
(7)a��b (mod n) ��ʾa��bģnͬ�࣬��a��b����n��������ȡ�

2������ȡģ

eg:
scanf("%s%d",n,&m);
int len=strlen(n);
int ans=0;
for(int i=0;i<len;i++)
{
   ans=(int)(((long long)ans*10+n[i]-'0')%m);
}
printf("%d\n",ans);






ʮ�ˡ�ACM���������֮scanf()��getchar()��gets()��ϸ���״��
(1)
��һ��Ҫע�ⲻͬ�ĺ����Ƿ���ܿո�����Ƿ��������Ļس���������!
��ȡ�ַ�ʱ��
scanf()��Space��Enter��Tab����һ�����룬�����������Ļس��������س���������ڻ������У���
getchar()��Enter�������룬Ҳ�����������Ļس��������س���������ڻ������У���
��ȡ�ַ���ʱ��
scanf()��Space��Enter��Tab����һ������,����ͬ���ַ���ͨ��Space��Enter��Tab�������֣�
gets()��Enter�������루�ո񲻽����������ܿո�(�ַ����а����ո�TabҲ���ԣ�)�����������Ļس���(�س��������������뻺������)

��scanf���ܽ��ܿո��Ʊ��Tab���س��ȣ� 
��gets�ܹ����ܿո��Ʊ��Tab�ͻس��ȣ� 
�����ַ������ܽ������Զ���\0�� 
scanf ���������س����ո��tab�����Զ����ַ���������ӡ�\0�������ǻس����ո��tab���Ի���������Ļ������С� 
gets���ɽ��ܻس���֮ǰ����������ַ������á�\n����� ��\0��.�س��������������뻺�����С�

���ԣ�gets��scanf������û��ʲô���𣬶��ǽ����ַ�����������getcharֻ�ܽ����ַ��� 
����getsû�����ޣ�ʹ��ʱ�ñ�֤�ռ��㹻���Ա�֤��ȡ�ǲ����������


�ڶ���Ϊ�˱�������������⣬����Ҫ��ջ������Ĳ������ݣ����������µķ��������
����1��C�������ṩ�˺�����ջ�������ֻҪ�ڶ�����֮ǰ����ջ�������û�����ˣ�
  ���������fflush(stdin)��
����2���Լ�ȡ����������Ĳ������ݡ�
��˵ʵ����������Ҳû�������Ǻǣ�Ϊʲô��ʽ�����������ģ�ϣ������ָ��һ�£���
 scanf("%[^\n]",string);


(2)ǰ���հ�����:
ÿһ��������Ҫ��ӡ�س���\n�����������һ��
���룺scanf, fgets(gets), getchar
scanf
�����ʽ
%d %lld  %c %s %lf
��ÿ�ָ�ʽ�����һ����Ҫ����
�Ƿ��Զ�����ǰ���հף�
ʲô�ǿհף��ո�TAB���س�
ע��:%d %lld %lf�Զ�ɨ��ǰ���ո�

��һ���ǿհ��ַ��ķ���:
����һ:
char str[2];
scanf(��%1s��, str);
// %sɨ��ǰ���հף�����ֻ��һ���ַ�
char c = str[0];
������:
ǿ��ɨ��հ�
��%ǰ�����һ���ո��ʾ��ǿ��ɨ��ǰ���հס�
scanf(�� %c��, &ch);
ǰ���Ǹ���������Ϣ������scanf��䣺
scanf(��%s %c %s��, name, &gender, ability);


(3)
���Ҫ��������ַ�����Ҫ���пո�ģ���δ����أ�
��һ�У�gets, fgets
gets�ᵼ�º������warning message�����Կɸ���fgets
fgets(str, sizeof str, stdin) = gets(str)
ע��Ӧʹ����һ���ַ���������һ�п�ͷ



