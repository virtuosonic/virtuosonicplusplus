/*********************************
*Pruebas de presicion de fracciones
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long double n1,r;
	r = n1 = 1;

	for (unsigned long i=0;i < 100;i++)
	{
		r += (n1/2);
		n1 = n1/2;
		cout << setprecision(1000) << r << endl;
	}
    cout << r << endl;
    return 0;
}
