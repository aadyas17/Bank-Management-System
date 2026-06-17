#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    string name;
    float balance;

    BankAccount() {
        accountNumber = 0;
        name = "";
        balance = 0;
    }

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    void deposit(float amount) {
        balance = balance + amount;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance = balance - amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

void addAccount() {
    BankAccount acc;
    acc.createAccount();

    ofstream file("bank.txt", ios::app);
    file << acc.accountNumber << " " << acc.name << " " << acc.balance << endl;
    file.close();

    cout << "Account created successfully!" << endl;
}

void displayAllAccounts() {
    BankAccount acc;

    ifstream file("bank.txt");

    while (file >> acc.accountNumber >> acc.name >> acc.balance) {
        acc.showAccount();
    }

    file.close();
}

void searchAccount() {
    int accNo;
    bool found = false;

    cout << "Enter Account Number to search: ";
    cin >> accNo;

    BankAccount acc;

    ifstream file("bank.txt");

    while (file >> acc.accountNumber >> acc.name >> acc.balance) {
        if (acc.accountNumber == accNo) {
            cout << "Account Found!";
            acc.showAccount();
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Account not found." << endl;
    }
}

void depositMoney() {
    int accNo;
    float amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    BankAccount acc;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    while (file >> acc.accountNumber >> acc.name >> acc.balance) {
        if (acc.accountNumber == accNo) {
            acc.deposit(amount);
            found = true;
        }

        temp << acc.accountNumber << " " << acc.name << " " << acc.balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found) {
        cout << "Amount deposited successfully!" << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void withdrawMoney() {
    int accNo;
    float amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    BankAccount acc;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    while (file >> acc.accountNumber >> acc.name >> acc.balance) {
        if (acc.accountNumber == accNo) {
            acc.withdraw(amount);
            found = true;
        }

        temp << acc.accountNumber << " " << acc.name << " " << acc.balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found) {
        cout << "Account not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Bank Management System =====";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Deposit Money";
        cout << "\n5. Withdraw Money";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addAccount();
            break;

        case 2:
            displayAllAccounts();
            break;

        case 3:
            searchAccount();
            break;

        case 4:
            depositMoney();
            break;

        case 5:
            withdrawMoney();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}