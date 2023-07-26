#pragma once
#define NUM_CHARACTERS 4

typedef enum {
	KING = 'K',
	MAGE = 'M',
	WARIOR = 'W',
	THEIF = 'T',
	NOCHAR = ' '
} CharacterType;

typedef enum {
	EMPTY = ' ',
	WALL = '=',
	GATE = '#',
	FIRE = '*',
	ORC = '!',
	KEY = 'F',
	TELEPORT = 'X', 
	THRONE = '@'
} TileType;

typedef enum {
	CHANGE_CHARACTER,
	MOVE_CHARACTER,
	EXIT_GAME, 
	UNDEFINED
} ActionType;

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
} ActionVal;

typedef struct {
	ActionType type;
	ActionVal val;
} Action;

typedef struct Location {
	int row;
	int col;
	//Location() : row(-1), col(-1) {}
	//Location(int r, int c) : row(r), col(c) {}
} Location;
