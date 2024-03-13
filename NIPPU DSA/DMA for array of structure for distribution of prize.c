#include <stdio.h>
#include <stdlib.h>

// Structure to store student details
struct Student {
    int rank;
    char name[50];
    int medals;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of structures
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    readStudentDetails(students, n);
    displayStudentDetails(students, n);

    sortStudentDetails(students, n);

    printf("\nSorted student details:\n");
    displayStudentDetails(students, n);

    int multipleMedalsCount = countStudentsWithMultipleMedals(students, n);
    printf("\nNumber of students who won multiple medals: %d\n", multipleMedalsCount);

    // Free dynamically allocated memory
    free(students);

    return 0;
}

// Function to read student details
void readStudentDetails(struct Student *students, int n) {
    printf("Enter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Enter rank: ");
        scanf("%d", &(students[i].rank));
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter number of medals: ");
        scanf("%d", &(students[i].medals));
    }
}

// Function to display student details
void displayStudentDetails(struct Student *students, int n) {
    printf("Student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Rank: %d\n", students[i].rank);
        printf("Name: %s\n", students[i].name);
        printf("Medals: %d\n", students[i].medals);
    }
}

// Function to swap two student records
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort student details by rank using selection sort
void sortStudentDetails(struct Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (students[j].rank < students[minIndex].rank) {
                minIndex = j;
            }
        }
        swap(&students[i], &students[minIndex]);
    }
}

// Function to count students who have won multiple medals
int countStudentsWithMultipleMedals(struct Student *students, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].medals > 1) {
            count++;
        }
    }
    return count;
}

