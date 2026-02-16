#include <string>

extern "C" __declspec(dllexport)
int num_of_build(int num1, int num2, int num3) {
	return num1 + num2 + num3;
}