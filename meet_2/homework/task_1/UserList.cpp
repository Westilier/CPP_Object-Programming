#include "UserList.h"

void UserList::AddUser(UserData const& user)
{
	m_userList.push_back(user);
}

void UserList::DeleteUser(MyString& surname)
{
	int index = SearchBySurname(surname);

	if (index >= 0)
	{
		m_userList.erase(m_userList.cbegin() + index);
		std::cout << "Ïîëüçîâàòåëü óäàëåí" << std::endl;
	}
	else
	{
		std::cout << "Ïîëüçîâàòåëü íå íàéäåí" << std::endl;
	}
}

void UserList::PrintAllUsers()
{
	for (size_t i = 0; i < m_userList.size(); ++i)
	{
		m_userList[i].Print();
		std::cout<<std::endl;
	}
}

UserData UserList::GetUser(size_t index)
{
	return m_userList[index];
}

int UserList::SearchByName(MyString& name)
{
	for (size_t i = 0; i < m_userList.size(); ++i)
	{
		if (name.Ñompare(m_userList[i].GetName()))
		{
			return i;
		}
	}
	return -1;
}

int UserList::SearchBySurname(MyString& surname)
{
	for (size_t i = 0; i < m_userList.size(); ++i)
	{
		if (surname.Ñompare(m_userList[i].GetSurname()))
		{
			return i;
		}
	}
	return -1;
}

int UserList::SearchByPatronymic(MyString& patronymic)
{
	for (size_t i = 0; i < m_userList.size(); ++i)
	{
		if (patronymic.Ñompare(m_userList[i].GetSurname()))
		{
			return i;
		}
	}
	return -1;

}

void UserList::SaveToFile()
{
	std::cout << "Ââåäèòå èìÿ ôàéëà";
	std::string filename;
	getline(std::cin, filename);
	filename += ".txt";
	std::cout << filename;
	std::ofstream save;
	save.open(filename);

	for (size_t i = 0; i < m_userList.size(); ++i)
	{
		save << "1." << m_userList[i].GetName().GetString() << std::endl;
		save << "2." << m_userList[i].GetSurname().GetString() << std::endl;
		save << "3." << m_userList[i].GetPatronymic().GetString() << std::endl;
		save << "4." << m_userList[i].GetWorkPhoneNumber().GetString() << std::endl;
		save << "5." << m_userList[i].GetHomePhoneNumber().GetString() << std::endl;
		save << "6." << m_userList[i].GetAdditionalInformation().GetString() << std::endl;
	}
	save.close();
}

void UserList::LoadFromFile()
{
	std::cout << "Ââåäèòå èìÿ ôàéëà";
	std::string filename;
	getline(std::cin,filename);
	filename += ".txt";
	std::cout << filename;
	std::ifstream load(filename);
	std::string buffer;

	UserData newUser;
	while(getline(load, buffer))
	{
		std::cout << buffer;
		if (buffer.find("1.") != std::string::npos)
		{
			newUser.SetName(MyString(buffer));
		}
		else if (buffer.find("2.") != std::string::npos)
		{
			newUser.SetSurname(MyString(buffer));
		}
		else if (buffer.find("3.") != std::string::npos)
		{
			newUser.SetPatronymic(MyString(buffer));
		}
		else if (buffer.find("4.") != std::string::npos)
		{
			newUser.SetWorkPhoneNumber(MyString(buffer));
		}
		else if (buffer.find("5.") != std::string::npos)
		{
			newUser.SetHomePhoneNumber(MyString(buffer));
		}
		else if (buffer.find("6.") != std::string::npos)
		{
			newUser.SetAdditionalInformation(MyString(buffer));
			m_userList.push_back(newUser);
		}
		std::cout << 30 << std::endl;
	}
	load.close();
}
