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

	while (true)
	{
		std::cout << "1 - добавить абонента" << std::endl
				<< "2 - удалить абонента" << std::endl
				<< "3 - искать абонента по имени" << std::endl
				<< "4 - искать абонента по фамилии" << std::endl
				<< "5 - искать абонента по отчеству" << std::endl
				<< "6 - показать всех абонентов" << std::endl
				<< "7 - сохранить информацию в файл" << std::endl
				<< "8 - загрузить информацию из файла" << std::endl
				<< "0 - Выход" << std::endl;
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
			std::cout << "Введите фамилию" << std::endl;
			buffer.Input();
			userList.DeleteUser(buffer);
			break;
		case 3:
			std::cout << "Введите имя" << std::endl;
			buffer.Input();
			index = userList.SearchByName(buffer);
			if (index >= 0)
			{
				userList.GetUser(index).Print();
			}
			else
			{
				std::cout << "Пользователь не найден" << std::endl;
			}
			break;
		case 4:
			std::cout << "Введите фамилию" << std::endl;
			buffer.Input();
			index = userList.SearchBySurname(buffer);
			if (index >= 0)
			{
				userList.GetUser(index).Print();
			}
			else
			{
				std::cout << "Пользователь не найден" << std::endl;
			}
			break;
		case 5:
			std::cout << "Введите Отчество" << std::endl;
			buffer.Input();
			index = userList.SearchByPatronymic(buffer);
			if (index >= 0)
			{
				userList.GetUser(index).Print();
			}
			else
			{
				std::cout << "Пользователь не найден" << std::endl;
			}
			break;
		case 6:
			userList.PrintAllUsers();
			break;
		case 7:
			userList.SaveToFile();
			break;
		case 8:

			userList.LoadFromFile();
			break;
		case 0:
			return 0;
		default:
			std::cout << "Некорректный ввод" << std::endl;
			break;
		}
	}

}