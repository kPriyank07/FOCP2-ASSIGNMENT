#include <iostream>
using namespace std;

int main() {
    float temp, converted;
    int choice;

    cout << "Choose conversion:\n";
    cout << "1. Fahrenheit to Celsius\n";
    cout << "2. Celsius to Fahrenheit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter temperature: ";
    cin >> temp;

    if (choice == 1) {
        converted = (temp - 32) * 5 / 9;
        cout << "Temperature in Celsius = " << converted << endl;
    }
    else if (choice == 2) {
        converted = (temp * 9 / 5) + 32;
        cout << "Temperature in Fahrenheit = " << converted << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
