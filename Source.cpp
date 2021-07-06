/*

 *Author: Wasim Algamal

 *Creation Date: 12/2019
 
 *Purpose: Lab 12 - Constructors and Destructors in Classes

*/

#include "House.h"

House houseList[NUM_HOUSES - 1];

void House::SetSqft(int squareFeet) {


	if (squareFeet % 2 == 0)
		houseList[squareFeet].sqft = squareFeet + 26;
	else
		houseList[squareFeet].sqft = squareFeet * 7;


	sqft = houseList[squareFeet].sqft;
}

int House::GetSqft() {
	return sqft;
}

void House::GetAll(string& a, int& b, int& c, float& d) {
	a = addy;
	b = sqft;
	c = numBeds;
	d = numBaths;
}

House::~House() {
	cout << "Destroying house with square footage: " << sqft << endl;
}

House::House(string a, int b, int c, float d) {
	addy = a;
	sqft = b;
	numBeds = c;
	numBaths = d;
}

int main() {
	string a;
	int b;
	int c;
	float d;
	House myHouse1;
	House myHouse2{ "House2", 80000 };
	House myHouse3{ "House3", 100000, 4, 3.5 };
	ofstream houseFile;

	houseFile.open("houseOut.txt");

	myHouse1.GetAll(a, b, c, d);

	houseFile << "Street Address: " << a << endl <<
		"Square Footage: " << b << endl <<
		"Number of Bedrooms: " << c << endl <<
		"Number of Bathrooms: " << d << endl << endl;

	myHouse2.GetAll(a, b, c, d);

	houseFile << "Street Address: " << a << endl <<
		"Square Footage: " << b << endl <<
		"Number of Bedrooms: " << c << endl <<
		"Number of Bathrooms: " << d << endl << endl;

	myHouse3.GetAll(a, b, c, d);

	houseFile << "Street Address: " << a << endl <<
		"Square Footage: " << b << endl <<
		"Number of Bedrooms: " << c << endl <<
		"Number of Bathrooms: " << d << endl << endl;

	houseFile <<
		"~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	for (int x = 1; x < NUM_HOUSES; x++) {
		houseList[x - 1].GetAll(a, b, c, d);

		houseList[x - 1].SetSqft(x);

		houseFile << "House " << x << endl <<
			"Street Address: " << a << endl <<
			"Square Footage: " << houseList[x - 1].GetSqft() << endl <<
			"Number of Bedrooms: " << c << endl <<
			"Number of Bathrooms: " << d << endl << endl;
	}

	houseFile <<
		"~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	houseFile << "Houses Greater than 31 Sqft:" << endl;

	for (int x = 1; x < NUM_HOUSES; x++) {

		if (houseList[x - 1].GetSqft() > 31) {
			houseFile << "House: " << x << endl;
		}

	}

	system("pause");
	return 0;
}
