#include <stdio.h>

struct Employee {
    int eno;
    char ename[50];
    float salary;
};

int main() {
    int n, i, max_index;
    float max_salary;
    
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    struct Employee employees[n];

    
    for (i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i+1);
        printf("Employee number: ");
        scanf("%d", &employees[i].eno);
        printf("Employee name: ");
        scanf("%s", employees[i].ename);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    
    max_index = 0;
    max_salary = employees[0].salary;
    for (i = 1; i < n; i++) {
        if (employees[i].salary > max_salary) {
            max_index = i;
            max_salary = employees[i].salary;
        }
    }

    
    printf("Employee with highest salary:\n");
    printf("Employee number: %d\n", employees[max_index].eno);
    printf("Employee name: %s\n", employees[max_index].ename);
    printf("Salary: %f\n", employees[max_index].salary);
    
    return 0;
}

