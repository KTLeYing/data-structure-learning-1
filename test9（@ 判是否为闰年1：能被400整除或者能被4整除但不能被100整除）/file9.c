/*
#include<stdio.h>
int main()
{
    int a;
	printf("������һ����:");
	scanf("%d",&a);
	if(a%400==0)
		printf("����\n");
	else
		if(a%4!=0)
		    printf("������\n");
		else
			if(a%100!=0)
				printf("����\n");
            else
				printf("������\n");
    return 0;
}
*/

//��
#include <stdio.h>
int main()
{
    int year;
    printf("��������ݣ�\n");
    scanf("%d",&year);
    if(year%400==0)
        printf("%d ����������\n",year);
    else
    {
        if(year%4==0&&year%100!=0)
            printf("%d ����������\n",year);
        else
            printf("%d ���������\n",year);
    }
    return 0;
} 
