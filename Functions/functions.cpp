#include <iostream>
using namespace std;

void function(int); //this is a prototype, which allows the function to be used

int main() {
	//C++ needs to have a prototype for each function before it is used. the prototype does not need to know the implementation, just the function header and the types of parameters it needs
	function(5);
}

void function(int x) {
	cout << "function " << x << endl;
}