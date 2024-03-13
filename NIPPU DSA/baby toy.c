#include <stdio.h>
float getDiscount(float amount, char type) {
    if (type == 'T') {
        if (amount <= 1000) {
            return 0;
        } else if (amount <= 10000) {
            return 7;
        } else {
            return 9;
        }
    } else {
        if (amount <= 5000) {
            return 3;
        } else if (amount <= 10000) {
            return 8;
        } else {
            return 15;
        }
    }
}

int main() {
    char type;
    int age;
    float amount;
    float discount;
    float totalBill;


    printf("Enter type of item (T - Toys, C - Clothes): ");
    scanf("%c", &type);
    printf("Enter age group in years: ");
    scanf("%d", &age);
    printf("Enter purchase amount: ");
    scanf("%f", &amount);


    discount = getDiscount(amount, type);
    totalBill = amount - (amount * discount / 100);


    printf("Discount: %.2f%%\n", discount);
    printf("Total bill to be paid: Rs. %.2f\n", totalBill);

    return 0;
}


