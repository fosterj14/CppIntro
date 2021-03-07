#include <iostream>
#include <vector>
#include <string>
using namespace std;

void double_data(int* int_ptr);

int main() {
	int test = 10;
	//pointers are variables that point to a memory address, declared using *
	//initialize before using
	int *int_ptr{};
	double* double_ptr{ nullptr }; //initializes to point nowhere
	char *char_ptr{ nullptr };
	string* str_ptr{ nullptr };

	int* p = &test; //points to the address that holds the variable test
	cout << "value of p is: " << p << endl;
	cout << "size of p is: " << sizeof(p) << endl;
	p = nullptr;
	cout << "value of p is now: " << p << endl;
	//typed pointers can only hold addresses of the same type

	//dereferencing a pointer gets what the pointer is pointing to
	//* is used to dereference
	int score{ 100 }; //sets score to 100
	int* score_ptr{ &score }; //creates a pointer that points to the address of score
	cout << *score_ptr << endl; //prints out the what is stored at the address the pointer is pointing to
	*score_ptr = 200; //changes what is stored at the address the pointer is pointing to
	cout << *score_ptr << endl;
	cout << score << endl; //the value of score was changed using a pointer
	score_ptr = &test; //score_ptr now points to the address of test
	cout << *score_ptr << endl;
	*score_ptr = 15; //changes what is stored at the address
	cout << test << endl;

	vector<string> name{ "John", "Matthew", "Foster" };
	vector<string> *vector_ptr{ nullptr };
	vector_ptr = &name;
	for (size_t i = 0; i < name.size(); i++)
	{
		cout << (*vector_ptr).at(i) << endl; //*vector_ptr dereferences to the vector that it points to, so this becomes name.at(i)
	}

	//Arrays and pointers
		//an array is just a pointer that points to the first value in a specified memory block
	int scores[]{ 100, 95, 89 };
	int* scores_ptr{ scores };
	cout << scores[0] << endl; //100
	cout << scores_ptr[0] << endl; //100
	cout << (scores_ptr + 1) << endl; //will give memory address of second array element
	cout << *(scores_ptr + 1) << endl; //will give the value of the second array element

	//Comparing pointers
		//when comparing, it compares the address that the pointers are pointing to, not the value of what is there(pointer_name1 == pointer_name2)
		//to compare the values, dereference the pointer first (*pointer_name1 == *pointer_name2)
	
	//Constants and pointers
		// const int *score_ptr {&high_score}; means that the value of high_score cannot be changed with the pointer
		// int *const score_ptr [&high_score}; means the pointer is constant and cannot be changed to point at something else
		// const int *const score_ptr [&high_score}; unchangeable constant pointing to an unchangeable value

	//Passing pointers
	int value = 10;
	cout << value << endl;
	double_data(&value); //parameter takes the address of value
	cout << value << endl;

	//Dereference to get to what the pointer is pointing to

	//A sentinel is used to tell a loop where to stop. For this, you would put the sentinal value at the end of the array, then when you loop through it after passing
	//it with a pointer, when the pointer points to the sentinal, it will know that is the end. This is a way to avoid needing to pass the size of the array
		// while(*array != sentinel) {} which means while the pointer is not pointing at something that contains the sentinel value

	//Don't return pointers to a local variable. When a function is called, the pointer is pointing to a part of the stack activation area, if that area is rewritten using the pointer, it will
	//cause problems

	//Dangling pointer: pointing to a memory address that is no longer valid (pointing to a local variable, or two pointers point at the same place and only one frees up the space

	//Memory Leak: a pointer is lost that was pointing to some allocated memory. This memory is lost and you won't be able to get back to it to clear it

	//References can be assigned
		//int num {100};
		//int &ref {num}; (gives 100)
	//You can use references to change the values of vectors/arrays when using a for each loop (usually it's just done as a copy)

	//L-values and R-values
		//L-values: object that occupies memory and is addressable (used on left hand side of assignment statement)
		//100 is not an L-value, (1000 + 20) is not an L-value
		//R-values: whatever isn't an L-value (such as in the line above). They are not addressable
		//R-values can be assigned to an L-value
		//When making a reference, it needs to be assigned to an L-value
		//int &ref1 = num; is good
		//int &ref2 = 100; is bad

	//References cannot be null
	//You can pass functions into functions when the object it is pointing to is expensive (such as a huge complex object so it saves resources by not copying it, but make it constant if it doesn't
	//need to change!)
		
}

void double_data(int* int_ptr) { //the pointer that is created here points to the address it was given when called
	*int_ptr *= 2;
}