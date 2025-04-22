#include <iostream>
using namespace std;

class BankAccount {
    int accNo;
    double balance;
public:
    BankAccount() : accNo(0), balance(0) {}
    BankAccount(int a, double b) : accNo(a), balance(b) {}

    void deposit(int amt) { balance += amt; }
    void deposit(double amt) { balance += amt; }

    bool operator > (BankAccount b) { return balance > b.balance; }

    void display() {
        cout << "AccNo: " << accNo << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount b1(101, 5000), b2(102, 3000);
    b1.deposit(1000);
    b2.deposit(500.5);
    b1.display();
    b2.display();
    if (b1 > b2) cout << "b1 has more balance\n";
    else cout << "b2 has more balance\n";
    return 0;
}
