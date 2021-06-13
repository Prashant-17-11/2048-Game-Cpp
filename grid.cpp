#include "Grid.h"

using namespace std;

void Grid :: generate_grid()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			game_board[i][j] = 0;
		}
	}
}

bool Grid :: is_empty(int i , int j)
{
	if(game_board[i][j] == 0)
		return true;
	return false;
}

bool Grid :: grid_filled()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			if(game_board[i][j] == 0)
				return false;
		}
	}
	return true;
}

void Grid :: display_grid()
{
	cout<<"-----------------------------------------------------------"<<endl;

	for(int i = 0 ; i < 4 ; i++)
	{
		cout<<endl<<"|";
		for(int j = 0 ; j < 4 ; j++)
		{
			if(game_board[i][j] == 0)
			{
				cout<<"      |";
			}
			else
			{
				if(game_board[i][j] < 10)
				{
					cout<<"   "<<game_board[i][j]<<"  |";
				}
				else if(game_board[i][j] < 100)
				{
					cout<<"  "<<game_board[i][j]<<"  |";
				}
				else if(game_board[i][j] < 1000)
				{
					cout<<"  "<<game_board[i][j]<<" |";
				}
				else
				{
					cout<<" "<<game_board[i][j]<<" |";
				}
			}
		}
	}
	cout<<endl<<"-----------------------------------------------------------"<<endl;
}

void Grid :: change_board(char c)
{
	if(c == 'W' || c == 'w')
	{
		up();
		return;
	}
	if(c == 'S' || c == 's')
	{
		down();
		return;
	}
	if(c == 'A' || c == 'a')
	{
		left();
		return;
	}
	if(c == 'D' || c == 'd')
	{
		right();
		return;
	}
}

void Grid :: up()
{
	for(int j = 0 ; j < 4 ; j++)
	{
		int pos = 0;
		for(int i = 0 ; i < 4 ; i++)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != i)
				{
					swap_i(pos,i,j);
				}
				pos++;
			}
		}	//shifting all the numbers present

		for(int i = 0 ; i < 3 ; i++)
		{
			if(game_board[i][j] == game_board[i+1][j] && game_board[i][j] != 0)
			{
				swap_double_i(i,i+1,j);
			}
		}	//merging same elements

		pos = 0;
		for(int i = 0 ; i < 4 ; i++)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != i)
				{
					swap_i(pos,i,j);
				}
				pos++;
			}
		}	//again shifting all the numbers present cause merging might have created a space in between two filled cells
	}
}

void Grid :: down()
{
	for(int j = 0 ; j < 4 ; j++)
	{
		int pos = 3;
		for(int i = 3 ; i >= 0 ; i--)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != i)
				{
					swap_i(pos,i,j);
				}
				pos--;
			}
		}	//shifting all the numbers present

		for(int i = 3 ; i >= 0 ; i--)
		{
			if(game_board[i][j] == game_board[i-1][j] && game_board[i][j] != 0)
			{
				swap_double_i(i,i-1,j);
			}
		}	//merging same elements

		pos = 3;
		for(int i = 3 ; i >= 0 ; i--)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != i)
				{
					swap_i(pos,i,j);
				}
				pos--;
			}
		}	//again shifting all the numbers present cause merging might have created a space in between two filled cells
	}
}

void Grid :: swap_i(int i1 , int i2 , int j)
{
	game_board[i1][j] = game_board[i2][j];
	game_board[i2][j] = 0;
}

void Grid :: swap_double_i(int i1 , int i2 , int j)
{
	game_board[i1][j] = 2*game_board[i2][j];
	game_board[i2][j] = 0;
}
//swapping when change is happening in row i.e. i

void Grid :: left()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		int pos = 0;
		for(int j = 0 ; j < 4 ; j++)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != j)
				{
					swap_j(i,pos,j);
				}
				pos++;
			}
		}	//shifting all the numbers present

		for(int j = 0 ; j < 4 ; j++)
		{
			if(game_board[i][j] == game_board[i][j+1] && game_board[i][j] != 0)
			{
				swap_double_j(i,j,j+1);
			}
		}	//merging same elements

		pos = 0;
		for(int j = 0 ; j < 4 ; j++)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != j)
				{
					swap_j(i,pos,j);
				}
				pos++;
			}
		}	//again shifting all the numbers present cause merging might have created a space in between two filled cells
	}
}

void Grid :: right()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		int pos = 3;
		for(int j = 3 ; j >= 0 ; j--)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != j)
				{
					swap_j(i,pos,j);
				}
				pos--;
			}
		}	//shifting all the numbers present

		for(int j = 3 ; j >= 0 ; j--)
		{
			if(game_board[i][j] == game_board[i][j-1] && game_board[i][j] != 0)
			{
				swap_double_j(i,j,j-1);
			}
		}	//merging same elements

		pos = 3;
		for(int j = 3 ; j >= 0 ; j--)
		{
			if(game_board[i][j] != 0)
			{
				if(pos != j)
				{
					swap_j(i,pos,j);
				}
				pos--;
			}
		}	//again shifting all the numbers present cause merging might have created a space in between two filled cells
	}
}

void Grid :: swap_j(int i , int j1 , int j2)
{
	game_board[i][j1] = game_board[i][j2];
	game_board[i][j2] = 0;
}

void Grid :: swap_double_j(int i , int j1 , int j2)
{
	game_board[i][j1] = 2*game_board[i][j2];
	game_board[i][j2] = 0;
}
//swapping when change is happening in column i.e. j
