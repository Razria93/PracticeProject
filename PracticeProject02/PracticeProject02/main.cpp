#include <iostream>

#include "CustomVector.h"

int main()
{
	CustomVector<bool> ver_bool;
	ver_bool.PrintData();

	CustomVector<char> ver_char;
	ver_char.PrintData();

	CustomVector<int> ver_int;
	ver_int.PrintData();

	CustomVector<float> ver_float;
	ver_float.PrintData();

	CustomVector<long long> ver_longlong;
	ver_longlong.PrintData();

	return 0;
}