#include "HTree.h"

// Constructor
HTree::HTree(string filename) {
	string line;
	ifstream in(filename);

	while (!in.eof()) {
		getline(in, line);
		textContainer.push_back(line);
	}

	buildTree();
	getCode(root, "");
}

void HTree::addToMap(char value) {
	if (frequencyMap.count(value) == 0)
		this->frequencyMap[value] = 1;
	else
		this->frequencyMap[value]++;
}

void HTree::fillFreqMap() {
	for (int i(0); i < textContainer.size(); i++) {
		for (int j(0); j < textContainer[i].size(); j++)
			addToMap(textContainer[i][j]);
	}
}

void HTree::fillQueue() {
	map<char, int>::iterator itr = frequencyMap.begin();
	for (; itr != frequencyMap.end(); itr++){
		this->queue.push_back(hnode(itr->first, itr->second, true));
	}
	// sorting queue in cending order
	sort(queue.begin(), queue.end(), [](hnode a, hnode b)->bool{
		return a.priority > b.priority; });
}

void HTree::buildTree() {
	this->fillFreqMap();
	this->fillQueue();

	while (queue.size() != 1) {
		hnode* first = new hnode(queue.back()); queue.pop_back();
		hnode* second = new hnode(queue.back()); queue.pop_back();

		// Create new parent node with priority equal to sum of priorities
		hnode parent('0', first->priority + second->priority, false);
		parent.lson = first; parent.rson = second;

		bool flag = true;
		//Insert node into corresponding place
		for (auto i = queue.begin(); !queue.empty() && i != queue.end(); i++) {
			if (i->priority <= parent.priority) {
				queue.insert(i, parent);
				flag = false;
				break;
			}
		}
		if (flag) queue.push_back(parent);
	}

	root = new hnode(queue.at(0));
}

void HTree::getCode(hnode* current, string code) {
	if (current->isLeaf) {
		if (current == root)
			code = "0";
		code_table.push_back(cpair(current->value, code));
		return;
	}

	getCode(current->lson, code + "0");
	getCode(current->rson, code + "1");
}

void HTree::printCodes() {
	for (int i = 0; i < code_table.size(); i++) {
		cout << "'" << code_table[i].value << "' " << "n: " << frequencyMap[code_table[i].value] << ":  " << code_table.at(i).code << endl;
	}
	cout << endl;
}
