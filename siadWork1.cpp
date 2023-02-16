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
    cout << "Выберите одну из заданных опраций:" << endl;
    cout << "1) Заполнить запись по сеансу" << endl;
    cout << "2) Вставиить запись по сеансу в таблицу" << endl;
    cout << "3) Удалить записи по заданной дате" << endl;
    cout << "4) Введите список кинотеатров, в которых можно посмотреть заданный фильм" << endl;
    cin >> chose;
    return chose;
}

session enter(session temp)
{
    cout << "Ведите название кинотеатра, названия фильма, дату,время начала фильма, стоимость билета" << endl;
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
    b[0] = { "Синема парк", "Человек паук", {10, "октября", 2023}, {10, 40}, 350 };
    b[1] = { "Китосити", "Игры разума", {15, "сентября", 2023}, {15, 30}, 200 };
    b[2] = { "Синема парк", "Пинокио", {8, "августа", 2023}, {9, 20}, 400 };
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