#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (isdigit(ch)) {
        cout << "It is a number";
    }
    else if (isalpha(ch)) {
        ch = tolower(ch);
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            cout << "It is a vowel";
        else
            cout << "It is a consonant";
    }
    else {
        cout << "It is a special character";
    }

    return 0;
}
