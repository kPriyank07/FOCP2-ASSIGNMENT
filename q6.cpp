#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<string, long long> accounts;
    
public:
    bool create(string x, long long y) {
        if (accounts.find(x) == accounts.end()) {
            accounts[x] = y;
            return true;
        }
        accounts[x] += y;
        return false;
    }
    
    bool debit(string x, long long y) {
        if (accounts.find(x) == accounts.end() || accounts[x] < y)
            return false;
        accounts[x] -= y;
        return true;
    }
    
    bool credit(string x, long long y) {
        if (accounts.find(x) == accounts.end())
            return false;
        accounts[x] += y;
        return true;
    }
    
    long long balance(string x) {
        if (accounts.find(x) == accounts.end())
            return -1;
        return accounts[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    
    Bank bank;
    
    while (q--) {
        string op;
        cin >> op;
        
        if (op == "CREATE") {
          
            string x; long long y;
           
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << "\n";
        }
        else if (op == "DEBIT") {
           
            string x; long long y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << "\n";
        }
        else if (op == "CREDIT") {
            
            string x; long long y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << "\n";
        }
        else if (op == "BALANCE") {
           
            string x;
            cin >> x;
            cout << bank.balance(x) << "\n";
        }
    }
    
    return 0;
}
