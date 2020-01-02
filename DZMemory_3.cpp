#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

/*
Составить программу, выводящую на экран текущую среду сборки (Windows/Linux),
дату и время последней успешной сборки. Использовать константу TIME для вывода времени.
*/

void out()
{
	cout << "Текущая среда сборки:" <<_WIN32<< endl;//константа-индикатор сборки в среде Windows
	cout << "Дата и время последней успешной сборки:" <<__DATE__<<" "<< __TIME__ << endl;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	out();
	system("pause");
	return 0;
}