#include<stdio.h>

main()
{
   int a[50];
    int n;
   void read_array(int a[50],int n);
   void display_array(int a[50],int n);
   void prime_array(int a[50],int n);

   printf("enter no of elements in array\n");
   scanf("%d",&n);
   if(n>=1 && n<=50)
   {
        read_array(a,n);
        display_array(a,n);
        prime_array(a,n);
   }
   else
    {
          printf("invalid number\n");
    }
}
 void read_array(int a[50],int n)
 {
 int i;
    printf("enter array elements\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
 }

 void display_array(int a[50],int n)
 {
 int i;
    printf("the array elements\n");
    for(i=0;i<n;i++)
    {
       printf("%d\n",a[i]);
    }
 }

 void prime_array(int a[50],int n)
 {
     int i,j,prime;
     printf("the prime elements are\n");
     for(j=0;j<n;j++)
     {
        prime=1;
          for(i=2;i<=a[j]/2;i++)
          {
             if(a[j]%i==0)
             {
                prime=0;
                break;
             }
          }
          if(prime==1)
            printf("%d\n",a[j]);
     }
 }
