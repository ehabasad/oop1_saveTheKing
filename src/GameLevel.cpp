#include <iostream>
#include <fstream> 
#include <cstdlib>      // for system()
#include <thread>       // for sleep
#include <conio.h>      // for _kbhit() and _getch()

#include "GameLevel.h"
#include "Character.h"
#include "Board.h"
#include "globals.h"

using namespace std;

// ---------------------------------- utilities ------------------------------ //
// keys definitions
const int KB_ESCAPE = 27;
const int SPECIAL_KEY = 224;
// special keys
const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;

ActionVal handleSpecialKey() {
	int c = _getch();
	switch (c)
	{
	case KB_UP:
		return UP;
		break;
	case KB_DOWN:
		return DOWN;
		break;
	case KB_LEFT:
		return LEFT;
		break;
	case KB_RIGHT:
		return RIGHT;
		break;
	default:
		return NONE;
		break;
	}
}

Action getNextAction() {
	ActionType t = UNDEFINED;
	ActionVal v = NONE;
	int c = 0;
	do
	{
		while (!_kbhit())       // Wait for a key to be pressed
			std::this_thread::sleep_for(std::chrono::milliseconds(500));

		c = _getch();
		switch (c)
		{

		case 'P':
		case 'p':
			t = CHANGE_CHARACTER;
			v = NONE;
			break;

		case SPECIAL_KEY:
			t = MOVE_CHARACTER;
			v = handleSpecialKey();
			break;


		case KB_ESCAPE:
			// std::cout << "Escape pressed. Exiting..." << std::endl;
			t = EXIT_GAME;
			v = NONE;
			break;

		default:
			break;
		}
	} while (t == UNDEFINED);

	return{ t, v };
}

Location getRelativeLocation(const Location& currentLoc, ActionVal direction) {
	switch (direction) {
		case UP:
			return{ currentLoc.row - 1, currentLoc.col };
			break;
		case DOWN:
			return{ currentLoc.row + 1, currentLoc.col };
			break;
		case LEFT:
			return{ currentLoc.row, currentLoc.col - 1 };
			break;
		case RIGHT:
			return{ currentLoc.row, currentLoc.col + 1 };
			break;
		default:
			return currentLoc;
	}
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
GameLevel::GameLevel(std::ifstream& ifs) : _steps(0), _board(), _characters(), _currentCharacter(0)
{
	//ifstream ifs(filename, ifstream::in);
	if (ifs.is_open()) {
		// assumes file format is OK
		if (_board.readBoard(ifs)) { // board read successfully
			char c;
			int i, j, k, l;
			while (!ifs.eof()) {
				// read first character
				ifs >> c;
				if (c == TELEPORT) {
					ifs >> i >> j >> k >> l; // read 4 numbers
					// update teleport pair
					_board.getTile({ i, j }).setDestination(&_board.getTile({ k, l }), { k, l });
					_board.getTile({ k, l }).setDestination(&_board.getTile({ i, j }), { i, j });
				}
				else { // a character location line
					ifs >> i >> j;

					_characters.push_back(new Character((CharacterType)c, { i, j })); // update character type and location
					_board.getTile({ i, j }).setCharacter(_characters[_characters.size() - 1]);
				}
			}
		}
	}
	else {
		// show message:
		cerr << "Error opening file: " << endl;
		exit(EXIT_FAILURE);
	}
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
GameLevel::~GameLevel()
{
	for (int i = 0; i < _characters.size(); i++) {
		delete _characters[i];
	}
}
//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool GameLevel::play()
{
	draw();
	// play (perform actions) until level is over or player exits
	bool isOver = false;
	while (!isOver) {
		Action currAction = getNextAction();
		if (currAction.type == EXIT_GAME) {
			return false;
		}
		isOver = performAction(currAction);
		draw();
	}
	return true;
}

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
bool GameLevel::performAction(Action action) {
	bool isOver = false, moved;
	Location oldLocation, newLocation;
	switch (action.type) {

	case CHANGE_CHARACTER:
		_currentCharacter = (_currentCharacter + 1) % _characters.size(); // circular switch of characters
		break;

	case MOVE_CHARACTER:
		oldLocation = _characters[_currentCharacter]->getLocation();
		newLocation = getRelativeLocation(oldLocation, action.val);
		moved = _characters[_currentCharacter]->moveInto(_board.getTile(newLocation), newLocation); // updates both the character and the tile, if needed
		if (moved) {
			_board.getTile(oldLocation).setCharacter(nullptr);
			_steps++;

			if (_board.getTile(newLocation).getType() == THRONE &&
				_characters[_currentCharacter]->getType() == KING) {
				isOver = true;
			}
		}
		break;
	default:
		break;
	}
	return isOver;
}

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
void GameLevel::draw() const
{
	std::system("cls"); // clears screen
	_board.draw();
	cout << "Current character: " << (char)_characters[_currentCharacter]->getType() << endl;
	bool hasKey = false;
	for (int i = 0; i < _characters.size(); i++) {
		if (_characters[i]->getType() == THEIF && _characters[i]->holdsKey()) {
			hasKey = true;
			break;
		}
	}
	if (hasKey) {
		cout << "Theif holds a key" << endl;
	}
	else {
		cout << "Theif has no key" << endl;
	}

	cout << "Number of steps: " << _steps << endl;
}





