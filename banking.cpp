#include <iostream>
#include <iomanip>

double deposit();
double withdraw(double balance);

int main() {

    double balance = 10000;
    int choice = 0;

    do{
        std::cout << "**********************\n";
        std::cout << "Enter your choice:\n";
        std::cout << "**********************\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        while(choice < 1 || choice > 4){
            std::cout << "Invalid input. Please select options 1 to 4.\n";
            std::cin >> choice;
        }

        switch(choice){
            case 1:
                std::cout << "Your balance is $" << balance <<'\n';
                break;
            case 2:
                double amount_d;
                amount_d = deposit();
                balance += amount_d;
                std::cout << "The amount you have deposited is $" << amount_d << ".\nYour balance is now $" << std::setprecision(2) << std::fixed << balance << ".\n";
                break;
            case 3:
                double amount_w = withdraw(balance);
                balance -= amount_w; 
                std::cout << "The amount you have withdrawn is $" << amount_w << ".\nYour balance is now $" << std::setprecision(2) << std::fixed << balance << ".\n";
                break;
        }
    }while(choice != 4);

    std::cout << "Thank you for using our services.\n";
    return 0;
}

double deposit() {
    std::cout << "Enter the amount you want to deposit: $";
    double depositAmount;
    std::cin >> depositAmount;

    while(depositAmount <= 0){
        std::cout << "\nInvalid input. Re-enter the amount: $";
        std::cin >> depositAmount;
    }

    while(depositAmount > 99999){
        std::cout << "\nYou have exceeded the deposit limit. Re-enter the amount: $";
        std::cin >> depositAmount;
    }

    return depositAmount; 
}

double withdraw(double balance) {
    std::cout << "Enter the amount you want to withdraw: $";
    double withdrawAmount;
    std::cin >> withdrawAmount;

    while(withdrawAmount > balance){
        std::cout << "\nInsufficient balance. Re-enter the amount: $";
        std::cin >> withdrawAmount;    
    }

    while(withdrawAmount <= 0){
        std::cout << "\nInvalid input. Re-enter the amount: $";
        std::cin >> withdrawAmount;
    }

    return withdrawAmount;
}



