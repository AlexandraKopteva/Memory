#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

/*
��������� ���������, ��������� �� ����� ������� ����� ������ (Windows/Linux),
���� � ����� ��������� �������� ������. ������������ ��������� TIME ��� ������ �������.
*/

void out()
{
	cout << "������� ����� ������:" <<_WIN32<< endl;//���������-��������� ������ � ����� Windows
	cout << "���� � ����� ��������� �������� ������:" <<__DATE__<<" "<< __TIME__ << endl;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	out();
	system("pause");
	return 0;
}