#include "categorizer.hpp"

using namespace std;

template<typename T>
T* Template()
{
	return T;
}
fstream* New()
{
	return new fstream;
}
unsigned int* NewUI(unsigned int &len) 
{
	return (new unsigned int[len]);
}
int ExtractNum(fstream *file, const char delimiter)
{
	file =New();
    int *alphabet;
	alphabet = new int[256];
    char sym;
    int res = 0;
    unsigned int digit_b = static_cast<unsigned int>(file->tellg());
    do
    {
        file->read(&sym, 1);
    }while(sym != delimiter);
    unsigned int digit_e = static_cast<unsigned int>(file->tellg()) - 2;
    int j = 0;
    for(int d = '0'; d <= '9'; d++, j++) alphabet[d] = j;
    int c = 1;
    for(j = digit_e; j >= digit_b; j--, c *= 10)
    {
        file->seekg(j);
        file->read(&sym, 1);
        res += alphabet[sym] * c;
    }
    file->seekg(digit_e + 2);
	delete file;
	delete [] alphabet;
    return res;
}

void BuildHistogram(std::fstream* file,
                    unsigned int* histogram,
                    unsigned int &len,
                    int &width,
                    int &height)
{
	file = New();
	histogram = NewUI(len);
    char sym;
    for(unsigned int d = 0; d < len; ++d) histogram[d] = 0;
    file->seekg(static_cast<unsigned int>(file->tellg()) + 4);
    for(unsigned int d = 0; d < (width * height); ++d)
    {
        if(file->eof())break;
        file->read(&sym, 1);
        histogram[static_cast<unsigned char>(sym)] += 1;
    }
    cout << endl;
    for(int j = 0; j < 256; j++)
    {
        cout << "[" << j << "] ";
        for(unsigned int c = 0; c < histogram[j]; c++)
            cout << "|";
        cout << endl;
    }
	delete file;
	delete[] histogram;
}

void PrintHistogram(unsigned int *histogram,
                    unsigned int &len,
                    int &width,
                    int &height)
{
	histogram = NewUI(len);
    ofstream* out = new ofstream("histogram.txt");
    *out << "Building histogram for graphic file" << endl;
    *out << "Width: " << width << "\t Height: " << height << endl;
    for(unsigned int j = 0; j < len; j++)
    {
        *out << "[" << j << "] ";
        for(unsigned int c = 0; c < histogram[j]; c++)
            *out << "|";
        *out << endl;
    }
    *out << "End of file " << endl << endl;
    out->close();
    delete out;
	delete[] histogram;
}

void ProcessFile(std::fstream *file, unsigned int* histogram, unsigned int &len)
{
	file = New();
	histogram = NewUI(len);
    int width, height;
    width = 0;
    height = 0;
    char PGM_hdr1[2];
    file->read(PGM_hdr1, 2);
    if((PGM_hdr1[0] != 0x50)||(PGM_hdr1[1] != 0x35)) return;
    cout << "PGM header detected" << endl;
    file->seekg(static_cast<unsigned int>(file->tellg()) + 1);
    width = ExtractNum(file, 0x20);
    cout << "Width: " << width <<  endl;
    height = ExtractNum(file, 0x0A);
    cout << "Height: " << width <<  endl;
    BuildHistogram(file, histogram, len, width, height);
    PrintHistogram(histogram, len, width, height);
	delete[] histogram;
	delete file;
}
/*
ѕереработать исходный текст программы - анализатора €ркостей из уровн€ 1, использу€ адреса, ссылки и указатели:
+ќбобщить однотипные операции;
+»збавитьс€ от копировани€ кода;
+ƒинамически выделить пам€ть под им€ с типом fstream и корректно освободить пам€ть после окончани€ записи файлов.
*/
int main(int argc, char** args)
{
	unsigned int N = 256;
	fstream *f = New();
    unsigned int *histogram = new unsigned int[N];
    if(argc == 1)
    {
        cout << "Please specify input file(s)!" << endl;
        return 1;
    }
    for(int i = 1; i < argc; i++)
    {
        f->open(args[i], ios::binary|ios::in);
        if(!f->is_open())
        {
            cout << "File: " << args[i] << " is not accessible!" << endl;
            continue;
        }
        cout << "File " << args[i] << " opened" << endl;
        ProcessFile(f, histogram, N);
        f->close();
    }
	delete f;
	delete [] histogram;
	system("pause");
    return 0;
}