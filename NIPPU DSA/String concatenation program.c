#include<stdio.h>

main()
{
        char str1[100],str2[10];
        int c;
        printf("enter 2 strings\n");
        gets(str1);
        gets(str2);
        printf("the 2 strings are\n");
        puts(str1);
        printf("\n");
        puts(str2);
        c=strcpy(str1,str2);//str2 copied to str1
        printf("new str1 after copying is\n");
        puts(str1);
        //i love you
}
