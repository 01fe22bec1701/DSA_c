#include<stdio.h>
#include<stdlib.h>
#include<cstring>
struct p
{
    char np[30];
    int pr;
};
struct p stack[10];
struct p ele;
int top,i,ch;
int push(int top);
void display();
void pri();
void max_pr();
void avg();
void pland();
void dis();
void min();
void search();
main()
{
    top=-1;
    do
    {
        printf("1--PUSH\n");
        printf("2--DISPLAY\n");
        printf("3-TOTAL PRICE\n");
        printf("4--MAXIMUM PRICE\n");
        printf("5--AVERAGE PRICE\n");
        printf("6--PALANDROME\n");
        printf("7--DISCOUNT FOR NEWS PAPER\n");
        printf("8--MINIMUM PRICE\n");
        printf("9--SEARCH NAME\n");
        printf("10--EXIT\n");

        printf("enter ur choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:if(top==9)
            {
                printf("Papers are full\n");
            }
            else{
                printf("name of newspaper,price\n");
                scanf("%s%d",&ele.np,&ele.pr);
                top=push(top);
               }

               break;

         case 2: display();
                 break;

        case 3: pri();
                break;
         case 4: max_pr();
                 break;
        case 5: avg();
                 break;
        case 6: pland();
                break;
        case 7:dis();
            break;

       case 8: min();
       break;
       case 9: search();
                break;
        case 10:exit(0);break;
        default:printf("INVALID CHOICE\n");break;

        }
    }while(ch!=10);
}

int push(int top)
{
    top++;
    strcpy(stack[top].np,ele.np);
    stack[top].pr=ele.pr;
    return(top);
}
void display()
{
    printf("news paper in stack are\n");
    for(i=top; i>=0; i--)
    {
     printf("name=%s\t price=%d\n",stack[i].np,stack[i].pr);
    }
}
void pri()
{
    int a=0,c=0;
    for(i=top;i>=0;i--)
    {
        c++;
        a=a+stack[i].pr;
    }
    printf("total no of news paper=%d\n",c);
    printf("total amount of news paper=%d\n",a);
}

void max_pr()
{
    int m,j;
    m=stack[top].pr;
    for(i=top;i>=0;i--)
    {
        if(stack[i].pr>m)
        {
            m=stack[i].pr;
            m=j;
        }
    }
    printf("maximum price newspaper=%d\n",m);
}
void avg()
{
    int tot,c;
    float a;
    tot=0;
    for(i=top;i>=0;i--)
    {
        c++;
        tot=tot+stack[i].pr;
    }
    a=float(tot)/c;
    printf("average price of news paper=%f\n",a);
}

void pland()
{
    int a,b,c=0;
    a=top;
    b=0;
    for(i=top;i>=0;i--)
    {
        if(stack[a].pr==stack[b].pr)
        {
            c=1;
        }
        else{c=0;}
        a--;
        b++;
        break;
    }
    if(c==1)
    {
        printf("price is palandrome\n");
    }
    else{
        printf("price is not apalandrome\n");
    }
}
void dis()
     {
         int d=0;
        for(i=top;i>=0;i--)
        {
            if(stack[i].pr>6)
            {
                d=(stack[i].pr)*0.1;

        printf("discount of the newspaper=%d\n",d);
        printf("news paper=%s\t price=%d\n",stack[i].np,stack[i].pr);
            }
        }
     }

void min()
{
    int m,j;
    m=stack[top].pr;
    for(i=top;i>=0;i--)
    {
        if(stack[i].pr<m)
        {
           m=stack[i].pr;
           m=j;
        }
    }
    printf("news paper with minimum price=%d\n",m);
}

void search()
{
    char r[20];
    printf("enter required name\n");
    scanf("%s",&r);
    for(i=top;i>=0;i--)
    {
        if(strcmp(stack[i].np,r)==0)
        {
          printf("news paper=%s\t price=%d\n",stack[i].np,stack[i].pr);
        }
    }
}
