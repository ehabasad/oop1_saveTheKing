#include <iostream>
#include <string>
#include <fstream>

#include "globals.h"
#include "Board.h"

using namespace std;

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
Board::~Board()
{
	if (_board != NULL)
	{
		for (int r = 0; r < _rows; r++)
			delete[] _board[r];
	}
	delete[] _board;
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Board::readFile()
{

	ifstream ifs;
	ifs.open("level1.txt");
	readBoard(ifs);
	draw();

}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool Board::readBoard(std::ifstream& ifs)
{
	// read board size
	ifs >> _rows >> _cols;

	// create empty board (allocate memory)
	_board = new Tile * [_rows];
	for (int i = 0; i < _rows; i++) {
		_board[i] = new Tile[_cols];
	}
	ifs.get(); // skip new line

	// read tiles
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			TileType c = (TileType)ifs.get();
			_board[i][j].setType(c);
		}
		ifs.get(); // skip new line
	}
	return true;
}

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void Board::draw() const
{
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			_board[i][j].draw(); // 2 chars
		}
		cout << endl;
	}
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
Tile& Board::getTile(Location loc) {
	return _board[loc.row][loc.col];
}
