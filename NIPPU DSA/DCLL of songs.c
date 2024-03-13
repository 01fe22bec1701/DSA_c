#include<stdio.h>
#include<stdlib.h>
struct song
{
   struct song *prev;
   char tit[30];
   char s_name[30];
   float dur;
   struct song *next;
};

struct song* insert_song_front(struct song *,struct song *);
struct song* insert_song_end(struct song *,struct song *);
struct song* delete_song_front(struct song *);
struct song* delete_song_end(struct song *);
void display_song(struct song*);
void display_song_backward(struct song *head);
struct song* insert_pos(struct song *,struct song *,int pos);
int count_song(struct song *head);
struct song *head,*start,*temp,*cur,*ptr;
main()
{
   int ch,pos,count;
   head=NULL;
   do
   {
   printf("1--insert a song at front\n");
   printf("2--insert a song at end\n");
   printf("3--delete a song at front\n");
   printf("4--delete a song at end\n");
   printf("5--display all songs\n");
   printf("6--display all songs in reverse\n");
   printf("7--count number of songs\n");
   printf("8--insert at position\n");

   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1: ptr=(struct song*)malloc(sizeof(struct song));
                     printf("enter title, singer name and duration\n");
                     scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);
                     head=insert_song_front(head,ptr);
                     break;
     case 2: ptr=(struct song*)malloc(sizeof(struct song));
                     printf("enter title, singer name and duration\n");
                     scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);
                     head=insert_song_end(head,ptr);
                     break;
    case 3: if(head==NULL)
                      printf("no songs to delete\n");
                      else
                      {
                          head=delete_song_front(head);
                      }
                      break;
    case 4:  if(head==NULL)
                      printf("no songs to delete\n");
                      else
                      {
                          head=delete_song_end(head);
                      }
                      break;
    case 5: if(head==NULL)
                      printf("no songs to display\n");
                      else
                      {
                          display_song(head);
                      }
                      break;

    case 6:  if(head==NULL)
                      printf("no songs to display\n");
                      else
                      {
                         display_song_backward(head);
                      }
                      break;
    case 7: count=count_song(head);
             printf("total songs are=%d\n",count);
             break;
    case 8: printf("enter the position\n");
             scanf("%d",&pos);
             if(pos<1 || pos>count_song(head)+1)
                    printf("invalid position\n");

             else
             {
                 ptr=(struct song*)malloc(sizeof(struct song));
                 printf("enter the details of new song\n");
                 scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);

                  if(pos==1)
                 {
                     head=insert_song_front(head,ptr);
                 }
                 else if(pos==count_song(head)+1)
                 {
                     head=insert_song_end(head,ptr);
                 }
                 else
                 {
                     head=insert_pos(head,ptr,pos);
                 }
             }
             break;
    case 9:exit(0);break;
    default:printf("Invalid choice\n");break;
   }
}while(ch!=9);
}

struct song* insert_song_front(struct song *head, struct song *ptr)
{
    struct song *last;
   if(head==NULL)
   {
     head=ptr;
     head->next=head;
     head->prev=head;
   }
   else
   {
      last=head->prev;
      ptr->next=head;
      head->prev=ptr;
      last->next=ptr;
      ptr->prev=last;
      head=ptr;
   }
    return(head);
}

struct song* insert_song_end(struct song *head, struct song *ptr)
{
    struct song *last;

  if(head==NULL)
   {
     head=ptr;
     head->next=head;
     head->prev=head;
   }

   else
   {
       last=head->prev;
       head->prev=ptr;
       ptr->next=head;
       last->next=ptr;
       ptr->prev=last;
   }
   return(head);
}

struct song* delete_song_front(struct song *head)
{
    struct song *last;

    if(head->next==head)
    {
       printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",head->tit, head->s_name, head->dur);
       free(head);
       head=NULL;
    }
    else
    {
        last=head->prev;
        cur=head;
        head=head->next;
        printf("song deleted\n");
        printf("title=%s\t singer name=%s\t duration=%f\n",cur->tit, cur->s_name, cur->dur);
        free(cur);
        head->prev=last;
        last->next=head;
    }
    return(head);
}


struct song* delete_song_end(struct song *head)
{
    struct song *last;
    if(head->next==head)
    {
       printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",head->tit, head->s_name, head->dur);
       free(head);
       head=NULL;
    }

    else
    {
        last=head->prev;
        cur=last->prev;
        printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",last->tit, last->s_name, last->dur);
       free(last);
       head->prev=cur;
       cur->next=head;
    }
    return(head);
}




void display_song(struct song *head)
{
    start=head;
    printf("the songs are\n");
    while(start->next!=head)
    {
         printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
         start=start->next;
    }
    printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
}

void display_song_backward(struct song *head)
{
    struct song *last;
    last=head->prev;
    while(last->prev!=head)
    {
       printf("title=%s\t singer name=%s\t duration=%f\n",last->tit, last->s_name, last->dur);
       last=last->prev;
    }
    printf("title=%s\t singer name=%s\t duration=%f\n",last->tit, last->s_name, last->dur);
}

int count_song(struct song *head)
{
    int c=0;
    if(head==NULL)
        return(c);
    else
    {
        start=head;
        while(start->next!=head)
        {
            c++;
            start=start->next;
        }
        c++;
        return(c);
    }
}

struct song* insert_pos(struct song *head,struct song *ptr,int pos)
{
    int p=1;
    start=head;
    while(p!=pos)
    {
        start=start->next;
        p++;
    }
    temp=start->prev;
    start->prev=ptr;
    ptr->next=start;
    temp->next=ptr;
    ptr->prev=temp;
    return(head);
}
