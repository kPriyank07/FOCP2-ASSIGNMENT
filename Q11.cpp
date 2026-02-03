#include <iostream>
using namespace std;

int main() {
    int quantity;
    float price, total, discount = 0;

    cout << "Enter number of items: ";
    cin >> quantity;

    cout << "Enter price per item: ";
    cin >> price;

    total = quantity * price;

    if (quantity > 1000) {
        discount = total * 0.10;
    }

    total = total - discount;

    cout << "Total Expense = " << total;

    return 0;
}
