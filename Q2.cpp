#include <iostream>
using namespace std;

int main() {
    float radius, area;
    const float PI = 3.14159;

    cout << "Enter radius of the fountain: ";
    cin >> radius;
   
    area = PI * radius * radius;

    cout << "Area of the circular fountain = " << area << endl;

    return 0;
}
