#include <iostream>
#include <cstring>

using namespace std;

int getDigit(const int number);
int sumOddDigits(string cardNumber);
int sumEvenDigits(string cardNumber);

void verify(){
    string cardNumber;
    int result = 0;

    cout << "Enter credit card number: ";
    cin >> cardNumber;

    while(cardNumber.length() < 16 || result%10 != 0){
        cout << "\nCard number is invalid. Re-enter your card number: \n";
        cin >> cardNumber;
        result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);
    }
    
    cout << "\nCard number is valid.";
}

int getDigit(const int number){
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i -= 2){
        sum += getDigit(cardNumber[i] - '0');
    }
    return sum;
}

int sumEvenDigits(const string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 2; i >= 0; i -= 2){
        sum += getDigit((cardNumber[i] - '0')*2);
    }
    return sum;
}
