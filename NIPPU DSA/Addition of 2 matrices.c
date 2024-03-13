#include<stdio.h>
main()
{
    int a[30][40],b[30][40],arow,acol,brow,bcol;
    void read_array(int a[30][40],int row,int col);
    void display_array(int a[30][40],int row,int col);
    void add_matrix(int a[30][40],int b[30][40],int row,int col);

    printf("enter no of rows and col of matrix A\n");
    scanf("%d%d",&arow,&acol);
    printf("enter no of rows and col of matrix B\n");
    scanf("%d%d",&brow,&bcol);
    if(arow==brow && acol==bcol)
    {
         read_array(a,arow,acol);
         read_array(b,brow,bcol);
       display_array(a,arow,acol);
       display_array(b,brow,bcol);
      add_matrix(a,b,arow,acol);
    }
    else
        {
              printf("matrix are not same: cant add the matrix\n");
         }


}

void read_array(int a[30][40],int row,int col)
{
     int i,j;
     printf("enter the array elements\n");
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
            scanf("%d",&a[i][j]);
         }
     }
}

void display_array(int a[30][40],int row,int col)
{
     int i,j;
     printf("the array elements are\n");
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
            printf("%d ",a[i][j]);
         }
        printf("\n");
     }
}

void add_matrix(int a[30][40],int b[30][40],int row,int col)
{
    int c[30][40];
    int i,j;
    printf("the sum array is\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            c[i][j]=a[i][j]+b[i][j];

        }
    }
    display_array(c,row,col);
}
