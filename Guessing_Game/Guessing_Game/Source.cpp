#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include "Header.h"
#include "Functions.h"
#include "Constructor.h"
using namespace std;

int main()
{
	
	ifstream file;
	file.open("Questions.txt");
	string temp;
	vector<string> construct;
	while (file.good())
	{
		getline(file, temp);
		construct.push_back(temp);
	}


	Node* StartNode = new Node;
	builder(construct, 0, StartNode);

	Node* start = StartNode->right;
	bool guessed = false;
	while (!guessed)
	{
		Instructions();
		run(start, guessed);
	}

	file.close();
	ofstream endFile;
	endFile.open("heap1.txt");
	int counter = 0;
	int size = pow(2, maxDepth(start));
	vector<string> result{};
	result.resize(size);
	Deconstructor(StartNode->right, 0, result);
	while (counter < result.size())
	{
		endFile << result[counter] << endl;
		counter++;
	}

	return 0;
}