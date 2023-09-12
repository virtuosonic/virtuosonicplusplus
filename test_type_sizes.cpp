/**********************************************
  * Name:     test_type_sizes.cpp
  * Created:   19-Abr-2011
  * Author:    Gabriel Espinoza
	<virtuosonic@users.sourceforge.net>
  * License:     MIT
  ********************************************/
#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <climits>
#include <cstdint>
#include <cxxabi.h>
#include <memory>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setiosflags;
using std::ios;

const unsigned bytesize = CHAR_BIT;

std::string demangle(const char* mangled)
{
      int status;
      std::unique_ptr<char[], void (*)(void*)> result(
        abi::__cxa_demangle(mangled, 0, 0, &status), std::free);
      return result.get() ? std::string(result.get()) : "error occurred";
}



template <class T> void print_size()
{
	cout << "  " << setiosflags(ios::left)
		<< setw(12)
		<< demangle(typeid(T).name())
		<< resetiosflags(ios::left)
		<< setw(3)<< sizeof (T) * bytesize
		<<" bits" << endl;
}

int main()
{
	cout << "types size:" << endl;
	print_size<bool>();
	print_size<char>();
	print_size<wchar_t>();
	print_size<short>();
	print_size<int>();
	print_size<long>();
	print_size<long long>();
	print_size<int8_t>();
	print_size<int16_t>();
	print_size<int32_t>();
	print_size<uint8_t>();
	print_size<uint16_t>();
	print_size<uint32_t>();
	size_t LLSIZE = sizeof(long long);
	#if ( LLSIZE > 8)
	print_size<__int128>();
	#endif // sizeof
	print_size<time_t>();
	print_size<size_t>();
	print_size<float>();
	print_size<double>();
	print_size<long double>();
	cin.get();
}
