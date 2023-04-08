#include <stdio.h>
#include <time.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_number;
    struct tm birthdate;
    struct tm admission_date;
};

int main() {
    struct Student student;
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    int age;
    
    printf("Enter student details:\n");
    printf("Name: ");
    fgets(student.name, 50, stdin);
    student.name[strcspn(student.name, "\n")] = 0;
    printf("Roll number: ");
    scanf("%d", &student.roll_number);
    printf("Birthdate (dd mm yyyy): ");
    scanf("%d %d %d", &student.birthdate.tm_mday, &student.birthdate.tm_mon, &student.birthdate.tm_year);
    printf("Admission date (dd mm yyyy): ");
    scanf("%d %d %d", &student.admission_date.tm_mday, &student.admission_date.tm_mon, &student.admission_date.tm_year);
    
    student.birthdate.tm_mon -= 1;
    student.birthdate.tm_year -= 1900;  
    student.admission_date.tm_mon -= 1;
    student.admission_date.tm_year -= 1900;
    
    age = local_time->tm_year - student.birthdate.tm_year;
    if (local_time->tm_mon < student.birthdate.tm_mon ||
        (local_time->tm_mon == student.birthdate.tm_mon && local_time->tm_mday < student.birthdate.tm_mday)) {
        age--;
    }
    
    printf("Age of student at the time of admission: %d\n", age);
    
    return 0;
}

