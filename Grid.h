#ifndef GRID_H_
#define GRID_H_

#include <bits/stdc++.h>

class Grid
{
	public:
		int game_board[4][4];
		void generate_grid();
		bool is_empty(int,int);
		bool grid_filled();
		void display_grid();
		void change_board(char);
		void up();
		void down();
		void left();
		void right();
		void swap_i(int,int,int);
		void swap_double_i(int,int,int);
		void swap_j(int,int,int);
		void swap_double_j(int,int,int);
};

#endif
