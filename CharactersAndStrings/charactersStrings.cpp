#include <iostream>
#include <cctype> //functions for testing characters and converting character cases
#include <cstring> //functions for c-style strings
#include <cstdlib> //functions to convert c-style strings to other types
#include <string> //for C++ strings
using namespace std;

int main() {
	//C-style Strings
	char c{ 'a' };
	//functions in cctype
	isalpha(c); //true if c is a letter
	isalnum(c); //true if c is a letter or digit
	isdigit(c); //true if c is a digit
	islower(c); //true if c is a lowercase letter
	isprint(c); //true if c is a printable character
	ispunct(c); //true if c is a punctuation character
	isupper(c); //true if c is an uppercase letter
	isspace(c); //true if c is whitespace
	tolower(c); //returns lowercase of c
	toupper(c); //returns uppercase of c

	//strings terminate in null (/0) which indicates the end of the string
	char my_string[8];
	//my_string = "string"; causes compile error, can't assign a string literal to an array, similar to assigning 10 to 12, both are fixed locations
	strcpy(my_string, "string"); //this puts a string into the char array
	strcat(my_string, " added"); //concatenates
	strcmp(my_string, "not my string"); //compares

	strlen(my_string); //gives the length of the string. it is of type size_t, which is basically an unsigned int, but the data it can hold is based on your system, so it will usually fit all values

	//cin.getline(string_name, 10) . provides the name of the c-style string that will hold the input and then a limit to the number of characters that it will read
	//strlen(string_name) returns the length of the string

	//C++ Strings
	string str{ "String" };
	string str1{ "String", 3 }; //gives "Str"
	string str2{ str1, 0,2 }; //gives "St". 0 is the starting index and 2 is the length
	string str3(3, 'X'); //gives "XXX"
	//string_name[] and string_name.at() can be used to display characters in the string
	//substr() method gives a substring
	str.substr(1, 3); //start index at 1, return 3 characters
	//find() provides the starting index for the parameter in a string
	string str4{ "This is a test" };
	str4.find("is"); //this will return 2, since "is" is a portion of this
	//erase() removes characters from a starting index to a specified length
	//clear() empties a string
	//string_name.length() returns the size of the string
	//string_name += " more" concatenates
	string s1;
	getline(cin, s1); //this will read the entire line until \n (enter)
	cout << s1 << endl;
	getline(cin, s1, 'x'); //this will stop capturing the string at the specified character
	//when using + to concatenate strings, at least 1 C++ string object needs to be involved. strcat needs to be used for putting C-style strings together (e.g. "hello" + "there" won't work)
	size_t position = s1.find("word");
	if (position != string::npos) { //npos means no position, so if "word" is found in s1, then it goes to the first statement. if the word is not found, the position = no position
		cout << "found " << "word" << " at position: " << position << endl;
	}
	else {
		cout << "Sorry, " << "word" << " not found" << endl;
	}
}