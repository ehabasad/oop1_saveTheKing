#pragma once

/*=========================================================================
Includes
===========================================================================*/
#include <iostream>
#include <vector>
#include "Board.h";
class Character;

class GameLevel
{
public:
	/*=========================================================================
	CTOR & DTOR
	===========================================================================*/
	GameLevel(std::ifstream& ifs);
	~GameLevel();

	/*=========================================================================
	Public Functions
	===========================================================================*/
	bool play(); // Returns true if game level is over, false if player pressed ESC

private:
	unsigned int _steps;//counter
	Board _board;
	std::vector<Character*> _characters; // array of our characters
	unsigned int _currentCharacter;

	/*=========================================================================
	Private Functions
	===========================================================================*/
	bool performAction(Action action);
	void draw() const;	// clears the screen and writes the current state of the level to the standard output
};

