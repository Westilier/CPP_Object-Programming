#include "FileManager.h"


int main()
{
	setlocale(LC_ALL,"rus");
	FileManager filemanager;
    std::string command;
    std::string path, new_path;
    std::string name;
    std::string searchWord;
    while (true)
	{
        std::cout << "������� ������� ��� ������� info, ��� ��������� ������ ������" << std::endl;
        std::cin >> command;
        system("cls");
        if (command == "info")
        {
            std::cout << "info - �������� ������ ������ ��� ������ � ����������" << std::endl <<
                "view - ���������� �� ������� ����������� �����" << std::endl <<
                "newd - ������� ����� �����" << std::endl <<
                "newf - ������� ����� ����" << std::endl <<
                "rename - �������������" << std::endl << 
                "move - �����������" << std::endl <<
                "copy - �����������" << std::endl <<
                "delete - ������� " << std::endl <<
                "search - ��������� ����� �� �����" << std::endl <<
                "size - ��������� ������" << std::endl <<
                "exit - ����� �� ���������" << std::endl;
        }
        else if (command == "view")
        {
            std::cout << "������� ����� �����. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            filemanager.Show(path);
        }
        else if (command == "newd")
        {
            std::cout << "������� ����� �����. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "������� �������� ����� ����������" << std::endl;
            std::cin >> name;
            filemanager.CreateDirectory(path, name);
        }
        else if (command == "newf")
        {
            std::cout << "������� ����� �����. ������ �����: (d:\\folder\\folder)"<<std::endl;
            std::cin >> path;
            std::cout << "������� �������� ������ ����� � �����������.������ ����� : (text.txt)" << std::endl;
            std::cin >> name;
            filemanager.CreateFile(path, name);
        }
        else if (command == "copy")
        {
            std::cout << "������� ����� ������� �����������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "������� ����� ����� ���� �����������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> new_path;
            filemanager.Copy(path, new_path);
        }
        else if (command == "move")
        {
            std::cout << "������� ����� ������� �����������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "������� ����� ���������� ���� �����������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> new_path;
            filemanager.Move(path,new_path);
        }
        else if (command == "delete")
        {
            std::cout << "������� ����� ������� ��������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            filemanager.Delete(path);
        }
        else if (command == "rename")
        {
            std::cout << "������� ����� ������� �������������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "������� ����� �������� .������ ����� " << std::endl << "��� ����� : (text.txt)" << std::endl << "��� ����� :(text)" << std::endl;
            std::cin >> name;
            filemanager.Rename(path,name);
        }
        else if (command == "size")
        {
            std::cout << "������� ����� �������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << filemanager.Size(path) << std::endl;
        }
        else if (command == "search")
        {
            std::cout << "������� ��������. ������ �����: (text)" << std::endl;
            std::cin >> searchWord;
            std::cout << "������� ����� ����� ��� ������. ������ �����: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            filemanager.Search(path, searchWord);
        }
        else if (command == "exit")
        {
            return 0;
        }
	}
}