#include <iostream>
#include <unordered_map> //используется в реализации бора для хранения дочерних узлов каждого узла. это контейнерное обобщение ассоциативного массива, где каждый элемент представляет пару ключ-значение.
#include <random> 
#include <ctime> 
#include <chrono>
using namespace std;
using namespace chrono;

struct TrieNode //содержит информацию о дочерних узлах и флаге, указывающем на конец слова.
{
    unordered_map <char, TrieNode*> children; //контейнер unordered_map, который 
    //хранит дочерние узлы текущего узла бора.

    bool isEndOfWord; //флаг, который указывает, является ли текущий узел концом (последней буквой) 
    //какого-либо слова в боре. если isEndOfWord установлен в true, это означает, что до текущего 
    //узла можно обойти буквы и получить полное слово.
};

TrieNode* createNode() 
{
    TrieNode* newNode = new TrieNode; //создание нового узла с помощью оператора new.
    newNode->isEndOfWord = false; //инициализация флага isEndOfWord значением false.
    return newNode; //возвращение указателя на новый узел.
}

void insert(TrieNode* root, const string& word) 
{
    TrieNode* current = root; //инициализация текущего узла как корневого узла.
    for (char ch : word)  //цикл для каждого символа в слове.
    {
        if (current->children.find(ch) == current->children.end()) //есть ли утекущего узла дочерний, соответствующий символу ch.
        {
            //если символ не является дочерним узлом текущего узла.
            current->children[ch] = createNode(); //создать узел для символа.
        }
        current = current->children[ch]; //перейти к дочернему узлу для символа.
    }
    current->isEndOfWord = true; //пометить текущий узел как конец слова.
}

bool search(TrieNode* root, const string& word) 
{
    TrieNode* current = root; //инициализация текущего узла как корневого узла.
    for (char ch : word) //цикл для каждого символа в слове.
    {
        if (current->children.find(ch) == current->children.end()) //если символ не является дочерним узлом текущего узла.
        {
            return false; //слово не найдено.
        }
        current = current->children[ch]; //перейти к дочернему узлу для символа.
    }
    return current->isEndOfWord; //вернуть значение флага последнего узла.
}

vector <string> generateRandomWords(int count, int length)
{
    vector <string> words;
    string characters = "abcdefghijklmnopqrstuvwxyz"; //строка, из которой будут браться значения для генерации.

    //строки кода инициализируют генератор случайных чисел gen с помощью случайных значений, полученных от random_device. 
    //затем создается распределение charDistribution, которое будет использоваться для генерации случайных индексов символов из строки characters, короче мега-имба.
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution <int> charDistribution(0, characters.length() - 1);

    for (int i = 0; i < count; i++)
    {
        string word;
        for (int j = 0; j < length; j++)
        {
            char randomChar = characters[charDistribution(gen)];
            word += randomChar;
        }
        words.push_back(word);
    }

    return words;
}

int countComparisons(TrieNode* root, const string& word)
{
    int comparisonCount = 0;
    TrieNode* current = root; // инициализация текущего узла как корневого узла.
    for (char ch : word) // цикл для каждого символа в слове.
    {
        if (current->children.find(ch) == current->children.end()) // если символ не является дочерним узлом текущего узла.
        {
            comparisonCount++; // увеличение счетчика сравнений.
            return comparisonCount; // возврат количества сравнений.
        }
        current = current->children[ch]; // перейти к дочернему узлу для символа.
        comparisonCount++; // увеличение счетчика сравнений.
    }
    comparisonCount++; // увеличение счетчика сравнений для последнего узла (флага конца слова).
    return comparisonCount; // возврат количества сравнений.
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    TrieNode* root = createNode();

    int wordCount;
    cout << "Введите количество случайных слов для словаря: ";
    cin >> wordCount;

    int wordLength;
    cout << "Введите длину случайных слов: ";
    cin >> wordLength;

    vector <string> dictionary = generateRandomWords(wordCount, wordLength);

    cout << endl;

    cout << "Словарь:" << endl; //вывод вектора изначального словаря.
    for (const string& word : dictionary) 
    {
        cout << word << endl;
    }
    cout << endl;

    for (const string& word : dictionary) //таким образом, данный цикл for перебирает каждое слово в векторе dictionary и вызывает функцию insert() для вставки каждого слова в бор. 
        //это позволяет построить бор, содержащий все слова из исходного словаря.
    {
        insert(root, word);
    }

    //поиск слов в словаре, польхователь сам вводит слово.
    cout << "Внимание! Если выводится 0, значит такого слова в словаре нет, если 1 - есть."  << endl;
    string slowo = dictionary[wordCount / 2]; //wordCount - количество сгенерированных слов, wordCount / 2 - индекс серединного слова в списке
    cout << "Искомое слово: " << slowo << endl;

    //cout << search(root, "apple") << endl; // нет
    //cout << search(root, "dog") << endl; // нет

    auto start1 = chrono::steady_clock::now();
    cout << "Результат работы поиска: " << search(root, slowo) << endl;
    auto end1 = chrono::steady_clock::now();

    cout << endl;

    //добавление нового слова.
    cout << "Введите новое слово, которое необходимо добавить в словарь: " << endl;
    string newWord;
    cin >> newWord;
    dictionary.push_back(newWord);
    insert(root, newWord);

    cout << "Обновленный словарь:" << endl; //вывод обновленного варианта словаря.
    for (const string& word : dictionary) 
    {
        cout << word << endl;
    }

    cout << endl;

    cout << "Проверка того, что слово было добавлено: " << endl;
    cout << search(root, newWord) << endl; // есть


    return 0;
}