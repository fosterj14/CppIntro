#include <iostream>
#include <vector>
using namespace std;

//vectors
int main() {
	vector <char> vowels(5);
	vector <char> vowels2{ 'a', 'e', 'i', 'o', 'u' };
	cout << vowels2[0] << endl;
	cout << vowels2.at(1) << endl;
	vowels.at(0) = 'a';
	vowels.at(1) = 'e';
	cout << vowels.at(0) << endl << vowels.at(1) << endl;
	vowels2.push_back('y'); //this is used to add an element at the back of the vector (arrayList.add)
	cout << vowels2.size() << endl;
	cout << vowels2.at(5) << endl;

	vector <vector<int>> movieRatings{
		{1,2,3,4},
		{1,2,4,4},
		{1,3,4,5}
	};

	cout << "\nRating for reviewer #1: " << endl;
	cout << movieRatings[0][0] << endl;
	cout << movieRatings[0][1] << endl;
	cout << movieRatings[0][2] << endl;
	cout << movieRatings[0][3] << endl;

	cout << "\nWith different format: " << endl;
	cout << movieRatings.at(0).at(0) << endl;
	cout << movieRatings.at(0).at(1) << endl;
	cout << movieRatings.at(0).at(2) << endl;
	cout << movieRatings.at(0).at(3) << endl;
}