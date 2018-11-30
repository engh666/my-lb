#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class coin_placement {
	
	// Task data
	int faces;			// N
	int tails;			// M
	int needFaces;		// L
	int step;			// S
	int numberOfSteps;	// K

	// Spots for coins
	vector<bool> places;
	vector<bool> flips;

	void fill_flips(int faces, int tails);
	void fill_no_flips(int faces, int tails);
	void place_coins(const int &faces_on_flips);

	int count_flips() const; // Calculates number of 'true' values in 'flips' vector
	void simulateFlips();	 // Simulates game process

	int makeMoreFaces(const int &balance);
	int makeLessFaces(const int &balance);

	void printTask();
public:
	coin_placement(const string &input);
	~coin_placement(){};
	
	void printPlacement();

	void calculate();
};