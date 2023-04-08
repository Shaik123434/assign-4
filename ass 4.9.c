#include <stdio.h>

union student {
    char name[50];
    float gpa;
};

int main() {
    union student s;
    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    printf("Enter student GPA: ");
    scanf("%f", &s.gpa);
    printf("Student name: %s\n", s.name);
    printf("Student GPA: %f\n", s.gpa);
    return 0;
}

