#include <stdio.h>361

int armstrong(int n);

int main() {
    int n, s;
    printf("Enter an integer number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Invalid number\n");
        exit(0);
    }
    s = armstrong(n);
    printf("sum=%d\n",s);
    if (s == n) {
        printf("It is an Armstrong number\n");
    } else {
        printf("It is not an Armstrong number\n");
    }
    return 0;
}

int armstrong(int n) {
    int d, count = 0, temp = n, sum = 0;
    while (temp > 0) {
        temp =temp/ 10;
        count++;
    }
    temp = n;
    while (temp > 0) {
        d = temp % 10;
        sum = sum+pow(d, count);
        temp =temp/ 10;
    }
    return sum;
}
