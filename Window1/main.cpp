
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")*/
#include"WinApiWindow.h"

#include"ClassificationFile.h"
#include<CommCtrl.h>
LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

LRESULT WINAPI cildWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
HWND hTextOpenFile;
HWND hEditOpenFile;
HWND hTextSaveFile;
HWND hEditSaveFile;
HWND hButtonLoader;
HWND hProggersBar;
HWND hButtonOk;
#define ID_EDIT_TEXT_OPEN_FILE 1
#define ID_EDIT_TEXT_SAVE_FILE 2

#define ID_BUTTON_LOADER 3
#define ID_PROGRESS_BAR 4
#define ID_BUTTON 5;
ClassificationFile classificationFile;

IWindowCore* childCore = nullptr;
int main()
{
	IWindowCore* windowCore = new WinApiWindow(WHITE_BRUSH, L"Window class", L"Афто.док", 1024, 768, WndProc, 0, 0, GetModuleHandle(nullptr), CS_VREDRAW | CS_HREDRAW, WS_SYSMENU | WS_MINIMIZEBOX);
	windowCore->Initialize();
	windowCore->MainLoop();

	return 0;
}
char pathOpenFileDirecoty[500];
char pathSaveFileDirecoty[500];
DirectoryPath* path = nullptr;
std::vector<std::string> vecPathFile = { "Устав_действующий", "Положение о СД", "Бухгалтерская отчетность_форма 1", "Бухгалтерская отчетность_форма 2",
			"Бухгалтерская отчетность_форма 1 _промежуточная", "Бухгалтерская отчетность_форма 2 _промежуточная", "Аудиторское заключение", "Описание_деятельности_ГК", "Решение_назначение ЕИО" };
LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:

		hTextOpenFile = CreateWindow(L"static", L"Расположение файла для чтения:", WS_CHILD | WS_VISIBLE, 50, 30, 300, 20, hwnd, NULL, GetModuleHandle(nullptr), NULL);
		ShowWindow(hTextOpenFile, SW_SHOWNORMAL);
		hEditOpenFile = CreateWindow(L"Edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL, 50, 50, 300, 20, hwnd, reinterpret_cast<HMENU>(ID_EDIT_TEXT_OPEN_FILE), GetModuleHandle(nullptr), NULL);
		ShowWindow(hEditOpenFile, SW_SHOWNORMAL);


		hTextSaveFile = CreateWindow(L"static", L"Расположение файла для записи:", WS_CHILD | WS_VISIBLE, 50, 100, 300, 20, hwnd, NULL, GetModuleHandle(nullptr), NULL);
		ShowWindow(hTextSaveFile, SW_SHOWNORMAL);
		hEditSaveFile = CreateWindow(L"Edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL, 50, 120, 300, 20, hwnd, reinterpret_cast<HMENU>(ID_EDIT_TEXT_SAVE_FILE), GetModuleHandle(nullptr), NULL);
		ShowWindow(hEditSaveFile, SW_SHOWNORMAL);


		hButtonLoader = CreateWindow(L"Button", L"загрузить", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 150, 150, 20, hwnd, reinterpret_cast<HMENU>(ID_BUTTON_LOADER), GetModuleHandle(nullptr), NULL);
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wp))
		{
		case ID_EDIT_TEXT_OPEN_FILE:

			break;
		case  ID_EDIT_TEXT_SAVE_FILE:

			break;
		case ID_BUTTON_LOADER:
			if (childCore != nullptr)
				childCore->Destroy();
			GetWindowTextA(hEditOpenFile, pathOpenFileDirecoty, 500);
			GetWindowTextA(hEditSaveFile, pathSaveFileDirecoty, 500);
			path = new DirectoryPath(pathOpenFileDirecoty, pathSaveFileDirecoty);
			path->searchFile();
			vecPathFile = { "Устав_действующий", "Положение о СД", "Бухгалтерская отчетность_форма 1", "Бухгалтерская отчетность_форма 2",
   "Бухгалтерская отчетность_форма 1 _промежуточная", "Бухгалтерская отчетность_форма 2 _промежуточная", "Аудиторское заключение", "Описание_деятельности_ГК", "Решение_назначение ЕИО" };
			path->createDirectory(vecPathFile);
			childCore = new WinApiWindow(WHITE_BRUSH, L"Window child", L"", 600, 150, cildWndProc, 0, 0, GetModuleHandle(nullptr), CS_VREDRAW | CS_HREDRAW, WS_SYSMENU | WS_MINIMIZEBOX);
			childCore->Initialize();
			break;
		default:
			break;
		}

		return 0;

	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, msg, wp, lp);

	}
}
Parser parser;
int i = 0;
std::vector<std::string> vecFile;
LRESULT WINAPI cildWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		hProggersBar = CreateWindowEx(0, PROGRESS_CLASS, NULL, WS_VISIBLE | WS_CHILD | PBS_SMOOTH, 20, 20, 540, 30, hwnd, (HMENU)ID_PROGRESS_BAR, GetModuleHandle(nullptr), nullptr);
		SendMessage(hProggersBar, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendMessage(GetDlgItem(hProggersBar, ID_PROGRESS_BAR), PBS_SMOOTH, 1, 0);
		//hButtonOk = CreateWindow(L"Button", L"", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 150, 150, 20, hwnd, reinterpret_cast<HMENU>( ID_BUTTON), GetModuleHandle(nullptr), NULL);
		 //шаг 1
		return 0;

	case WM_COMMAND:

	
		return 0;
	case WM_PAINT:
		
	
		return 0;

	default:
		return DefWindowProc(hwnd, msg, wp, lp);

	}
}