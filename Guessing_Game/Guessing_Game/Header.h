#pragma once
#include <string>

using namespace std;

class Node
{
public:
	string data;
	Node* left;
	Node* right;

};
void Instructions()
{

	cout << "Rules Of the Game"  <<endl;
	cout << "1. Player 1 and Player 2 one is a thinker and the other is a guesser" << endl;
	cout << "2. The Thinker is the player who thinks of a person, place or thing." << endl;
	cout << "3. The Guesser is the player who guesses what the thinker is thinking by asking yes or no questions" << endl;
	cout << "4. The game will continue until the guesser gives up or finds the answer." << endl;
	
	
}


