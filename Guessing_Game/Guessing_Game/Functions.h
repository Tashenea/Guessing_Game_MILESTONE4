#pragma once
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Header.h"

using namespace std;
void allocate(vector<string> vector, int index)
{
	while (index > vector.size())
	{
		vector.push_back("");
	}
}

void set_(string answer, Node* root)
{
	Node* tree = new Node;
	tree->data = root->data;
	root->left = tree;
	Node* Answer = new Node;
	Answer->data = "Is this your animal " + answer + "?";
	root->right = Answer;
	cout << "Write a question that only describes the " + answer + " that will make this answer be yes" << endl;
	string Question;
	getline(cin, Question);
	root->data = Question;
}

void run(Node* root, bool& guessed)
{
	cout << root->data << endl;
	string answer;
	getline(cin, answer);
	if (root->right != nullptr || root->left != nullptr)
	{
		if (answer == "yes")
		{
			run(root->right, guessed);
		}
		else
		{
			run(root->left, guessed);
		}
	}
	else
	{
		if (answer == "yes")
		{
			cout << "Congradulations, you lost  " << endl;
			guessed = true;
		}
		else
		{
			cout << "What is the animal?" << endl;
			string animal;
			getline(cin, animal);
			set_(animal, root);

		}
	}
}

int maxSize(int depth)
{
	int n = 0;
	int counter = 0;
	while (counter < depth)
	{
		n += (counter + 1);
		counter++;
	}
	return n;
}

int maxDepth(Node* front)
{
	if (front == NULL)
	{
		return 0;
	}
	else
	{

		int leftDepth = maxDepth(front->left);
		int rightDepth = maxDepth(front->right);


		if (leftDepth > rightDepth)
		{
			return(leftDepth + 1);
		}
		else
		{
			return(rightDepth + 1);
		}
	}
}

void allocate(vector<string>& vector, int size)
{
	while (vector.size() < size)
	{
		vector.push_back("");
	}
}

void Deconstructor(Node* start, int i, vector<string>& result)
{
	if (result.size() > i)
	{
		if (start == NULL)
		{
			result[i] = "";

		}
		else
		{
			result[i] = start->data;
			Deconstructor(start->left, (2 * i + 1), result);
			Deconstructor(start->right, (2 * i + 2), result);
		}
	}
}