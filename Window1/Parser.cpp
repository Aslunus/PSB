#include "Parser.h"



void Parser::ReadFile(const std::string& path)
{
	std::ifstream ifstr(path, std::ios::binary | std::ios::in);

	std::stringstream pbuf;

	pbuf << ifstr.rdbuf();
	 str = pbuf.str().c_str();
	 ifstr.close();

	

}

bool Parser::initialize(const std::vector<std::string>& vecSupp)
{
	for (int i = 0; i < vecSupp.size(); i++)
	{
		bool est = (str.find(vecSupp[i]) != std::string::npos);
		if (!est)
			return false;
	}
	return true;
}

bool Parser::ouputFile(const std::vector<std::string>& vecSupp)
{
	if (initialize(vecSupp))
	{
		std::ofstream ofstr(pathOut, std::ios::ate | std::ios::binary);
		ofstr << str;
		ofstr.close();
		return true;
	}
	else
	{
		std::cout << "not file" << std::endl;
		return false;
	}
}

void Parser::getPathOut(const std::string& pathOut)
{
	this->pathOut = pathOut;
}
