#pragma once
#include "WordAndCount.h"
#include <vector>
//
//template<typename T>
//class INode 
//{
//public:
//	T m_word;
//	int m_count;
//	INode* m_leftNode;
//	INode* m_rightNode;
//	virtual void Add() = 0;
//	virtual std::vector<WordAndCount> Collect() = 0;
//};

class TreeNode /*:INode<std::vector<char>>*/
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

