#include "Program.h"

void Program::LoadStartData()
{
	std::string path;
	User newUser;

	for (const auto& entry : std::filesystem::directory_iterator("Users"))
	{
		path = entry.path().string();
		std::ifstream stream(path);
		if (stream.is_open())
		{
			stream >> newUser;
			m_users.push_back(newUser);
			stream.close();
		}
	}

	int i = 0;

	for (const auto& category : std::filesystem::directory_iterator("Categories"))
	{
		path = category.path().string();
		if ((path.rfind("\\") + 1) < path.size())
		{
			m_categories.push_back(path.substr(path.rfind("\\") + 1));
			for (const auto& pathTest : std::filesystem::directory_iterator(path))
			{
				Test newTest(" ");
				std::ifstream stream(pathTest.path().string());
				stream >> newTest;
				m_categories[i].AddTest(newTest);
				stream.close();
			}
			i++;
		}
	}
}

void Program::ActivateUser()
{
	int key;

	while (true)
	{
		std::cout << "1 - ������������������" << std::endl
			<< "2 - �����" << std::endl;
		std::cin >> key;
		if (key == 1)
		{
			m_activeUser.Registration(m_users);
			break;
		}
		else if (key == 2)
		{
			if (m_activeUser.Enter(m_users))
			{
				break;
			}
		}
	}
}

void Program::Work()
{
	LoadStartData();
	ActivateUser();
	if (m_activeUser.IsAdmin())
	{
		AdminPossibilities();
	}
	else
	{
		TesterPossibilities();
	}
	FinishWork();
}

void Program::FinishWork()
{
	for (size_t i = 0; i < m_users.size(); i++)
	{
		std::string path = "Users/" + std::to_string(i) + ".txt";
		std::ofstream stream(path);
		stream << m_users[i];
		stream.close();
	}
	for (size_t i = 0; i < m_categories.size(); i++)
	{
		std::filesystem::create_directory("Categories/" + m_categories[i].GetName());
		for (size_t j = 0; j < m_categories[i].GetCountTest(); j++)
		{
			std::string path = "Categories/" + m_categories[i].GetName() + "/" + m_categories[i].GetTest(j).GetName() + ".txt";
			std::ofstream stream(path);
			stream << m_categories[i].GetTest(j);
			stream.close();
		}
	}
}

void Program::AdminPossibilities()
{
	int key,bufferNumber;
	std::string buffer;

	while (true) {
		if (m_activeUser.IsAdmin())
		{
			std::cout << "1 - �������� ������" << std::endl
				<< "2 - �������� �����" << std::endl
				<< "3 - ������� �����������" << std::endl
				<< "4 - ������� �����������" << std::endl
				<< "5 - ����������� �����������" << std::endl
				<< "6 - ����������� ����������" << std::endl
				<< "7 - ��������� ��������� " << std::endl
				<< "8 - ��������� �����" << std::endl
				<< "9 - �������� ������ � ������" << std::endl
				<< "10 - �������� ���������� �����" << std::endl
				<< "11 - ������������� ��������� �� �����" << std::endl
				<< "12 - ������������� ����� � ��������� �� �����" << std::endl
				<< "13 - �������������� ��������� � ����" << std::endl
				<< "14 - �������������� ����� � ��������� � ����" << std::endl
				<< "15 - �����" << std::endl;

			std::cin >> key;
			std::cin.ignore(20, '\n');
			if (key == 1)
			{
				std::cout << "������� ����� ������" << std::endl;
				std::getline(std::cin, buffer);
				m_activeUser.ChangePassword(buffer);
			}
			else if (key == 2)
			{
				std::cout << "������� ����� �����" << std::endl;
				std::getline(std::cin, buffer);
				m_activeUser.ChangeLogin(buffer, m_users);
			}
			else if (key == 3)
			{
				User newUser;
				newUser.Registration(m_users);
			}
			else if (key == 4)
			{
				if (m_activeUser.DeleteUser(m_users))
				{
					std::cout << "������������ ������� ������" << std::endl;
				}
				else
				{
					std::cout << "������������ �� ������" << std::endl;
				}
			}
			else if (key == 5)
			{
				std::cout << "������� ����� ������������ " << std::endl;
				std::cin >> buffer;
				std::cout << "�������� ��,��� ������ ��������" << std::endl
					<< "1 - ���" << std::endl
					<< "2 - �����" << std::endl
					<< "3 - ����� ��������" << std::endl;
				std::cin >> key;
				if (key == 1)
				{
					m_activeUser.ChangeFIO(buffer,m_users);
				}
				else if (key == 2)
				{
					m_activeUser.ChangeAddress(buffer,m_users);
				}
				else if (key == 3)
				{
					m_activeUser.ChangeNumber(buffer,m_users);
				}
			}
			else if (key == 6)
			{
				std::cout << "1 - ����������� ����� ���������� �� �����" << std::endl
					<< "2 - ����������� �� ���������� ������" << std::endl
					<< "3 - ����������� �� ����������� �������������" << std::endl;
				std::cin >> key;
				int countCorrectAnswers = 0, countQuestion = 0, countTests = 0;
				double averageMark = 0;
				if (key == 1)
				{
					for (size_t i = 0; i < m_users.size(); i++)
					{
						for (size_t j = 0; j < m_users[i].GetPassedTests().size(); j++)
						{
							Test test = m_users[i].GetPassedTests()[j];
							if (test.IsFinished())
							{
								countTests ++;
								countCorrectAnswers = test.GetCountCorrectAnswer();
								countQuestion = test.GetCountQuestion();
								averageMark += countCorrectAnswers / (countQuestion / 12);
							}
						}
					}
					if (countTests > 0)
					{
						averageMark /= countTests;
					}
					std::cout << "������� ������: " << averageMark << std::endl
						<< "���������� ����������� ������: " << countTests << std::endl;
				}
				else if (key == 2)
				{
					Test searchTest = ChooseTest();
					if (searchTest.GetName() != " ")
					{
						for (size_t i = 0; i < m_users.size(); i++)
						{
							for (size_t j = 0; j < m_users[i].GetPassedTests().size(); j++)
							{
								Test test = m_users[i].GetPassedTests()[j];
								if (searchTest == test)
								{
									countTests++;
									averageMark += test.GetCountCorrectAnswer() / (test.GetCountQuestion() / 12);
								}
							}
						}
					}
					if (countTests > 0)
					{
						averageMark /= countTests;
					}
					if (searchTest.GetName() == " ")
					{
						std::cout << "������� ������: " << averageMark << std::endl
							<< "���������� ����������� �����: " << countTests << std::endl;
					}
				}
				else if (key == 3)
				{
					std::cout << "������� ����� ������������" << std::endl;
					std::cin.ignore(20, '\n');
					std::getline(std::cin, buffer);
					User user;
					user.FindUser(buffer, m_users);
					for (size_t j = 0; j < user.GetPassedTests().size(); j++)
					{
						Test test = user.GetPassedTests()[j];
						if (test.IsFinished())
						{
							countTests ++;
							countCorrectAnswers = test.GetCountCorrectAnswer();
							countQuestion = test.GetCountQuestion();
							averageMark += countCorrectAnswers / (countQuestion / 12);
						}
					}
					if (countTests > 0)
					{
						averageMark /= countTests;
					}	
					if (!user.GetFIO().empty())
					{
						std::cout << "������� ������: " << averageMark << std::endl
							<< "���������� ����������� �����: " << countTests << std::endl;
					}
				}
			}
			else if (key == 7)
			{
				std::cout << "������� �������� ����� ���������" << std::endl;
				std::getline(std::cin, buffer);
				Category newCategory(buffer);
				m_categories.push_back(newCategory);
			}
			else if (key == 8)
			{
				std::cout << "�������� ����� ���������" << std::endl;
				for (size_t i = 0; i < m_categories.size(); i++)
				{
					std::cout << i + 1 << " - ";
					m_categories[i].PrintName();
				}
				std::cin >> key;
				std::cin.ignore(20, '\n');
				key--;

				if (key < m_categories.size() && key >= 0)
				{
					std::cout << "������� �������� ������ �����" << std::endl;
					std::getline(std::cin, buffer);
					Test newTest(buffer);
					m_categories[key].AddTest(newTest);
				}
				else
				{
					std::cout << "��������� �� �������" << std::endl;
				}
			}
			else if (key == 9)
			{
				int key, key_2;
				std::cout << "�������� ����� ���������" << std::endl;
				for (size_t i = 0; i < m_categories.size(); i++)
				{
					std::cout << i + 1 << " - ";
					m_categories[i].PrintName();
				}
				std::cin >> key;
				std::cin.ignore(20, '\n');
				key--;

				if (key >= m_categories.size() || key < 0)
				{
					std::cout << "��������� �� �������" << std::endl;
				}
				else
				{
					std::cout << "�������� ����� �����" << std::endl;
					m_categories[key].PrintTests();
					std::cin >> key_2;
					std::cin.ignore(20, '\n');
					key_2--;
					if (key_2 >= m_categories[key].GetCountTest() || key_2 < 0)
					{
						std::cout << "���� �� ������" << std::endl;
					}
					else
					{
						std::cout << "������� ���������� ��������� ������" << std::endl;
						std::cin >> bufferNumber;
						m_categories[key].GetTest(key_2).AddQuestion(bufferNumber);
					}
				}
			}
			else if (key == 10)
			{
				Test test = ChooseTest();
				int numberQuestion, numberCorrectAnswer;

				if (!test.GetName().empty())
				{
					std::cout << "������� ����� �������" << std::endl;
					for (size_t i = 0; i < test.GetCountQuestion(); i++)
					{
						std::cout << i + 1 << " - ";
						test.PrintQuestion(i);
					}
					std::cin >> numberQuestion;
					numberQuestion--;

					std::cout << "������� ����� ����������� ������" << std::endl;
					test.PrintVariantsAnswer(numberQuestion);
					std::cin >> numberCorrectAnswer;
					if (numberCorrectAnswer > 0 && numberCorrectAnswer <= test.GetCountAnswers(numberQuestion))
					{
						test.SetCorrectAnswer(numberQuestion, numberCorrectAnswer);
					}
					else
					{
						std::cout << "�� ������ ���� ������ ������" << std::endl;
					}
				}
			}
			else if (key == 11)
			{
				Test newTest("");
				std::string Directory, path;

				std::cout << "������� ����� ���������. ������ �����: (d:\\folder\\folder)" << std::endl;
				std::getline(std::cin, Directory);
				if (std::filesystem::is_directory(Directory))
				{
					for (const auto& entry : std::filesystem::directory_iterator(Directory))
					{
						path = entry.path().string();
						std::ifstream stream(path);
						if (stream.is_open())
						{
							stream >> newTest;
							m_categories[key].AddTest(newTest);
							stream.close();
						}
						else
						{
							std::cout << "���� �� ������" << std::endl;
						}
					}
				}
				else
				{
					std::cout << "��������� �� �������" << std::endl;
				}

			}
			else if (key == 12)
			{
				std::cout << "�������� ����� ���������" << std::endl;
				for (size_t i = 0; i < m_categories.size(); i++)
				{
					std::cout << i + 1 << " - ";
					m_categories[i].PrintName();
				}
				std::cin >> key;
				std::cin.ignore(20, '\n');
				key--;

				if (key >= m_categories.size() || key < 0)
				{
					std::cout << "��������� �� �������" << std::endl;
				}
				else
				{
					std::string path;
					Test newTest("");
					std::cout << "������� ����� �����. ������ �����: (d:\\folder\\folder)" << std::endl;
					std::getline(std::cin, path);
					std::ifstream stream(path);
					if (stream.is_open())
					{
						stream >> newTest;
						m_categories[key].AddTest(newTest);
					}
					else
					{
						std::cout << "���� �� ������" << std::endl;
					}
				}
			}
			else if (key == 13)
			{
				std::cout << "�������� ����� ���������" << std::endl;
				for (size_t i = 0; i < m_categories.size(); i++)
				{
					std::cout << i + 1 << " - ";
					m_categories[i].PrintName();
				}
				std::cin >> key;
				std::cin.ignore(20, '\n');
				key--;

				if (key >= m_categories.size() || key < 0)
				{
					std::cout << "��������� �� �������" << std::endl;
				}
				else
				{
					std::string Directory;
					std::cout << "������� ����� ���� �������������� ���������. ������ �����: (d:\\folder\\folder)" << std::endl;
					std::getline(std::cin, Directory);
					for (size_t i = 0; i < m_categories[key].GetCountTest(); i++)
					{
						std::string path = Directory + "\\" + m_categories[key].GetTest(i).GetName() + ".txt";
						std::cout << path << std::endl;
						std::ofstream stream(path);
						if (stream.is_open())
						{
							stream << m_categories[key].GetTest(i);
							stream.close();
						}
						else
						{
							std::cout << "�� ������� ����� �����" << std::endl;
						}
					}
				}
			}
			else if (key == 14)
			{
				Test test = ChooseTest();
				if (!test.GetName().empty())
				{
					std::string Directory;
					std::cout << "������� ����� ���� �������������� ����. ������ �����: (d:\\folder\\folder)" << std::endl;
					std::getline(std::cin, Directory);
					std::string path = Directory + "\\" + test.GetName() + ".txt";
					std::ofstream stream(path);
					if (stream.is_open())
					{
						stream << test;
						stream.close();
					}
					else
					{
						std::cout << "�� ������� ����� �����" << std::endl;
					}
				}
			}
			else if (key == 15)
			{
				break;
			}
		}
	}
}

void Program::TesterPossibilities()
{
	int key;

	while (true)
	{
		std::cout << "1 - ������ ����� ����" << std::endl
			<< "2 - ���������� ���������� ������" << std::endl
			<< "3 - ���������� ���������� �����" << std::endl
			<< "4 - �����" << std::endl;
		std::cin >> key;
		std::cin.ignore(20, '\n');
		if (key == 1)
		{
			Test test = ChooseTest();
			if (!test.GetName().empty() && test.GetCountQuestion()>0)
			{
				m_activeUser.PassTest(test);
			}
		}
		else if (key == 2)
		{
			std::vector<Test> PassedTests = m_activeUser.GetPassedTests();

			for (size_t i = 0; i < PassedTests.size(); i++)
			{
				std::cout << i + 1 << " - ";
				if (PassedTests[i].IsFinished())
				{
					std::cout << PassedTests[i].GetName() << std::endl;
					m_activeUser.PassTest(PassedTests[i]);
				}
			}
			if(m_activeUser.GetPassedTests().empty())
			{
				std::cout << "����� �� ������" << std::endl;
			}
		}
		else if (key == 3)
		{
			std::vector<Test> PassedTests = m_activeUser.GetPassedTests();

			std::cout << "�������� ����� �����" << std::endl;
			for (size_t i = 0; i < PassedTests.size(); i++)
			{
				std::cout << i + 1 << " - ";
				if (!PassedTests[i].IsFinished())
				{
					std::cout << PassedTests[i].GetName() << std::endl;
				}
			}
			std::cin >> key;
			std::cin.ignore(20, '\n');
			key--;
			if (key >= PassedTests.size() || key < 0)
			{
				std::cout << "����� �� ������" << std::endl;
			}
			else
			{
				m_activeUser.PassTest(PassedTests[key]);
			}
		}
		else if (key == 4)
		{
			break;
		}
	}
}

Test Program::ChooseTest()
{
	int key, key_2;
	std::cout << "�������� ����� ���������" << std::endl;
	for (size_t i = 0; i < m_categories.size(); i++)
	{
		std::cout << i + 1 << " - ";
		m_categories[i].PrintName();
	}
	std::cin >> key;
	std::cin.ignore(20, '\n');
	key--;

	if (key >= m_categories.size() || key < 0)
	{
		std::cout << "��������� �� �������" << std::endl;
	}
	else
	{
		std::cout << "�������� ����� �����" << std::endl;
		m_categories[key].PrintTests();
		std::cin >> key_2;
		std::cin.ignore(20, '\n');
		key_2--;
		if (key_2 >= m_categories[key].GetCountTest() || key_2 < 0)
		{
			std::cout << "���� �� ������" << std::endl;
		}
		else
		{
			return m_categories[key].GetTest(key_2);
		}
	}
	Test test("");
	return test;
}
