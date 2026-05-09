#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    // movie_id -> number of booked tickets
    unordered_map<int, int> bookedCount;
    // (customer_id, movie_id) -> booked status
    set<pair<int,int>> bookings;
    const int MAX_SLOTS = 100;

public:
    bool book(int customerId, int movieId) {
        if (bookings.count({customerId, movieId})) return false;
        if (bookedCount[movieId] >= MAX_SLOTS) return false;
        bookings.insert({customerId, movieId});
        bookedCount[movieId]++;
        return true;
    }

    bool cancel(int customerId, int movieId) {
        if (!bookings.count({customerId, movieId})) return false;
        bookings.erase({customerId, movieId});
        bookedCount[movieId]--;
        return true;
    }

    bool isBooked(int customerId, int movieId) {
        return bookings.count({customerId, movieId}) > 0;
    }

    int availableTickets(int movieId) {
        return MAX_SLOTS - bookedCount[movieId];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    MovieTicket mt;

    while (q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << "\n";
        } else if (query == "CANCEL") {
              
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << "\n";
        } else if (query == "IS_BOOKED") {
           
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << "\n";
        } else if (query == "AVAILABLE_TICKETS") {
           
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << "\n";
        }
    }

    return 0;
}
