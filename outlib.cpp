#include "outlib.h"

OutManager::OutManager()
{
};

OutManager::~OutManager()
{
};

void OutManager::printMessage(string _str)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	for (int i = 0; i < _str.length(); i++)
	{
		cout << _str[i];
		Sleep(100);
	};
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
};

void OutManager::printMessage(int _numb)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	char buffer[3];
	_itoa_s(_numb, buffer, 3, 10);
	string str = buffer;
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		Sleep(100);
	};
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
};

void OutManager::terminatorOut(int i, float _one_percent)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	system("cls");
	cout.setf(ios::fixed);
	cout << "Т-800 выполняет сложные математические калькуляции. Прогресс (" << setprecision(2) << i / _one_percent << "%) " << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
};