#include<stdio.h>
#define NULL
struct book
{
char author;
char title;
float price;
struct book *link
};
main()
{
    struct book *hrad,*start,*ptr;
    int ch;
    head=NULL;
    struct book* insert_at_front(struct book *,struct book *);
    struct book* insert_at_end(struct book *,struct book *);
    struct book* delete_at_front(struct book*);
    struct book* delete_at_end(struct book*);
    void display_SLL(struct book*);
    do
    {
        printf("1-INSERT A NODE AT FRONT\N");
        printf("2-INSERT A NODE AT END\n");
        printf("3-DELETE A NODE AT FRONT\n");
        printf("4-DELETE A NODE AT END\n");
        printf("5-DISPLAY LINKED LIST\n");
        printf("6-EXIT\n");

        printf("enter a choice\n");
        scanf("%d",ch);

        switch(ch)
        {
            case 1: ptr=(struct book*)malloc(sizeof(struct book));
            printf("enter author,title,price of a book\n");
            scanf("%s%s%f",&head->autrhor,&head->title,&head->price);
        }
()    }
}
