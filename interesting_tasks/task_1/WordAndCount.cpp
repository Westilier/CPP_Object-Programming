#include "WordAndCount.h"

WordAndCount::WordAndCount() : m_word{ 0 }, m_count{ 0}
{
}

WordAndCount::WordAndCount(std::vector<char> word, int count) : m_word{ word }, m_count{ count }
{
}

WordAndCount& WordAndCount::operator=(const WordAndCount& other)
{
	if (&other != this)
	{
		m_word = other.m_word;
		m_count = other.m_count;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const WordAndCount& wordAndCount)
{
	for (size_t i = 0; i < wordAndCount.m_word.size(); i++)
	{
		out << wordAndCount.m_word[i];
	}
	out << ' ';
	out << wordAndCount.m_count;
	return out;
}
