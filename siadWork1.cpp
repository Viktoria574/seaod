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

int openning() {
    int chose;
    cout << "�������� ���� �� �������� �������:" << endl;
    cout << "1) ��������� ������ �� ������" << endl;
    cout << "2) ��������� ������ �� ������ � �������" << endl;
    cout << "3) ������� ������ �� �������� ����" << endl;
    cout << "4) ������� ������ �����������, � ������� ����� ���������� �������� �����" << endl;
    cin >> chose;
    return chose;
}

session enter() {
    session temp;
    cout << "������� �������� ����������" << endl;
    cin >> temp.cinema;
    cout << "������� �������� ������" << endl;
    cin >> temp.film;
    cout << "������� ����" << endl;
    cin >> temp.nowaDays.data;
    cin >> temp.nowaDays.month;
    cin >> temp.nowaDays.year;
    cout << "������� ����� ������ ������" << endl;
    cin >> temp.beginTime.hour;
    cin >> temp.beginTime.minutes;
    cout << "������� ��������� ������" << endl;
    cin >> temp.coast;
    return temp;
};


int main() {
    int chose, s;
    session a;
    struct session b[100];
    b[0] = { "������ ����", "������� ����", {10, "�������", 2023}, {10, 40}, 350 };
    b[1] = { "������ ����", "������� ����", {10, "�������", 2023}, {10, 40}, 350 };
    b[2] = { "������ ����", "������� ����", {10, "�������", 2023}, {10, 40}, 350 };
    s = b[0].coast;
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    cout << s;
    // switch(chose)
    // {
    //     case 1:

    // }
    // session first = enter();
    // cout << first.cinema << " " << first.nowaDays.data << " " << first.nowaDays.month << " " << first.nowaDays.year << " " << first.beginTime.hour << ":" << first.beginTime.minutes << " " << first.coast << endl;
};