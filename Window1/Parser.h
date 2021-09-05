#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
class Parser
{
public:
	void ReadFile(const std::string& path);
	
	bool ouputFile(const std::vector<std::string>& vecSupp);
	void getPathOut(const std::string& pathOut);
private:
	bool initialize(const std::vector<std::string>& vecSupp);
	std::string str;
	std::string pathOut;
};