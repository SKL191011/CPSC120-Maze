#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <time.h>

int row_index=0,
    col_index=0,
	Mrow_index=0,
	Mcol_index=0,
	temp_val = 0,
	temp_val2 = 0,
	temp_row = 0,
	temp_col = 0,
	temp_row2 = 0,
	temp_col2 = 0;
  
char board [15][20]={"*********==********",
	 		 	     "*        M  **    *",
	 		         "**   **       **  *",
	 		   	     "*      ********   *",
	 		  	     "*  **            **",
	 		   	     "*        ***      *",
	 		   	     "******         ****",
	 		   	     "*     ***** *******",
	 		   	     "*                 *",
	 	    	     "****    *****    **",
	 	    	     "*     *        *  *",  
	 		   	     "*                 *",
	 		         "*   ******        *",
	 		         "****          *** *",
	 		         "******** i ********"};

void printBoard ()
{
	for(int a=0; a < 15; a++)
	{
			for(int b=0; b < 20; b++)
				cout << board [a][b];
	cout <<endl;
	}
}
void searchI ()
{
	for(int i=0; i< 15; i++)
	  {
	  	for(int j=0; j< 20; j++)
	  		{
	  		if(board[i][j]== 'i')
	  			{
	  			row_index = i;
	  			col_index = j;
	  			return;
	  			}
	  		}
	  }
}
void searchM()
{
	for(int x=0; x< 15; x++)
	  {
	  	for(int y=0; y< 20; y++)
	  		{
	  		if(board[x][y]== 'M')
	  			{
	  			Mrow_index = x;
	  			Mcol_index = y;
	  			return;
	  			}
	  		}
	  }
}
/*void movement()
{
	switch()
		{
		case 'w':
			if(board[row_index-1][col_index] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index-1][col_index];
				board[row_index-1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index-1][col_index] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index-1][col_index];
				board[row_index-1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				cout << "Yay! You win!" << endl;
				}
		
			break;

		case 'a':
			if(board[row_index][col_index-1] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index-1];
				board[row_index][col_index-1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index][col_index-1] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index-1];
				board[row_index][col_index-1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				cout << "Yay! You win!" << endl;
				}
			break;

		case 's':
			if(board[row_index+1][col_index] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index+1][col_index];
				board[row_index+1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index+1][col_index] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index+1][col_index];
				board[row_index+1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				cout << "Yay! You win!" << endl;
				}

			break;

		case 'd':
			if(board[row_index][col_index+1] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index+1];
				board[row_index][col_index+1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index][col_index+1] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index+1];
				board[row_index][col_index+1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				cout << "Yay! You win!" << endl;
				}

			break;

		default:
		cout << "Please use w,a,s,d to move your character";
		}
}*/
void Mmove()
{
	srand(time(NULL));

	if((row_index != Mrow_index)&&(col_index != Mcol_index))
	{
	temp_row2 = Mrow_index;
	temp_col2 = Mcol_index;
	Mrow_index = rand()%15;
	Mcol_index = rand()%20;
	
	temp_val2 = board[Mrow_index][Mcol_index];
	board[Mrow_index][Mcol_index] = board[temp_row2][temp_col2];
	board[temp_row2][temp_col2]= temp_val2;
	}
}

int main()
{	
	int win = 0,
		monster = 0;
	char move;

	for (;;) 
	{
	 printBoard();
	 searchI();
	 searchM();
	 cin >> move;
	 Mmove();
	 switch(move)
		{
		case 'w':
			if(board[row_index-1][col_index] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index-1][col_index];
				board[row_index-1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index-1][col_index] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index-1][col_index];
				board[row_index-1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				win = 1;
				}

			if(board[row_index-1][col_index] == 'M')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index-1][col_index];
				board[row_index-1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				monster = 1;
				}
		
			break;

		case 'a':
			if(board[row_index][col_index-1] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index-1];
				board[row_index][col_index-1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index][col_index-1] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index-1];
				board[row_index][col_index-1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				win = 1;
				}

			if(board[row_index][col_index-1] == 'M')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index-1];
				board[row_index][col_index-1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				monster = 1;
				}
			break;

		case 's':
			if(board[row_index+1][col_index] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index+1][col_index];
				board[row_index+1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index+1][col_index] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index+1][col_index];
				board[row_index+1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				win = 1;
				}

			if(board[row_index+1][col_index] == 'M')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index+1][col_index];
				board[row_index+1][col_index] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				monster = 1;
				}

			break;

		case 'd':
			if(board[row_index][col_index+1] == ' ')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index+1];
				board[row_index][col_index+1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;
				}

			if(board[row_index][col_index+1] == '=')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index+1];
				board[row_index][col_index+1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				win = 1;
				}

			if(board[row_index][col_index+1] == 'M')
				{
				temp_row = row_index;
				temp_col = col_index;

				temp_val = board[row_index][col_index+1];
				board[row_index][col_index+1] = board[temp_row][temp_col];
				board[temp_row][temp_col] = temp_val;

				monster = 1;
				}

			break;

		default:
		cout << "Please use w,a,s,d to move your character and press enter/return to play";
		}

		if(win)
			cout << "Yay! You won!" << endl;
		else if(monster)
			cout << "Uh Oh, the boogie man ate you!" << endl;
	//movement();	
	}
	return 0;
}
