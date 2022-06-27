
/*
// количество циклов  
int _tmain(int argc, _TCHAR* argv[])
{
	int cycles = 1000000;
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;
	setlocale(LC_ALL, "rus");
	auxil::start();                          // старт генерации
	for (int i = 0; i < 10; i++)
	{
		t1 = clock();                            // фиксация времени 
		for (int i = 0; i < cycles; i++)
		{

			av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
			av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
		}
		t2 = clock();                            // фиксация времени 
		std::cout << std::endl << "количество циклов:         " << cycles;
		std::cout << std::endl << "среднее значение (int):    " << av1 / cycles;
		std::cout << std::endl << "среднее значение (double): " << av2 / cycles;
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "продолжительность (сек):   "
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << "\n\n";
		cycles += 1000000;
	}
	system("pause");
	return 0;
}*/
#include "Auxil.h"    
#include <tchar.h>
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <locale>
#include <map>
#include <cmath>
#include <random>
int main(int argc, _TCHAR* argv[])
{
	const int StartCycle = 100000;
	int CYCLE = StartCycle;
	double  av1 = 0, av2 = 0, rand = 0;
	int m = 5, k = 2;
	int ranMin = -100, ranMax = 100;
	clock_t  t1 = 0, t2 = 0;
	setlocale(LC_ALL, "rus");
	auxil::start();                          // старт генерации 

	std::map<int, int> hist{};

	int allCycles = 0;
	for (int i = 0; i < m; i++)
	{
		allCycles += StartCycle * pow(k, i);
	}

	double parts = log2(allCycles);


	int diap = ranMax - ranMin;
	double part = diap / parts;

	for (int i = 0; i < m; i++)
	{
		t1 = clock();                            // фиксация времени 
		for (int i = 0; i < CYCLE; i++)
		{
			rand = (double)auxil::iget(ranMin, ranMax);
			av1 += rand; // сумма случайных чисел 
			av2 += auxil::dget(ranMin, ranMax);         // сумма случайных чисел 
			++hist[floor(rand / part)];
		}
		t2 = clock();                            // фиксация времени 


		std::cout << std::endl << "количество циклов:         " << CYCLE;
		std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
		std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "                  (сек):   "
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;


		CYCLE *= k;
	}

	for (auto p : hist)
	{
		std::cout << p.first * (int)part << " " << p.second << '\n';
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
