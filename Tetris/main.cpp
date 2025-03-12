#include "Game.h"
#include "Utility.h"

int main()
{
	loadFiles();

	Game mainGame{};
	mainGame.play();

}