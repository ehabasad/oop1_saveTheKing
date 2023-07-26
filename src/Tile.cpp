#include <iostream>
#include "Tile.h"
#include "Character.h"

using namespace std;

Tile::Tile() : 
_currentCharacter(nullptr), _type(TileType::EMPTY),
_destination(nullptr), _destinationLoc({ -1, -1 }) {}

Tile::~Tile(){}


/*=========================================================================
Public Functions
===========================================================================*/
void Tile::draw() const{
	cout << (char)_type <<
		(char)(_currentCharacter == nullptr ? NOCHAR : _currentCharacter->getType());
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool Tile::isOccupied() const{
	return _currentCharacter != nullptr;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
TileType Tile::getType() const{
	return _type;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Tile::setType(TileType type) {
	_type = type;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Tile::setDestination(Tile* destination, Location destinationLocation) {
	_destination = destination;
	_destinationLoc = destinationLocation;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
// define acceptCharacter() for each character type, which returns true if success
bool Tile::acceptKing(Character* c, const Location& l) {
	switch (_type)
	{
	case EMPTY:
	case KEY:
		_currentCharacter = c;
		c->setLocation(l);
		break;

	case WALL:
	case GATE:
	case FIRE:
	case ORC:
		return false;
		break;

	case TELEPORT: // King moves to destination
		if (!_destination->isOccupied()) {
			_destination->_currentCharacter = c;
			c->setLocation(_destinationLoc);
		}
		else {
			_currentCharacter = c;
			c->setLocation(l);
		}
		break;

	case THRONE:
		_currentCharacter = c;
		c->setLocation(l);
		break;

	default:
		break;
	}
	return true;

}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool Tile::acceptTheif(Character* c, const Location& l) {
	switch (_type)
	{
	case EMPTY:
		_currentCharacter = c;
		c->setLocation(l);
		break;

	case WALL:
	case FIRE:
	case ORC:
	case THRONE:
		return false;
		break;

	case KEY: // if not already has key, pick it up
		if (!c->holdsKey()) {
			c->pickUpKey();
			this->setType(EMPTY);
		}
		_currentCharacter = c;
		c->setLocation(l);
		break;

	case GATE:// if has key, open gate
		if (!c->holdsKey()){
			return false;
			break;
		}
			
		if (c->holdsKey()) {
			c->useKey();
			this->setType(EMPTY);
			_currentCharacter = c;
			c->setLocation(l);
		}
		break;

	case TELEPORT: // Theif moves to destination
		if (!_destination->isOccupied()) {
			_destination->_currentCharacter = c;
			c->setLocation(_destinationLoc);
		}
		else {
			_currentCharacter = c;
			c->setLocation(l);
		}
		break;
	
	default:
		break;
	}
	return true;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool Tile::acceptMage(Character* c, const Location& l) {
	switch (_type)
	{
	case EMPTY:
	case KEY:
	case TELEPORT:
		_currentCharacter = c;
		c->setLocation(l);
		break;

	case WALL:
	case GATE:
	case ORC:
	case THRONE:
		return false;
		break;

	case FIRE:
		this->setType(EMPTY);
		_currentCharacter = c;
		c->setLocation(l);
		break;
	
	default:
		break;
	}
	return true;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool Tile::acceptWarior(Character* c, const Location& l) {
	switch (_type)
	{
	case EMPTY:
	case KEY:
		_currentCharacter = c;
		c->setLocation(l);
		break;

	case WALL:
	case GATE:
	case FIRE:
	case THRONE:
		return false;
		break;

	case ORC:
		this->setType(KEY);
		_currentCharacter = c;
		c->setLocation(l);
		break;

	case TELEPORT: // Warior moves to destination
		if (!_destination->isOccupied()) {
			_destination->_currentCharacter = c;
			c->setLocation(_destinationLoc);
		}
		else {
			_currentCharacter = c;
			c->setLocation(l);
		}
		break;

	default:
		break;
	}
	return true;
}