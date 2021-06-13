#include "Game.h"

using namespace std;

void Game :: play()
{
	display_message1();
	display_commands();
	grid.generate_grid();
	while(player.highest_score != 2048 && !grid.grid_filled())
	{
		add_random_two();
		grid.display_grid();
		player.command = accept_user_command();
		grid.change_board(player.command);
		grid.display_grid();
		player.highest_score = game_score();
	}
	result();
}

void Game :: display_message1()
{
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"\t\t2048 Game"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Game :: display_commands()
{
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"\t W or w : Move Up"<<endl;
	cout<<"\t S or s : Move down"<<endl;
	cout<<"\t A or a : Move left"<<endl;
	cout<<"\t D or d : Move right"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Game :: add_random_two()
{
	srand(time(NULL));
	int r = rand()%4;
	int c = rand()%4;
	while(!grid.is_empty(r,c))
	{
		r = rand()%4;
		c = rand()%4;
	}
	grid.game_board[r][c] = 2;
}

char Game :: accept_user_command()
{
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"Enter your command"<<endl;
	char c;
	cin>>c;
	while(!command_verification(c))
	{
		cout<<"Enter a valid command!! Try again!!";
		cin>>c;
	}
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	return c;
}

bool Game :: command_verification(char c)
{
	if(c == 'W' || c == 'w' || c == 'S' || c == 's' || c == 'A' || c == 'a' || c == 'D' ||c == 'd')
	{
		return true;
	}
	return false;
}

int Game :: game_score()
{
	int max = 0;
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			if(grid.game_board[i][j] > max)
			{
				max = grid.game_board[i][j];
			}
		}
	}
	return max;
}

void Game :: result()
{
	if(player.highest_score == 2048)
	{
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<"Congrats!! You scored 2048 and won the game!!"<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<endl<<endl;
	}
	else
	{
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<"Oh NO!! No more moves left to continue!!"<<endl;
		cout<<"Your high score was ="<<player.highest_score<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<endl<<endl;
	}
}
