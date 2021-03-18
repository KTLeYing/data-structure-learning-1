一、常用的顺序表的结构定义、初始化、创建（几种情况）
(1)【一般用于查找、排序算法】
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
{                               //表L中封装着data指针（地址），即为数组data[],和表的长度
   L.data=new ElemType[MAX];   //data指向ElemType的一个数组，所以data也是一个数组，即表示为("data[]"),data是数组名，首地址，然后ElemType是一个自定义数据类型;
   if(!L.data)                //ElemType中又包含着int的key（数据、关键字）和int的其他数据，即表示为("L.data[].key")
      exit(OVERFLOW);          //三层嵌套，即SqList L包含着装数据的data数组，data数组（因为对于ElemType）的每个元素有包含着key关键字（即最终书局）
   L.length=0;
}

int CreatList(SqList &L)
{
    int i,n;
    cout<<"输入数据的数量:";
    cin>>n;
    cout<<"请输入数据:";
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



(2)【和(1)相似，有key】
typedef struct
{
  int key;
  char *otherinfo;
}ElemType;
//顺序表的存储结构
typedef struct
{
    ElemType *r;                //存储空间的基地址
    int  length;                  //顺序表长度
}SqList;           //顺序表类型


void Create_Sq(SqList &L)
{
  int i,n;
  cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
  cin>>n;           //输入个数
  cout<<"请输入待排序的数据:\n";
 while(n>MAXSIZE)
 {
   cout<<"个数超过上限，不能超过"<<MAXSIZE<<"，请重新输入"<<endl;
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


(3)【和(2)相似，少了定义InitList函数的步骤】
typedef struct
{
  int key;
  char *otherinfo;
}ElemType;
//顺序表的存储结构
typedef struct
{
    ElemType *r;                //存储空间的基地址
    int  length;                  //顺序表长度
}SqList;           //顺序表类型


void Create_Sq(SqList &L)
{
  L.r=new ElemType[MAXSIZE+1];
   L.length=0;
   int i,n;
  cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
  cin>>n;           //输入个数
  cout<<"请输入待排序的数据:\n";
 while(n>MAXSIZE)
 {
   cout<<"个数超过上限，不能超过"<<MAXSIZE<<"，请重新输入"<<endl;
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



(4)【一般的，无key，一次输入保存多个数组在表中，用for循环】【一般用于普通的线性表存储】
Typedef int ElemType;
Typedef struct
{
   ElemType *data;    //SqList封装着data数组（data[]）和长度；data指针==数组，*data==data[];指向首地址
   int length;
}SqList;

int InitList(SqList &L)
{
   L.data=new ElemType[MAX];      //data指向ElemType数据类型的数组的首地址，即data[]为一个数组，而且data类型也为ElemType的数据类型，此处分配一个最大MAX的长度
   if(!L.data)                    //的数组，然后ElemType也被定义为int类型
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

(5)【与（4）相似，这里一次保存一个数据在表中】
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
    cout<<"(1)初始化顺序表"<<endl;
    InitList(L);
    cout<<"(2)一次用尾插法插入a,b,c,d,e元素"<<endl;
    CreatLis(L,'a',1);
    CreatLis(L,'b',2);
    CreatLis(L,'c',3);
    CreatLis(L,'d',4);
    CreatLis(L,'e',5);
}



二、C++和C语言的字符串（字符数组）的输入和输出
(1)C++:
①
char str[20];                            //PS:此形式只适用于字符串和，字符数组，不能用于整型int
cin>>str; //用字符数组名输入字符串
cout<<str; //用字符数组名输出字符串

在运行输入一个字符串，如：China
在内存中，数组str的状态如图5.9所示，在5个字符的后面自动加了一个结束符'\0'。
输出时，逐个输出字符直到遇结束符′\0′，就停止输出。输出结果为：China
②
// char str[5] = "hello";//编译失败、提示字符串太长
char str[] = { '1', '2', '3', '4' }; //可以编译通过, 可是打印直到遇到\0才结束
cout << str << " " << sizeof(str) << endl;

打印结果: 12340@ 4
str 的长度为 4
但是打印的时候会出问题，知道遇到\0才会结束
③
char str[] = "hello world";
cout << str << " " << sizeof(str) << endl;
cout << "请输入一行字符串" << endl;
4 cin >> str;  // 123 hello worl
cout << "str的值为 " << str << endl; //str的值为 heelo (遇到第一个[空格、制表符、换行符]即结束输入)
cin.getline(str, 20); //最多输入19个字符, 最后一个字符是\0  但是str定义的长度为12,
cout << "str的值为" << str << " " << sizeof(str) << endl;

str的长度为12 末尾自动加一个空白符\0
在第四行输入 123 hello world
然后str赋值为 123
然后继续cin.getLine 
str=" hello worl" 注意hello前面的空格一起输入到str中了。这个时候 str的长度已经为12了。如果在接着输入更多字符，程序会出现异常

(2)C语言:
①scanf输入，printf输出:
scanf对字符串的输入有%s和%c两种格式。%c格式用来输入单个字符，它能够识别空格和换行符并将其保存到字符数组中；%s格式用来输入一个字符串，它通过空格和换行来识别一个字符串的结束。也就是说使用%s格式输入并保存到字符数组中的字符串是不含空格的。下面是一个实例：

#include <stdio.h>
int main(){
    char str[10];
    scanf("%s", str);
    printf("%s", str);
    return 0;
}

输入字符串“abc def ghi”，输出的结果为“abc”。可以看到，%s识别空格作为字符串的结尾，因此第一个空格后面的字符都不会被读入。
②getchar输入，putchar输出:
getchar和putchar分别用来输入和输出单个字符。getchar可以识别换行符和空格并将其保存。下面是一个例子：

#include <stdio.h>
int main(){
    char c1, c2, c3;
    c1 = getchar();     //getchar只能输入单个字符 
    c2 = getchar();
    c3 = getchar();		    
    putchar(c1);
    putchar(c2);
    putchar(c3);
    return 0;
}

在这里我们如果输入“a“，然后敲回车，然后输入”bc“，再敲回车，输出的结果会是这样：a b
这是由于getchar可以识别换行符，所以c2实际上存储的是换行符，因此字符c没有被存入，字符ab之间会有一个换行出现。

③gets输入，puts输出:
gets用来输入一行字符串并将其存放于一维数组（或二维数组的一维）中，读取字符串直到换行符结束，但换行符会被丢弃，然后再末尾添加‘\0’，它与scanf(”%s“, s)相似，但不完全相同，gets可识别空格并将其输入。puts函数会自动换行。下面是一个例子:

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

输入下面几个字符串：
abc def
QAQ
T_T
WoAiNi



三、连续输入多组测试用例的算法

(1)一般对于字符数组的输入:
while((ch=getchar())!='\n')
{

}
●(2)
while(cin>>a)
{

}
//或者
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
●while(1)
{
	......
	if(a == -1 && b == -1) //退出测试的条件
		break;
}
(4)用for循环:
for(i=1;i<n;i++)
{
}
●(5)
while(scanf("%d",&n)!=EOF,n)     
{
}
//或者写成
while(scanf("%d",&n)!=EOF)     //改为while((cin>>n)!=EOF)是不可以的，此处不用用cin（特殊）
{
	.....
    if(n==0)
		break;
}
//然后在循环里加一句if(n==0)break;
//或者
int main()
{
    char a[3],t;
    int i,j;
    while(scanf(" %c %c %c",&a[0],&a[1],&a[2])!=EOF)//这里数组元素前应该加&
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
●(6)
int main()
{
   int a,b;
   while( scanf("%d%d",&a，&b )!= EOF ) //输入直到文件结束，当出现EOF时，结束测试
   {
        printf("%d\n\n",a+b ); //一行一个结果，结果输完后还有一个回车
   }
   return 0;
}
●(7)
int main()
{
    int n,sum;
    while( scanf( "%d" , &n ) != EOF ) //输出到文件结尾
	{
        int x;
        sum = 0;
        while( n-- ) //控制该组输入个数
		{
           scanf( "%d" , &x );
           sum += x;
		}
        printf( "%d\n" , sum ); //一行一个结果
	}
     return 0;
}
(8)
while( scanf( "%d%d" , &a , &b ) && (a||b) ) //输入直到满足a和b均为0结束
{
    printf( "%d\n" , a+b ); //一行一个结果
}
//或者(原理一样)
int main()
{
   int n,sum;
   while( scanf( "%d" , &n ) && n ) //每组case前有一个控制该组输入数据的数，为0结束
   {
       int x;
       sum = 0;
       while( n-- ) //控制该组输入个数
	   {
           scanf( "%d" , &x );
           sum += x;
	   }
       printf( "%d\n" , sum ); //一行一个结果
   }
   return 0;
}
●(9)
while(scanf("%d",&n)==1)  //为真
{
   if(n==0)     //退出测试的条件
	   break;
   sum=0;      //普通测试代码
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
   char buf[100000]={0};//最终输出缓冲
   char buf0[10];//中间结果缓存
   int a=1,b=1,c;//初始条件不是全0就可以

   while(a||b)   //连续进行多组测试的条件(当a和b都不为空设时)
   {
      scanf("%d%d",&a,&b);//读取两个整数,存于变量a和b中
      fflush(stdin);//清空键盘输入缓冲区 保证一行最多取两个数 多余的或其它非数字的被忽略
      sprintf(buf0,"%d\n",a+b);//输出a+b结果加回车号\n 存到串buf0
      if(a||b)//结束的最后一项不输出
          strcat(buf,buf0);//追加到最终输出缓冲中
   }
   printf("\n%s",buf);//输出最终结果
}


(11)【ACM常用】:●●●
①用C++写:
#include <iostream>
using namespace std;
int a,b;
while(cin>>a>>b)
{
    cout<<a+b<<endl;
}
//或者(对于一个变量)
while(cin>>a)
{
    cout<<a<<endl;
}
②用C写:                           
#include <stdio.h>
int a,b;                                   //关于EOF的解释:【用于scanf输入函数中】
while(scanf("%d%d",&a,&b)!=EOF)            //使用istream对象作为循环的判断条件，检测流的状态。如果流是有效的，即流未遇到错误，那么检测成功。
{ //改为while((cin>>n)!=EOF)是不可以的，  //当遇到文件结束符（EOF）或者遇到一个无效输入时istream对象的状态就会变为无效。处于无效状态的istream对象会使条件变假
	//此处不用用cin（特殊）               //用C语言的的方法，把输入语句作为while循环的判断条件，当输入数据不是文件结束符（EOF）的时候，就可以实现连续输入      
    printf("%d+%d\n",a+b);                                 
}  
//或者
while(~scanf("%d", &n))
{
    /*
     *code
    */
}                               




四、关于字符串(string)和字符串函数

C++提供了一种新的数据类型——字符串类型(string类型),在使用方法上,它和char?int类型一样,可以用来定义变量,这就是字符串变量——用一个名字代表一个字符序列

实际上,string并不是C++语言本身具有的基本类型,它是在C++标准库中声明的一个字符串类,用这种类可以定义对象?每一个字符串变量都是string类的一个对象

(1)字符串变量的定义和引用
1. 定义字符串变量
和其他类型变量一样,字符串变量必须先定义后使用,定义字符串变量要用类名string
如:
string string1; //定义string1为字符串变量
string string2=″China″; //定义string2同时对其初始化
应当注意: 要使用string类的功能时,必须在本文件的开头将C++标准库中的string头文件包含进来,即应加上
#include <string> //注意头文件名不是string.h

2. 对字符串变量的赋值
在定义了字符串变量后,可以用赋值语句对它赋予一个字符串常量,如
string1=″Canada″;
既可以用字符串常量给字符串变量赋值,也可以用一个字符串变量给另一个字符串变量赋值?如
string2=string1; //假设string2和string1均已定义为字符串变量
不要求string2和string1长度相同,假如string2原来是″China″,string1原来是″Canada″,赋值后string2也变成″Canada″?在定义字符串变量时不需指定长度,
长度随其中的字符串长度而改变

可以对字符串变量中某一字符进行操作,如
string word=″Then″; //定义并初始化字符串变量word
word[2]=′a′; //修改序号为2的字符,修改后word的值为″Than″

3. 字符串变量的输入输出
可以在输入输出语句中用字符串变量名,输入输出字符串,如
cin>> string1; //从键盘输入一个字符串给字符串变量string1
cout<< string2; //将字符串string2输出

 

(2)字符串变量的运算
在上一节中可以看到: 在以字符数组存放字符串时,字符串的运算要用字符串函数,如strcat(连接) strcmp(比较) strcpy(复制),而对string类对象,可以不用这些函数,
而直接用简单的运算符

 

字符串复制用赋值号
string1=string2;
其作用与“strcpy(string1,string2);”相同
字符串连接用加号
string string1=″C++″; //定义string1并赋初值
string string2=″Language″;//定义string2并赋初值
string1=string1 + string2;//连接string1和string2
连接后string1为″C++ Language″
字符串比较直接用关系运算符
可以直接用 ==(等于)>(大于)<(小于)!=(不等于)>=(大于或等于)<=(小于或等于)等关系运算符来进行字符串的比较
使用这些运算符比使用5.5.5节中介绍的字符串函数直观而方便?
 

(3)字符串数组
不仅可以用string定义字符串变量,也可以用string定义字符串数组
如:
string name[5]; //定义一个字符串数组,它包含5个字符串元素
string name[5]={″Zhang″,″Li″,″Fun″,″Wang″,″Tan″};
//定义一个字符串数组并初始化


关于字符串数组的几点说明：

在一个字符串数组中包含若干个(现为5个)元素,每个元素相当于一个字符串变量
并不要求每个字符串元素具有相同的长度,即使对同一个元素而言,它的长度也是可以变化的,当向某一个元素重新赋值,其长度就可能发生变化
在字符串数组的每一个元素中存放一个字符串,而不是一个字符,这是字符串数组与字符数组的区别?如果用字符数组存放字符串,一个元素只能存放一个字符,
用一个一维字符数组存放一个字符串

每一个字符串元素中只包含字符串本身的字符而不包括′\0′

可见用字符串数组存放字符串以及对字符串进行处理是很方便的?

在定义字符串数组时怎样给数组分配存储空间呢?实际上,编译系统为每一个字符串变量分配4个字节,在这个存储单元中,并不是直接存放字符串本身,
而是存放字符串的地址,在本例中,就是把字符串″Zhang″的地址存放在name[0],把字符串″Li″ 的地址存放在name[1],把字符串″Fun″的地址存放在name[2]

(4)字符串连接函数 strcat
其函数原型为
strcat(char[],const char[]);
strcat是string catenate(字符串连接)的缩写?该函数有两个字符数组的参数,函数的作用是:将第二个字符数组中的字符串连接到前面字符数组的字符串的后面,
第二个字符数组被指定为const,以保证该数组中的内容不会在函数调用期间修改?连接后的字符串放在第一个字符数组中,函数调用后得到的函数值,就是第一个字符数组的地址
例如:
char str1[30]="People" s Republic of ″;
char str2[]="China";
cout<<strcat(str1,str2));//调用strcat函数
输出:
People" s Republic of China


(5)字符串复制函数strcpy
其函数原型为
strcpy(char[],const char[]);
strcpy是string copy(字符串复制)的缩写?它的作用是将第二个字符数组中的字符串复制到第一个字符数组中去,将第一个字符数组中的相应字符覆盖?例如
char str1[10],str2[]=″China″;
strcpy(str1,str2);
执行后,str2中的5个字符″China″和′\0′(共6个字符)复制到数组str1中

关于字符串复制函数strcpy的几点说明：

在调用strcpy函数时,第一个参数必须是数组名(如str1),第二个参数可以是字符数组名,也可以是一个字符串常量?
可以用strcpy函数将一个字符串中前若干个字符复制到字符数组中去?
只能通过调用strcpy函数来实现将一个字符串赋给一个字符数组,而不能用赋值语句将一个字符串常量或字符数组直接赋给一个字符数组
 

(6)字符串比较函数strcmp
其函数原型为
strcmp(const char[],const char[]);
strcmp是string compare(字符串比较)的缩写作用是比较两个字符串,由于这两个字符数组只参加比较而不应改变其内容,因此两个参数都加上const声明,以下写法是合法的:
strcmp(str1,str2);            // =0,则str1=str2;  >0,则str1>str2;  <0,则str1<str2
strcmp("China","Korea");
strcmp(str1,"Beijing");

比较的结果由函数值带回:
如果字符串1=字符串2,函数值为0
如果字符串1>字符串2,函数值为一正整数
如果字符串1<字符串2,函数值为一负整数

字符串比较的规则与其他语言中的规则相同,即对两个字符串自左至右逐个字符相比(按ASCII码值大小比较),直到出现不同的字符或遇到′\0′为止?如全部字符相同,则认为相等;
若出现不相同的字符,则以第一个不相同的字符的比较结果为准

注意:对两个字符串比较,不能用以下形式:
if(str1>str2) cout<<″yes″;
字符数组名str1和str2代表数组地址,上面写法表示将两个数组地址进行比较,而不是对数组中的字符串进行比较,对两个字符串比较应该用 
if(strcmp(str1,str2)>0) cout<<″yes″;

 

(7)字符串长度函数strlen
函数原型为:
strlen(const char[]);
strlen是string length(字符串长度)的缩写?它是测试字符串长度的函数?其函数的值为字符串中的实际长度,不包括′\0′在内
如:
char str[10]="China";
cout<<strlen(str);
输出结果不是10,也不是6,而是5




五、小端和大端模式:

 （1）什么是大端和小端
 Big-Endian和Little-Endian的定义如下：
   1.Little-Endian就是低位字节排放在内存的低地址端，高位字节排放在内存的高地址端。
   2.Big-Endian就是高位字节排放在内存的低地址端，低位字节排放在内存的高地址端。
举一个例子，比如数字0x12 34 56 78在内存中的表示形式为：
1)大端模式：

低地址 -----------------> 高地址
0x12 ?| ?0x34 ?| ?0x56 ?| ?0x78
2)小端模式：

低地址 ------------------> 高地址
0x78 ?| ?0x56 ?| ?0x34 ?| ?0x12
可见，大端模式和字符串的存储模式类似。

3.下面是两个具体例子：

16bit宽的数0x1234在Little-endian模式（以及Big-endian模式）CPU内存中的存放方式（假设从地址0x4000开始存放）为：

内存地址	小端模式存放内容	大端模式存放内容
0x4000	0x34	0x12
0x4001	0x12	0x34
32bit宽的数0x12345678在Little-endian模式以及Big-endian模式）CPU内存中的存放方式（假设从地址0x4000开始存放）为：

内存地址	小端模式存放内容	大端模式存放内容
0x4000	0x78	0x12
0x4001	0x56	0x34
0x4002	0x34	0x56
0x4003	0x12	0x78

 4.大端小端没有谁优谁劣，各自优势便是对方劣势：

小端模式 ：强制转换数据不需要调整字节内容，1、2、4字节的存储方式一样。
大端模式 ：符号位的判定固定为第一个字节，容易判断正负。

(2)数组在大端小端情况下的存储：
　　以unsigned int value = 0x12345678为例，分别看看在两种字节序下其存储情况，我们可以用unsigned char buf[4]来表示value：
　　Big-Endian: 低地址存放高位，如下：
高地址
 ---------------
 buf[3] (0x78) -- 低位
 buf[2] (0x56)
 buf[1] (0x34)
 buf[0] (0x12) -- 高位
 ---------------
 低地址
Little-Endian: 低地址存放低位，如下：
高地址
 ---------------
 buf[3] (0x12) -- 高位
 buf[2] (0x34)
 buf[1] (0x56)
 buf[0] (0x78) -- 低位
 --------------
低地址


(3).为什么会有大小端模式之分呢
   这是因为在计算机系统中，我们是以字节为单位的，每个地址单元都对应着一个字节，一个字节为8bit。但是在C语言中除了8bit的char之外，还有16bit的short型，32bit的long型（要看具体的编译器），另外，对于位数大于8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如果将多个字节安排的问题。因此就导致了大端存储模式和小端存储模式。例如一个16bit的short型x，在内存中的地址为0x0010，x的值为0x1122，那么0x11为高字节，0x22为低字节。对于大端模式，就将0x11放在低地址中，即0x0010中，0x22放在高地址中，即0x0011中。小端模式，刚好相反。我们常用的X86结构是小端模式，而KEIL C51则为大端模式。很多的ARM，DSP都为小端模式。有些ARM处理器还可以由硬件来选择是大端模式还是小端模式。

(4).如何判断机器的字节序
可以编写一个小的测试程序来判断机器的字节序：
BOOL IsBigEndian()
{
	int a = 0x1234;
	char b =  *(char *)&a;  //通过将int强制类型转换成char单字节，通过判断起始存储位置。即等于 取b等于a的低地址部分
	if( b == 0x12)
	{
		return TRUE;
	}
	return FALSE;
}
联合体union的存放顺序是所有成员都从低地址开始存放，利用该特性可以轻松地获得了CPU对内存采用Little-endian还是Big-endian模式读写：
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

 (5).常见的字节序
一般操作系统都是小端，而通讯协议是大端的。
 1. 常见CPU的字节序
Big Endian : PowerPC、IBM、Sun
Little Endian : x86、DEC
ARM既可以工作在大端模式，也可以工作在小端模式。

 2. 常见文件的字节序
Adobe PS – Big Endian
BMP – Little Endian
DXF(AutoCAD) – Variable
GIF – Little Endian
JPEG – Big Endian
MacPaint – Big Endian
RTF – Little Endian

(6).如何进行转换
对于字数据（16位）：
#define BigtoLittle16(A)   (( ((uint16)(A) & 0xff00) >> 8)    ||
                                       (( (uint16)(A) & 0x00ff) << 8))
对于双字数据（32位）：


#define BigtoLittle32(A)   ((( (uint32)(A) & 0xff000000) >> 24) ||
                                       (( (uint32)(A) & 0x00ff0000) >> 8)   ||
                                       (( (uint32)(A) & 0x0000ff00) << 8)   ||
                                       (( (uint32)(A) & 0x000000ff) << 24))

eg1:(电子地图实训用到)
 #define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //反转短整形的16位进制码
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//反转长整型的16进制码

#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //获取是否有道路名称
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //获取分支数
#define GET_DISPCLASS(__data__) (__data__&0x0f)                //获取分类号

(7)、从软件的角度理解端模式
 从软件的角度上，不同端模式的处理器进行数据传递时必须要考虑端模式的不同。如进行网络数据传递时，必须要考虑端模式的转换。在Socket接口编程中，以下几个函数用于大小端字节序的转换。
#define ntohs(n)     //16位数据类型网络字节顺序到主机字节顺序的转换
#define htons(n)     //16位数据类型主机字节顺序到网络字节顺序的转换
#define ntohl(n)      //32位数据类型网络字节顺序到主机字节顺序的转换
#define htonl(n)      //32位数据类型主机字节顺序到网络字节顺序的转换

其中互联网使用的网络字节顺序采用大端模式进行编址，而主机字节顺序根据处理器的不同而不同，如PowerPC处理器使用大端模式，而Pentuim处理器使用小端模式。
大端模式处理器的字节序到网络字节序不需要转换，此时ntohs(n)=n，ntohl = n；而小端模式处理器的字节序到网络字节必须要进行转换，此时ntohs(n) = __swab16(n)，ntohl = __swab32(n)。__swab16与__swab32函数定义如下所示。
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
 PowerPC处理器提供了lwbrx，lhbrx，stwbrx，sthbrx四条指令用于处理字节序的转换以优化__swab16和__swap32这类函数。此外PowerPC处理器中的rlwimi指令也可以用来实现__swab16和__swap32这类函数。
在对普通文件进行处理也需要考虑端模式问题。在大端模式的处理器下对文件的32，16位读写操作所得到的结果与小端模式的处理器不同。单纯从软件的角度理解上远远不能真正理解大小端模式的区别。事实上，真正的理解大小端模式的区别，必须要从系统的角度，从指令集，寄存器和数据总线上深入理解，大小端模式的区别。




六、读写文件的一些常用函数和区别

(1)
fread(buffer,size,count,fp) 【一般与char字符类型连用】    
从fp所指 的文件读入一个数据块。size—读入的字节数，count—读入多少个size字节数据， buffer—读入数据存放内存的起始地址。正常返回count的值。
eg1:(读取一般的代码)【与下面写入文件的eg1的fwrite配对】
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
    if(fread(buffer,sizeof(int),4,fp)!=4)   //可以一次读取
    {
        printf("file read error\n");
        exit(0);
    }
    
    for(int i=0;i<4;i++)
        printf("%d\n",buffer[i]);
    return 0;
}

eg2:(读取结构体)【与下面写入文件的eg2的fwrite配对】
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

    while(fread(&per,sizeof(people),1,fp)==1)   //如果读到数据，就显示；否则退出
    {
        printf("%d %s\n",per.age,per.name);
    }
    return 0;
}


fwrite(buffer,size, count,fp)   【一般与char字符类型连用】
在fp所指文件写入一个数据块。size—写入的字节数，count—写入多少个size字节数据，buffer—写入数据在内存的首地址。正常返回count 的值。
eg1:(写入一般的代码)
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
   //可以写多个连续的数据(这里一次写4个)
   fwrite (buffer , sizeof(char), 4, pFile);   //如果是buffer数组名，不用取址符号&,已经是地址，首地址;
   //或
	/*
     for(i=0;i<4;i++)
	    fwrite(&buffer[i],sizeof(int),1,pFile);    //如果是buffer[i],则要&符号取地址，即&buffer[i]
  */
   fclose (pFile);
   return 0;
}

eg2:(写入结构体)
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



fprintf(fp, 格式控制串，输出表列)  【与任何数据类型（char、int、float）连用都行】
输出表列中的数据，按格式控制串 的格式写入由fp所指的文件。


fscanf(fp,格式控制串, 输入表列)   【与任何数据类型（char、int、float）连用都行】
由fp所指文件按格式控制串的格式 读入数据，依次赋给输入表列中相应变量


(2)区别：
C语言把文件看作一个字符（字节）的序列，即由一个一个字符（字节）的数据顺序组成。根据数据的组织形式，可分为ASCII文件和二进制文件.
ASCII文件又称为文本（text）文件，它的每个字节放一个ASCII代码，代表一个字符。二进制文件是把内存中的数据按其在内在中的存储形式原样输出到磁盘上存放。

fprintf(fp, "%d", buffer); 是将格式化的数据写入文件
fprintf(文件指针,格式字符串,输出表列);

fwrite(&buffer, sizeof(int), 1, fp);是以二进位方式写入文件
fwrite(数据，数据类型大小（字节数），写入数据的最大数量，文件指针);

由于fprintf写入时，对于整数来说，一位占一个字节，比如1，占1个字节；10，占2个字节；100，占3个字节，10000，占5个字节
所以文件的大小会随数据的大小而改变，对大数据空间占用很大。
而fwrite是按二进制写入，所以写入数据所占空间是根据数据类型来确定，比如int的大小为4个字节（一般32位下），那么整数10所占空间为4个字节，
100、10000所占空间也是4个字节。所以二进制写入比格式化写入更省空间。


(3)其他的文件相关的函数:

1.fopen()函数：
a.作用:
在C语言中fopen()函数用于打开指定路径的文件，获取指向该文件的指针。

b.函数原型：
FILE * fopen(const char * path,const char * mode);

-- path: 文件路径，如："F:\Visual Stdio 2012\test.txt"

-- mode: 文件打开方式，例如：

r:以只读方式打开文件，该文件必须存在。
r+:以读/写方式打开文件，该文件必须存在。
rb:以读/写方式打开一个二进制文件，只允许读数据。（比较常用）
rb+:以读/写方式打开一个二进制文件，只允许读/写数据。
rt+:以读/写方式打开一个文本文件，允许读和写。
w:打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件。
w+:打开可读/写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
a:以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留（EOF符保留）。
a+:以附加方式打开可读/写的文件。若文件不存在，则会建立该文件，如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留（原来的 EOF 符不保留）。
wb:以只写方式打开或新建一个二进制文件，只允许写数据。
wb+:以读/写方式打开或建立一个二进制文件，允许读和写。
wt+:以读/写方式打开或建立一个文本文件，允许读写。
at+:以读/写方式打开一个文本文件，允许读或在文本末追加数据。
ab+:以读/写方式打开一个二进制文件，允许读或在文件末追加数据。

有"+":可读写
无"+":只可读或只可写
t:文本文件
b:二进制文件
--返回值: 文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在errno中。


2.fwrite()函数：
a.作用：
在C语言中fwrite()函数常用语将一块内存区域中的数据写入到本地文本。

b.函数原型：
size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);

-- buffer:指向数据块的指针

-- size:每个数据的大小，单位为Byte(例如：sizeof(int)就是4)

-- count:数据个数

-- stream:文件指针

c.注意：返回值随着调用格式的不同而不同：
 调用格式1：fwrite(buf,sizeof(buf),1,fp);
 成功写入返回值为1(即count)

调用格式2：fwrite(buf,1,sizeof(buf),fp);
成功写入则返回实际写入的数据个数(单位为Byte)

 注意事项:
 写完数据后要调用fclose()关闭流，不关闭流的情况下（文件将始终处于打开状态占用内存），每次读或写数据后，文件指针都会指向下一个待写或者读数据位置的指针。


3.fprintf()函数：
a.作用：
传送格式化输出到一个文件中

b.用 法
#include <stdio.h>
int fprintf( FILE *stream, const char *format, ... );
fprintf()函数根据指定的format(格式)(格式)发送信息(参数)到由stream(流)指定的文件.???

c.返回值
成功时返回转换的字节数，失败时返回一个负数.
在LINUX/UNIX操系统中成功返回0，失败返回-1。并置errno值.

4.fgets()函数:
 char *fgets(char *s, int size, FILE *stream);    //读取的是字符串，比如“ajkjc”
其中：s 代表要保存到的内存空间的首地址，可以是字符数组名，也可以是指向字符数组的字符指针变量名。size 代表的是读取字符串的长度。stream 表示从何种流中读取，
可以是标准输入流 stdin，也可以是文件流，即从某个文件中读取，
eg1:
# include <stdio.h>
int main(void)
{
    char str[20];  /*定义一个最大长度为19, 末尾是'\0'的字符数组来存储字符串*/
    printf("请输入一个字符串:");
    fgets(str, 7, stdin);  /*从输入流stdin即输入缓冲区中读取7个字符到字符数组str中*/【也可以从文件中读取，也可从标准流(即键盘)中读取】
    printf("%s\n", str);
    return 0;
}


eg2:
#include <stdio.h>
 
int main()
{
   FILE *fp;
   char str[60];
 
   /* 打开用于读取的文件 */
   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("打开文件时发生错误");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL )    /*从文件中读取60个字符到字符数组str中*/
   {
      /* 向标准输出 stdout 写入内容 */
      puts(str);
   }
   fclose(fp);
   return(0);
}


eg3:
#include<stdio.h>
/**
*需求：把这个文件的源代码打印输出（test.c）
*/
int main(void){
   FILE * file；
   char c;
   //打开文件
   file = fopen("test,c","r");
   if (!file){
       printf("文件打开失败\n");
       return 1;
    }
    while (1){
       c=fgetc(file);
       if(c==EOF) {      //EOF==-1
          break；
       }
       printf("%c",c);
    }
    /*while(c=fgets(file)!=EOF){
    *          printf("%c",c);
    */  } 
    return 0;
}


5.fgetc()函数:
读取的是一个个字符，比如'c',从数据流stream指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节。
格式：int fgetc(FILE *stream);

fgets()和fgetc()实例:
#include <string.h>
#include <stdio.h>
int main(void)
{
 FILE *stream;
 char string[100],c; 
 stream = fopen("fan.txt", "r+");  /* 打开一个文本*/
 fgets(string,99, stream);  /* 读取文本中第一行 */
 printf("%s", string); /* 在控制台显示该行文字 */
 c = fgetc(stream);//读取文本第二行第一个字符
 putchar(c); //在控制台显示该字符
 fclose(stream); //关闭文件
 return 0;
}

6.fputs()函数:  
int fputs(buffer, fp)             
向文件中输出字符串

eg:                     //fputs与fgets连用要借助一个数组
#include <stdio.h>

#define MYPWD "/home/chenw/c/test.txt"
#define SIZE 1000

int 
main(void)
{
  FILE *fp;
  char buffer[SIZE];　//分配内存空间

  if ((fp = fopen(MYPWD, "a")) == NULL) {
  　　printf("can't open the file\n");
  }
  while (fgets(buffer, SIZE, stdin) != NULL) {　//从标准输入将size-1个字符到字符数组中
  　　fputs(buffer, fp);　//把字符串输出到文件中
  　　fputs(buffer, stdout);　//把字符串输出到标准输出
  }
  fclose(fp);
  return 0;
}


7.fputc()函数:
向文件中输入单个字符

eg:
#include <stdio.h>

#define MYPWD　"/home/chenw/c/test.txt"

int main(void)
{
  FILE *fp;
  char c;

  if ((fp = fopen(MYPWD, "a")) == NULL)
  {
  　　printf("can't open the file\n");
  }
  while ((c=getchar()) != EOF) 
  {　//从标准输入读入字符
  　　fputc(c,fp);　//把字符输出到文件中
  　　putchar(c);　//把字符输出到标准输出
  }
  fclose(fp);
  return 0;
}


8.ftell()函数
ftell一般用于读取文件的长度，ftell函数用于得到文件位置指针当前位置相对与文件首的偏移字节。

long len = ftell(fp)   //ftell用于读取文件的长度

eg1：
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
   long f1;      /* 此处将f1设置为long 可以读取更长的文件 */
   myf = fopen( "1.txt", "rb" );
   fseek( myf, 0, SEEK_END );
   f1 = ftell( myf );
   fclose( myf );
   printf( " % d \ n ", f1 );
}

9.fseek()函数
int fseek(FILE * stream, long offset, int whence);
函数说明：
fseek()用来移动文件流的读写位置.

a、参数stream 为已打开的文件指针,
b、参数offset 为根据参数whence 来移动读写位置的位移数。
c、参数 whence 为下列其中一种:
     SEEK_SET 从距文件开头offset 位移量为新的读写位置. SEEK_CUR 以目前的读写位置往后增加offset 个位移量.
     SEEK_END 将读写位置指向文件尾后再增加offset 个位移量. 当whence 值为SEEK_CUR 或
     SEEK_END 时, 参数offset 允许负值的出现.

下列是较特别的使用方式:
a、欲将读写位置移动到文件开头时:fseek(FILE *stream, 0, SEEK_SET);
b、 欲将读写位置移动到文件尾时:fseek(FILE *stream, 0, 0SEEK_END);

返回值：当调用成功时则返回0, 若有错误则返回-1, errno 会存放错误代码.

附加说明：fseek()不像lseek()会返回读写位置, 因此必须使用ftell()来取得目前读写的位置.

范例:
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
执行：
offset = 5
offset = 0
offset = 10




(4)实例:
a.fwrite,fread 读写的时候，我发现不管使用FILE* pFile = fopen(“myfile.bin”, “wb”);无论是使用“wb”还是“w”,最后写出的数据均是乱码，所以内容是不可读的。
但是安全性好，我们后来就使用fwrite,fread 读写model.而 fprintf,fscanf是可视的。 
b. 使用fwrite,fread 读写文件的时候，切记注意变量的格式，举个例子：

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


我读入一个double类型数据，但是想以float型写入文件，然后再以float读入，发现读出的数据b是错的。原因在于一个double类型，读入sizeof(float)个字节，会发生截断，
所以数据是错误的。应该改为：

#include <stdio.h>
#include <string.h>


int main()
{
    FILE * pFile;
    pFile = fopen("myfile.bin", "wb");
    double  a = 5.1615665161; 
    float  atemp = a;                            //把double的a转换为float的a   
    fwrite(&atemp, sizeof(float), 1, pFile);
    rewind(pFile);
    pFile = fopen("myfile.bin", "rb");
    double b ;
    float btemp;                               //把double的b转换为float的b
    fread(&btemp, sizeof(float), 1, pFile);
    b = btemp;
    return 0;
}
也就是必须坚持以原数据的原有格式去读写。 

c. 多次打开文件，写数据的方式 
一般我们使用：

FILE *fp = NULL;
fp = fopen(saved_file_name.txt, "ab");

a即附加的意思。读的时候，如果我们先读入部分数据，再将文件关掉，然后再打开文件，继续读下一行的数据，可以使用 
long offset = ftell(fp); 
先记下之前读文本的指针位置偏移量，然后下一次打卡文件，将文件指针从头偏移offset量即可。

FILE *fp = fopen(forest_file_name.txt, "rb");
fseek(fp, offset, 0);


10.putw()函数
作用:putw()函数用于向文件流中写入整数
头文件:#include<stdio.h>
原型为:int putw( int w, FILE *stream );
【参数】w为要写入的整数，stream为文件指针
【返回值】成功返回整数，否则返回EOF


eg:向文件写入一个整数，然后读取出来
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int ch;
    int len;
    int i=0;
    FILE* fstream;
    /*w+，打开可读写文件，若文件存在则文件长度清为零，
    即该文件内容会消失。若文件不存在则建立该文件*/
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


12.getw()函数
作用: 从流中取一整数,fp所指向文件读取下一个字（整数）
原型: int getw(FILE *strem);
返回值:返回输入的整数,如果文件结束或者出错返回-1

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




七、读取文件是判断是否读到文件结尾的方法

[用feof(fp)函数 或 EOF来实现]

(1)
while(!feof(fp))    
{
            ...                              //正常读取文件内容  
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



七、处理大数的方法:【用数组输入存储再间接处理】

eg1:(一大数取余)
#define N 1000

using namespace std;

int main()
{
     char str[N];
     int len,i;

     while(cin>>str)
     {
         long long sum=0;             //先定义为长长整型
         len=strlen(str);           //先用数组存储
         for(i=0;i<len;i++)        //用数组间接处理
         {
             sum=(sum*10+str[i]-'0')%3;     //此处是计算一大数模3后的结果的计算方法
         }
         sum=(int)sum;        //把长长整型换位整型
         cout<<sum<<endl;
     }
    return 0;
}


eg2:(一大数阶乘取余)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define LL long long

const int mod = 2009;   //此处的mod可以为任何数
int main()
{
    LL n;
    while(~scanf("%lld",&n))
	{
        if(n >= mod)    //前提是n<=mod才可以正常操作
			puts("0");//此处mod可以改为41，因为之前已经有个数可以整除
        else 
		{				// 2009,7*7*41=2009;
            LL ans = 1;
            for(int i = n; i>1; i--)
			{
                ans = (ans*(i%mod))%mod;//或ans=(ans%mod*i%mod)%mod;     //阶乘取余的公式(常用于阶乘的求解)
            }
            printf("%lld\n",ans);           //阶乘取余的结果
        }

    }
    return 0;
}




八、"."与"->"的区别

相同点：两者都是二元操作符，而且右边的操作数都是成员的名称。
不同点：点运算符( . )的左边操作数是一个结果为结构的表达式; 箭头运算符( -> )的左边的操作数是一个指向结构体的指针。


例如:
typedef struct          // 定义一个结构体类型：DATA
{
    char key[10];       // 结构体成员：key
    char name[20];      // 结构体成员：name
    int age;            // 结构体成员：age
}DATA;
 
 
(1)"."  （取内容）——>一般的结构体变量
DATA data;     // 声明一个结构体变量（目标：取内容）
// 访问数据操作如下：
data.age = 24;          // 结构体变量通过点运算符( . )访问【内容(数据)】


(2)"->"（取地址）——>结构体指针或结构体数组
1.DATA *pdata;            // 声明一个指向结构体的指针（目标：取地址）          [PS：指针==数组，都是取地址，在结构体中均使用"->"]
2.DATA  pdata[MAXSIZE]      //声明一个指向结构体的结构体数组（目标：取地址）
// 访问数据操作如下：
pdata->age = 24;        // 指向结构体的指针通过箭头运算符( -> )访问其【地址】




九、结构体定义的四种方法

(1)先定义结构体，然后在定义结构体变量
struct stu       //stu为结构体数据类型
{ /*定义学生结构体类型*/
    char name[20]; //学生姓名
    char sex; //性别
    long num; //学号
    float score[3]; //三科考试成绩
};
struct stu student1,student2; //定义结构体类型变量
struct stu student3,student4;
//用此结构体类型，可以定义更多的该结构体类型变量。

 

(2)定义结构体类型同时定义结构体类型变量
struct data
{
    int day;
    int month;
    int year;
} time1,time2;
//也可以在定义如下变量:
struct data time3,time4;
//用此结构体类型，同样可以定义更多的该结构体类型变量。

 

(3)直接定义结构体类型变量
struct
{
    char name[20]; //学生姓名
    char sex; //性别
    long num; //学号
    float score[3]; //三科考试成绩
} person1,person2; //定义该结构体类型变量
//该定义方法由于无法记录该结构体类型，所以除直接定义外，不能再定义该结构体类型变量。

 

(4)在C中定义一个结构体类型要用typedef【有typedef的情况】
1.
typedef struct (Student)    //此处的Student可省略
{
   int a;
}Stu;     //Stu在这里是自定义的类型
//于是在声明变量的时候就可： Stu  stu1;（类型 + 变量）【这里的Stu, 实际上就是 struct Student的替换，一样的】
//如果没有typedef就必须用struct Student stu1【就是(1)中的那种】;来声明;有typedef就可以直接用Stu stu1来声明变量


2.
typedef struct
{
   int a;
}Stu;
 /*如果没有typedef就必须用struct Student stu1;来声明
这里的Stu, 实际上就是 struct Student的别名
另外这里也可以不写Student（于是也不能struct Student stu1;了）*/



十、动态分配内存和静态分配内存

(1)动态分配内存:(在指针和数组的动态内存分配中常用)

1.malloc()和free()形式（一般用于C中）
void *malloc(size_t size);     //分配
void *free(void *pointer);     //释放   (PS:分配与释放连用)

eg1:
int *p=(int*) malloc(sizeof(int));         //存储1个int值得内存
int *p=(int*) malloc(100);          　　　　 //分配100字节内存
int *p=(int*) malloc(sizeof(int)*25);        //存储25个int值得内存(分配一个25x4=100个字节的整型内存块)
//或 int p;
//   p=(int*) malloc(sizeof(int)*25);
free(p);

eg2:
char *p;       
p=(char*) malloc(sizeof(char)*25);            //存储25个char值得内存(分配一个50(25x2)个字节的字符型内存块)
//或 char *p=(char*) malloc(sizeof(char)*25);
free(p);

程序完整实例:
int main()
{
   int count,*array; /*count是一个计数器，array是一个整型指针，也可以理解为指向一个整型数组的首地址*/
   if((array(int *) malloc(10*sizeof(int)))==NULL)  //分配10个整型的连续存储空间，并返回一个指向其起始地址的整型指针;把此整型指针地址赋给array;
   {                                                //检测返回值是否为NULL
       printf("不能成功分配存储空间:");
       exit(1);
   }
   for (count=0;count<10;count++) /*给数组赋值*/
      array[count]=count;
   for(count=0;count<10;count++) /*打印数组元素*/
      printf("%2d",array[count]);
}


2.new()和delete()形式(一般用于C++中)
int *p = new int[MAX];  //分配
//或 int *p;
//   p=new int[MAX];
【此时p就是一个普通数组了，即可直接用p[MAX]来操作】

delete p;     //释放   (PS:分配与释放连用)

eg1:
int *p=new int[10]; //动态数组的大小可以是变量或常量；而一般直接声明数组时，数组大小必须是常量
eg2:
char *p1;
p1=new char[12];
eg3:
double *p2;
p2=new double[100];
【此时p就是一个普通数组了，即可直接用p[MAX]来操作】

eg4:（自定义的结构体类型）
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
【此时HT就是一个普通数组了，即可直接用HT[MAX]来操作】


(2)静态分配内存(平时用的、普通的数组或指针)
char str[80];

eg:
char *str,s[80];
str=s;
cout<<"请输入一个字符串:";
cin>>str;



十一、嵌套的结构体中常用的一些符合【一般在结构体数组中使用】(*、&或无符号)【参考实训电子地图项目的结构体的实例(用*和&配对)】

1."*" (取地址，表示返回数组的全部数据，取地址或间接内容时用"->"，数组也是用"->",表示取地址)
eg1:【*与&配对，结构体操作时常用】
typedef struct{ //包含权的邻接矩阵的的定义
    int Vertices[MaxVertices];  //顶点信息的数组
    int Edge[MaxVertices][MaxVertices]; //边的权信息的数组
    int numV; //当前的顶点数
    int numE; //当前的边数
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //图的生成函数      //●●●【(*与&配对)用" & "传实参时，形参的定义要用上" * "（指针）】
{
     G->numV=n;G->numE=e;         //●●●【因为上面的形参类型定义是AdjMatrix *G, 有"*"指针（数组也一样）,代表取地址,所以要用"->"来操作地址，然后间接取内容】
}

int main()
{
    AdjMatrix G;
    CreateGraph(&G);     //●●●【(*与&配对)用" & "传实参时，形参的定义要用上" * "（指针）】
}



2."&"(表示操作完后返回数组的全部数据，引用符号)
eg:
typedef struct{ //包含权的邻接矩阵的的定义
    int Vertices[MaxVertices];  //顶点信息的数组
    int Edge[MaxVertices][MaxVertices]; //边的权信息的数组
    int numV; //当前的顶点数
    int numE; //当前的边数
}AdjMatrix;

void InsertGraph(AdjMatrix &G) //输出邻接矩阵的信息      //●●●【使用引用符号"&"，返回操作后的全部数据，形参要加上"&"】
{
     for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);                      //●●●【因为AdjMatrix &G，G是一般的结构体变量（不是指针和数组），所以用"."来直接取内容】
}

int main()
{
    AdjMatrix G;
    InsertGraph(G);                        //●●●【形参的结构体类型定义是引用符号&时，直接传实参结构体变量G 】                           
}



3.无符号(表示操作完后不返回数组的数据，即对原来开始的数组无影响)
typedef struct{ //包含权的邻接矩阵的的定义
    int Vertices[MaxVertices];  //顶点信息的数组
    int Edge[MaxVertices][MaxVertices]; //边的权信息的数组
    int numV; //当前的顶点数
    int numE; //当前的边数
}AdjMatrix;

void DispGraph(AdjMatrix G) //输出邻接矩阵的信息         //●【什么符号也不用，表示不返回数组数据，也不影响之前操作过的数组，一般是对数组的输出或展示时用】
{
     for(i=0;i<G.numV;i++)
        printf("%8d",G.Vertices[i]);                     //●【因为AdjMatrix G，G是一般的结构体变量（不是指针和数组），所以用"."来直接取内容】
}

int main()
{
    AdjMatrix G;
    DispGraph(G);                            //●【直接传实参结构体变量G】
}



十二、各种数据类型的取值范围

short int 1个字节储存
unsigned   short int    0～255
short int   -128～127
int 2个字节储存
unsigned   int    0～4294967295   
int   2147483648～2147483647
long 4个字节储存 
unsigned long 0～4294967295
long   2147483648～2147483647
long long int 8个字节储存 【VC6.0++不支持long long 整型】
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：1844674407370955161
__int64的最大值： 9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615
unsigned __int64的最大值：18446744073709551615

类型名称        字节数    取值范围
signed char       1        -128～+127
short int         2        -32768～+32767
int               4        -2147483648～+2147483647
long int          4        -2147483648～+2141483647
long long long int  8      -9223372036854775808～+9223372036854775807
unsigned long long的最大值：1844674407370955161

unsigned int (unsigned long)
4字节8位可表达位数：2^32=4294967296  
范围：0 ～ 4294967295 (42*10^8)  

int （long）
4字节8位可表达位数：2^32=4294967296  
范围：-2147483648 ～ 2147483647 (21*10^8)

long long (__int64)
8字节8位可表达位数：2^64=18446744073709600000  
范围：-9223372036854775808 ～ 9223372036854775807 (922*10^16)

unsigned long (unsigned __int64)
8字节8位可表达位数：2^64=18446744073709600000  
范围：0 ～ 18446744073709551615 (1844*10^16)



十三、字符数组的赋值(初始化)以及字符数组相关的易错点

(1)定义的时候直接用字符串赋值
char a[10]="hello";   【有" "双引号的是按顺序来赋值，从0坐标开始赋值，直到所有元素使用完】
char a[]="hello";   【根据后面真实赋值的元素个数来自动确定数组大小，这里是5，即a[5]】
char str[]={"I am happy"}; == char str[]="I am happy";(花括号可以省略)
在C++中可以:
char a[20];   【只用于字符数据类型】
cin>>a;

!!!注意：不能先定义再给它赋值!!!
如:
char a[10];
a[10]="hello";  !这样是错误的!
【因为字符数组的赋值只能按元素一一赋值(错误的原因： C语言并没有提供可以直接操作字符串的运算符；“=”可以用于其他数据类型的赋值，但是不可以直接给字符串赋值)】


(2)对数组中字符逐个赋值
1. char a[10]={'h','e','l','l','o'};【有{}号的是按顺序来赋值，从0坐标开始赋值，直到所有元素使用完】
2. char charr[] = { 'z','i','f','u','c','h','u','a','n','s','h','u','z','u' }; 【根据后面真实赋值的元素个数来自动确定数组大小，这里是14，即charr[14]】
3. 用for循环逐个赋值:
char a[20];
for(i=0;i<20;i++)
   cin>>a[i];
4. 
【
【!!!
区别:也可以赋值给某个位置的元素:(与字符数组的字符串一次性赋值不同,字符串一次性赋值完要{}或双引号,这里不是一次性赋值完,只是赋值给某一个位置,一次只赋值一个位置)
eg1:(字符型)
char array[5];
array[2]='a';
cout<<array[2];
(此处只赋值给下标为2的位置的元素，没赋值给其他位置)
eg2:(整型)
 int array[5];
 array[2]='5';
 cout<<array[2];
(此处只赋值给下标为2的位置的元素，没赋值给其他位置)
】
】

(3)用字符指针赋值:(存储字符串)【只用于字符数据类型】
char* str="zifuchuanshuzu";   【指针相当于数组，地址，用于存储数据】
或
char *str;      //只是把字符串首地址赋值给str(因为指针已指向首地址，系统首先输出str指向的字符，而后自加1，直至遇到’\0’;与数组的输出方式相同。)
str="zifuzhizhen";    !!!对于字符指针这种赋值方式是正确的。与字符数组(即第(1)点)不同!!!                                      //printf("%s",str);


(4)利用strcpy复制间接赋值
char a[10]; 
strcpy(a, "hello");


(5)!!!【易错情况(注意点)】!!!
1.char a[10]; a[10]=“hello”;【是错误的】 //一个字符怎么能容纳一个字符串，况且a[10]也是不存在的

2.char a[10]; a=“hello”;【是错误的】 //这种情况容易出现，a虽然是指针，但是它已经指向在堆栈中分配的10个字符空间，现在这个情况a又指向数据区中的hello常量，这
里的指针a出现混乱，不允许！

3.C语言的运算符根本无法操作字符串。在C语言中把字符串当作数组来处理，因此，对字符串的限制方式和对数组的一样，特别是，它们都不能用C语言的【运算符】进行复制和
比较操作。

直接尝试对字符串进行【复制或比较】操作会失败。【要使用字符串的复制函数strcpy()和比较函数strcmp()】
例如，假定str1和str2有如下声明：
char str1[10],str2[10];
str1 = "abc"; /*** WRONG ***/  //【利用=运算符来把字符串【复制】到字符数组中是不可能的[是错误的]】
str2 = str1; /***要运算符直接进行复制 WRONG ***/
C语言把这些语句解释为一个指针与另一个指针之间的（非法的）赋值运算。

【!!!PS: 
   但是，使用=####初始化###字符数组是合法的
   char str1[10] = "abc";   //此处是###初始化###数组【合法、正确的】
!!!】


4.试图使用关系运算符或判等运算符来***比较***字符串是合法的，但不会产生预期的结果：

if (str1==str2)  /*** WRONG ***/ .... //str1和str2有不同的地址，所以表达式str1 == str2的值一定为0(错误)【要用strcmp()函数】
//【这条语句把str1和str2作为**指针(地址)**来进行比较，而不是比较两个数组的**内容(数据)**。因为str1和str2有不同的地址，所以表达式str1 == str2的值一定为0】




十四、memset()函数的正确使用和注意点(●●●统一赋一样的值;在char数据类型时可正确正常使用来赋值;在其他的数据类型时不能正确正常使用来赋值,智能赋0或-1,代表清零)
(1)
memset()函数原型是:extern void *memset(void *buffer, 数据类型 c, int count) 
buffer:为指针或是数组, c:是赋给buffer的值, count:是buffer的长度
(2)●●●【易错,要慎重选择使用】
1.作用:所有数组统一赋一样的值(一般常用于清理)
2.c的数据类型为char时，可以正确正常使用memset()函数 ; 
3.如果是其他类型(int、float...)的数据就不能正确正常使用了，它只能赋0或-1值(即代表数组的统一清理清零(数组的值全为空),赋其他的值容易出错),否则就得用平常的循环
结构来实现
4.要使用#include<string.h>头文件

●●●【memset()函数一般常用于清零,即把数组的值清空】

eg1:(字符型)
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

int main()
{
    int i,j；
	char array[3][3];     //为字符类型,可正确正常使用
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
    memset(array, 'c', sizeof(array));    //为字符类型,可正确正常使用
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
}
运行结果为:
1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

c c c      //为字符类型,可正确正常使用,结果正确
c c c
c c c

eg2:(其他数据类型)
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include <string.h>

using namespace std;

int main()
{
    int i,j；
	int array[3][3];      //为其他类型,不可正确正常使用
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
    memset(array, 0, sizeof(array));    //为其他类型,不可正确正常使用
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           cout<<array[i][j]<<" ";
        cout<<endl;
    }
}
运行结果为:
1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

892679477 892679477 892679477     //为其他类型,不可正确正常使用,结果错误
892679477 892679477 892679477
892679477 892679477 892679477

eg3:(一般常用于清零)
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
运行结果为:
1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

//已完成清零,数组全部为空,所以最后没数据输出



十五、STL库之栈（stack）和队列（queue）的定义与基本用法
(1)栈(stack)
头文件:#include<stack>
声明一个栈:stack <数据类型> 数据名  如：stack <int> a
说明:stack 模板类需要两个模板参数，一个是元素类型，一个容器类型，但只有元素类型是必要的，在不指定容器类型时，默认的容器类型为deque
基本用法：
a.push();   //向栈内压入一个成员
a.pop();   //从栈顶弹出一个成员
a.empty();   //为空返回true，否则返回false
a.top();   //返回栈顶，但不删除成员
a.size();   //返回栈的大小

eg:
#include<iostream>
#include<string>
#include<stack>    //头文件
using namespace std;
int main()
{
    int t,i,num;
    string a,b;
    stack <int> stk;    //定义声明一个栈
    cin>>t;
    for(i=1;i<=t;i++)
    {
        if(i>1)
            cout<<endl;
        cin>>a>>b;
        int l1=a.size(),l2=b.size();   //返回栈大小
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
            stk.push(num%10);   //压栈
        }
        if(j)
            stk.push(j);       //压栈
        cout<<"Case "<<i<<':'<<endl;
        cout<<a<<" + "<<b<<" = ";
        while(!stk.empty())
        {
            cout<<stk.top();   //返回栈顶元素
            stk.pop();    //出栈
        }
        cout<<endl;
    }
    return 0;
}


(2)队列(queue)
头文件:#include<queue>
声明一个队列:queue <数据类型> 数据名 如：queue <int> q
说明:queue 模板类也需要两个模板参数，一个是元素类型，一个容器类型，元素类型是必要的，容器类型是可选的，默认为deque 类型
基本用法：
q.push();  //在队尾插入数据  
q.pop();  //在队首删除数据   
q.empty();  //为空返回true，否则返回false
q.front(); //返回队首元素   
q.back();  //返回队尾的元素 
q.size();  //返回队列的大小

eg:
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int e,n,m;
    queue<int> q1;     //定义声明一个队列
    for(int i=0;i<10;i++)
      q1.push(i);         //进队
    if(!q1.empty())      //判断是否队空
    cout<<"dui lie??bu kong\n";
    n=q1.size();      //返回队的大小
    cout<<n<<endl;
    m=q1.back();      //返回队尾元素
    cout<<m<<endl;
    for(int j=0;j<n;j++)
	{
       e=q1.front();     //返回队首元素
       cout<<e<<" ";
       q1.pop();       //出队
	}
    cout<<endl;
    if(q1.empty())
    cout<<"dui lie??bu kong\n";
    system("PAUSE");
    return 0;
}


(3)优先队列(priority_queue) 
1.特点： 
自动排序(默认从大到小) 

2.定义:priority_queue<int>  p_queue;    //系统默认为从大到小排序

3.头文件:#include<queue> 

4.优先输出大数据:
priority_queue<Type, Container, Functional>   Type为数据类型, Container为保存数据的容器,Functional为元素比较方式
(如果不写后两个参数，那么容器默认用的是vector,比较方式默认用operator<,也就是优先队列是大顶堆，队头元素最大)

5.非系统默认优先队列的操作:
//node是结构体，这里必须要重载"<" 
priority_queue <node> q;
//两个>>不要写在一起，>>是右移运算符 
priority_queue <int,vector<int>,greater<int> > q;  //从小到大 (小顶堆)
priority_queue <int,vector<int>,less<int> > q;      //从大到小(大顶堆)


eg1:系统默认为从大到小排序(常用)
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


eg2:含有结构体，重载<
#include<bits/stdc++.h>
using namespace std;
//重载小于号 
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
    priority_queue<int>  p_queue;    //系统默认为从大到小排序
    for(int i=0;i<sizeof(data)/sizeof(*data);++i)
    {
        p_queue.push(data[i]);//输入数据 
    }


    cout<<"输出堆顶元素：";
    for(int i=0;i<sizeof(data)/sizeof(*data);++i)
    {
        cout<<p_queue.top()<<" ";//输出:10 9 8 7 6 5 4 3 2 1 
        p_queue.pop();
	}




十六、C++中string的用法●●●(经常用，用途范围广)

我们知道string可以构造一个字符串变量，那么它的操作有哪些呢。它包含在string库中（不是string.h没有.h），它可以和定义一个字符一样定义一个字符串变量，
而且强大的C++还内置了各种函数，基本实现不用再手写操作函数。而且可以进行字典序的比较和串操作。

(1)简略介绍:

1.对位和对串操作:
如何或者string串中的某一位字符呢，我们使用数组下面的方式就可以访问。
例如:
string s = "abcdef";
cout << s[0] << endl;
结果就应该是输出了字符'a'，同时string类型也可以直接加上另一个字符串，
例如:
string a = "abc", b = "bcd";
a = a + b;
cout << a << endl;
结果应该输出字符串“abcbcd”。

2.初始化方式:
string test1;    //空串
string test2 = "内容"; //使用=
string test3("内容");   //使用引用字符数组作为参数传给构造函数
string test4(test2); //用一个string初始化另一而string
string test5(test2,pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
string test6 = test2 + "内容" + test3 //混合初始化
string test7 = test2.substr(pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
string test8 = test2.substr(); //参数列表为空则会拷贝test2的整个对象（复制test2的简便方法）
string test9(num,ch); //拷贝num个字符型ch到test9

3.内置函数:
在string类型中其实包括了很多函数，
例如:
 1     string s = "a";
 2     s.append(2,'b');//s.append(n,c);在s串后面加入n个c字符（append还有其他用法，详情可百度）
 3     s.erase(s.begin(),s.begin()+2);//s.erase(l,r);删除某个区间，l,r都为迭代器
 4     s.erase(it);//删除一个字符，it为迭代器
 5     s.size();//返回字符串s的长度大小
 6     s.begin();//返回首位置的迭代器
 7     s.end();//返回末位置的迭代器
 8     s.insert(it,ch);//在it位置插入ch字符，it为迭代器
 9     s.resize(len,c);//把字符串当前大小置为len，并用c填充不足的部分
10     s.empty();//判断是否为空串
11     s.length();//返回字符串的长度
12     s.max_size();//返回当前系统string对象可存放的最大长度
13     s.capacity();//返回当前容量
14     s.at(k);//返回第k+1个字符（该用法会坚持是否越界）
15     s.c_str();//返回C字符串的指针，内容为s串
16     s.find(s1);//查找s中是否包含s1，并返回头位置，找不到则返回string::npos
17     s.replace(k,x,ch);//从k位置开始，把后面的x个元素替换为ch（还有很多其他用法）
18     s.swap(s2);//交换两个string字符串
而且string还支持直接比较两个字符串的大小（内置字典序比较方式）。除了上面写了的外，string其实还有很多函数。




(2)string类型详解:●●●

之所以抛弃char*的字符串而选用C++标准程序库中的string类，是因为他和前者比较起来，不必担心内存是否足够、字符串长度等等，而且作为一个泛型类出现，他集成的操作
函数足以完成我们大多数情况下(甚至是100%)的需要。我们可以用 = 进行赋值操作，== 进行比较，+ 做串联（是不是很简单?）。我们尽可以把它看成是C++的基本数据类型。

C++中对于strinig的定义为：typedef basic_string string; 也就是说C++中的string类是一个泛型类，由模板而实例化的一个标准类，本质上不是一个标准数据类型。
好了，进入正题………
首先，为了在我们的程序中使用string类型，我们必须包含头文件 。如下：
#include //注意这里不是string.h string.h是C字符串头文件

using namespace std;  //此语句必不可少，否则有的编译器无法识别

1.声明一个C++字符串
声明一个字符串变量很简单：string Str;
这样我们就声明了一个字符串变量，但既然是一个类，就有构造函数和析构函数。上面的声明没有传入参数，所以就直接使用了string的默认的构造函数，这个函数所作的就是把
Str初始化为一个空字符串。String类的构造函数和析构函数如下：
a)    string s;  //生成一个空字符串s
b)    string s(str) //拷贝构造函数 生成str的复制品
c)    string s(str,stridx) //将字符串str内“始于位置stridx”的部分当作字符串的初值
d)    string s(str,stridx,strlen) //将字符串str内“始于stridx且长度顶多strlen”的部分作为字符串的初值
e)    string s(cstr) //将C字符串作为s的初值
f)    string s(chars,chars_len) //将C字符串前chars_len个字符作为字符串s的初值。
g)    string s(num,c) //生成一个字符串，包含num个c字符
h)    string s(beg,end) //以区间beg;end(不包含end)内的字符作为字符串s的初值
i)    s.~string() //销毁所有字符，释放内存


2．字符串操作函数:
这里是C++字符串的重点，我先把各种操作函数罗列出来，不喜欢把所有函数都看完的人可以在这里找自己喜欢的函数，再到后面看他的详细解释。
a) =,assign()   //赋以新值
b) swap()   //交换两个字符串的内容
c) +=,append(),push_back() //在尾部添加字符
d) insert() //插入字符
e) erase() //删除字符
f) clear() //删除全部字符 
g) replace() //替换字符
h) + //串联字符串
i) ==,!=,<,<=,>,>=,compare()  //比较字符串
j) size(),length()  //返回字符数量
k) max_size() //返回字符的可能最大个数
l) empty()  //判断字符串是否为空
m) capacity() //返回重新分配之前的字符容量
n) reserve() //保留一定量内存以容纳一定数量的字符
o) [ ], at() //存取单一字符
p) >>,getline() //从stream读取某值
q) <<  //将谋值写入stream
r) copy() //将某值赋值为一个C_string
s) c_str() //将内容以C_string返回
t) data() //将内容以字符数组形式返回
u) substr() //返回某个子字符串（截取字符串）
v)查找函数
w)begin() end() //提供类似STL的迭代器支持
x) rbegin() rend() //逆向迭代器
y) get_allocator() //返回配置器


3.下面详细介绍细节以及各种用法:

①C++字符串和C字符串的转换:
C++提供的由C++字符串得到对应的C_string的方法是使用data()、c_str()和copy()，其中，data()以字符数组的形式返回字符串内容，但并不添加’\0’。c_str()返回一个
以‘\0’结尾的字符数组，而copy()则把字符串的内容复制或写入既有的c_string或字符数组内。C++字符串并不以’\0’结尾。我的建议是在程序中能使用C++字符串就使用，
除非万不得已不选用c_string。由于只是简单介绍，详细介绍掠过，谁想进一步了解使用中的注意事项可以给我留言(到我的收件箱)。我详细解释。

②大小和容量函数:
一个C++字符串存在三种大小：a)现有的字符数，函数是size()和length()，他们等效。Empty()用来检查字符串是否为空。b)max_size() 这个大小是指当前C++字符串最多能
包含的字符数，很可能和机器本身的限制或者字符串所在位置连续内存的大小有关系。我们一般情况下不用关心他，应该大小足够我们用的。但是不够用的话，会抛
出length_error异常c)capacity()重新分配内存之前 string所能包含的最大字符数。这里另一个需要指出的是reserve()函数，这个函数为string重新分配内存。重新分配的大小
由其参数决定，默认参数为0，这时候会对string进行非强制性缩减。

【注意:还有必要再重复一下C++字符串和C字符串转换的问题，许多人会遇到这样的问题，自己做的程序要调用别人的函数、类什么的（比如数据库连接
函数Connect(char*,char*)），但别人的函数参数用的是char*形式的，而我们知道，c_str()、data()返回的字符数组由该字符串拥有，所以是一种const char*,要想作为上面提
及的函数的参数，还必须拷贝到一个char*,而我们的原则是能不使用C字符串就不使用。那么，这时候我们的处理方式是：如果此函数对参数(也就是char*)的内容不修改的话，我
们可以这样Connect((char*)UserID.c_str(), (char*)PassWD.c_str()),但是这时候是存在危险的，因为这样转换后的字符串其实是可以修改的（有兴趣地可以自己试一试），所
以我强调除非函数调用的时候不对参数进行修改，否则必须拷贝到一个char*上去。当然，更稳妥的办法是无论什么情况都拷贝到一个char*上去。同时我们也祈祷现在仍然使用C字
符串进行编程的高手们（说他们是高手一点儿也不为过，也许在我们还穿开裆裤的时候他们就开始编程了，哈哈…）写的函数都比较规范，那样我们就不必进行强制转换了。】

③元素存取:
 我们可以使用下标操作符[]和函数at()对元素包含的字符进行访问。但是应该注意的是操作符[]并不检查索引是否有效（有效索引0~str.length()），如果索引失效，会引起未定
 义的行为。而at()会检查，如果使用at()的时候索引无效，会抛出out_of_range异常。
 有一个例外不得不说，const string a;的操作符[]对索引值是a.length()仍然有效，其返回值是’\0’。其他的各种情况，a.length()索引都是无效的。举例如下：
const string Cstr(“const string”);
string Str(“string”);

Str[3];    //ok
Str.at(3);  //ok

Str[100]; //未定义的行为
Str.at(100);  //throw out_of_range

Str[Str.length()]  //未定义行为
Cstr[Cstr.length()] //返回 ‘\0’
Str.at(Str.length());//throw out_of_range
Cstr.at(Cstr.length()) ////throw out_of_range

我不赞成类似于下面的引用或指针赋值：
char& r=s[2];
char* p= &s[3];
因为一旦发生重新分配，r,p立即失效。避免的方法就是不使用。

④比较函数:
    C++字符串支持常见的比较操作符（>,>=,<,<=,==,!=），甚至支持string与C-string的比较(如 str<”hello”)。在使用>,>=,<,<=这些操作符的时候是根据
	“当前字符特性”将字符按字典顺序进行逐一得比较。字典排序靠前的字符小，比较的顺序是从前向后比较，遇到不相等的字符就按这个位置上的两个字符的比较结果确定
	两个字符串的大小。同时，string(“aaaa”)
    另一个功能强大的比较函数是成员函数compare()。他支持多参数处理，支持用索引值和长度定位子串来进行比较。他返回一个整数来表示比较结果，返回值意义如下：
	0-相等〉0-大于 <0-小于。
	举例如下：
    string s(“abcd”);
    s.compare(“abcd”); //返回0
    s.compare(“dcba”); //返回一个小于0的值
    s.compare(“ab”); //返回大于0的值
  
    s.compare(s); //相等
    s.compare(0,2,s,2,2); //用”ab”和”cd”进行比较 小于零
    s.compare(1,2,”bcx”,2); //用”bc”和”bc”比较。

⑤更改内容:
这在字符串的操作中占了很大一部分。
首先讲赋值，第一个赋值方法当然是使用操作符=，新值可以是string(如：s=ns) 、c_string(如：s=”gaint”)甚至单一字符（如：s=’j’）。还可以使用成员函数assign()，
这个成员函数可以使你更灵活的对字符串赋值。
还是举例说明吧：
s.assign(str); //不说
s.assign(str,1,3);//如果str是”iamangel” 就是把”ama”赋给字符串
s.assign(str,2,string::npos);//把字符串str从索引值2开始到结尾赋给s
s.assign(“gaint”); //不说
s.assign(“nico”,5);//把’n’ ‘I’ ‘c’ ‘o’ ‘\0’赋给字符串
s.assign(5,’x’);//把五个x赋给字符串
把字符串清空的方法有三个：s=””;s.clear();s.erase();(我越来越觉得举例比说话让别人容易懂！)。
string提供了很多函数用于插入（insert）、删除（erase）、替换（replace）、增加字符。
先说增加字符（这里说的增加是在尾巴上），函数有 +=、append()、push_back()。举例如下：
s+=str;//加个字符串
s+=”my name is jiayp”;//加个C字符串
s+=’a’;//加个字符

s.append(str);
s.append(str,1,3);//不解释了 同前面的函数参数assign的解释
s.append(str,2,string::npos)//不解释了

s.append(“my name is jiayp”);
s.append(“nico”,5);
s.append(5,’x’);

s.push_back(‘a’);//这个函数只能增加单个字符 对STL熟悉的理解起来很简单

也许你需要在string中间的某个位置插入字符串，这时候你可以用insert()函数，这个函数需要你指定一个安插位置的索引，被插入的字符串将放在这个索引的后面。
    s.insert(0,”my name”);
    s.insert(1,str);
这种形式的insert()函数不支持传入单个字符，这时的单个字符必须写成字符串形式(让人恶心)。既然你觉得恶心，那就不得不继续读下面一段话：为了插入单个字符，
insert()函数提供了两个对插入单个字符操作的重载函数：insert(size_type index,size_type num,chart c)和insert(iterator pos,size_type num,chart c)。其中size_type
是无符号整数，iterator是char*,所以，你这么调用insert函数是不行的：insert(0,1,’j’);这时候第一个参数将转换成哪一个呢？所以你必须这
么写：insert((string::size_type)0,1,’j’)！第二种形式指出了使用迭代器安插字符的形式，在后面会提及。顺便提一下，string有很多操作是使用STL的迭代器的，他也尽
量做得和STL靠近。
删除函数erase()的形式也有好几种（真烦！），替换函数replace()也有好几个。
举例吧：
string s=”il8n”;
s.replace(1,2,”nternationalizatio”);//从索引1开始的2个替换成后面的C_string
s.erase(13);//从索引13开始往后全删除
s.erase(7,5);//从索引7开始往后删5个

⑥提取子串和字符串连接:
题取子串的函数是：substr(),形式如下：
s.substr();//返回s的全部内容
s.substr(11);//从索引11往后的子串
s.substr(5,6);//从索引5开始6个字符
把两个字符串结合起来的函数是+。（谁不明白请致电120）

⑦输入输出操作:
1．>> 从输入流读取一个string。
2．<< 把一个string写入输出流。
另一个函数就是getline(),他从输入流读取一行内容，直到遇到分行符或到了文件尾。

⑧搜索与查找:
查找函数很多，功能也很强大，包括了：
    find()
    rfind()
    find_first_of()
    find_last_of()
    find_first_not_of()
    find_last_not_of()
这些函数返回符合搜索条件的字符区间内的第一个字符的索引，没找到目标就返回npos。所有的函数的参数说明如下：
第一个参数是被搜寻的对象。第二个参数（可有可无）指出string内的搜寻起点索引，第三个参数（可有可无）指出搜寻的字符个数。比较简单，不多说不理解的可以向我提出，
我再仔细的解答。当然，更加强大的STL搜寻在后面会有提及。
最后再说说npos的含义，string::npos的类型是string::size_type,所以，一旦需要把一个索引与npos相比，这个索引值必须是string::size)type类型的，更多的情况下，
我们可以直接把函数和npos进行比较（如：if(s.find(“jia”)==string::npos)）。

⑨string 函数列表:
函数名	描述
begin	得到指向字符串开头的Iterator
end	得到指向字符串结尾的Iterator
rbegin	得到指向反向字符串开头的Iterator
rend	得到指向反向字符串结尾的Iterator
size	得到字符串的大小(与length功能相同)
length	和size函数功能相同
max_size	字符串可能的最大大小
capacity	在不重新分配内存的情况下，字符串可能的大小
empty	判断是否为空
operator[]	取第几个元素，相当于数组
c_str	取得C风格的const char* 字符串
data	取得字符串内容地址
operator=	赋值操作符
reserve	预留空间
swap	交换函数
insert	插入字符
append	追加字符
push_back	追加字符
operator+=	+= 操作符
erase	删除字符串
clear	清空字符容器中所有内容
resize	重新分配空间
assign	和赋值操作符一样
replace	替代
copy	字符串到空间
find	查找
rfind	反向查找
find_first_of	查找包含子串中的任何字符，返回第一个位置
find_first_not_of	查找不包含子串中的任何字符，返回第一个位置
find_last_of	查找包含子串中的任何字符，返回最后一个位置
find_last_not_of	查找不包含子串中的任何字符，返回最后一个位置
substr	得到字串
compare	比较字符串
operator+	字符串链接
operator==	判断是否相等
operator!=	判断是否不等于
operator<</td>	判断是否小于
operator>>	从输入流中读入字符串
operator<<	字符串写入输出流
getline	从输入流中读入一行


实例:
#include<iostream>
#include<string> 
using namespace std;
int main()
{
    //创建对象,及初始化 
    string str("abddassas");
    string str2("ab");
    //输入 
    cin>>str;
    //输出str，方法1
    cout<<str<<endl;
    //输出方法2， 
    cout<<str.c_str()<<endl;
    //输出某一个特定元素
    cout<<str[2];
    //指定下标位置插入某个字符串 
    str.insert(2,str2);
    //尾部插入
    str.insert(str.length(),str2); 
    cout<<str<<endl;
    //指定位置删除
    str.erase(2,2);//从下标2开始删除两个。
    cout<<str<<endl; 

	string str("1234567");
    cout << "size=" << str.size() << endl;         // size=7
    cout << "length=" << str.length() << endl;     // length=7
    cout << "max_size=" << str.max_size() << endl; // max_size=4294967294
    cout << "capacity=" << str.capacity() << endl; // capacity=15

    //比较函数
    cout<<(str1>str2)<<endl;//str1>str2,返回1，否则返回0；
    //复制函数，把字符串中的函数复制到另一个字符数组中。 
    char ss[8]={0};
    str2.copy(ss,3,0);//把str2中的字符从下表0开始复制3个到ss中 
    //查找字串
    str.find(str2,2)//在str中从下标2开始找在str中是否含有str2，若有返回字串在大串中下标位置，否则返回-1.
     //打印字串
     cout<<str.substr(2,4)<<endl;//从2位置开始连续打印4个字符
     //交换字符串
     str.swap(str2);//交换str和str2 
     //如何判断一个string类型的字符串当中是否含有另一个string类型的字符串
    string str1="sda_hello_sds";
    string str2="hello";
    string::size_type idx=str1.find(str2);
    if(idx!=string::npos)
    {
     cout<<"字符串含有"<<str2；
    }
    else
    cout<<"字符串没有"<<str2;
    return 0;
}




十七、取模运算
1、取模公式
(1)取模运算：a % p（a mod p），表示a除以p的余数。
(2)模p加法：(a + b) % p = (a%p + b%p) % p
(3)模p减法：(a - b) % p = (a%p - b%p) % p
(4)模p乘法：(a * b) % p = ((a % p)*(b % p)) % p
(5)幂模p ： (a^b) % p = ((a % p)^b) % p
(6)模运算满足结合律、交换律和分配律。
(7)a≡b (mod n) 表示a和b模n同余，即a和b除以n的余数相等。

2、大数取模

eg:
scanf("%s%d",n,&m);
int len=strlen(n);
int ans=0;
for(int i=0;i<len;i++)
{
   ans=(int)(((long long)ans*10+n[i]-'0')%m);
}
printf("%d\n",ans);






十八、ACM的输入输出之scanf()、getchar()、gets()的细节易错点
(1)
第一：要注意不同的函数是否接受空格符、是否舍弃最后的回车符的问题!
读取字符时：
scanf()以Space、Enter、Tab结束一次输入，不会舍弃最后的回车符（即回车符会残留在缓冲区中）；
getchar()以Enter结束输入，也不会舍弃最后的回车符（即回车符会残留在缓冲区中）；
读取字符串时：
scanf()以Space、Enter、Tab结束一次输入,即不同的字符串通过Space、Enter、Tab进行区分！
gets()以Enter结束输入（空格不结束），接受空格(字符串中包含空格（Tab也可以）)，会舍弃最后的回车符(回车键不会留在输入缓冲区中)

【scanf不能接受空格、制表符Tab、回车等； 
而gets能够接受空格、制表符Tab和回车等； 
它们字符串接受结束后自动加\0； 
scanf ：当遇到回车，空格和tab键会自动在字符串后面添加’\0’，但是回车，空格和tab键仍会留在输入的缓冲区中。 
gets：可接受回车键之前输入的所有字符，并用’\n’替代 ‘\0’.回车键不会留在输入缓冲区中。

所以，gets和scanf本质上没有什么区别，都是接收字符串，不过，getchar只能接受字符。 
由于gets没有上限，使用时得保证空间足够大，以保证读取是不会溢出。】


第二：为了避免出现上述问题，必须要清空缓冲区的残留数据，可以用以下的方法解决：
方法1：C语言里提供了函数清空缓冲区，只要在读数据之前先清空缓冲区就没问题了！
  这个函数是fflush(stdin)。
方法2：自己取出缓冲区里的残留数据。
（说实话这个语句我也没看懂，呵呵！为什么格式控制是这样的！希望高手指点一下！）
 scanf("%[^\n]",string);


(2)前导空白问题:
每一行输出完后要打印回车’\n’，包括最后一行
输入：scanf, fgets(gets), getchar
scanf
输入格式
%d %lld  %c %s %lf
对每种格式搞清楚一个重要问题
是否自动跳过前导空白？
什么是空白：空格，TAB，回车
注意:%d %lld %lf自动扫描前导空格

读一个非空白字符的方法:
方法一:
char str[2];
scanf(“%1s”, str);
// %s扫描前导空白，并且只读一个字符
char c = str[0];
方法二:
强制扫描空白
在%前面加上一个空格表示“强制扫描前导空白”
scanf(“ %c”, &ch);
前面那个读人物信息的完整scanf语句：
scanf(“%s %c %s”, name, &gender, ability);


(3)
如果要求输入的字符串需要带有空格的，如何处理呢？
读一行：gets, fgets
gets会导致很讨厌的warning message，所以可改用fgets
fgets(str, sizeof str, stdin) = gets(str)
注意应使“下一个字符”处于这一行开头



