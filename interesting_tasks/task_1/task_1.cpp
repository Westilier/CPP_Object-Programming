#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "TreeNode.h"

bool IsLetter(char& symbol)
{
    return symbol >= 'а' && symbol <= 'я' ||
        symbol >= 'А' && symbol <= 'Я' ||
        symbol == 'ё' || symbol == 'Ё' ||
        symbol >= 'a' && symbol <= 'z' ||
        symbol >= 'A' && symbol <= 'Z';
}
bool IsLower(char& symbol)
{
    return symbol >= 'а' && symbol <= 'я' || symbol == 'ё' || symbol >= 'a' && symbol <= 'z';
}
bool IsRussianLanguage(char& symbol)
{
    return symbol >= 'а' && symbol <= 'я' ||
        symbol >= 'А' && symbol <= 'Я' ||
        symbol == 'ё' || symbol == 'Ё';
}
void ToLower(char& symbol)
{
    if (symbol == 'Ё')
    {
        symbol = 'ё';
    }

    if (IsRussianLanguage(symbol))
    {
        symbol -= ('А' - 'а');
    }
    else
    {
        symbol -= ('Z' - 'z');
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<char> word;
    std::ifstream in("1.txt");
    if (!in.is_open())
    {
        std::cout << "не удалось открыть файл"<<std::endl;
    }

    char symbol;
    TreeNode treeNode;
    while (in.get(symbol))
    {
        if (IsLetter(symbol))
        {
            if (IsLower(symbol))
            {
                word.push_back(symbol);
            }
            else
            {
                ToLower(symbol);
                word.push_back(symbol);
            }
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
        else if(symbol != '.' && symbol != ',' && symbol != '?' && symbol != '!' && symbol != '"' && symbol != ':')
        {
            treeNode.Add(word);
            word.clear();
        }
    }
    treeNode.Add(word);
    std::vector<WordAndCount> wordsAndCounts = treeNode.Collect();
    std::ofstream out("wordsAndCounts.txt");
    for(size_t i = 0;i< wordsAndCounts.size();i++)
    {
        out <<wordsAndCounts[i];
        out << std::endl;
    }
    return 0;
}

