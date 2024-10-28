#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

bool IsLetter(char symbol)
{
    return symbol >= 'а' && symbol <= 'я' ||
        symbol >= 'А' && symbol <= 'Я' ||
        symbol == 'ё' || symbol == 'Ё' ||
        symbol >= 'a' && symbol <= 'z' ||
        symbol >= 'A' && symbol <= 'Z';
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using Word = std::vector<char>;
    using Words = std::vector <Word>;
    Word word;
    Words words;
    std::ifstream in("2.txt");
    if (!in.is_open())
    {
        std::cout << "не удалось открыть файл"<<std::endl;
    }
    char symbol;
    while (in.get(symbol))
    {
        if (IsLetter(symbol))
        {
            word.push_back(symbol);
        }
        else if (symbol == '-')
        {
            in.get(symbol);
            in.get(symbol);
            word.push_back(symbol);
        }
        else if (symbol == '\'')
        {
            word.push_back(symbol);
        }
        else
        {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    for(size_t i = 0;i<words.size();i++)
    {
        word = words[i];
        for (size_t j = 0; j < word.size(); j++)
        {
            std::cout << word[j];
        }
    }
    return 0;
}

