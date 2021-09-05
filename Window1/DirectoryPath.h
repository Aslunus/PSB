#pragma once
#include<fstream>
#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
class DirectoryPath
{
public:
	DirectoryPath(const std::string& path, const std::string& pathOut);
	~DirectoryPath();
	void SetNumberFile();
	void searchFile();
	void SetPath(const std::string& path)
	{
		m_pathInput = path;
	}
	const int GetNumberFile() const { return numberFileSize; } ;

	std::vector<std::string> GetVecFile() { return vecFile; };
	std::string GetPath() { return m_pathInput; };
	bool createDirectory(const std::vector<std::string>& vecFileName);

protected:


	int numberFileSize;
	std::string m_pathInput;
	std::string m_pathOuntput;
	std::vector<std::string> vecFile;
	std::vector<std::string> vecPathOutput;
};