#include <bits/stdc++.h>
#include <ctime>
#include <chrono>

using namespace std;

int prefix_function(const string& s) {
    vector<int> pi(s.length(), 0);
    int ci, counter=0, maxi=-100;;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i < s.length(); i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
            ci++;
        }

        if (s[i] == s[j]) {
            pi[i] = j + 1;
            ci++;
        } 
        else {
            pi[i] = j;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    cout<<"Время"<<elapsed.count()<<endl;
    cout<<"Ci:";
    cout<<"Ci "<<ci<<endl;
    //Доп условие задачи
    for (int i=0; i<pi.size(); i++){
        if(pi[i]-1==counter)
            counter+=1;
        else{
            if (counter>maxi)
                maxi=counter;
            counter=0;
        }
    }
    return maxi;
}

int main() {
    string s, t;
    int counter=0, maxi=-100;
    cin >> s >> t;

    cout<<prefix_function(t + '&' + s);
}