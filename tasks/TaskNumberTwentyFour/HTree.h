#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;


struct cpair {
	char value;
	string code;
	cpair(char _value, string _code) :value(_value), code(_code){};
};

struct hnode {
	bool isLeaf;
	char value;
	int priority;
	hnode *lson, *rson;
	hnode(char _value, int _priority, bool _isLeaf) :value(_value), priority(_priority), isLeaf(_isLeaf){};
};

class HTree {

	// Holds top node of tree
	hnode *root;

	// contains text
	vector<string> textContainer;
	
	// Contains pairs <char; number of entries>
	map<char, int> frequencyMap;

	// Additional space used to build tree
	vector<hnode> queue;

	// Stores codes
	vector<cpair> code_table;

	

	// Add char entry to frequency table with frequency = 1
	void addToMap(char a);
	// Builds frequencey table
	void fillFreqMap();
	// Fills queue with leaves
	void fillQueue();
	// Builds tree
	void buildTree();
	// Recursively find codes for nodes
	void getCode(hnode *cur, string code);

public:
	HTree(string filename);
	void printCodes();
};