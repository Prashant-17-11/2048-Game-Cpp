#include "Game.h"

using namespace std;


int main()
{
	Game game;
	game.play();

	while(getchar() != '\n');
	cout<<endl<<"Press ENTER to close the program."<<endl;
	getchar();
}
