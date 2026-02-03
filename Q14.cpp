#include <iostream>
using namespace std;

int main() {
    int c; float a,b;
    do {
        cin>>c;
        if(c==5) break;
        cin>>a>>b;
        if(c==1) cout<<a+b;
        else if(c==2) cout<<a-b;
        else if(c==3) cout<<a*b;
        else if(c==4 && b!=0) cout<<a/b;
    } while(true);
}
