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
        std::cout << "”кажите команду или введите info, дл€ получени€ списка команд" << std::endl;
        std::cin >> command;
        system("cls");
        if (command == "info")
        {
            std::cout << "info - показать список команд дл€ работы с менеджером" << std::endl <<
                "view - отобразить на консоль содержимого папке" << std::endl <<
                "newd - создать новую папку" << std::endl <<
                "newf - создать новый файл" << std::endl <<
                "rename - переименовать" << std::endl << 
                "move - переместить" << std::endl <<
                "copy - скопировать" << std::endl <<
                "delete - удалить " << std::endl <<
                "search - выполнить поиск по маске" << std::endl <<
                "size - вычислить размер" << std::endl <<
                "exit - выйти из программы" << std::endl;
        }
        else if (command == "view")
        {
            std::cout << "”кажите адрес папки. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            filemanager.Show(path);
        }
        else if (command == "newd")
        {
            std::cout << "”кажите адрес папки. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "”кажите название новой директории" << std::endl;
            std::cin >> name;
            filemanager.CreateDirectory(path, name);
        }
        else if (command == "newf")
        {
            std::cout << "”кажите адрес папки. ‘ормат ввода: (d:\\folder\\folder)"<<std::endl;
            std::cin >> path;
            std::cout << "”кажите название нового файла с расширением.‘ормат ввода : (text.txt)" << std::endl;
            std::cin >> name;
            filemanager.CreateFile(path, name);
        }
        else if (command == "copy")
        {
            std::cout << "”кажите адрес объекта копировани€. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "”кажите адрес папки куда скопировать. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> new_path;
            filemanager.Copy(path, new_path);
        }
        else if (command == "move")
        {
            std::cout << "”кажите адрес объекта перемещени€. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "”кажите адрес директории куда скопировать. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> new_path;
            filemanager.Move(path,new_path);
        }
        else if (command == "delete")
        {
            std::cout << "”кажите адрес объекта удалени€. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            filemanager.Delete(path);
        }
        else if (command == "rename")
        {
            std::cout << "”кажите адрес объекта переменовани€. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << "”кажите новое название .‘ормат ввода " << std::endl << "дл€ файла : (text.txt)" << std::endl << "дл€ папки :(text)" << std::endl;
            std::cin >> name;
            filemanager.Rename(path,name);
        }
        else if (command == "size")
        {
            std::cout << "”кажите адрес объекта. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            std::cout << filemanager.Size(path) << std::endl;
        }
        else if (command == "search")
        {
            std::cout << "”кажите название. ‘ормат ввода: (text)" << std::endl;
            std::cin >> searchWord;
            std::cout << "”кажите адрес папки где искать. ‘ормат ввода: (d:\\folder\\folder)" << std::endl;
            std::cin >> path;
            filemanager.Search(path, searchWord);
        }
        else if (command == "exit")
        {
            return 0;
        }
	}
}