#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct time {
    int hour;
    int minutes;
};

struct day {
    int data;
    string month;
    int year;
};

struct session {
    string cinema;
    string film;
    day nowaDays;
    time beginTime;
    int coast;
};

struct size {
    int n;
    int maxN;
};

session enter() {
    session temp;
    cout << "��������" << endl;
    temp.cinema = "Star";
    cout << "Напишите дату фильма" << endl;
    temp.nowaDays.data = 10;
    temp.nowaDays.month = "october";
    temp.nowaDays.year = 2022;
    cout << "Напишите времѝ начала фильма" << endl;
    temp.beginTime.hour = 10;
    temp.beginTime.minutes = 40;
    cout << "Напишите ѝтоимоѝть билета" << endl;
    temp.coast = 200;
    return temp;
};

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    session first = enter();
    cout << first.cinema << " " << first.nowaDays.data << " " << first.nowaDays.month << " " << first.nowaDays.year << " " << first.beginTime.hour << ":" << first.beginTime.minutes << " " << first.coast << endl;
};