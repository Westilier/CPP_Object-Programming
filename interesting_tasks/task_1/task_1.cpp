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

void ToLower(char& symbol)
{
    if (!IsLower(symbol))
    {
        symbol += 32;
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
            ToLower(symbol);
            word.push_back(symbol);
        }
        else if (symbol == '-')
        {
            in.get(symbol);

            if (symbol == '-' || IsLetter(symbol))
            {
                word.push_back(symbol);
            }
        }
        else if (symbol == '\'')
        {
            word.push_back(symbol);
        }
        else if ((symbol == '.' || symbol == ',' || symbol == '?' || symbol == '!' || symbol == '"' || symbol == ':' || symbol == ' ') && !word.empty())
        {
            treeNode.Add(word);
            word.clear();
        }
    }
    if (!word.empty())
    {
        treeNode.Add(word);
    }

    std::vector<WordAndCount> wordsAndCounts = treeNode.Collect();
    std::ofstream out("wordsAndCounts.txt");
    for(size_t i = 0;i< wordsAndCounts.size();i++)
    {
        out <<wordsAndCounts[i];
        out << std::endl;
    }
    return 0;
}

