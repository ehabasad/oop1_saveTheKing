//
// Created by Ehab on 10/11/2021.
//
#include "globals.h"
class Character;



class King {
    /*=========================================================================
	CTOR & DTOR
	===========================================================================*/
    ~King() ;

    /*=========================================================================
    Public Functions
    ===========================================================================*/
    void setLocation(const Location& l) ;
    const Location& getLocation() const ;
    bool holdsKey() const ;
    void pickUpKey() ;
    void useKey() ;
    void draw() const;
    bool isOccupied() const;
    TileType getType() const;
    void setType(TileType type);
    void setDestination(King* destination, Location destinationLocation);
    bool acceptKing(King* c, const Location& l);

    /*=========================================================================
    Private Functions
    ===========================================================================*/
private:
    Location	_location;
    bool        _holdsKey; // NOTE: relevant only for thief
    TileType	_type;
    King*  _currentCharacter;
    King*       _destination;    // relevant only for teleport type
    Location    _destinationLoc; // relevant only for teleport type

};
