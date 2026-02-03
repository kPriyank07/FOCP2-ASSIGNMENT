#include <iostream>
using namespace std;

int main() {
    int p1, p2, p3;

    cout << "Enter scores of three players: ";
    cin >> p1 >> p2 >> p3;

    if (p1 > p2 && p1 > p3)
        cout << "Player 1 is the winner";
    else if (p2 > p1 && p2 > p3)
        cout << "Player 2 is the winner";
    else if (p3 > p1 && p3 > p2)
        cout << "Player 3 is the winner";
    else
        cout << "It's a tie";

    return 0;
}
