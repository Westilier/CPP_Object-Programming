#pragma once
#include "WordAndCount.h"
#include <vector>

//template<typename T>
//class INode 
//{
//public:
//	T parameter;
//	int m_count;
//	INode*
//	virtual void add() = 0;
//	virtual vector<T>
//};

class TreeNode
{
public:
	TreeNode();
	~TreeNode() = default;
	TreeNode& operator=(const TreeNode& other);

	void Add(std::vector<char> word);
	std::vector<WordAndCount> Collect();

private:
	std::vector<char> m_word;
	int m_count;
	TreeNode* m_leftNode;
	TreeNode* m_rightNode;


};

