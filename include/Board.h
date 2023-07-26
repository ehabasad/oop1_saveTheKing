#pragma once

/*=========================================================================
Includes
===========================================================================*/
#pragma once
#include <iostream>
#include <fstream>
#include "Tile.h"

class Board
{
public:
	/*=========================================================================
	CTOR & DTOR
	===========================================================================*/
	Board() :_rows(0), _cols(0), _board(NULL){};
	~Board();


	/*=========================================================================
	Public Functions
	===========================================================================*/	
	bool readBoard(std::ifstream& ifs);//The function reads the file it receives note for note
	void draw() const;	// paint the base of the board
	Tile& getTile(Location loc);//Function accepts tile location and returns its type
	void readFile();

private:
	unsigned int	_rows;//length of the rows in the array 
	unsigned int	_cols;//length of the cols in the array 
	Tile**			_board; // 2D array of Tiles

};

