#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

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

struct tablu {//Структура для таблицы
    int n;
    int N;
    vector <session> massive;
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

session enter(session temp)//Р¤СѓРЅРєС†РёСЏ РІРІРѕРґР° СЃС‚СЂРѕРєРё
{
    cout << "Ведите название кинотеатра, названия фильма, дату,время начала фильма, стоимость билета" << endl;
    cin >> temp.cinema >> temp.film >> temp.nowaDays.data >> temp.nowaDays.month;
    cin >> temp.nowaDays.year >> temp.beginTime.minutes >> temp.beginTime.hour >> temp.coast;
    return temp;
};

day enterNew(day temp) {
    cout << "Введите дату:" << endl;
    cin >> temp.data >> temp.month >> temp.year;
    return temp;
}

string enterFi(string tes) {
    cout << "Введите название фильма:" << endl;
    cin >> tes;
    return tes;
}

void printRow(session temp) {
    cout << temp.cinema << " " << temp.film << " " << temp.nowaDays.data << " ";
    cout << temp.nowaDays.month << " " << temp.nowaDays.year << " ";
    cout << temp.beginTime.hour << ":" << temp.beginTime.minutes << " " << temp.coast << endl;
};

void print(vector<session> b, int n) {
    for (int i = 0; i < n; i++) {
        printRow(b[i]);
    }
}

int add(vector <session> b, int n, session temp) {
    int i=0;
    while(i<n){
        if (b[i].cinema == temp.cinema) {
            b.insert(b.begin()+i, temp);
            i=n+1;
        }
        else{
            i+=1;
        }
    }
    if (i == n) {
        b.push_back(temp);
    }
    cout << "Измененная таблица:" << endl;
    print(b, n+1);
    return n;
}

int delite(vector<session> b, int n, day temp) {
    int m = 0;
    int i=0;
    while(i<n-m){
        if (b[i].nowaDays.data == temp.data and b[i].nowaDays.month == temp.month and b[i].nowaDays.year == temp.year) {
            b.erase(b.begin() + i);
            m += 1;
        }
        else{
            i++;
        }
    }
    cout << "Измененная таблица:" << endl;
    return n - m;
}

void need(string tes, vector<session> b, int n) {
    cout << "Найденые кинотеатры:" << endl;
    for (int i = 0; i < n; i++) {
        if (b[i].film == tes) {
            cout << b[i].cinema << endl;
        }
    }
}

int main() {
    int n = 3, N = 100;
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    tablu t;
    t.n = 3;
    t.N = 100;
    t.massive.push_back({ "Киносити", "Хатико", {10, "октября", 2023}, {10, 40}, 350 });
    t.massive.push_back({ "СинемаПарк", "Джокер", {15, "сентября", 2023}, {15, 30}, 200 });
    t.massive.push_back({ "СинемаСтар", "Пинокио", {15, "сентября", 2023}, {9, 20}, 400 });
    t.massive.reserve(t.N);
    switch (oppening({}))//Для выбора дальнейших действий
    {
    case 1:
        enter({});
        cout<<"Запись успешно заполнена!";
        break;
    case 2:
        t.n = add(t.massive, t.n, enter({}));
        break;
    case 3:
        t.n = delite(t.massive, t.n, enterNew({}));
        print(t.massive, t.n);
        break;
    case 4:
        need(enterFi({}), t.massive, t.n);
        break;
    }
};