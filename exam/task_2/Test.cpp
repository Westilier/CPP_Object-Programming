#include "Test.h"


Test::Test(std::string name) : m_name{name}
{
}

Test::Test(std::string name, std::vector<std::string> questions, std::vector<std::vector<std::string>> variantAnswer, std::vector<int> answers)
	:m_name{ name }, m_questions{ questions }, m_variantAnswer{ variantAnswer }, m_answers{ answers }
{
}

Test::Test(const Test& object)
{
	if (&object != this)
	{
		m_name = object.m_name;
		m_questions = object.m_questions;
		m_variantAnswer = object.m_variantAnswer;
		m_answers = object.m_answers;
	}
}

void Test::PrintQuestion(int index) const
{
	std::cout << m_questions[index] << std::endl;
}

void Test::PrintVariantsAnswer(int index) const
{
	for (size_t i = 0; i < m_variantAnswer[index].size(); i++)
	{
		std::cout <<i+1 <<" - " << m_variantAnswer[index][i] << std::endl;
	}
}

int Test::GetCountCorrectAnswer()
{
	return m_countCorrectAnswer;
}

int Test::GetlastQuestion()
{
	return m_lastQuestion;
}

int Test::GetAnswer(int index) const
{
	return m_answers[index];
}

int Test::GetCountQuestion() const
{
	return m_questions.size();
}

int Test::GetCountAnswers(int index)
{
	return m_variantAnswer[index].size();
}

std::string Test::GetName() const
{
	return m_name;
}

void Test::SetResult(int& countCorrectAnswer, int mark, int lastQuestion, bool isFinished)
{
	m_countCorrectAnswer = countCorrectAnswer;
	m_mark = mark;
	m_lastQuestion = lastQuestion;
	m_isFinished = isFinished;
}

bool Test::IsFinished()
{
	if (m_countCorrectAnswer == m_questions.size())
	{
		return true;
	}
	return false;
}

void Test::AddQuestion(int countVariantAnswer)
{
	std::string buffer;
	std::vector<std::string> variantsAnswer;

	std::cout << "¬ведите вопрос" << std::endl;
	std::cin.ignore(20, '\n');
	std::getline(std::cin, buffer);
	m_questions.push_back(buffer);
	for (size_t i = 0; i < countVariantAnswer; i++)
	{
		std::cout << "¬ведите вариант ответа" << std::endl
			<< i+1<<" - ";
		std::getline(std::cin, buffer);
		variantsAnswer.push_back(buffer);
		
	}
	m_variantAnswer.push_back(variantsAnswer);
	std::cout << "¬ведите номер правильного ответа" << std::endl;
	int number;
	std::cin >> number;
	m_answers.push_back(number);
}

void Test::SetCorrectAnswer(int numberQuestion,int numberAnswer)
{
	m_answers[numberQuestion] = numberAnswer;
}

Test& Test::operator=(const Test& object)
{
	if (&object != this)
	{
		m_name = object.m_name;
		m_questions = object.m_questions;
		m_variantAnswer = object.m_variantAnswer;
		m_answers = object.m_answers;
	}
	return *this;
}

bool operator==(const Test& left, const Test& right)
{
	if (left.m_name == right.m_name
		&& left.m_questions == right.m_questions
		&& left.m_variantAnswer == right.m_variantAnswer
		&& left.m_answers == right.m_answers)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& stream, const Test& test)
{
	stream << test.m_name << std::endl;
	for (size_t i = 0; i < test.m_questions.size(); i++)
	{
		stream << test.m_questions[i] << std::endl;
	}
	for (size_t i = 0; i < test.m_variantAnswer.size(); i++)
	{
		stream << "////" << std::endl;
		for (size_t j = 0; j < test.m_variantAnswer[i].size(); j++)
		{
			stream << test.m_variantAnswer[i][j] << std::endl;
		}
	}
	stream << "/////" << std::endl;
	for (size_t i = 0; i < test.m_answers.size(); i++)
	{
		stream << test.m_answers[i] << std::endl;
	}
	stream << "//////" << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Test& test)
{
	std::string buffer;
	std::vector<std::string> vec_buffer;
	
	stream >> test.m_name;

	if (test.m_name !=" ")
	{
		while (true)
		{
			stream >> buffer;
			if (buffer == "////")
			{
				stream >> buffer;
				vec_buffer.push_back(buffer);
				test.m_variantAnswer.push_back(vec_buffer);
				break;
			}
			test.m_questions.push_back(buffer);
		}

		int i = 0;

		while (true)
		{
			stream >> buffer;
			if (buffer == "/////")
			{
				break;
			}
			test.m_variantAnswer[i].push_back(buffer);
			i++;
		}
		while (true)
		{
			stream >> buffer;
			if (buffer == "//////")
			{
				break;
			}
			test.m_answers.push_back(stoi(buffer));
		}
	}
	return stream;
}