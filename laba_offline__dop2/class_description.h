#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

int CoctailSort(std::vector<int>& v1, std::vector<double>& v2);
//opisanie classa
class BankAccount {
    //po suti nam nuzhno tri atributa: vector s account numbers, vector s accout balances i peremennaya int,
    //kotoraya otslezhivaet maximal'niy nomer otkritogo scheta.
private:
    std::vector<int> number;
    std::vector <double> balance;
    int last_num;
public:
    //default counstructor modeliruet situaciyu, kogda iznachal'no otkriti 100 schetov.
    BankAccount() {
        last_num = 1000;
        for (int i{ 0 }; i < 100; i++) {
            last_num++;
            number.push_back(last_num);
            balance.push_back(rand());
        }
    }
    //etot constructor otkrivaet iznachal'no ukazannoe kol-vo schetov.
    BankAccount(int n) {
        if (n <= 0){
            last_num = 1000;
            for (int i{ 0 }; i < 100; i++) {
                last_num++;
                number.push_back(last_num);
                balance.push_back(rand());
            }
        }
        else {
            last_num = 1000;
            for (int i{ 0 }; i < n; i++) {
                last_num++;
                number.push_back(last_num);
                balance.push_back(rand());
            }
        }
    }
    int O();
    int B();
    int D();
    int W();
    int C();
    int P();
    int I();
};

//vneshnie funkcii, sootvetstvuyushie vibrannoy userom tranzakcii.
int BankAccount::O() {

    double amount;
    std::cout << "Amount: ";
    std::cin >> amount;

    CoctailSort(number, balance);

    for (int i{ 0 }; i < number.size() - 1; i++) {
        if (number[i] != 1001 + i) {
            number.push_back(1001+i);
            balance.push_back(amount);
            std::cout << "Account: " << number[number.size() - 1] << std::endl;
            std::cout << "Amount: " << balance[balance.size() - 1] << std::endl;
            return 0;
        }
    }

    number.push_back(last_num + 1);
    balance.push_back(amount);
    last_num++;
    std::cout << "Account: " << number[number.size() - 1] << std::endl;
    std::cout << "Amount: " << balance[balance.size() - 1] << std::endl;
    return 0;
}
int BankAccount::B() {

    int account_number;
    std::cout << "Account number: ";
    std::cin >> account_number;

    for (int i{ 0 }; i < number.size(); i++) {
        if (account_number == number[i]) {
            std::cout << "Account: " << number[i] << std::endl;
            std::cout << "Balance: " << balance[i] << std::endl;
            return 0;
        }
    }
    std::cout << "There's no account with that number." << std::endl;
    return 0;
}
int BankAccount::D() {

    int account_number;
    double amount;
    std::cout << "Account number: ";
    std::cin >> account_number;
    std::cout << "Amount: ";
    std::cin >> amount;

    for (int i{ 0 }; i < number.size(); i++) {
        if (account_number == number[i]) {
            balance[i] += amount;
            std::cout << "Account: " << number[i] << std::endl;
            std::cout << "Balance: " << balance[i] << std::endl;
            return 0;
        }
    }
    std::cout << "There's no account with that number." << std::endl;
    return 0;
}
int BankAccount::W() {
    int account_number;
    double amount;
    std::cout << "Account number: ";
    std::cin >> account_number;
    std::cout << "Amount: ";
    std::cin >> amount;

    for (int i{ 0 }; i < number.size(); i++) {
        if (account_number == number[i]) {
            if (balance[i] >= amount) {
                balance[i] -= amount;
                std::cout << "Account: " << number[i] << std::endl;
                std::cout << "Balance: " << balance[i] << std::endl;
                return 0;
            }
            else
                std::cout << "The balance is lower than the amount you'd like to get.";
        }
    }
    std::cout << "There's no account with that number." << std::endl;
    return 0;
}
int BankAccount::C() {

    int account_number;
    double amount;
    std::cout << "Account number: ";
    std::cin >> account_number;

    CoctailSort(number, balance);

    if (account_number == last_num) {
        number.erase(number.end() - 1);
        balance.erase(balance.end() - 1);
        last_num = *(number.end() - 1);
        return 0;
    }
    else {
        for (int i{ 0 }; i < number.size(); i++) {
            if (account_number == number[i]) {
                number.erase(number.begin() + i);
                balance.erase(balance.begin() + i);
                std::cout << "The account was successfully closed." << std::endl;
                std::cout << "The number of remaining accounts: " << number.size() << std::endl;
                return 0;
            }
        }
    }
    std::cout << "There's no accounts with that number." << std::endl;
    return 0;
}
int BankAccount::P() {

    CoctailSort(number, balance);

    std::cout << std::setw(20) << "Account number:";
    std::cout << std::setw(20) << "Amount:" << std::endl;

    for (int i{ 0 }; i < number.size(); i++) {
        std::cout << std::setw(20) << number[i];
        std::cout << std::setw(20) << balance[i] << std::endl;
    }
    return 0;
}
int BankAccount::I() {

    double interest_rate;
    std::cout << "Interest rate: ";
    std::cin >> interest_rate;

    std::cout << std::setw(20) << "Account number:";
    std::cout << std::setw(40) << "Amount with the interest rate:" << std::endl;

    for (int i{ 0 }; i < number.size(); i++) {
        balance[i] = balance[i] + ((balance[i]) * (interest_rate / 100));
        std::cout << std::setw(20) << number[i];
        std::cout << std::setw(30) << balance[i] << std::endl;
    }

    return 0;
}

//sortirovka, neobhodimaya dlya korrektnoy raboty vneshnih funkciy.
int CoctailSort(std::vector<int>& v1, std::vector<double>& v2) {

    int start = 0;
    int finish = v1.size() - 2;
    int dop = 0;
    int another_dop = v1.size();

    while (finish >= start) {

        for (int i = start; i < another_dop - 1; i++) {
            if (v1[i] > v1[i + 1]) {
                std::swap(v1[i], v1[i + 1]);
                std::swap(v2[i], v2[i + 1]);
            }
        }

        for (int j = finish; j > dop; j--) {
            if (v1[j] < v1[j - 1]) {
                std::swap(v1[j - 1], v1[j]);
                std::swap(v2[j - 1], v2[j]);
            }
        }

        start++;
        finish--;
        another_dop--;
        dop++;
    }

    return 0;
}