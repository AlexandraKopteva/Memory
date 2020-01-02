#include<iostream>
#include<cstdint>

//using namespace std;

std::uint32_t* Fanction(unsigned char* a)
{
	void* b = static_cast<void*>(&a);
	std::uint32_t* uint_p;
	uint_p= static_cast<uint32_t*>(b);
  	//или
	//uint_p = reinterpret_cast<uint32_t*>(&b);
	std::cout << "Size uint32_t:" << sizeof(uint_p) << std::endl;
	return uint_p;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned char* arr = new unsigned char[4];
	arr[0] = '1';
	arr[1] = '2';
	arr[2] = '3';
	arr[3] = '4';
	std::cout << "Elemet Array:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	//
	std::uint32_t* f = Fanction(arr);
	std::cout << "Fanction address:" << f << std::endl;
	std::cout << "Fanction value:" << *f << std::endl;
	delete[] arr;
	system("pause");
	return 0;
}