#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	ofstream of("imbue_test.txt");
	if (argc > 1)
	{
		of.imbue(locale(argv[1]));
	}
	else
	{
		try{
			of.imbue(locale("es_ES.UTF8"));
		}
		catch(runtime_error& e){
			cout<< e.what() << "\n";
		}
	}

	of << 3.141592;
	of << endl;
	of.imbue(locale("C"));
	of << 3.141592;

    return 0;
}
