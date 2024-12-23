#include "User.h"


User::User() :m_login{}, m_password{}, m_FIO{}, m_address{}, m_phone{}, m_passedTests{}, m_isAdmin{false}
{
}

User::User(const User& object)
{
	if (&object != this)
	{
		m_login = object.m_login;
		m_password = object.m_password;
		m_FIO = object.m_FIO;
		m_address = object.m_address;
		m_phone = object.m_phone;
		m_passedTests = object.m_passedTests;
		m_isAdmin = object.m_isAdmin;
	}
}

User& User::operator=(const User& object)
{
	if (&object != this)
	{
		m_login = object.m_login;
		m_password = object.m_password;
		m_FIO = object.m_FIO;
		m_address = object.m_address;
		m_phone = object.m_phone;
		m_passedTests = object.m_passedTests;
		m_isAdmin = object.m_isAdmin;
	}
	return *this;
}

void User::Registration(std::vector<User>& users)
{
	std::string buffer;
	bool end = true;
	while (end)
	{
		std::cout << "Введите логин" << std::endl;
		std::cin >> buffer;
		buffer = EncryptDecrypt(buffer);
		for (size_t i = 0; i < users.size(); i++)
		{
			if (buffer == users[i].m_login)
			{
				std::cout << "Логин занят" << std::endl;
				break;
			}
			else if (i == users.size() - 1)
			{
				m_login = buffer;
				end = false;
			}
		}
		if (users.empty())
		{
			m_login = buffer;
			end = false;
			m_isAdmin = true;
		}
	}
	std::cout << "Введите пароль" << std::endl;
	std::cin >> buffer;
	buffer = EncryptDecrypt(buffer);
	m_password = buffer;

	std::cout << "Введите ФИО" << std::endl;
	std::cin >> buffer;
	m_FIO = buffer;

	std::cout << "Введите адрес" << std::endl;
	std::cin >> buffer;
	m_address = buffer;

	std::cout << "Введите номер телефона" << std::endl;
	std::cin >> buffer;
	m_phone = buffer;
	users.push_back(*this);

	std::string path = "Users/" + std::to_string(users.size() - 1) + ".txt";
	std::ofstream stream(path);
	stream << users[users.size()-1];
	stream.close();

	std::cout << "регистрация завершена" << std::endl << std::endl;
}

bool User::Enter(std::vector<User>& users)
{
	std::string login;
	std::string password;
	std::cout << "Введите логин" << std::endl;
	std::cin >> login;
	login = EncryptDecrypt(login);
	std::cin.ignore(20, '\n');
	std::cout << "Введите пароль" << std::endl;
	std::getline(std::cin,password);
	password = EncryptDecrypt(password);
	for (size_t i = 0; i < users.size(); i++)
	{
		if (login == users[i].m_login && password == users[i].m_password)
		{
			*this = users[i];
			std::cout << "Успешный вход" << std::endl;
			return true;
		}
	}
	std::cout << "Неверный логин или пароль" << std::endl;
	return false;
}

void User::PassTest(Test test)
{
	if (!test.IsFinished())
	{
		int answer;
		int countCorrectAnswer = test.GetCountCorrectAnswer();

		std::cout << "0 - выйти" << std::endl;
		for (size_t i = test.GetlastQuestion(); i < test.GetCountQuestion(); i++)
		{
			test.PrintQuestion(i);
			std::cout << "Выберите вариант ответа" << std::endl;
			test.PrintVariantsAnswer(i);
			std::cin >> answer;
			if (answer == test.GetAnswer(i))
			{
				countCorrectAnswer++;
			}
			else if (answer == 0)
			{
				test.SetResult(countCorrectAnswer, 0, i, false);
				break;
			}
			if (i == test.GetCountQuestion() - 1)
			{
				test.SetResult(countCorrectAnswer, 0, i, true);
			}
			break;
		}
	}
	
	if (test.IsFinished())
	{
		int countCorrectAnswer = test.GetCountCorrectAnswer();
		int mark = 1 / test.GetCountQuestion() * countCorrectAnswer;
		std::cout << "количество праывильных ответов: " << countCorrectAnswer << std::endl
			<< "процент правильных ответов: " << countCorrectAnswer / (test.GetCountQuestion() / 12) << "%" << std::endl
			<< "Оценка" << mark << std::endl;
		test.SetResult(countCorrectAnswer, mark, test.GetCountQuestion());
	}

	m_passedTests.push_back(test);
}

bool User::DeleteUser(std::vector<User>& users)
{
	if (m_isAdmin)
	{
		std::string buffer,path;
		std::cout << "Введите логин пользователя для удаления" << std::endl;
		std::cin >> buffer;
		buffer = EncryptDecrypt(buffer);
		for (size_t i = 0; i < users.size(); i++)
		{
			if (buffer == users[i].m_login)
			{
				path = "Users\\" + std::to_string(i) + ".txt";
				if (remove(path.c_str()) != 0)
				{
					return false;
				}
				users.erase(users.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool User::IsAdmin()
{
	return m_isAdmin;
}

void User::FindUser(std::string login, std::vector<User>& users)
{
	login = EncryptDecrypt(login);
	for (size_t i = 0; i < users.size(); i++)
	{
		if (login == users[i].m_login)
		{
			*this = users[i];
			break;
		}
	}
}

void User::ChangeLogin(std::string newLogin, std::vector<User>& users)
{
	newLogin = EncryptDecrypt(newLogin);

	if (m_isAdmin)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (newLogin == users[i].m_login)
			{
				std::cout << "Логин занят" << std::endl;
				break;
			}
			else if (i == users.size() - 1)
			{
				m_login = newLogin;
				users[0].m_login = newLogin;
			}
		}
	}
}

void User::ChangePassword(std::string newPassword)
{
	newPassword = EncryptDecrypt(newPassword);

	if (m_isAdmin)
	{
		m_password = newPassword;
	}
}

void User::ChangeFIO(std::string login, std::vector<User>& users)
{
	std::string buffer;
	login = EncryptDecrypt(login);

	std::cout << "Введите новое ФИО" << std::endl;
	std::cin.ignore(20, '\n');
	std::getline(std::cin, buffer);

	if (m_isAdmin)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (login == users[i].m_login)
			{
				users[i].m_FIO = buffer;
				break;
			}
			else if (i == users.size() - 1)
			{
				std::cout << "пользователь не найден" << std::endl;
			}
		}
	}
}

void User::ChangeAddress(std::string login, std::vector<User>& users)
{
	std::string buffer;
	login = EncryptDecrypt(login);

	std::cout << "Введите новый адрес" << std::endl;
	std::cin.ignore(20, '\n');
	std::getline(std::cin, buffer);

	if (m_isAdmin)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (login == users[i].m_login)
			{
				users[i].m_address = buffer;
				break;
			}
			else if (i == users.size() - 1)
			{
				std::cout << "пользователь не найден" << std::endl;
			}
		}
	}
}

void User::ChangeNumber(std::string login, std::vector<User>& users)
{
	std::string buffer;
	login = EncryptDecrypt(login);

	std::cout << "Введите новый номер телефон" << std::endl;
	std::cin.ignore(20, '\n');
	std::getline(std::cin, buffer);

	if (m_isAdmin)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (login == users[i].m_login)
			{
				users[i].m_phone = buffer;
				break;
			}
			else if (i == users.size() - 1)
			{
				std::cout << "пользователь не найден" << std::endl;
			}
		}
	}
}

std::string User::GetFIO()
{
	return m_FIO;
}

std::vector<Test> User::GetPassedTests()
{
	return m_passedTests;
}

std::string User::EncryptDecrypt(std::string& toEncrypt) {
	char key[3] = { 'K', 'C', 'Q' }; 
	std::string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}

std::ostream& operator<<(std::ostream& stream, const User& user)
{
	stream << user.m_login << std::endl;
	stream << user.m_password << std::endl;
	stream << user.m_FIO << std::endl;
	stream << user.m_address << std::endl;
	stream << user.m_phone << std::endl;
	stream << static_cast<int>(user.m_isAdmin) << std::endl;
	for (size_t i = 0; i < user.m_passedTests.size(); i++)
	{
		stream << user.m_passedTests[i];
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, User& user)
{
	stream >> user.m_login;
	stream >> user.m_password;
	stream >> user.m_FIO;
	stream >> user.m_address;
	stream >> user.m_phone;
	stream >> user.m_isAdmin;

	while (true)
	{
		Test test(" ");
		stream >> test;
		if (test.GetName() != " ")
		{
			user.m_passedTests.push_back(test);
		}
		else
		{
			break;
		}
	}
	return stream;
}
