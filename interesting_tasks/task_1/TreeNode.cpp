#include "TreeNode.h"

TreeNode::TreeNode() :m_word{}, m_count{0}, m_leftNode{ nullptr }, m_rightNode{nullptr}
{
}

TreeNode& TreeNode::operator=(const TreeNode& other)
{
	if (&other != this)
	{
		m_word = other.m_word;
		m_count = other.m_count;
		m_leftNode = other.m_leftNode;
		m_rightNode = other.m_rightNode;
	}
	return *this;
}

void TreeNode::Add(std::vector<char> word)
{
	if (m_word == word)
	{
		m_count++;
	}
	else if (m_word.empty())
	{
		m_word = word;
		m_count++;
	}
	else if (word < m_word)
	{
		if (m_leftNode == nullptr)
		{
			m_leftNode = new TreeNode[1];
			m_leftNode->m_word = word;
			m_leftNode->m_count ++;
		}
		else
		{
			m_leftNode->Add(word);
		}
	}
	else if (word > m_word)
	{
		if (m_rightNode == nullptr)
		{
			m_rightNode = new TreeNode[1];
			m_rightNode->m_word = word;
			m_rightNode->m_count++;
		}
		else
		{
			m_rightNode->Add(word);
		}
	}
}