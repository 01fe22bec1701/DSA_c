    1`  #include<stdio.h>
#include<stdlib.h>
struct player
{
    char name[30];
    int gl;
    float ht;
    struct player *link;
};
struct player *head,*ptr,*temp,*cur,*start;
 int ch,count,pos;
 int main()
{
head=NULL;
 struct player* insert_front(struct player *head, struct player *ptr);
 struct player* insert_end(struct player *head, struct player *ptr);
 struct player* delete_front(struct player *head);
 struct player* delete_end(struct player *head);
 void display(struct player *head);
 int count_node(struct player *head);
 struct player* insert_at_position(struct player *head,struct player *ptr);
 struct player* delete_at_position(struct player *head);
 struct player* search_name(struct player *head);
 struct player* search_gl(struct player *head);
 struct player* it_aft_given_name(struct player *head,struct player *ptr);
 struct player* it_bef_given_gl(struct player *head,struct player *ptr);
 struct player* de_aft_given_name(struct player *head);


 do
 {
printf("1--INSERT NODE PRONT\n");
printf("2--INSERT NODE END\n");
printf("3--DELETE NODE PRONT\n");
printf("4--DELETE NODE PRONT\n");
printf("5--DISPLAY\n");
printf("6--COUNT NODE\n");
printf("7--INSERT AT POSITION\n");
printf("8--DELETE AT POSITION\n");
printf("9--SEARCH A GIVEN NAME\n");
printf("10--SEARCH A GIVEN GOAL\n");
printf("11--INSERT A PLAYER AFTER A GIVEN NAME\n");
printf("12--INSERT A PLAYER BEFORE A GIVEN GOAL\n");
printf("13--DELETE A PLAYER AFTER A GIVEN NAME\n");
printf("14--EXIT\n");

printf("enter your choice\n");
scanf("%d",&ch);

switch(ch)
{
    case 1:    ptr=(struct player*)malloc(sizeof(struct player));
               printf("enter name.goal,height of the player\n");
               scanf("%s%d%f",&ptr->name,&ptr->gl,&ptr->ht);
               head=insert_front(head,ptr);
               break;

    case 2:
               ptr=(struct player*)malloc(sizeof(struct player));
               printf("enter name.goal,height of the player\n");
               scanf("%s%d%f",&ptr->name,&ptr->gl,&ptr->ht);
               head=insert_end(head,ptr);
               break;


    case 3: if(head==NULL)
          {
             printf("SLL is empty\n");
          }
          else
          {
              head=delete_front(head);
          }
          break;

     case 4: if(head==NULL)
          {
             printf("SLL is empty\n");
          }
          else
          {
              head=delete_end(head);
          }
          break;

     case 5: if(head==NULL)
          {
             printf("SLL is empty\n");
          }
          else
          {
              display(head);
          }
          break;

    case 6: count=count_node(head);
            printf("number of node=%d\n",count);
            break;
    case 7: printf("enter the position\n");
            scanf("%d",&pos);
            if(pos<1 || pos>count_node(head)+1)
            {
                printf("Invalid position\n");
            }
            else
            {
              ptr=(struct player*)malloc(sizeof(struct player));
               printf("enter name.goal,height of the player\n");
               scanf("%s%d%f",&ptr->name,&ptr->gl,&ptr->ht);
               if(pos==1)
               {
                   head=insert_front(head,ptr);
               }
               else if(pos==count_node(head)+1)
               {
                   head=insert_end(head,ptr);
               }
               else
               {
                   insert_at_position(head,ptr);
               }
            }
            break;


    case 8: printf("enter the position\n");
            scanf("%d",&pos);
            if(pos<1 || pos>count_node(head))
            {
                printf("Invalid position\n");
            }
            else
            {
                if(pos==1)
                {
                    head=delete_front(head);
                }
                else if(pos>count_node(head))
                {
                    head=delete_end(head);
                }
                else
                {
                    head=delete_at_position(head);
                }
            }
            break;
    case 9: head=search_name(head);
           break;
    case 10: head=search_gl(head);
             break;

    case 11: ptr=(struct player*)malloc(sizeof(struct player));
               printf("enter name.goal,height of the player\n");
               scanf("%s%d%f",&ptr->name,&ptr->gl,&ptr->ht);
               head=it_aft_given_name(head,ptr);
               break;
    case 12:ptr=(struct player*)malloc(sizeof(struct player));
               printf("enter name.goal,height of the player\n");
               scanf("%s%d%f",&ptr->name,&ptr->gl,&ptr->ht);
               head=it_bef_given_gl(head,ptr);
               break;
    case 13: head=de_aft_given_name(head);
             break;
    case 14: exit(0);break;
    default:printf("Invalid choice\n");
    }

}while(ch!=14);
}


 struct player* insert_front(struct player *head,struct player*ptr)
 {
   struct player *start;
   if(head==NULL)
   {
       head=ptr;
       head->link=head;
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
    head=ptr;
}
return(head);
 }

  struct player* insert_end(struct player *head,struct player*ptr)
  {
   struct player *start;
   if(head==NULL)
   {
       head=ptr;
       head->link=head;
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


 struct player* delete_front(struct player *head)
 {
  struct player *cur,*start,*temp;
  if(head->link==head)
  {
    printf("node deleted is\n");
      printf("name=%s\t goal=%d\t height=%f\n",head->name,head->gl,head->ht);
      free(head);
      head=NULL;
  }
  else
    {
    temp=head;
  head=head->link;
  printf("node deleted is\n");
      printf("name=%s\t goal=%d\t height=%f\n",temp->name,temp->gl,temp->ht);
      free(temp);
  start=head;
  while(start->link!=head)
  {
      start=start->link;
  }
  start->link=head;
  }
  return(head);
 }


  struct player* delete_end(struct player *head)
  {
   struct player *cur,*start;
   if(head->link==head)
  {
      printf("node deleted is\n");
      printf("name=%s\t goal=%d\t height=%f\n",head->name,head->gl,head->ht);
      free(head);
      head=NULL;
  }
  else
  {
      cur=head;
      while(cur->link!=head)
      {
          start=cur;
          cur=cur->link;
      }
      printf("node deleted is\n");
      printf("name=%s\t goal=%d\t height=%f\n",cur->name,cur->gl,cur->ht);
      free(cur);
      start->link=head;
  }
  return(head);
  }


   void display(struct player *head)
   {

      struct player *start;
      start=head;
      printf("the details of the player are\n");
      while(start->link!=head)
      {
        printf("name=%s\t goal=%d\t height=%f\n",start->name,start->gl,start->ht);
        start=start->link;
      }
        printf("name=%s\t goal=%d\t height=%f\n",start->name,start->gl,start->ht);
   }



 int count_node(struct player *head)
 {
     int count=0;
     if(head==NULL)
     {
          return(count);
     }
     else
     {
         start=head;
         while(start->link!=head)
         {
             count++;
             start=start->link;
         }
         count++;
         }
     return(count);
 }


 struct player* insert_at_position(struct player *head,struct player *ptr)
 {
  struct player *temp,*start,*cur;
  int p;
  start=head;
  p=1;
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

 struct player* delete_at_position(struct player *head)
 {
   struct player *start,*temp,*cur;
   int p=1;
   start=head;
   while(p!=pos)
   {
       temp=start;
       start=start->link;
       p++;
   }
   cur=start->link;
   printf("node deleted is\n");
   printf("name=%s\t goal=%d\t height=%f\n",start->name,start->gl,start->ht);
   free(start);
   temp->link=cur;
   return(head);
   }

    struct player* search_name(struct player *head)
    {
     struct player *start,*temp;
     char na[30];
     printf("enter the required name\n");
     scanf("%s",&na);
     start=head;
     while(start!=NULL)
     {
         if(strcmp(start->name,na)==0)
         {
             printf("player found\n");
             printf("name=%s\t goal=%d\t height=%f\n",start->name,start->gl,start->ht);
             break;
         }
         start=start->link;

     }
     if(start==NULL)
     {
         printf("NO player found\n");
     }

     return(head);
    }



struct player* search_gl(struct player *head)
{
 struct player *start;
 int g;
 printf("enter the required goal\n");
 scanf("%d",&g);
 start=head;
 while(start!=NULL)
 {
     if(start->gl==g)
     {
          printf("player found\n");
             printf("name=%s\t goal=%d\t height=%f\n",start->name,start->gl,start->ht);
             break;
     }
     start=start->link;
 }
 if(start==NULL)
     {
         printf("NO player found\n");
     }

     return(head);
}

 struct player* it_aft_given_name(struct player *head,struct player *ptr)
 {
    char n[30];
    printf("enter the required name\n");
    scanf("%s",&n);
    start=head;
    while(start->link!=head)
    {
        if(strcmp(start->name,n)==0)
        {
            temp=start->link;
            start->link=ptr;
            ptr->link=temp;
        }
        start=start->link;
    }
    return(head);
 }


 struct player* it_bef_given_gl(struct player *head,struct player *ptr)
 {
  struct player *start;
  int g;
  printf("enter the required goal\n");
  scanf("%d",&g);
  start=head;
  while(start->link!=head)
  {
      if(start->gl==g)
      {
         if(start==head)
         {
             ptr->link=start;
             head=ptr;
             break;
         }
         else
         {
             cur->link=ptr;
             ptr->link=start;
             break;
         }
      }
    cur=start;
    start=start->link;
  }
  return(head);
 }

  struct player* de_aft_given_name(struct player *head)
  {
   char n[30];
   printf("enter the required name\n");
   scanf("%s",&n);
   start=head;
   while(start->link!=head)
   {
       if(strcmp(start->name,n)==0)
       {

           temp=start->link;
            printf("node deleted is\n");
            printf("name=%s\t goal=%d\t height=%f\n",temp->name,temp->gl,temp->ht);

            if(temp->link==NULL)
            {
                start->link=NULL;
                free(temp);
            }
            else
            {
              start->link=temp->link;
              free(temp);
            }

       }
               start=start->link;
   }
   return(head);
  }

