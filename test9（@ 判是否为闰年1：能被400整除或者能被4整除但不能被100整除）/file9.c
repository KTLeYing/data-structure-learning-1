/*
#include<stdio.h>
int main()
{
    int a;
	printf("请输入一个数:");
	scanf("%d",&a);
	if(a%400==0)
		printf("闰年\n");
	else
		if(a%4!=0)
		    printf("非闰年\n");
		else
			if(a%100!=0)
				printf("闰年\n");
            else
				printf("非闰年\n");
    return 0;
}
*/

//或
#include <stdio.h>
int main()
{
    int year;
    printf("请输人年份：\n");
    scanf("%d",&year);
    if(year%400==0)
        printf("%d 此年是闰年\n",year);
    else
    {
        if(year%4==0&&year%100!=0)
            printf("%d 此年是闰年\n",year);
        else
            printf("%d 此年非闰年\n",year);
    }
    return 0;
} 
