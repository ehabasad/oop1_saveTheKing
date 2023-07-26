#pragma once

/*=========================================================================
Includes
===========================================================================*/
#include "globals.h"
class Tile;

class Character
{
public:
	/*=========================================================================
	CTOR & DTOR
	===========================================================================*/
	Character(CharacterType type, const Location& loc);
	~Character();

	/*=========================================================================
	Public Functions
	===========================================================================*/
	void setLocation(const Location& l);	//Returns the position of the Character
	const Location& getLocation() const;
	CharacterType getType() const;
	bool holdsKey() const;// NOTE: relevant only for thief
	void pickUpKey();// NOTE: relevant only for thief
	void useKey();// NOTE: relevant only for thief

	
	bool moveInto(Tile& t, const Location& l);//returns if moved or not
	
	/*=========================================================================
	Private Functions
	===========================================================================*/
private:
	CharacterType	_type;		// will hold the type of this 
	Location		_location;
	bool            _holdsKey; // NOTE: relevant only for thief
};

