#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student {
    int roll_no;
    char stud_name[50];
    int mark1, mark2, mark3;
    int total_marks;
    float avg_marks;
};

void calculate_marks(struct Student *stud) {
    stud->total_marks = stud->mark1 + stud->mark2 + stud->mark3;
    stud->avg_marks = stud->total_marks / 3.0;
}

void sort_students(struct Student *students, int num_students) 
{
	int i,j;
    for (i = 0; i < num_students-1; i++) {
        for (j = 0; j < num_students-i-1; j++) {
            if (students[j].total_marks < students[j+1].total_marks) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int main() 
{
    struct Student students[MAX_STUDENTS];
    int num_students,i;
    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);
    for (i = 0; i < num_students; i++) {
        struct Student stud;
        printf("Enter details for student %d:\n", i+1);
        printf("Roll no: ");
        scanf("%d", &stud.roll_no);
        printf("Name: ");
        scanf("%s", stud.stud_name);
        printf("Mark 1: ");
        scanf("%d", &stud.mark1);
        printf("Mark 2: ");
        scanf("%d", &stud.mark2);
        printf("Mark 3: ");
        scanf("%d", &stud.mark3);
        calculate_marks(&stud);
        students[i] = stud;
    }
    sort_students(students, num_students);
    printf("Roll No\tName\t\tTotal Marks\tAverage Marks\n");
    for (i = 0; i < num_students; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", students[i].roll_no, students[i].stud_name, students[i].total_marks, students[i].avg_marks);
    }
    return 0;
}

