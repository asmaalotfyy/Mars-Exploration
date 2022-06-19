#pragma once
#include "MarsStation.h"
#include <iostream>
using namespace std;
int main()
{
	cout << "please choose your preffered output method" << endl;
	cout << "1-interactive mode" << endl;
	cout << "2-step by step mode" << endl;
	cout << "3-silent mode" << endl;
	int mode;
	cin >> mode;

	MarsStation mars;
	mars.StartUp();
	mars.CheckingSystem(mode);
	return 0;
}