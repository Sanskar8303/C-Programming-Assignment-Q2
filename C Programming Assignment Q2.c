#include <stdio.h>

// Structure for bank account
typedef struct {
    int account_number;
    float balance;
} BankAccount;

// Function prototypes
void display_menu();
void deposit(BankAccount* account);
void withdraw(BankAccount* account);
void check_balance(BankAccount* account);

int main() {
    // Initialize three bank accounts
    BankAccount accounts[3] = {
        {1, 1000.0},
        {2, 2000.0},
        {3, 3000.0}
    };

    int choice, account_choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        printf("Select an account (1, 2, or 3): ");
        scanf("%d", &account_choice);

        if (account_choice < 1 || account_choice > 3) {
            printf("Invalid account selection!\n");
            continue;
        }

        BankAccount* selected_account = &accounts[account_choice - 1];

        switch (choice) {
            case 1:
                deposit(selected_account);
                break;
            case 2:
                withdraw(selected_account);
                break;
            case 3:
                check_balance(selected_account);
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

// Display banking menu
void display_menu() {
    printf("\n--- Banking Menu ---\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
}

// Deposit money into an account
void deposit(BankAccount* account) {
    float amount;
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);

    if (amount > 0) {
        account->balance += amount;
        printf("Deposit successful. New balance: $%.2f\n", account->balance);
    } else {
        printf("Deposit amount must be positive!\n");
    }
}

// Withdraw money from an account
void withdraw(BankAccount* account) {
    float amount;
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);

    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawal successful. New balance: $%.2f\n", account->balance);
    } else {
        printf("Insufficient balance or invalid amount!\n");
    }
}

// Check account balance
void check_balance(BankAccount* account) {
    printf("Current balance: $%.2f\n", account->balance);
}
