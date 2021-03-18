#include<stdio.h>
int main()
{
    int a=65,b;
	char c='a';
	b=a+1;
    printf("整数a=%d,显示为字符:%c\n",a,a);
	printf("整数b=%d,显示为字符:%c\n",b,b);
	printf("字符c=%c,显示为整数:%d\n",c,c);
	c=c+1;
	printf("字符c=%c,显示为整数:%d\n",c,c);
	return 0;
}
