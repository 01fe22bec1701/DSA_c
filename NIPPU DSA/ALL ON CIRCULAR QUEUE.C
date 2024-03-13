#include<stdio.h>
#include<stdlib.h>
#include<cstring>
# define seze 10
struct patient
{
    char n[30];
    int id;
};
struct patient  s;
struct patient q[10];
int insert();
int Delete();
void display();
void you();
void avg();
int i,f,r,ch;
main()
{
    r=-1;
    f=-1;
    do
        {
        printf("1--insert\n");
        printf("2--Delete\n");
        printf("3--display\n");
        printf("4--younger\n");
        printf("5--average\n");
        printf("6--exit\n");

        printf("enter ur choice\n");
        scanf("%d",&ch);


    switch(ch)
    {
        case 1: if(r==9)
                 {
                     printf("q is full\n");
                 }
                 else
                 {
                     printf("enter name,id of the patient\n");
                     scanf("%s%d",&s.n,&s.id);
                     r=insert();
                 }
                 break;

        case 2:if(r==-1 && f==-1)
               {
                   printf("q is empty\n");
               }
               else
               {
                   f=Delete();
               }
               break;
        case 3:if(r==-1 && f==-1)
               {
                   printf("q is empty\n");
               }
               else
               {
                   display();
               }
        case 4: if(r==-1 && f==-1)
               {
                   printf("q is empty\n");
               }
               else
               {
                   you();
               }
               break;
         case 5: if(r==-1 && f==-1)
               {
                   printf("q is empty\n");
               }
               else
               {
                   avg();
               }
               break;
        case 6:exit(0);break;
        default:printf("invalid choice\n");
    }
}while(ch!=6);
}

int insert()
{
    if(f==-1 && r==-1)
    {
         f++;
         r++;
         strcpy(q[r].n,s.n);
         q[r].id=s.id;
    }
    else
    {
        r++;
         strcpy(q[r].n,s.n);
         q[r].id=s.id;
    }
    return(r);
}
int Delete()
{
    if(r==f)
    {
        printf("patient Deleted\n");
        printf("name=%s\t id=%d\n",q[i].n,q[f].id);
        r=-1;
        f=-1;
    }
    else
    {
       printf("patient Deleted\n");
       printf("name=%s\t id=%d\n",q[f].n,q[f].id);
       f++;
    }
    return(f);
}
void display()
{
    int i;
    printf("details of the patient are\n");
    for(i=f;i<=r;i++)
    {
         printf("name=%s\t id=%d\n",q[i].n,q[i].id);
    }
}
void you()
{
    int j;
    int m;
    m=q[f].id;
    for(i=f;i<=r;i++)
    {
        if(q[i].id<m)
        {
            m=q[i].id;
            j=i;
        }
    }
    printf("younger patient=%d\n",m);
    printf("name=%s\t id=%d\n",q[j].n,q[j].id);

}
void avg()
{
    int c=0,tot=0;
    float a;
     for(i=f;i<=r;i++)
     {
         c++;
         tot=tot+q[i].id;
     }
     a=float(tot)/c;
    printf("count=%d\n",c);
    printf("average=%f\n",a);
}

