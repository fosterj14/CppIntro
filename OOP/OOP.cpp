#include <iostream>
using namespace std;

int main() {
	//When an object is made as a pointer, it needs to be accessed by dereferencing it first
	//This can be done two ways:
		//Account *newAccount = new Account();
		//(*newAccount).balance;
		//or
		//newAccount -> balance;

	//When implementing a class method outside of the class declaration, you need to use className::methodName

	//Include guard: used in the header file, this will prevent the compiler from including it more than once if the ehader file is used in multiple .cpp files
		#ifndef _CLASSNAME_
		#define _CLASSNAME_
		class declaration
		#endif
	//#pragma once -- this works the same way, but is compiler specific, so not all compilers will have this

	//When making a class .cpp file from a header, use #"className.h"
		//This will also be included in the main.cpp file

	//Header files are used to separate the implementation from the specification (which is done in the class .cpp file)

	//Destructors (~className) are called when objects are deleted
		//Destructors are called when an object goes out of scope
		//Destructors are called in reverse order in which they were created

	//Better way for contructor initializations (initialization lists):
		Player::Player()
			:name{"None"}, health{0}, xp{0}{
		}
		//So now you don't need to do: name = "None", health = 0, and xp = 0. It also means that blank instances of those variables don't need to be created on initialization
	//This is done before the open bracket, so before the body is processed, as when the constructor is first called, it will already initialized the variable for it, making what happens in the
	//body redundant
		Player::Player(string name_val, int health_val, int xp_val)
			:name{name_val}, health{health_val}, xp{xp_val} {
		}

	//Delagating Constructors: this prevents the rewriting of similar constructors (only works with initialization lists)
		Player::Player(string name_val, int health_val, int xp_val)
			: name{name_val}, health{health_val}, xp{xp_val} {
		}
		
		Player::Player()
			: Player {"None", 0, 0} {
		}
		
		Player::Player(string name_val)
			: Player {name_val, 0, 0} {
		}

	//Default values are placed in the constructor and will be used unless told otherwise
		//Player(string name_val = "None", int health_val = 0, int xp_value = 0);
		//Values will default to those in the constructor unless specified otherwise with input parameters

	//When an object is returned by value, it is made using a copy constructor

	//Shallow Copy: Original and copy are both pointing to the same storage space. So when one object is destroyed, the pointer for one is released, but the other pointer is now pointing
		//to an empty memory space (the copy happens by making a pointer that points to the same place that the original does, so it is not a real copy, just a different name for the same thing)

	//Move Constructors:
		//R-value reference uses && (this is things like numbers, so you can have int &&num = 200 so it is a reference to a specific integer)
		//The move constructor moves the resource to a new pointer, so it doesn't make a deep copy like a copy constructor. The new pointer points to the resource and then the old pointer is set to null
		//The parameter for this won't be const since it needs to be set to null
		//This is used for times when an R-value is used but not being assigned, such as adding something to a vector

		//For this example, data is a pointer, so the parameter is the value that the pointer is pointing to (through R-value), then the data pointer for the new object is set to the resource that
		//the source was pointing at, and finally the source pointer is set to null (it is similar to a shallow copy which is 
		Move::Move(Move&& source)
			: data{ source.data } { // the new pointer "steals" the resource
			source.data = nullptr; // now the old pointer points to nothing
			}
		//Creates a temp R value by making a pointer that points to the passed value, the move constructor (with &&) is called next, not the copy constructor, which then takes the pointer for the 
		//temp and assigns it to the new pointer, then nulls out the source pointer

		//This is a keyword that refers to the address of the object currently being worked on

		//Objects can be const
		const Player villain{ "Villain",100,55 };
		//This can make some class methods difficult, so they will need to have the const qualifier in order to allow them to be used

		//static members: belong to the class, not individual objects
			//This would be something like keeping track of objects of that class that have been created
			static int num_objects = 0;
			static int get_num_objects();
			//Best place to increment this would be in a constructor, decrement would be in the destructor
			//Static functions only have access to static variables

		//structs: similar to classes but everything inside is public by default
			//Everything else is the same as a class
			//Good to use for passive objects
			//Methods aren't really needed since all the data is public
			//Really acts as a container for connected variables

		//friends: function or class that has access to private class members outside of its own class/function
			//Not symmetric, transitive, or inherited
			class Player {
				friend void display_player(Player& p); //this wouldn't need getters or setters at access and change things
				friend void Other_class::display_player(Player& p); //member from another class can access the private members of this class
				friend class Other_class; //entire class is a friend, so everything in Other_class can access private members from Player
			};
			//friends can help prevent the overuse of getters and setters (use only in situations where it makes sense to use, and use it sparingly)

}