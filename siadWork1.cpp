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
    cout << "Выберите одну из заданных опраций:" << endl;
    cout << "1) Заполнить запись по сеансу" << endl;
    cout << "2) Вставиить запись по сеансу в таблицу" << endl;
    cout << "3) Удалить записи по заданной дате" << endl;
    cout << "4) Введите список кинотеатров, в которых можно посмотреть заданный фильм" << endl;
    cin >> chose;
    return chose;
}

session enter() {
    session temp;
    cout << "Введите название кинотеатра" << endl;
    cin >> temp.cinema;
    cout << "Введите название фильма" << endl;
    cin >> temp.film;
    cout << "Введите дату" << endl;
    cin >> temp.nowaDays.data;
    cin >> temp.nowaDays.month;
    cin >> temp.nowaDays.year;
    cout << "Введите время начала фильма" << endl;
    cin >> temp.beginTime.hour;
    cin >> temp.beginTime.minutes;
    cout << "Введите стоимость билета" << endl;
    cin >> temp.coast;
    return temp;
};


int main() {
    int chose, s;
    session a;
    struct session b[100];
    b[0] = { "Синема парк", "Человек паук", {10, "октября", 2023}, {10, 40}, 350 };
    b[1] = { "Синема парк", "Человек паук", {10, "октября", 2023}, {10, 40}, 350 };
    b[2] = { "Синема парк", "Человек паук", {10, "октября", 2023}, {10, 40}, 350 };
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