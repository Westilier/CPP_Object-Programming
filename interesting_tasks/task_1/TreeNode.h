#pragma once
#include <vector>

class TreeNode
{
public:
	TreeNode();
	TreeNode& operator=(const TreeNode& other);

	void Add(std::vector<char> word);
private:
	std::vector<char> m_word;
	int m_count;
	TreeNode* m_leftNode;
	TreeNode* m_rightNode;
};

