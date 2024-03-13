#include<stdio.h>
# define size 10
int q[size];
int insert();
int Delete(int r,int f);
void display(int r,int f);
void max();
void count();
void avg();
void search();
void min();
int i,r,n,f,a;
main()
{
    int i;
    r=-1;
    f=-1;
    printf("enter no of players\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        r=insert();
    }
    display(r,f);
    printf("enter the player to delete\n");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        f=Delete(r,f);
    }
    printf("remaining players are\n");
    display( r,f);
    max();
    count();
    avg();
    search();
    min();
}
int insert()
{
    if(r==size-1)
    {
        printf("q is full\n");
    }
    else if(r==-1 && f==-1)
    {
        r++;
        f++;
        printf("enter the element\n");
        scanf("%d",&q[r]);
    }
    else
    {
        r++;
        printf("enter the element\n");
        scanf("%d",&q[r]);
    }
    return(r);
}

int Delete(int r,int f)
{
    if(r==-1 && f==-1)
    {
        printf("q is mt\n");
    }
    else if(r==f)
    {
        printf("element deleted =%d\n",q[f]);
        f=-1;
        r=-1;

    }
    else
    {
         printf("element deleted=%d\n",q[f]);
         f++;
    }
    return(f);
}
void display(int r,int f)
{
    int i;

    for(i=f;i<=r;i++)
    {
        printf("element=%d\n",q[i]);
    }
}
void max()
{
    int m,i;
    m=q[f];
    for(i=f;i<=r;i++)
    {
        if(q[i]>m)
        {
            m=q[i];
        }
    }
    printf("maximum player=%d\n",m);

}
void count()
{
    int c=0;
    for(i=f;i<=r;i++)
    {
        c++;
    }
    printf("total members=%d\n",c);
}
void avg()
{
    int tot=0,c=0;
    float a;
    for(i=f;i<=r;i++)
    {
        c++;
        tot=tot+q[i];
    }
    a=float(tot)/c;
    printf("count=%d\n",c);
    printf("a=%f\n",a);
}

void search()
{
    int a;
    printf("enter required person\n");
    scanf("%d",&a);
    for(i=f;i<=r;i++)
    {
        if(q[i]==a)
        {
            printf("person found\n");
            printf("%d",q[i]);
        }
    }
}
void min()
{
    int m;
    m=q[f];
    for(i=f;i<=r;i++)
    {
        if(q[i]<m)
        {
            m=q[i];
        }
    }
    printf("min=%d\n",m);
}
