#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Test
{
public:
	Test() = delete;
	Test(std::string name);
	Test(std::string name, std::vector<std::string> questions, std::vector<std::vector<std::string>> variantAnswer, std::vector<int> answers);
	Test(const Test& object);

	void PrintQuestion(int index) const;
	void PrintVariantsAnswer(int index) const;

	int GetCountCorrectAnswer();
	int GetlastQuestion();
	int GetAnswer(int index) const;
	int GetCountQuestion() const;
	int GetCountAnswers(int index);
	std::string GetName() const;

	void SetResult(int& countCorrectAnswer, int mark, int lastQuestion, bool isFinished);
	void SetCorrectAnswer(int numberQuestion, int numberAnswer);

	bool IsFinished();
	void AddQuestion(int countVariantAnswer);

	Test& operator=(const Test& object);

	friend bool operator==(const Test& left, const Test& right);
	friend std::ostream& operator<<(std::ostream& stream, const Test& test);
	friend std::istream& operator>>(std::istream& stream, Test& test);
private:
	std::string m_name;
	std::vector<std::string> m_questions;
	std::vector<std::vector<std::string>> m_variantAnswer;
	std::vector<int> m_answers;
	int m_countCorrectAnswer = 0;
	int m_mark = 0;
	int m_lastQuestion = 0;
	bool m_isFinished = false;
};

