#include"DirectoryPath.h"

DirectoryPath::DirectoryPath(const std::string& path, const std::string& pathOut) : m_pathInput(path), m_pathOuntput(pathOut), vecFile(std::vector<std::string>())
{

	setlocale(LC_ALL, "");

}

void DirectoryPath::SetNumberFile()
{
	
	WIN32_FIND_DATAA wfd;
	HANDLE  hFile = FindFirstFileA(m_pathInput.c_str(), &wfd);
	numberFileSize = -2;
	if (INVALID_HANDLE_VALUE != hFile)
	{
		do
		{
			numberFileSize++;

		} while (NULL != FindNextFileA(hFile, &wfd));
		FindClose(hFile);
	}
	std::cout << "numberFileSize:\n" << numberFileSize << std::endl;
	vecFile.resize(numberFileSize);
}
void DirectoryPath::searchFile()
{
	WIN32_FIND_DATAA wfd;
	HANDLE  hFile = FindFirstFileA(m_pathInput.c_str(), &wfd);

	vecFile.resize(numberFileSize);
	setlocale(LC_ALL, "rus");

	if (INVALID_HANDLE_VALUE != hFile)
	{
		int i = -2;
		do
		{

			if (i >= 0)

			{
				std::cout << wfd.cFileName /*& FILE_ATTRIBUTE_DIRECTORY ? "Каталог: " : "Файл: "*/ << std::endl;
				vecFile[i] = wfd.cFileName;
			}

			i++;
		} while (NULL != FindNextFileA(hFile, &wfd));

		FindClose(hFile);
	}
}

bool DirectoryPath::createDirectory(const std::vector<std::string>& vecFileName)
{	
	vecPathOutput.resize(vecFileName.size());
	int fileNameSize = 0;
	for (int i = 0; i < vecFileName.size(); i++)
	{
		vecPathOutput[i] = m_pathOuntput + vecFileName[i];
	}
	
	
	for (const auto& fileName : vecPathOutput)
	{
		if (CreateDirectoryA(fileName.c_str(), nullptr) == 0)
			return false;
	}
	return true;
}

DirectoryPath::~DirectoryPath()
{

}