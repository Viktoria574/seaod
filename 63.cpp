#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

void createMas(vector <int>& massive, int n) {
    for (int i = 0; i < n; i++) {
        massive.push_back(rand() % 100);
    }
}

// void revers(vector <int> arr[], int size)
// {
//     for (int i = 0, j = size - 1; i < (size / 2); i++, j--)
//     {
//         int x = arr[i];
//         arr[i] = arr[j];
//         arr[j] = x;
//     }
// }

void Magic(vector <int>& massive, int ind1, int ind2, int ind3) {
    int pos1=ind1, pos2=ind2, len=ind3-ind1+1;
    vector <int> result;
    while(pos1<ind2 and pos2<ind3+1){
        if (massive[pos1]<=massive[pos2]){
            result.push_back(massive[pos1]);
            pos1++;
        }
        if (massive[pos2]<=massive[pos1]){
            result.push_back(massive[pos2]);
            pos2++;
        }
    }
    if (pos2>ind3 and result.size()<len){
        while(pos1<ind2){
            result.push_back(massive[pos1]);
            pos1++;
        }
    }
    for (int i=0; i<result.size(); i++){
        massive[i+ind1]=result[i];
    }
}

int Midl(int begin, int end){
    return ((end-begin)/2+begin);
}

void Sort(vector <int>& massive, int n, int ind1, int ind2) {//ÑÐ¾Ñ€Ñ‚Ð¸Ñ€Ð¾Ð²ÐºÐ°
    if (n > 1) {
        if (n % 2 == 0) {
            Sort(massive, n / 2, ind1, Midl(ind1, ind2));
            Sort(massive, n / 2, Midl(ind1, ind2)+1, ind2);

        }
        else {
            Sort(massive, n / 2 + 1, ind1, Midl(ind1, ind2));
            Sort(massive, n / 2,Midl(ind1, ind2)+1, ind2);
        }
        Magic(massive, ind1, Midl(ind1, ind2)+1, ind2);
    }
    else {
        return;
    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    vector <int> mas;
    vector <int>* p = &mas;
    createMas(mas, n);
    cout << "Äî" << endl;
    for (int j = 0; j < n; j++) {
        cout << mas[j] << "  ";
    }
    cout << endl;
    cout << "Ïîñëå" << endl;
    Sort(mas, n, 0, n - 1);
    for (int j = 0; j < n; j++) {
        cout << mas[j] << "  ";
    }
}