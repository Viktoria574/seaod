#include <iostream>

using namespace std;
int main(){
    char a;
    cin>>a;
    int b=(int)a;
    if (((int)'a'<=b and b<=(int)'z') or ((int)'A'<=b and b<=(int)'Z')){
        if (b<(int)'Z'){
            b+=(int)'a'-(int)'A';
        }
        if (b==(int)'a' or b==(int)'e' or b==(int)'i' or b==(int)'o' or b==(int)'u' or b==(int)'y'){
            cout<<"vowel";
        }
        else{
            cout<<"consonant";
        };
    }
    else{
        cout<<"Not letter";
    }
}