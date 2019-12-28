#ifndef CATEGORIZER_HPP
#define CATEGORIZER_HPP

#include <iostream>
#include <fstream>
#include<conio.h>

//fstream* New();
//unsigned int* NewUI(unsigned int &len);
void ProcessFile(std::fstream* file, unsigned int *histogram, unsigned int &len);
int ExtractNum(std::fstream* file, const char delimiter);
void BuildHistogram(std::fstream* file,
                    unsigned int* histogram,
                    unsigned int &len,
                    int &width,
                    int &height);
void PrintHistogram(unsigned int* histogram,
                    unsigned int &len,
                    int &width,
                    int &height);
#endif
