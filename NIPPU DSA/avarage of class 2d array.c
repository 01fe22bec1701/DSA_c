#include<stdio.h>
main()
{
    int a[30][40],N,M;
    void read_array(int a[30][40],int N,int M);
    void display_array(int a[30][40],int N,int M);
    void avg_array(int a[30][40],int N,int M);
    printf("enter no of students and courses\n");
    scanf("%d%d",&N,&M);
    if((N>=1 && N<=30) && (M>=1 && M<=40))
    {
         read_array(a,N,M);
       display_array(a,N,M);
       avg_array(a,N,M);
    }
    else
        {
              printf("invalid students count/courses count\n");
         }

}

void read_array(int a[30][40],int N,int M)
{
     int i,j;
     printf("enter the marks\n");
     for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
            scanf("%d",&a[i][j]);
         }
     }
}

void display_array(int a[30][40],int N,int M)
{
     int i,j;
     printf("the marks sheet is\n");
     for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
            printf("%d ",a[i][j]);
         }
        printf("\n");
     }
}

void avg_array(int a[30][40],int N,int M)
{
    int sum=0,i,j;
    float avg;
     for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
           sum=sum+a[i][j];
         }
     }

     avg=(float)sum/(N*M);
     printf("average of the class=%f\n",avg);
}
