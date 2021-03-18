#include<stdio.h>
#include<string.h>
int primer[350000];
int numbers[1000010];
int ans[1000010];
int N=1000000;
void primers()
{
    int i,j,k;
    k=0;
    memset(numbers,0,sizeof(numbers));
    for(i=2;i<N;i++)
    {
        if(numbers[i]==0)
            primer[k++]=i;
        for(j=0;(j<k)&&(i*primer[j])<N;j++)
        {
            numbers[i*primer[j]]=1;
            if(i%primer[j]==0)
                break;
        }
    }
}
int sums(int t)
{
    int a,sum=0;
    while(t)
    {
        a=t%10;
        t=t/10;
        sum=sum+a;
    }
    return sum;
}
void answers()
{
    int i;
    memset(ans,0,sizeof(ans));
    for(i=2;i<N;i++)
    {
        if(numbers[i]==0&&(numbers[sums(i)]==0))
            ans[i]=ans[i-1]+1;
        else
            ans[i]=ans[i-1];
    }
}
int main()
{
    int T,s=1;
    primers();
    answers();
    scanf("%d",&T);
    while(T--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        printf("Case #%d: %d\n",s++,ans[R]-ans[L-1]);
    }
    return 0;
}
