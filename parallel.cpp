/**************************************
Nombre:	parallel.cpp
Autor:	Gabriel Espinoza
Fecha:	12-Jun-2018
License:	MIT
Desc:	hace una comparacion del algoritmo sort
	estandar y su version paralela
**************************************/

#include <vector>
#include <parallel/algorithm>
#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std;

int main()
{
	std::vector<int> vector1(1e7);
	auto start_t = steady_clock::now();
	std::sort(vector1.begin(), vector1.end());
	auto end_t = steady_clock::now();
	cout << "std::sort " <<duration_cast<milliseconds>(end_t - start_t).count() << " milliseconds\n";
	start_t = steady_clock::now();
	__gnu_parallel::sort(vector1.begin(), vector1.end());
	end_t = steady_clock::now();
	cout << "__gnu_parallel::sort " <<duration_cast<milliseconds>(end_t - start_t).count() << " milliseconds\n";

	return 0;
}
