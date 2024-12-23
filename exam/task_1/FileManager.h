#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

class FileManager
{
public:
	void CreateFile(std::string path, std::string name);
	void CreateDirectory(std::string path, std::string name);

	void Show(std::string path);
	void Delete(std::string path);
	void Rename(std::string path, std::string new_name);
	void Copy(std::string path, std::string new_path);
	void Move(std::string path, std::string new_path);
	long long Size(std::string path);
	void Search(std::string path, std::string searchWord);

private:
	bool IsConsist(std::string path, std::string new_path);
};


