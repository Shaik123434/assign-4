#include <stdio.h>

struct Customer {
    int account_no;
    char name[50];
    float balance;
};

void print_low_balance_customers(struct Customer customers[], int n) {
    int i;
    printf("Customers with balance less than 100 Rs:\n");
    for (i = 0; i < n; i++) {
        if (customers[i].balance < 100) {
            printf("%d %s\n", customers[i].account_no, customers[i].name);
        }
    }
}

int main() {
    struct Customer customers[3];
    int i;
    
    printf("Enter customer details:\n");
    for (i = 0; i < 3; i++) {
        printf("Customer %d:\n", i+1);
        printf("Account number: ");
        scanf("%d", &customers[i].account_no);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }
    
    print_low_balance_customers(customers, 3);
    
    return 0;
}

