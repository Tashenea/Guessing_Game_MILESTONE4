#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "Header.h"
#include "Constructor.h"
#include "Functions.h"
using namespace std;

string remove(string& str)
{
	string str1 = str;
	str1.erase(0, 1);
	return str1;
}

Node* builder(vector<string> file, int i, Node* tree)
{
	if (i < file.size())
	{
		if (file[i] == "")
		{
			return tree;
		}
		else if (i % 2 == 1)
		{
			Node* root = new Node;
			root->data = file[i];
			tree->left = root;

			builder(file, (2 * i + 1), root);
			builder(file, (2 * i + 2), root);

			return tree;
		}
		else if (i % 2 == 0)
		{
			Node* root = new Node;
			root->data = file[i];
			tree->right = root;

			builder(file, (2 * i + 1), root);
			builder(file, (2 * i + 2), root);

			return tree;
		}
	}
	return tree;

}