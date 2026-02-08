#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin>>n;

    // Perfect check
    int sum=0;
    for(int i=1;i<n;i++)
        if(n%i==0) sum+=i;

    if(sum==n) cout<<"Perfect\n";

    // Armstrong check
    int temp=n, digits=0;
    while(temp){ digits++; temp/=10; }

    temp=n; sum=0;
    while(temp){
        int d=temp%10;
        sum += pow(d,digits);
        temp/=10;
    }

    if(sum==n) cout<<"Armstrong";
}
