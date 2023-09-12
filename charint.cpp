#include <iostream>

using namespace std;

int main()
{
	string abc = {60,61,62,'\0'};
    cout << abc << endl;
	abc = {'\u003c','\u003d','\u003e','\0'};
    cout << abc << endl;
    return 0;
}
