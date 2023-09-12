#include <iostream>

using namespace std;

int main()
{
	unsigned short n1 = 5;
	unsigned short n2 = 10;
	unsigned short result;
	unsigned short n3 = 5e4;
	unsigned short n4 = 2e4;

    cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
    result = n1 - n2;
    cout << n1 << " - " << n2 << " = " << result << endl;
    result = n3 + n4;
    cout << n3 <<" + " << n4 << " = " << result << endl;
    return 0;
}
