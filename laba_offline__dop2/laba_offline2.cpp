#include "class_description.h"

int main()
{
    srand(time(NULL));

    BankAccount test;
   
    std::cout << "You have bank accounts. These are some options you can manage them:" << std::endl;
    std::cout << "Transaction O - to open a new account with an initial deposit." << std::endl;
    std::cout << "Transaction B - to reveal an account balance." << std::endl;
    std::cout << "Transaction D - to add a deposit to an account." << std::endl;
    std::cout << "Transaction W - to get money from an account" << std::endl;
    std::cout << "Transaction C - to close an account." << std::endl;
    std::cout << "Transaction P - to print all available accounts and their balances." << std::endl;
    std::cout << "Transaction I - to estimate the balances of accounts after a year adding an interest rate." << std::endl;
    std::cout << "Your choice is ";

    std::string choice;
    std::cin >> choice;

    while (1) {
        if (choice == "O") {
            test.O();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = ""; //esli ne pisat' etu strochku, no pri etom v vizove funkcii ukazat' vmesto chisel simvoli, to cikl uhodit v eternity.
            //a tak on prosto prekrashaet rabotat', chto odnoznachno luchse. hotya ya ne do konca ponimayu, pochemu eto tak rabotaet.
            std::cin >> choice;

        }
        else if (choice == "B") {
            test.B();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = "";
            std::cin >> choice;

        }
        else if (choice == "D") {
            test.D();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = "";
            std::cin >> choice;

        }
        else if (choice == "W") {
            test.W();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = "";
            std::cin >> choice;

        }
        else if (choice == "C") {
            test.C();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = "";
            std::cin >> choice;

        }
        else if (choice == "P") {
            test.P();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = "";
            std::cin >> choice;
        }
        else if (choice == "I") {
            test.I();
            std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
            choice = "";
            std::cin >> choice;
        }
        else {
            std::cout << std::endl << "There's no option like that." << std::endl;
            break;
        }

    }
    return 0;
}
