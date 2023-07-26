#include <iostream>
#include <conio.h>
#include "globals.h"
#include "GameLevel.h"

using namespace std;

int main() {

	// load level
	ifstream infile;

	infile = ifstream("level3.txt");
	
	GameLevel currLevel(infile);

	// play current level
	bool isOver = currLevel.play();
	
	return 0;
}