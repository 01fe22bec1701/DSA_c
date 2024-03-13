#include<stdio.h>

main()
{
    int arr[50];
    int n,key;
   void read_array(int arr[50],int n);
   void display_array(int arr[50],int n);
   void linear_search(int arr[50],int n,int key);

   printf("enter no of elements in array\n");
   scanf("%d",&n);
   if(n>=1 && n<=50)
   {
        read_array(arr,n);
        display_array(arr,n);
        printf("enter the key to search\n");
        scanf("%d",&key);
        linear_search(arr,n,key);
   }
   else
    {
          printf("invalid number\n");
    }
}
 void read_array(int arr[50],int n)
 {
 int i;
    printf("enter array elements\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&arr[i]);
    }
 }

 void display_array(int arr[50],int n)
 {
 int i;
    printf("the array elements\n");
    for(i=0;i<n;i++)
    {
       printf("%d\n",arr[i]);
    }
 }

 void linear_search(int arr[50],int n,int key)
 {
     int i,j,f=0,c=0;

          for(i=0;i<n;i++)
          {
             if(arr[i]==key)
             {

               f=1;
               c++;
             }
          }
          if(f==1)
         printf("key found %d times\n",c);
         else
            printf("key not found\n");

 }
