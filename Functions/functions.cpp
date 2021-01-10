#include <iostream>
#include <array>
using namespace std;

void function(int); //this is a prototype, which allows the function to be used
double calc_cost(double base_cost, double tax_rate = .06); //tax_rate is a default, it needs to come at the tail end
void print_array(int[], size_t);

int main() {
	//C++ needs to have a prototype for each function before it is used. the prototype does not need to know the implementation, just the function header and the types of parameters it needs
	function(5);
	//default arguments can be added to the prototype. these defualts can be replaced during function call
	cout << calc_cost(10); //uses default of .06
	cout << calc_cost(10, .08); //replaces default with .08
	cout << endl;

	int arr [5] = { 1,2,3,4,5 };
	cout << "arr size with size(arr): " << size(arr) << endl; //also gets array size, but unsure where the function is from
	int arrSize = sizeof(arr) / sizeof(arr[0]); //gets array size. sizeof gives the number of bytes the array occupies. with 5 integers, it takes up 20 bytes. sizeof(arr[0]) will give the bytes of a 
	// single element in the array, for an int, that is 4. so this equates to 20/4 which is 5
	cout << "arr size with formula: " << arrSize << endl;
	print_array(arr, arrSize);

	//pass by reference using &
	//for a vector, you can protect data by making the reference a const

	//static variables: declared locally, retains its value between calls, so if a static variable is increased during one function call, it will save that increased value for the next call
		// start function
		// static int num = 5000;
		// num += 1000;
		// end of function
	// next time the function is called, num will be 6000 and increased to 7000

	//global variables: usually constants, declared outside of a function or class

	//inline functions allow for assembly code to avoid call overhead, but this is usually controlled by the compiler automatically

	//recursion
}

void function(int x) {
	cout << "function " << x << endl;
}

double calc_cost(double base_cost, double tax_rate) {
	return 0;
}

void print_array(int arr[], size_t size) { //when an array is passed into a function, it only knows the memory location of the first value, so a size needs to be given
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}