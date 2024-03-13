#include<stdio.h>
#define size 10
int top1,top2;
int stack1[size],stack2[size];
int push1(int top1);
int push2(int top2);
void display();
void check();
main()
{
    int n,i;
    top1=-1;
    top2=-1;
    printf("enter the no of container\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        top1=push1(top1);
    }
    for(i=0;i<n;i++)
    {
        top2=push2(top2);
    }
    display();
    check();
}
int push1(int top1)
{
    top1++;
    printf("enter the container\n");
    scanf("%d",&stack1[top1]);
    return(top1);
}
int push2(int top2)
{
    top2++;
    printf("enter the  closing container\n");
    scanf("%d",&stack2[top2]);
    return(top2);
}
void display()
{
    int i;
    for(i=top1;i>=0;i--)
    {
        printf("%d ",stack1[i]);
    }
    printf("\n closing sequence\n");
     for(i=top2;i>=0;i--)
    {
        printf("%d ",stack2[i]);
    }

}
void check()
{
    int i,a,b,c=0;
    a=top1;
    b=0;
    for(i=top1;i>=0;i--)
    {
        if(stack1[a]==stack2[b])
        {
           c=1;
        }
        else
        {
            c=0;
            break;
        }
        a--;
        b++
    }
    if(c==1)
    {
        printf("valid sequence\n");
    }
    else
    {
        printf("invalid sequence\n");
    }
}

