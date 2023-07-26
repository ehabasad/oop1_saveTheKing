#pragma once

/*=========================================================================
Includes
===========================================================================*/
#include "globals.h"
class Character;

class Tile
{
public:
	/*=========================================================================
	CTOR & DTOR
	===========================================================================*/
	Tile();
	~Tile();
	
	/*=========================================================================
	Public Functions
	===========================================================================*/
	void draw() const;
	bool isOccupied() const;
	TileType getType() const;
	void setType(TileType type);
	void setDestination(Tile* destination, Location destinationLocation); 
	void setCharacter(Character* ch) {
		_currentCharacter = ch;
	}

	// define acceptCharacter() for each character type, which returns true if game is over
	bool acceptKing(Character* c, const Location& l);
	bool acceptTheif(Character* c, const Location& l);
	bool acceptMage(Character* c, const Location& l);
	bool acceptWarior(Character* c, const Location& l);
	
	/*=========================================================================
	Private Functions
	===========================================================================*/
private:
	TileType	_type;
	Character*	_currentCharacter;
	Tile*       _destination;    // relevant only for teleport type
	Location    _destinationLoc; // relevant only for teleport type
};

