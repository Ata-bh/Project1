#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// کلاس حساب بانکی
class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // سازنده
    BankAccount(string accNum, string accHolder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = accHolder;
        balance = initialBalance;
    }

    // متدهای getter
    string getAccountNumber() { return accountNumber; }
    string getAccountHolder() { return accountHolder; }
    double getBalance() { return balance; }

    // واریز وجه
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Price" << amount << " doller deposit successfully !" << endl;
        } else {
            cout << "The amount must be greater than zero" << endl;
        }
    }

    // برداشت وجه
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "price " << amount << "doller withdraw successfully" << endl;
            return true;
        } else {
            cout << "Insufficient or invalid balance" << endl;
            return false;
        }
    }

    // نمایش اطلاعات حساب
    void displayAccountInfo() {
        cout << "\n=== Bank account info ===" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account holder: " << accountHolder << endl;
        cout << "Balance acc: " << fixed << setprecision(2) << balance << "$" << endl;
        cout << "=====================" << endl;
    }
};

// کلاس سیستم بانکی
class BankingSystem {
private:
    vector<BankAccount> accounts;

public:
    // ایجاد حساب جدید
    void createAccount() {
        string accNum, accHolder;
        double initialBalance;

        cout << "\n--- Making new acc ---" << endl;
        cout << "Enter Account number: ";
        cin >> accNum;
        
        // بررسی وجود حساب تکراری
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                cout << "This account number has already been registered" << endl;
                return;
            }
        }

        cout << "Enter AccountHolder name: ";
        cin.ignore();
        getline(cin, accHolder);
        
        cout << "Enter first deposit amount: ";
        cin >> initialBalance;

        BankAccount newAccount(accNum, accHolder, initialBalance);
        accounts.push_back(newAccount);
        
        cout << "Account succesfully registered." << endl;
    }

    // پیدا کردن حساب با شماره حساب
    BankAccount* findAccount(string accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    // واریز وجه
    void deposit() {
        string accNum;
        double amount;

        cout << "\n--- Deposit funds ---" << endl;
        cout << "Enter the account number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account != nullptr) {
            cout << "Enter the deposit amount: ";
            cin >> amount;
            account->deposit(amount);
        } else {
            cout << "No account was found with this number." << endl;
        }
    }

    // برداشت وجه
    void withdraw() {
        string accNum;
        double amount;

        cout << "\n--- withdraw funds ---" << endl;
        cout << "Enter the account number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account != nullptr) {
            cout << "Enter the deposit amount:";
            cin >> amount;
            account->withdraw(amount);
        } else {
            cout << "No account was found with this number." << endl;
        }
    }

    // مشاهده موجودی
    void checkBalance() {
        string accNum;

        cout << "\n--- check balance ---" << endl;
        cout << "Enter the account number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account != nullptr) {
            account->displayAccountInfo();
        } else {
            cout << "No account was found with this number." << endl;
        }
    }

    // نمایش تمام حساب‌ها
    void displayAllAccounts() {
        cout << "\n--- Display all acc ---" << endl;
        if (accounts.empty()) {
            cout << "No Account registered" << endl;
        } else {
            for (auto &account : accounts) {
                account.displayAccountInfo();
            }
        }
    }
};

// تابع نمایش منو
void displayMenu() {
    cout << "\n=== Bank Management System ===" << endl;
    cout << "1. Sign in" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Balance" << endl;
    cout << "5. Display all account" << endl;
    cout << "6. Exit" << endl;
    cout << "Please select the desired option: ";
}

// تابع اصلی
int main() {
    BankingSystem bankSystem;
    int choice;

    cout << "Welcome to the bank management system!" << endl;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                bankSystem.createAccount();
                break;
            case 2:
                bankSystem.deposit();
                break;
            case 3:
                bankSystem.withdraw();
                break;
            case 4:
                bankSystem.checkBalance();
                break;
            case 5:
                bankSystem.displayAllAccounts();
                break;
            case 6:
                cout << "Thank you for using It. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}