#include <stdio.h>
#include <string.h>

struct Employee 
{
    int emp_id;
    char name[50];
    char designation[50];
    char department[50];
    float salary;
};

int main() {
    struct Employee emp;
    
    printf("Enter employee ID: ");
    scanf("%d", &emp.emp_id);
    fflush(stdin);
    
    printf("Enter employee name: ");
    fgets(emp.name, 50, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;
    
    printf("Enter employee designation: ");
    fgets(emp.designation, 50, stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;
    
    printf("Enter employee department: ");
    fgets(emp.department, 50, stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;
    
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    
    printf("\nEmployee details:\n");
    printf("ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);
    
    return 0;
}

