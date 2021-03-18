#include <stdio.h>
int main()
{
    int i,j,z;
	i=1;
	printf("«Î ‰»Îz:");
	scanf("%d",&z);
	for(j=2;j<=5;j++)
	{
	   i=j*z;
	   z++;
	   printf("z=%d\n",z);
	   printf("i=%d\n",i);
	}
    return 0;
}