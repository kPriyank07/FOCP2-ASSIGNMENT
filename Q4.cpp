#include <iostream>
using namespace std;

int main() {
    int itemNo, qty;
    float price;

    cin >> itemNo >> qty >> price;

    float total = qty * price;
    float net = total - (0.20 * total);

    cout << "Net Bill Amount = " << net;
    return 0;
}
