#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

void find_word(string str){
    int ci=0; 
    char counter='&';
    string answer="", Ans="";
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<str.size(); i++){
        if (str[i]==',' and (counter==',' or counter=='&')){
            Ans=Ans+answer+" ";
            ci+=1;
        }
        else if(counter==',' and i==str.size()-1){
            Ans=Ans+answer+str[i];
            ci+=1;
        }
        else if(str[i]==' ' or str[i]==','){
            counter=str[i];
            answer="";
            ci+=1;
        }
        else{
            answer+=str[i];
            ci+=3;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double, micro> elapsed = end - start;
    cout<<"Время"<<elapsed.count()<<endl;
    cout<<"Ci:";
    cout<<"Ci "<<ci<<endl;
    cout<<Ans;
}

int main(){
    string str;
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    cout<<"Введите строку"<<endl;
    getline(cin, str);
    find_word(str);
    return 0;
}