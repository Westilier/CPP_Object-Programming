#include "UserList.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	UserList userList;

	int index;
	UserData newUser;
	MyString buffer;

	bool IsOn = true;
	while (IsOn)
	{
		std::cin.ignore(20, '\n');
		std::cout << "1 - �������� ��������" << std::endl
				<< "2 - ������� ��������" << std::endl
				<< "3 - ������ �������� �� �����" << std::endl
				<< "4 - ������ �������� �� �������" << std::endl
				<< "5 - ������ �������� �� ��������" << std::endl
				<< "6 - �������� ���� ���������" << std::endl
				<< "7 - ��������� ���������� � ����" << std::endl
				<< "8 - ��������� ���������� �� �����" << std::endl
				<< "0 - �����" << std::endl;
		size_t key;
		std::cin >> key;
		std::cin.ignore(20, '\n');
		switch (key)
		{
		case 1:
			newUser.Input();
			userList.AddUser(newUser);
			break;
		case 2:
			std::cout << "������� �������" << std::endl;
			buffer.Input();
			userList.DeleteUser(buffer);
			break;
		case 3:
			std::cout << "������� ���" << std::endl;
			buffer.Input();
			index = userList.SearchByName(buffer);
			if (index > 0)
			{
				userList.GetUser(index).Print();
			}
			else
			{
				std::cout << "������������ �� ������" << std::endl;
			}
			break;
		case 4:
			std::cout << "������� �������" << std::endl;
			buffer.Input();
			index = userList.SearchBySurname(buffer);
			if (index > 0)
			{
				userList.GetUser(index).Print();
			}
			else
			{
				std::cout << "������������ �� ������" << std::endl;
			}
			break;
		case 5:
			std::cout << "������� ��������" << std::endl;
			buffer.Input();
			index = userList.SearchByPatronymic(buffer);
			if (index > 0)
			{
				userList.GetUser(index).Print();
			}
			else
			{
				std::cout << "������������ �� ������" << std::endl;
			}
			break;
		case 6:
			userList.PrintAllUsers();
			break;
		case 7:
			std::cout << "������� ��� �����";
			buffer.Input();
			userList.SaveToFile(buffer);
			break;
		case 8:
			std::cout << "������� ��� �����";
			buffer.Input();
			userList.LoadFromFile(buffer);
			break;
		case 0:
			IsOn = false;
			break;
		default:
			std::cout << "������������ ����" << std::endl;
			break;
		}
	}
	return 0;
}