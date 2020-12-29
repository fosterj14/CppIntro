#include <iostream>;
using namespace std;

int main() {
	int num1;
	int num2;

	cout << "Enter 2 integers separated with a space";
	cin >> num1 >> num2; // inputs are stored in a buffer before being sent through. here, num1 and num2 are both stored in the buffer before being assigned. then the program goes through the
	// buffer to assign values to num1 and num2. when it reaches a space, it registers that it has reached the end of the input and moves on to what is left in the buffer. the buffer is all based on
	// the logic of what is in the buffer and what it is seeing.
	// if you want an int and a double and just type 10.5, the int will be 10 and the double will be .5
	cout << "You entered " << num1 << " and " << num2;
}