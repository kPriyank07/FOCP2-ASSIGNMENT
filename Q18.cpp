#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;

    string r=s;
    reverse(r.begin(),r.end());

    if(s==r) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}
