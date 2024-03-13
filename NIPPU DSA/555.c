#include<stdio.h>
#define NULL 0
typedef struct player
{
    char name[30],gender[6];
    int score;
    struct player *link;
}c;
c *ptr,*head,*start,*cur,*temp;
c* insert_number_of_players(c*);
c* turn_after_given_player(c*);
void vinay(c*);
c* player_left(c*);
main()
{
    head=NULL;
    int ch;
    do
    {
        printf("1--Allow number of player\n");
        printf("2--player who have turn to play after k th player\n");
        printf("3--number of player whose name id VINAY\n");
        printf("4--Current players details of M th player left the game\n");
        printf("5--To end the Game\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:head=insert_number_of_players(head);
                    break;
            case 2:if(head==NULL)
            {
                printf("There is no players\n");
            }
            else
            {
                head=turn_after_given_player(head);
            }
            break;

        case 3:if(head==NULL)
        {
            printf("There is no players\n");
        }
        else
        {
          vinay(head);
        }
        break;

        case 4:if(head==NULL)
        {
            printf("There is no players\n");
        }
        else
        {
            head=player_left(head);
        }
        break;

        case 5:exit(0);break;
        default:printf("invalid choice\n");break;
    }
}while(ch!=5);
}

c* insert_number_of_players(c* head)
{
    int n,i;
    printf("Enter number of new players\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        ptr=(c*)malloc(sizeof(c));
        printf("Enter player name, Gender, score\n");
        scanf("%s%s%d",&ptr->name,&ptr->gender,&ptr->score);
            if(head==NULL)
            {
                head=ptr;
                head->link=head;
            }
            else if(head->link==head)
            {
                head->link=ptr;
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

    }
    return(head);
}


c* turn_after_given_player(c* head)
{
    int p=1,k;
    printf("Enter value of K\n");
    scanf("%d",&k);
    start=head;
    cur=start->link;
    while(p!=k)
    {
      start=start->link;
      cur=start->link;
      p++;
    }
    printf("Details of player who have turn to play after %d player\n",k);
    printf("Name=%s\tGender=%s\tscore=%d\n",cur->name,cur->gender,cur->score);
    return(head);
}

void vinay(c* head)
{
    int v=0;
    char s[30];
    start=head;
    printf("Enter Name\n");
    scanf("%s",&s);
    while(start->link!=head)
    {
        if(strcmp(s,start->name)==0)
        {
            v++;
        }
        start=start->link;
    }

        if(strcmp(s,start->name)==0)
        {
            v++;
        }
    printf("Number of players who named as vinay is= %d\n",v);
}

c* player_left(c* head)
{
    int m,p=1;
    printf("Enter value of M\n");
    scanf("%d",&m);
    start=head;
    temp=start;
    while(p!=m)
    {
      temp=start;
      start=start->link;
      p++;
    }

    if(start==head)
    {
         printf("Details of player who left the game is:\n");
    printf("Name=%s\tGender=%s\tscore=%d\n",head->name,head->gender,head->score);
        while(start->link!=head)
        {
            start=start->link;
        }
        head=head->link;
        start->link=start;
        free(start);
    }
    else
    {
         printf("Details of player who left the game is:\n");
    printf("Name=%s\tGender=%s\tscore=%d\n",start->name,start->gender,start->score);

        temp->link=start->link;
        free(start);
    }


    start=head;
    printf("\n");
    printf("Current plyaers are\n");
    while(start->link!=head)
    {
        printf("Name=%s\tGender=%s\tscore=%d\n",start->name,start->gender,start->score);
        start=start->link;
    }
        printf("Name=%s\tGender=%s\tscore=%d\n",start->name,start->gender,start->score);
        return(head);
}
