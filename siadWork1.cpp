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

int oppening(int chose) {
    cout << "�������� ���� �� �������� �������:" << endl;
    cout << "1) ��������� ������ �� ������" << endl;
    cout << "2) ��������� ������ �� ������ � �������" << endl;
    cout << "3) ������� ������ �� �������� ����" << endl;
    cout << "4) ������� ������ �����������, � ������� ����� ���������� �������� �����" << endl;
    cin >> chose;
    return chose;
}

session enter(session temp)
{
    cout << "������ �������� ����������, �������� ������, ����,����� ������ ������, ��������� ������" << endl;
    cin >> temp.cinema>>temp.film>>temp.nowaDays.data>>temp.beginTime.hour>>temp.beginTime.minutes>>temp.coast;
    return temp;
};

void print(session b[], int n){
    for (int i=0; i<n; i++){
        cout<<b[i].cinema<<" "<<b[i].film<<" "<<b[i].beginTime.hour<<":"<<b[i].beginTime.minutes<<" ";
        cout<<b[i].nowaDays.data<<" "<<b[i].nowaDays.month<<" "<<b[i].nowaDays.year<<" "<<b[i].coast<<endl;
    };
}


int main() {
    int chose=0, s, n=3;
    session temp;
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    struct session b[100];
    b[0] = { "������ ����", "������� ����", {10, "�������", 2023}, {10, 40}, 350 };
    b[1] = { "��������", "���� ������", {15, "��������", 2023}, {15, 30}, 200 };
    b[2] = { "������ ����", "�������", {8, "�������", 2023}, {9, 20}, 400 };
    chose = oppening(chose);
    // switch (chose)
    // {
    // case 1:
    //     b[3] = enter();

    // }
    print(b, n);
    // session first = enter();
    // cout << first.cinema << " " << first.nowaDays.data << " " << first.nowaDays.month << " " << first.nowaDays.year << " " << first.beginTime.hour << ":" << first.beginTime.minutes << " " << first.coast << endl;
};