#include<stdio.h>
int main()
{
    int i=3,j=1;
	while(i<=9)
	{
	     i=i+2;
		 j=i*j;
	}
    printf("%d\n",j);
	return 0;
}
