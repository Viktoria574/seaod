#include <iostream>
#include <string>

using namespace std;

struct session {
    string cinema;
    // char film[25];
    // char date[25];  
    // int time; 
    int coast;
};

struct size {
    int n;
    int maxN;
};

int main() {
    session first;
    first.cinema = "Sgtyuhkjk";
    first.coast = 200;
    cout << first.cinema;
};