
#include<stdio.h>
main()
{
    int n;
    void nat_sum(int *n);
    printf("enter the value of n\n");
    scanf("%d",&n);
    nat_sum(&n);
}
void nat_sum(int *x)
{
    int sum=0,i;
    for(i=1;i<=*x;i++)
    {
        sum=sum+i;

    }
        printf("sum=%d\n",sum);
}
