#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 1000;
struct Node {
    int next[26];
    bool leaf;
};
Node trie[MAXN * MAXN];
int node_count = 1;

// функция для добавления слова в словарь
void add_word(string word) {
    int v = 0;
    for (int i = 0; i < word.length(); i++) {
        int c = word[i] - 'a';
        if (trie[v].next[c] == 0) {
            trie[v].next[c] = node_count++;
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}

// функция для поиска слова в словаре
bool find_word(string word) {
    int v = 0;
    for (int i = 0; i < word.length(); i++) {
        int c = word[i] - 'a';
        if (trie[v].next[c] == 0) {
            return false;
        }
        v = trie[v].next[c];
    }
    return trie[v].leaf;
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    vector<string> dictionary;
    string word;
    // считываем слова и добавляем их в словарь
    cout<<"Введите слова"<<endl;
    while (true) {
        cin >> word;
        if (word == "end") 
            break; 
        dictionary.push_back(word);
        add_word(word);
    }
    // создаем текст, содержащий слова из бора
    string text = "The quick brown fox jumps over the lazy dog. ";
    text += dictionary[0] + "s, " + dictionary[1] + "s, ";
    text += dictionary[2] + "ing, " + dictionary[3] + "ed, ";
    text += "and some other words.";
    // проверяем, что все образцы входят в текст
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++) {
        if (find_word(dictionary[i])) {
            if (text.find(dictionary[i]) != string::npos) {
                count++;
            }
            else if (text.find(dictionary[i].substr(0, dictionary[i].length() - 1)) != string::npos) {
                count++;
            }
            else if (text.find(dictionary[i].substr(0, dictionary[i].length() - 2)) != string::npos) {
                count++;
            }
        }
    }
    cout << "Number of patterns found: " << count << endl;
    return 0;
}