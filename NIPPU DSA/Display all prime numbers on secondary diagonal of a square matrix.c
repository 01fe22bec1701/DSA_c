#include<stdio.h>
main()
{
    int a[30][40],row,col;
    void read_array(int a[30][40],int row,int col);
    void display_array(int a[30][40],int row,int col);
    void prime_principal_dig(int a[30][40],int row,int col);
    printf("enter no of rows and col\n");
    scanf("%d%d",&row,&col);
    if(row==col)
    {
    if((row>=1 && row<=30) && (col>=1 && col<=40))
    {
         read_array(a,row,col);
       display_array(a,row,col);
      prime_principal_dig(a,row,col);
    }
    }
    else
        {
              printf("row and col not equal\n");
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

void prime_principal_dig(int a[30][40],int row,int col)
{
    int sum=0,i,j,prime,k;
    float avg;
    printf("the prime numbers on pri diagonal are\n");
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
             if(i+j=row-1)
             {
                 if(a[i][j]>1)
                 {
                 prime=1;
                 for(k=2;k<=a[i][j]/2;k++)
                 {
                     if(a[i][j]%k==0)
                     {
                         prime=0;
                         break;
                     }
                 }
                 if(prime==1)
                 {
                     printf("%d ",a[i][j]);
                 }

             }
             }
         }
     }



}
