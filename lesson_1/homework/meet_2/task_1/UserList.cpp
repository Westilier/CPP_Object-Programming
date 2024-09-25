#include "UserList.h"

void UserList::AddUser(UserData& user)
{
	m_userList.push_back(user);
	std::cout << 20;
}

void UserList::DeleteUser(MyString& surname)
{
	UserList userListNew;
	UserData user;
	int index = SearchBySurname(surname);
	UserData needUser = m_userList[index];
	for (size_t i = m_userList.size(); i >= 0; --i)
	{
		user = m_userList[i];
		if (user == needUser)
		{

		}
		m_userList.pop_back();
		userListNew.m_userList.push_back(user);
	}
	while (!m_userList.empty())
	{

	}
	if (index >= 0)
	{
		//m_userList[index].~UserData();

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
	}
}

UserData UserList::GetUser(size_t index)
{
	return UserData();
}

int UserList::SearchByName(MyString name)
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

int UserList::SearchBySurname(MyString surname)
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

int UserList::SearchByPatronymic(MyString patronymic)
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

void UserList::SaveToFile(MyString fileName)
{
	std::ofstream save(fileName.GetString());

	for (size_t i = 0; i < m_userList.size(); ++i)
	{
		save << "1." << m_userList[i].GetName().GetString();
		save << "2." << m_userList[i].GetSurname().GetString();
		save << "3." << m_userList[i].GetPatronymic().GetString();
		save << "4." << m_userList[i].GetWorkPhoneNumber().GetString();
		save << "5." << m_userList[i].GetHomePhoneNumber().GetString();
		save << "6." << m_userList[i].GetAdditionalInformation().GetString();
	}
	save.close();
}

void UserList::LoadFromFile(MyString fileName)
{
	std::string filenameStdStr = fileName.GetString();
	std::ifstream load(filenameStdStr + ".txt");
	std::string buffer;
	while(getline(load, buffer))
	{
		UserData newUser;
		if (buffer.find("1.") != std::string::npos)
		{
			newUser.SetName(buffer.c_str());
		}
		else if (buffer.find("2.") != std::string::npos)
		{
			newUser.SetSurname(buffer.c_str());
		}
		else if (buffer.find("3.") != std::string::npos)
		{
			newUser.SetPatronymic(buffer.c_str());
		}
		else if (buffer.find("4.") != std::string::npos)
		{
			newUser.SetWorkPhoneNumber(buffer.c_str());
		}
		else if (buffer.find("5.") != std::string::npos)
		{
			newUser.SetHomePhoneNumber(buffer.c_str());
		}
		else if (buffer.find("6.") != std::string::npos)
		{
			newUser.SetAdditionalInformation(buffer.c_str());
		}
		m_userList.push_back(newUser);
	}
	load.close();
}
