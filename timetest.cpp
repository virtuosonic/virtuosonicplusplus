#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	time_t t = time(nullptr);
	cout << "ctime: "<< ctime(&t)<< endl;
	cout << "gmtime: " << gmtime(&t)<< endl;
	cout << "localtime: " << localtime(&t)<< endl;
	char fecha[100] = "";
	strftime(fecha,sizeof(fecha),"%Y-%m-%d_%H%M",localtime(&t));
	cout << "strftime: " << fecha << endl;
	long long maxtime_t = sizeof(time_t) * CHAR_BIT;
	t = pow(2,maxtime_t - 1 ) -1;
	cout << "max ctime: "<< ctime(&t) << endl;
	cout << "gmtime: " << gmtime(&t)<< endl;
	cout << "localtime: " << localtime(&t)<< endl;
    return 0;
}
