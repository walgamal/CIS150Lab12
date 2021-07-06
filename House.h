#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <fstream>

class House {
private:
	string addy;
	int sqft;
	int numBeds;
	float numBaths;
public:
	House(string a, int b = 0, int c = 0, float d = 0.0);
	House() { addy = "None", sqft = 0, numBeds = 0, numBaths = 0.0; };
	~House();
	void GetAll(string&, int&, int&, float&);
	void SetSqft(int squareFeet);
	int GetSqft();
};

const int NUM_HOUSES = 11;
extern House houseList[NUM_HOUSES - 1];
