#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *n) {
    printf("Enter Roll No: ");
    scanf("%d", &s[*n].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s[*n].name);
    printf("Enter Marks: ");
    scanf("%f", &s[*n].marks);
    (*n)++;
    printf("Student Added!\n");
}

void displayAll(struct Student s[], int n) {
    printf("\nAll Student Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void searchByRoll(struct Student s[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("Found: %s with %.2f marks\n", s[i].name, s[i].marks);
            return;
        }
    }
    printf("Student with roll %d not found.\n", roll);
}

float calculateAverage(struct Student s[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += s[i].marks;
    }
    return (n > 0) ? total / n : 0;
}

void findTopper(struct Student s[], int n) {
    if (n == 0) {
        printf("No records to search.\n");
        return;
    }
    int topIndex = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topIndex].marks)
            topIndex = i;
    }
    printf("Topper: %s with %.2f marks\n", s[topIndex].name, s[topIndex].marks);
}

int main() {
    struct Student s[MAX];
    int n = 0, choice, roll;

    do {
        printf("\n--- SmartStudent Menu ---\n");
        printf("1. Add Student\n2. Display All\n3. Search by Roll\n4. Average Marks\n5. Topper\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(s, &n); break;
            case 2: displayAll(s, n); break;
            case 3: 
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                searchByRoll(s, n, roll); 
                break;
            case 4: 
                printf("Average Marks: %.2f\n", calculateAverage(s, n)); 
                break;
            case 5: findTopper(s, n); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 6);

    return 0;
}
