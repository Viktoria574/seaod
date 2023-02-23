#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct time {//Структура для времени
    int hour;
    int minutes;
};

struct day {//Структура для даты
    int data;
    string month;
    int year;
};

struct session {//Структура для записи
    string cinema;
    string film;
    day nowaDays;
    time beginTime;
    int coast;
};

struct tablu {//Структура для таблицы
    int n;
    int N;
    session *massive;
};

int oppening(int chose) {//Функция для выбора операции
    cout << "Выберите одну из заданных опраций:" << endl;
    cout << "1) Заполнить запись по сеансу" << endl;
    cout << "2) Вставиить запись по сеансу в таблицу" << endl;
    cout << "3) Удалить записи по заданной дате" << endl;
    cout << "4) Вывести список кинотеатров, в которых можно посмотреть заданный фильм" << endl;
    cin >> chose;
    return chose;
}

session enter(session temp)//Функция для ввода записи
{
    cout << "Ведите название кинотеатра, названия фильма, дату,время начала фильма, стоимость билета" << endl;
    cin >> temp.cinema >> temp.film >> temp.nowaDays.data >> temp.nowaDays.month;
    cin >> temp.nowaDays.year >> temp.beginTime.minutes >> temp.beginTime.hour >> temp.coast;
    return temp;
};

day enterNew(day temp) {//Функция для ввода даты
    cout << "Введите дату:" << endl;
    cin >> temp.data >> temp.month >> temp.year;
    return temp;
}

string enterFi(string tes) {//Функция для ввода названия фильма
    cout << "Введите название фильма:" << endl;
    cin >> tes;
    return tes;
}

void printRow(session temp) {//Процедура для вывода одной записи
    cout << temp.cinema << " " << temp.film << " " << temp.nowaDays.data << " ";
    cout << temp.nowaDays.month << " " << temp.nowaDays.year << " ";
    cout << temp.beginTime.hour << ":" << temp.beginTime.minutes << " " << temp.coast << endl;
};

void print(session b[], int n) {//Процедура для вывода таблицы
    for (int i = 0; i < n; i++) {
        printRow(b[i]);
    }
}

int add(session b[], int n, session temp) {//Функция для добавления записи в таблицу
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
    if (m == n) {
        b[n] = temp;
        n += 1;
    }
    cout << "Измененная таблица:" << endl;
    print(b, n);
    return n;
}

int delite(session b[], int n, day temp) {//Функция для удаления записи
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (b[i].nowaDays.data == temp.data and b[i].nowaDays.month == temp.month and b[i].nowaDays.year == temp.year) {
            for (int j = i; j < n; j++) {
                b[j] = b[j + 1];
            }
            m += 1;
            i = 0;
        }
    }
    cout << "Измененная таблица:" << endl;
    print(b, n - m);
    return n - m;
}

void need(string tes, session b[], int n) {//Процедура поиска и вывода нужной записи по фильму
    cout << "Найденые кинотеатры:" << endl;
    for (int i = 0; i < n; i++) {
        if (b[i].film == tes) {
            cout << b[i].cinema << endl;
        }
    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    tablu t;
    t.n = 3;
    t.N = 100;
    t.massive= new session[t.N];
    t.massive[0] = { "Киносити", "Хатико", {10, "октября", 2023}, {10, 40}, 350 };
    t.massive[1] = { "СинемаСтар", "Джокер", {15, "сентября", 2023}, {15, 30}, 200 };
    t.massive[2] = { "СинемаПарк", "Пинокио", {15, "сентября", 2023}, {9, 20}, 400 };
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
        break;
    case 4:
        need(enterFi({}), t.massive, t.n);
        break;
    }
};