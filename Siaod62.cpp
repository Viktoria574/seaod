#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void createMas(int* massive, int n) {
    for (int i = 0; i < n; i++) {
        massive[i] = rand() % 100;
    }
}

void revers(int arr[], int size)
{
    for (int i = 0, j = size - 1; i < (size / 2); i++, j--)
    {
        int x = arr[i];
        arr[i] = arr[j];
        arr[j] = x;
    }
}

void Normalas(int* massive, int n) {//нормализация дерева
    int count = 1;
    while (count != 0) {
        count = 0;
        for (int i = 0; i < (n - 1) / 2 + (n - 1) % 2; i++) {
            if (massive[i] < massive[2 * i + 1]) {
                swap(massive[i], massive[2 * i + 1]);
                count++;
            }
            if (2 * i + 2 < n and massive[i] < massive[2 * i + 2]) {
                swap(massive[i], massive[2 * i + 2]);
                count++;
            }
        }
    }
}

void Chose(int* massive, int m) {//сортировка
    int mini, mi = 0, ci = 0, count=1, n;
    auto start = chrono::high_resolution_clock::now();
    for (int j = m - 1; j > 0; j--) {
        n=j+1;
        count=1;
        while (count != 0) {
            count = 0;
            for (int i = 0; i < (n - 1) / 2 + (n - 1) % 2; i++) {
                ci += 1;
                if (massive[i] < massive[2 * i + 1]) {
                    swap(massive[i], massive[2 * i + 1]);
                    count++;
                    mi += 1;
                }
                if (2 * i + 2 < n and massive[i] < massive[2 * i + 2]) {
                    swap(massive[i], massive[2 * i + 2]);
                    count++;
                    mi += 1;
                }
            }
        }
        swap(massive[0], massive[j]);
        mi += 1;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    cout << "Время выполнения сортировки: " << elapsed.count() << endl;
    cout << ci << "+" << mi << endl;
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Сколько чисел в массиве?" << endl;
    cin >> n;
    int massive[n];
    createMas(massive, n);
    //Bubble(massive, n);
    //revers(massive, n);
    Chose(massive, n);
    for (int j = 0; j < n; j++) {
        cout << massive[j] << "  ";
    }
}