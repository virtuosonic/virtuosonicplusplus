/*********************************
*pruebas de chrono y string
*compilar usando -std=c++11
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

int main()
{

	std::chrono::steady_clock::duration dt;
	dt = std::chrono::steady_clock::duration(atoi("1"));

	cout << dt.count();
    string str("Hello world!");
    for_each(str.begin(),str.end(),[](char s){cout << s;});
    return 0;
}
