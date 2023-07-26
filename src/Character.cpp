#include "Character.h"
#include "globals.h"
#include "Tile.h"

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
Character::Character(CharacterType type, const Location& loc)
	: _type(type), _location(loc), _holdsKey(false)
{

}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
Character::~Character() {

}

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Character::setLocation(const Location& l)
{
	_location = l;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
const Location& Character::getLocation() const
{
	return _location;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
CharacterType Character::getType() const
{
	return _type;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool Character::holdsKey() const {
	return _holdsKey;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Character::pickUpKey() {
	_holdsKey = true;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Character::useKey() {
	_holdsKey = false;
}


//-------------------------------------------------------------------------
// returns if the game character can move or not
//-------------------------------------------------------------------------
bool Character::moveInto(Tile& t, const Location& l) {
	if (t.isOccupied()) {
		return false;
	}
	bool moved = false;
	switch (_type)
	{
	case KING:
		moved = t.acceptKing(this, l);
		break;
	case THEIF:
		moved = t.acceptTheif(this, l);
		break;
	case MAGE:
		moved = t.acceptMage(this, l);
		break;
	case WARIOR:
		moved = t.acceptWarior(this, l);
		break;
	default:
		break;
	}
	return moved;
}