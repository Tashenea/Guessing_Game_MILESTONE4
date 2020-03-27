
#pragma once
#include <iostream>
#include <string>


using namespace std;

struct BinaryTreeNode
{
	string data;
	BinaryTreeNode* leftChild = NULL;
	BinaryTreeNode* rightChild = NULL;
}; 

class BinaryTree
{
private:
	BinaryTreeNode* root = new BinaryTreeNode();


public:

	BinaryTree()
	{
		string user_input;  //problem 
		begin(root);
	}
	void begin(BinaryTreeNode* tree);
	void win();
	void lose(BinaryTreeNode* tree, BinaryTreeNode* tree_2);
	
};    
void BinaryTree::begin(BinaryTreeNode* tree)
{

	string input_1, input_2, input_3; 
	if (input_1 == "No" || input_1 == "no")
	{
		if (tree != NULL)
		{
			cout << tree->data << " ";
			getline(cin, input_1);

		}

		if (tree->rightChild != NULL)
		{
			if (tree->rightChild->leftChild == NULL && tree->rightChild->rightChild == NULL)
			{
				cout << "Is it " << tree->rightChild->data << " ? ";
				getline(cin, input_1);
				if (input_1 == "Yes" || input_1 == "yes")
				{
					win();
				}
				else
				{
					lose(tree, tree->rightChild);
				}
			}
			else
			{
				begin(tree->rightChild);
			}

		}
		else
		{
			lose(tree->rightChild, tree);
		}
	}

	if (tree->leftChild != NULL)                 
	{
		if (tree->leftChild->leftChild != NULL)
		{
			begin(tree->leftChild);
		}
		else
		{
			cout << "Is it " << tree->leftChild->data << " ? ";
			getline(cin, input_2);
			if (input_2 == "Yes" || input_2 == "yes")
			{
				win();
			}
			else
			{
				lose(tree, tree->leftChild);
			}
		}
	}
	else
	{
		lose(tree->leftChild, tree);
	}

}
void BinaryTree::win()
{
	string input;
	cout << " I win!";
	cout << "Would you like to play again? please type yes or no";
	getline(cin, input);
	if (input == "Yes" || "yes")
	{
		cout << endl;
		begin(root);
	}
	else
	{
		cout << "Thank you for playing :)";
	}

}
void BinaryTree::lose(BinaryTreeNode* tree, BinaryTreeNode* tree_2)
{
	string question;
	string answer;
	string input_a;
	string input_b;



	BinaryTreeNode* Node1 = new BinaryTreeNode;
	BinaryTreeNode* Node2 = new BinaryTreeNode;
	if (root == NULL)
	{
		cout << "Something I should know???" << endl;
		cout << "Think and enter a place, person, or an object! ";
		getline(cin, answer);

	}
	else
	{
		cout << "I can not think of anything that matches";
		cout << "Please tell me";
		getline(cin, answer);

	}
	if (tree != NULL)
	{
		cout << "Write a question that only describes a/an " << answer << "from " << tree_2->leftChild->data << " .";

	}
	else if (root != NULL)
	{
		if (tree_2->leftChild != NULL)
		{
			if (tree_2->leftChild->leftChild == NULL)
			{
				cout << "Write a question that only describes a/an " << answer << "from " << tree_2->leftChild->data << " .";

			}
		}
	}
	else
	{
		cout << " Provide a question that helps me figure out what i am looking for:";
	}
	cout << "Enter a Question";
	getline(cin, question);
	cout << "If the answer were " << answer << "the answer would be? ";
	getline(cin, input_a);

	if (tree != NULL)
	{
		Node1->data = question;
		if (input_a == "Yes " || input_a == "yes")
		{
			Node1->rightChild = tree_2;
			Node1->leftChild = Node2;
		}
		else
		{
			Node1->leftChild = tree_2;
			Node1->rightChild = Node2;
		}
		tree_2 = Node1;
		Node2->data = question;
		Node2->rightChild = Node2->leftChild = NULL;
	}
	else
	{
		tree = Node1;
		Node1->data = question;
		if (input_a == "yes" || input_a == "Yes")
		{
			Node1->rightChild = NULL;
			Node1->leftChild = Node2;

		}
		else
		{
			Node1->leftChild = NULL;
			Node1->rightChild = Node2;
		}
		Node2->data = answer;
		Node2->leftChild = Node2->rightChild = NULL;
	}
	if (root == NULL)
	{
		root = tree;
		cout << "Play Again? Enter Yes or No" << endl;
		getline(cin, answer);
		if (input_b == "yes" || input_b == "Yes")
		{
			begin(root);
		}
		else
		{
			cout << "Thank you for giving me the information ;)" << endl;
		}
	}


}
void IgnoreLine()
{
	char next;
	do
		cin.get(next);
	while (next != '\n');
}
void Instructions()
{

	cout << "Rules Of the Game"  <<endl;
	cout << "1. Player 1 and Player 2 one is a thinker and the other is a guesser" << endl;
	cout << "2. The Thinker is the player who thinks of a person, place or thing." << endl;
	cout << "3. The Guesser is the player who guesses what the thinker is thinking by asking yes or no questions" << endl;
	cout << "4. The game will continue until the guesser gives up or finds the answer." << endl;
	IgnoreLine();
	
}


