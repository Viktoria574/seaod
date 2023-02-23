#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct time {//��������� ��� �������
    int hour;
    int minutes;
};

struct day {//��������� ��� ����
    int data;
    string month;
    int year;
};

struct session {//��������� ��� ������
    string cinema;
    string film;
    day nowaDays;
    time beginTime;
    int coast;
};

struct tablu {//��������� ��� �������
    int n;
    int N;
    session *massive;
};

int oppening(int chose) {//������� ��� ������ ��������
    cout << "�������� ���� �� �������� �������:" << endl;
    cout << "1) ��������� ������ �� ������" << endl;
    cout << "2) ��������� ������ �� ������ � �������" << endl;
    cout << "3) ������� ������ �� �������� ����" << endl;
    cout << "4) ������� ������ �����������, � ������� ����� ���������� �������� �����" << endl;
    cin >> chose;
    return chose;
}

session enter(session temp)//������� ��� ����� ������
{
    cout << "������ �������� ����������, �������� ������, ����,����� ������ ������, ��������� ������" << endl;
    cin >> temp.cinema >> temp.film >> temp.nowaDays.data >> temp.nowaDays.month;
    cin >> temp.nowaDays.year >> temp.beginTime.minutes >> temp.beginTime.hour >> temp.coast;
    return temp;
};

day enterNew(day temp) {//������� ��� ����� ����
    cout << "������� ����:" << endl;
    cin >> temp.data >> temp.month >> temp.year;
    return temp;
}

string enterFi(string tes) {//������� ��� ����� �������� ������
    cout << "������� �������� ������:" << endl;
    cin >> tes;
    return tes;
}

void printRow(session temp) {//��������� ��� ������ ����� ������
    cout << temp.cinema << " " << temp.film << " " << temp.nowaDays.data << " ";
    cout << temp.nowaDays.month << " " << temp.nowaDays.year << " ";
    cout << temp.beginTime.hour << ":" << temp.beginTime.minutes << " " << temp.coast << endl;
};

void print(session b[], int n) {//��������� ��� ������ �������
    for (int i = 0; i < n; i++) {
        printRow(b[i]);
    }
}

int add(session b[], int n, session temp) {//������� ��� ���������� ������ � �������
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
    cout << "���������� �������:" << endl;
    print(b, n);
    return n;
}

int delite(session b[], int n, day temp) {//������� ��� �������� ������
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
    cout << "���������� �������:" << endl;
    print(b, n - m);
    return n - m;
}

void need(string tes, session b[], int n) {//��������� ������ � ������ ������ ������ �� ������
    cout << "�������� ����������:" << endl;
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
    t.massive[0] = { "��������", "������", {10, "�������", 2023}, {10, 40}, 350 };
    t.massive[1] = { "����������", "������", {15, "��������", 2023}, {15, 30}, 200 };
    t.massive[2] = { "����������", "�������", {15, "��������", 2023}, {9, 20}, 400 };
    switch (oppening({}))//��� ������ ���������� ��������
    {
    case 1:
        enter({});
        cout<<"������ ������� ���������!";
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