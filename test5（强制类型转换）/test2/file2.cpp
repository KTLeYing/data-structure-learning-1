#include <stdio.h>

int main()
{
    float c,f;
	printf("请输入摄氏温度值：30");
	scanf("%f",&c);

	f=32+c*1.8;
	printf("摄氏温=%.2f,转换为华氏温度=%.2f\n",c,f);
	return 0;
}