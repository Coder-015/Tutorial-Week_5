#include <iostream>
using namespace std;

class Car {
    string model;
    double price;
    bool available;
public:
    Car() : model("Unknown"), price(0), available(true) {}
    Car(string m, double p, bool a) : model(m), price(p), available(a) {}
    Car(const Car &c) { model = c.model; price = c.price; available = c.available; }

    void book(int days) { cout << "Total: " << days * price << endl; }
    void book(double discount) { cout << "Discounted: " << price - (price * discount / 100) << endl; }
    void bookExtra(int insurance) { cout << "With Insurance: " << price + insurance << endl; }

    double getPrice() { return price; }

    Car operator + (Car c) { return Car("Combo", price + c.price, true); }
    bool operator > (Car c) { return price > c.price; }

    void display() {
        cout << "Model: " << model << ", Price: " << price << endl;
    }
};

int main() {
    Car c1("Sedan", 1000, true), c2("SUV", 1500, true);
    c1.book(3);
    c2.book(10.0);
    c1.bookExtra(200);

    Car combo = c1 + c2;
    combo.display();

    if (c1 > c2) cout << "Sedan is costlier\n";
    else cout << "SUV is costlier\n";
    return 0;
}
