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
    cin >> temp.cinema >> temp.film >> temp.nowaDays.data >> temp.nowaDays.month;
    cin >> temp.nowaDays.year >> temp.beginTime.minutes >> temp.beginTime.hour >> temp.coast;
    return temp;
};

day enterNew(day temp) {
    cout << "Введите дату:"<<endl;
    cin >> temp.data >> temp.month >> temp.year;
    return temp;
}

string enterFi(string tes) {
    cout << "Введите название фильма:"<<endl;
    cin >> tes;
    return tes;
}

void printRow(session temp) {
    cout << temp.cinema << " " << temp.film << " " << temp.nowaDays.data << " " << temp.nowaDays.month << " " << temp.nowaDays.year << " ";
    cout << temp.beginTime.hour << ":" << temp.beginTime.minutes << " " << temp.coast << endl;
};


void print(session b[], int n) {
    for (int i = 0; i < n; i++) {
        printRow(b[i]);
    }
}

int add(session b[], int n, session temp) {
    session help, moreHelp;
    int m = n;
    for (int i = 0; i <= n; i++) {
        if (b[i].cinema == temp.cinema) {
            help = b[i];
            b[i] = temp;
            for (int j = i + 1; j <= n + 1; j++) {
                moreHelp = b[j];
                b[j] = help;
                help = moreHelp;
            }
            n = n + 1;
            break;
        }
    }
    if (m = n) {
        b[n] = temp;
        n += 1;
    }
    cout << "Измененная таблица:" << endl;
    print(b, n);
    return n;
}

int delite(session b[], int n,day temp){
    int m=0;
    for (int i=0; i<n; i++){
        if ( b[i].nowaDays.data==temp.data and b[i].nowaDays.month==temp.month and b[i].nowaDays.year==temp.year){
            for (int j=i; j<n; j++){
                b[j]=b[j+1];
            }
            m+=1;
            i=0;
        }
    }
    cout << "Измененная таблица:" << endl;
    print(b, n-m);
    return n-m;
}

void need(string tes, session b[], int n) {
    cout<<"Найденые кинотеатры:"<<endl;
    for (int i = 0; i <n; i++) {
        if (b[i].film == tes) {
            cout<<b[i].cinema<<endl;
        }
    }
}

int main() {
    int n = 3;
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    struct session b[100];
    b[0] = { "Синема парк", "Хатико", {10, "октября", 2023}, {10, 40}, 350 };
    b[1] = { "Киносити", "Джокер", {15, "сентября", 2023}, {15, 30}, 200 };
    b[2] = { "Синема парк", "Пинокио", {15, "сентября", 2023}, {9, 20}, 400 };
    switch (oppening({}))
    {
    case 1:
        enter({});
        break;
    case 2:
        n = add(b, n, enter({}));
        break;
    case 3:
        delite(b, n, enterNew({}));
        break;
    case 4:
        need(enterFi({}), b, n);
        break;
    }
};