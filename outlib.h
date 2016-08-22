#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

class OutManager
{
public:
	OutManager();
	~OutManager();
	void printMessage(string _str);
	void printMessage(int _numb);
	void terminatorOut(int i, float _one_percent);

private:

};

