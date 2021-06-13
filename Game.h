#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "Grid.h"
#include <time.h>

class Game
{
	public:
		Grid grid;
		Player player;

		void play();
		void display_message1();
		void display_commands();
		void add_random_two();
		char accept_user_command();
		bool command_verification(char);
		int game_score();
		void result();
};

#endif
