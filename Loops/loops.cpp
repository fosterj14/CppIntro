#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	// comma operator can be used in loops to initialize multiple variables
	for (int i = 0, j = 3; i < 5; i++, j++)
	{

	}

	vector <int> nums{ 10, 20, 30, 40, 50 };
	for (unsigned i = 0; i < nums.size(); i++){
		cout << nums.at(i) << endl;
	}

	//range based for loop
	int scores[]{ 100,90,97 };
	for (int score : scores) {
		cout << score << endl;
	}

	for (auto score : scores) { //auto is used to automatically pick the type 
		cout << score << endl;
	}

	vector<double> temps{ 87.2,77.1,80.0,72.5 };
	double average_temp {};
	double running_sum{};

	//iomanip allows for the manipulation of the IO stream
	cout << fixed << setprecision(1); //this sets the output to 1 decimal point
	cout << 8.5133456;
}