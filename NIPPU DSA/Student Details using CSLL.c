#include<stdio.h>
#define NULL 0
struct student
{
  char name[30];
  int rno;
  float ht;
  struct student *link;
};

main()
{
struct student *head,*ptr;
head=NULL;
int ch,pos,count;
struct student* insert_at_front(struct student*,struct student *);
struct student* insert_at_end(struct student*,struct student *);
struct student* delete_at_front(struct student*);
struct student* delete_at_end(struct student*);
void display_SLL(struct student*);
int count_node(struct student *head);
struct student* insert_at_pos(struct student *head, struct student *ptr,int pos);
struct student* delete_at_pos(struct student *head , int pos);
struct student* search_rollno_node(struct student *head);
struct student* search_height_node(struct student *head);
struct student* search_name_node(struct student *head);
struct student* insert_newnode_after_node(struct student *head ,struct student *ptr);
struct student* insert_newnode_before_node(struct student *head,struct student *ptr);

do
{
   printf("1--INSERT A NODE AT FRONT\n");
   printf("2--INSERT A NODE AT END\n");
   printf("3--DELETE A NODE AT FRONT\n");
   printf("4--DELETE A NODE AT END\n");
   printf("5--DISPLAY LINKED LIST\n");
   printf("6--COUNT THE NODES\n");
   printf("7--INSERT A NODE AT POSITION\n");
   printf("8--DELETE A NODE AT POSITION\n");
   printf("9--SEARCH FOR A ROLL NUMBER NODE \n");
   printf("10--SEARCH FOR A HEIGHT NODE\n");
   printf("11--SEARCH FOR A NAME NODE\n");
   printf("12--INSERT NODE AFTER GIVEN NODE\n");
   printf("13--INSERT NODE BEFORE GIVEN NODE\n");
   printf("14--EXIT\n");


   printf("enter your choice\n");
   scanf("%d",&ch);

   switch(ch)
   {
     case 1:ptr=(struct student*)malloc(sizeof(struct student));
            printf("enter name rollno and height of student\n");
            scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
            head=insert_at_front(head,ptr);
            break;
    case 2: ptr=(struct student*)malloc(sizeof(struct student));
            printf("enter name rollno and height of student\n");
            scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
            head=insert_at_end(head,ptr);
            break;
    case 3: if(head==NULL)
            printf("CSLL is empty\n");
            else
            {
               head=delete_at_front(head);
            }
            break;
    case 4:if(head==NULL)
            printf("CSLL is empty\n");
            else
            {
               head=delete_at_end(head);
            }
            break;
    case 5: if(head==NULL)
            printf("CSLL is empty\n");
            else
            {
              display_SLL(head);
            }
            break;
    case 6: count=count_node(head);
            printf("number of node=%d\n",count);
            break;
    case 7: printf("enter the position\n");
                     scanf("%d",&pos);
                     if(pos<1 || pos>count_node(head)+1)
                        printf("inavalid position\n");
                     else
                     {
                         ptr=(struct student*)malloc(sizeof(struct student));
                        printf("enter name rollno and height of student\n");
                        scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
                          if(pos==1)
                         {
                             head=insert_at_front(head,ptr);
                         }
                         else if(pos==count_node(head)+1)
                         {
                             head=insert_at_end(head,ptr);
                         }
                         else
                         {
                             head=insert_at_pos(head,ptr,pos);
                         }
                     }
                     break;

     case 8: printf("enter the position\n");
              scanf("%d",&pos);
               if(pos<1 || pos>count_node(head)+1)
                printf("inavalid position\n");
                else
                {
                    if(pos==1)
                    {
                        head=delete_at_front(head);
                    }
                    else if(pos==count_node(head))
                    {
                        head=delete_at_end(head);
                    }
                    else
                    {
                    delete_at_pos(head,pos);
                    }
                }
               break;

        case 9: search_rollno_node(head);
                break;

       case 10: search_height_node(head);
                break;

        case 11: search_name_node(head);
                  break;

        case 12:ptr=(struct student*)malloc(sizeof(struct student));
                 printf("Enter the details \n");
               scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
                   insert_newnode_after_node(head,ptr);
                     break;
        case 13:ptr=(struct student*)malloc(sizeof(struct student));
        printf("enter the details\n");
        scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
         insert_newnode_before_node(head,ptr);
                     break;

    case 14: exit(0);break;
    default:printf("Invalid choice\n");break;
   }
}while(ch!=14);
}




struct student* insert_at_front(struct student *head, struct student *ptr)
{
    struct student *start,*cur;
    if(head==NULL)
    {
       head=ptr;
       ptr->link=head;
    }
    else
    {
       start=head;
       while(start->link!=head)
       {
           start=start->link;
       }
       ptr->link=head;
       start->link=ptr;
       head=ptr;
    }
    return(head);
}

struct student* insert_at_end(struct student *head, struct student *ptr)
{
    struct student *start;
    if(head==NULL)
    {
       head=ptr;
       ptr->link=head;
    }
    else
    {
      start=head;
      while(start->link!=head)
      {
         start=start->link;
      }
      start->link=ptr;
      ptr->link=head;
    }
    return(head);
}

struct student* delete_at_front(struct student *head)
{
   struct student *start,*cur;
      if(head->link==head)
      {
          printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",head->name,head->rno,head->ht);
          free(head);
          head=NULL;
      }
      else
      {
         start=head;
         while(start->link!=head)
         {
             start=start->link;
         }
           printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",head->name,head->rno,head->ht);
          cur=head->link;
          free(head);
          start->link=cur;
          head=cur;
      }
      return(head);

}


struct student* delete_at_end(struct student *head)
{
    struct student *start,*cur;
      if(head->link==head)
      {
          printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",head->name,head->rno,head->ht);
          free(head);
          head=NULL;
      }
      else
      {
          start=head;
      while(start->link!=head)
      {
          cur=start;
         start=start->link;
      }
        printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);
          free(start);
          cur->link=head;
      }
      return(head);

}

void display_SLL(struct student *head)
{
   struct student *start;
   start=head;
   while(start->link!=head)
   {
       printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);
       start=start->link;
   }
     printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);

}
int count_node(struct student *head)
{
     int c=0;
        struct student *start;
    if(head==NULL)
       return(c);
    else
    {
        start=head;
        while(start->link!=head)
        {
            c++;
            start=start->link;
        }
        c++;
        return(c);
    }

}
struct student* insert_at_pos(struct student *head, struct student *ptr,int pos)
{
    int p=1;
    struct student *start,*temp;
    start=head;
    while(p!=pos)
    {
        temp=start;
        start=start->link;
        p++;
    }
    temp->link=ptr;
    ptr->link=start;
    return(head);
}


struct student* delete_at_pos(struct student *head , int pos)
{
    int p=1;
    struct student *start,*temp;
    start=head;

    while(p!=pos)
    {
        temp=start;
        start=start->link;
        p++;
    }
    printf("deleted node is:\n");
    printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);
  //  temp->link=NULL;
    temp->link=start->link;
    free(start);
    return(head);
}

struct student* search_rollno_node(struct student *head)
{
    int r;
    struct student *start;
    if(head==NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        printf("Enter the roll number\n");
        scanf("%d",&r);
        start=head;

        while(start!=NULL)
        {
            if(start->rno==r)
            {
                printf("Student record found\n");
                printf("Name=%s\t Roll number=%d\t Height=%f\n",start->name,start->rno,start->ht);
                break;
            }
            start=start->link;
        }

        if(start==NULL)
        {
            printf("Student details not found\n");
        }
    }
}

struct student* search_height_node(struct student *head)
{
    float h;
    struct student *start;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Enter height\n");
        scanf("%f",&h);
        start=head;

        while(start!=NULL)
        {
            if(start->ht==h)
            {
                 printf("Name=%s\t Roll number=%d\t Height=%f\n",start->name,start->rno,start->ht);
                 break;
            }
            start=start->link;
        }
        if(start==NULL)
        {
            printf("Student not found\n");
        }
    }
}

struct student* search_name_node(struct student *head)
{
    char n[30];
    struct student *start;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Enter Name\n");
        scanf("%s",&n);
        start=head;

        while(start!=NULL)
        {
            if(strcmp(start->name,n)==0)
            {
                printf("Student found\n");
                 printf("Name=%s\t Roll number=%d\t Height=%f\n",start->name,start->rno,start->ht);
                 break;
            }
            start=start->link;
        }
        if(start==NULL)
        {
            printf("Student not found\n");
        }
    }
}

struct student* insert_newnode_after_node(struct student *head ,struct student *ptr)
{
    int rollno;
  struct student *start;
   start=head;
   printf("Enter roll number node\n");
   scanf("%d",&rollno);
   while(start!=NULL)
   {
   if(start->rno==rollno)
   {
       ptr->link=start->link;
       start->link=ptr;
   }
   start=start->link;
   }
}
struct student* insert_newnode_before_node(struct student *head ,struct student *ptr)
{
    int rollno;
  struct student *start;
   start=head;
   printf("Enter roll number node\n");
   scanf("%d",&rollno);
   while(start!=NULL)
   {
   if(start->rno==rollno)
   {
       ptr->link=start->link;
       start->link=ptr;
   }
   start=start->link;
   }
}

