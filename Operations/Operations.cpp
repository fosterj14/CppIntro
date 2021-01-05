#include <iostream>
using namespace std;

int main() {
	//type casting: static_cast<type>
	//(double)variable_name can be used, but it is the old version. static_type checks that what follows can be converted to a double before converting
	int num1{ 100 };
	int num2{ 8 };
	double average{ 0 };

	average = num1 / num2;
	cout << average << endl;

	average = static_cast<double>(num1) / num2;
	cout << average << endl;

	//std::boolalpha changes boolean outputs to be true or false instead of 1 or 0, noboolalpha changes it back

	bool test = true;
	cout << test << endl;
	cout << boolalpha; //changes to true/false
	cout << test << endl;

	//conditional operator - ternary
	//(bool) ? if_true : if_false
}