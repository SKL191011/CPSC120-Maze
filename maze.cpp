#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <string.h>

int row_index=0,
    col_index=0;
    
char board [15][20]={"*********==********",
	 		 	     "*     **    **    *",
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
						
int main()
{
	int n = 0,
		temp_val = 0,
		temp_val2 = 0,
		temp_row = 0,
		temp_col = 0;
	
	char move;
	 
	for (;;) 
	{
	 printBoard();
	 searchI();
	
	
	  	  	
	cin >> move;
	
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
				
			
			break;
		
		default:
		cout << "Please use w,a,s,d to move your character";
		}
	}
	
	cout << "The user i is located at row: " << row_index
		 << " and column: " << col_index << endl;
	   
	return 0;
}
