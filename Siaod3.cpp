#include <iostream>
#include <stack>

using namespace std;
 int main(){
    stack <int> steck;
    string infix, m='0';
    infix="z^(y+x)/m/n*(k-p)";
    infix.erase(infix.begin());
    auto iterator=m.insert(m.begin(), infix.begin());
    cout<<infix;
 }