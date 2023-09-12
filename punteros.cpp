#include <iostream>

using namespace std;

void cualquierfuncion(int* f)
{
	*f +=1;
}

int main()
{
	int ii=90;
	int is[] = {1,3,25,654,7,1};
	int** pis;
	int* p_ii;
	p_ii = &ii;
    cout << ii << endl;
    cout << p_ii << endl;
    cout << *p_ii << endl;
    cualquierfuncion(p_ii);
    cout << *p_ii << endl;
    return 0;
}
