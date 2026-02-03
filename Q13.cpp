#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, D, x1, x2;

    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    D = b * b - 4 * a * c;

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Roots are real and different\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2;
    }
    else if (D == 0) {
        x1 = -b / (2 * a);
        cout << "Roots are real and equal\n";
        cout << "x = " << x1;
    }
    else {
        cout << "Roots are imaginary";
    }

    return 0;
}
