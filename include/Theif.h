//
// Created by Ehab on 10/11/2021.
//
#include "globals.h"

class Character;


class Theif {
    /*=========================================================================
	CTOR & DTOR
	===========================================================================*/
    ~Theif() ;


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
    void setDestination(Theif* destination, Location destinationLocation);
    bool acceptTheif(Theif* c, const Location& l);

    /*=========================================================================
    Private Functions
    ===========================================================================*/
private:
    Location	_location;
    bool        _holdsKey; // NOTE: relevant only for thief
    TileType	_type;
    Theif*  _currentCharacter;
    Theif*       _destination;    // relevant only for teleport type
    Location    _destinationLoc; // relevant only for teleport type

};

