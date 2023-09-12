/*********************************
*Nombre: Memoria.cpp
*Creado:12 - Junio - 2016
*Autor Gabriel Espinoza
	<virtuosonic@users.sourceforge.net>
*Licencia:     MIT
*agrega elementos a un vector, prueba
*para saturar memoria
*/
#include <climits>
#include <vector>

int main()
{
	std::vector<unsigned long> v;
	for(unsigned long i : ULLONG_MAX)
		v.push_back(i);
    return 0;
}
