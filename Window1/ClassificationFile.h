#pragma once
#include"DirectoryPath.h"
#include"Parser.h"
class ClassificationFile
{
public:
	void SetInputPath(const std::string& pathIn);
	void SetOutputPath(const std::string& pathOut);
	void ValidationFile( std::string file);
	
private:
	std::vector<std::vector<std::string>> globalVecValidator;
	std::vector<std::string> vecFile;
	std::string m_pathIn;
	std::string m_pathOut;

};