//
// Created by Ehab on 10/11/2021.
//
#include "globals.h"
class Character;


class Mage {
    /*=========================================================================
	CTOR & DTOR
	===========================================================================*/
    ~Mage() ;


    /*=========================================================================
    Public Functions
    ===========================================================================*/
    void setLocation(const Location& l) ;
    const Location& getLocation() const ;
    bool holdsKey() const ;
    void pickUpKey() ;
    void useKey() ;
    void setType(TileType type);
    bool isOccupied() const;
    TileType getType() const;
    void setDestination(Mage* destination, Location destinationLocation);
    bool acceptMage(Mage* c, const Location& l);

    /*=========================================================================
    Private Functions
    ===========================================================================*/
private:
    Location	_location;
    bool        _holdsKey; // NOTE: relevant only for thief
    TileType	_type;
    Mage*  _currentCharacter;
    Mage*       _destination;    // relevant only for teleport type
    Location    _destinationLoc; // relevant only for teleport type

};
