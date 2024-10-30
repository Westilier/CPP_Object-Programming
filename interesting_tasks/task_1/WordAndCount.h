#pragma once
#include <vector>
#include <iostream>

class WordAndCount
{
public:
	WordAndCount();
	WordAndCount(std::vector<char> word, int count);
	WordAndCount& operator=(const WordAndCount& other);

	friend std::ostream& operator<<(std::ostream& out, const WordAndCount& wordAndCount);
private:
	std::vector<char> m_word;
	int m_count = 0;
};

