/****************************
Nombre:	redondeo.cpp
Fecha:	01-01-2018
Autor:	Gabriel Espinoza
Desc:	Redondea a .2
****************************/

#include <iostream>
#include <cmath>

using namespace std;

const char* mensaje = "escribe el numero a redondear\n";

int main()
{
    double n;
    cout << mensaje;
    while(true)
	{
		cin >> n;
		n = nearbyint(n * 5) *.2 ;
		cout << n << endl;
	}
}
