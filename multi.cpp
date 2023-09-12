/**
Nombre: multi.cpp
Creado:14 - Julio - 2016
Autor Gabriel Espinoza
	<virtuosonic@users.sourceforge.net>
Licencia:     MIT
*/
#include <thread>
#include <climits>
#include <vector>

void h()
{
	std::vector<unsigned long> v;
	for(unsigned long i =0;i < ULLONG_MAX; i++)
		v.push_back(i);
}

int main()
{
	std::thread first(h);
	std::thread second(h);
	first.join();
	second.join();
    return 0;
}
