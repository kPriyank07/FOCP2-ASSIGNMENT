#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of entries: ";
    cin >> n;

    int num, max;
    cout << "Enter number 1: ";
    cin >> num;
    max = num;

    for (int i = 2; i <= n; i++) {
        cout << "Enter number " << i << ": ";
        cin >> num;
        if (num > max)
            max = num;
    }

    cout << "Largest number = " << max;
    return 0;
}
