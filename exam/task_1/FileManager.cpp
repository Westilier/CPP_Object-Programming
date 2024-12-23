#include "FileManager.h"


void FileManager::CreateFile(std::string path, std::string name)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	std::string new_path = path + "\\" + name;
	int i = 1;

	while (std::filesystem::exists(new_path))
	{
		i++;
		int dot_index = new_path.find('.');
		std::string temp_path = new_path.substr(0, dot_index);
		std::string expansion = new_path.substr(dot_index);
		new_path = temp_path + " (" + std::to_string(i) + ')' + expansion;
	}

	std::ofstream file(new_path);

	if (!file.is_open())
	{
		std::cout << "failed to create a file" << std::endl;
	}
	file.close();
}

void FileManager::CreateDirectory(std::string path, std::string name)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	std::string new_path = path + "\\" + name;
	int i = 1;

	while (std::filesystem::exists(new_path))
	{
		i++;
		new_path = new_path + ' ' + std::to_string(i);
	}

	if (!std::filesystem::create_directory(new_path))
	{
		std::cout << "failed to create a directory" << std::endl;
	}
}

void FileManager::Show(std::string path)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	std::filesystem::path path_path = path;
	if (std::filesystem::is_directory(path))
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			std::cout << entry.path() << std::endl;
		}
	}
}

void FileManager::Delete(std::string path)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	if (std::filesystem::remove_all(path))
		std::cout << "successfully deleted";
	else
		std::cout << "failed to delete" << std::endl;
}

void FileManager::Rename(std::string path, std::string new_name)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	std::string new_path = path;
	new_path.replace(new_path.rfind("\\")+1, new_path.size() - new_path.rfind("\\"), new_name);
	if (rename(path.c_str(), new_path.c_str()) != 0)
	{
		std::cout << "Error renaming" << std::endl;
	}
}

void FileManager::Copy(std::string path, std::string temp_path)
{
	if (!std::filesystem::exists(path) && !std::filesystem::exists(temp_path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	std::string new_path = path;
	std::string name;
	new_path.replace(0, new_path.rfind("\\"), temp_path);
	if (!IsConsist(path,new_path))
	{
		std::cout << path << new_path << std::endl;
		std::filesystem::copy(path, new_path, std::filesystem::copy_options::recursive);
	}
}

void FileManager::Move(std::string path, std::string temp_path)
{
	if (!std::filesystem::exists(path) && !std::filesystem::exists(temp_path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return;
	}

	std::string new_path = path;
	new_path.replace(0, new_path.rfind("\\"), temp_path);
	if (rename(path.c_str(), new_path.c_str()) != 0)
	{
		std::cout << "Error moving" << std::endl;
	}
}

long long FileManager::Size(std::string path)
{
	long long sizeBit = 0;
	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: The path was not found" << std::endl;
		return 0;
	}
	if (std::filesystem::is_directory(path))
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			sizeBit += Size(entry.path().string());
		}
	}
	else
	{
		return std::filesystem::file_size(path);
	}
	return sizeBit;
}

void FileManager::Search(std::string path, std::string  searchWord)
{
	if (std::filesystem::is_directory(path))
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			Search(entry.path().string(), searchWord);
		}
	}
	else
	{
		std::string fileName = path.substr(path.rfind("\\") + 1);
		if (fileName == searchWord)
		{
			std::cout << path << std::endl;
			return;
		}
		int iterSearchWord = 0,
			iterFileName = 0,
			count = 0,
			countSign = 0;

		while (iterFileName < fileName.size())
		{
			if (searchWord[iterSearchWord] == '?')
			{
				iterSearchWord++;
				countSign++;
				continue;

			}
			else if(searchWord[iterSearchWord] == '*')
			{
				iterSearchWord++;
				countSign++;
				continue;
			}
			else if (fileName[iterFileName] != searchWord[iterSearchWord]
				&& iterSearchWord > 0
				&& (searchWord[iterSearchWord - 1] == '*'
					|| searchWord[iterSearchWord - 1] == '?'))
			{
				iterFileName++;
				continue;
			}
			else if (fileName[iterFileName] == searchWord[iterSearchWord])
			{
				count++;
			}	
			else
			{
				break;
			}
			iterFileName++;
			iterSearchWord++;
		}
		if (count == searchWord.size()- countSign)
		{
			std::cout << path << std::endl;
		}
	}
}

bool FileManager::IsConsist(std::string path, std::string new_path)
{
	if (path == new_path)
	{
		return true;
	}
	if (std::filesystem::is_directory(path))
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			if (IsConsist(entry.path().string(), new_path))
			{
				return true;
			}
		}
	}
	return false;
}
