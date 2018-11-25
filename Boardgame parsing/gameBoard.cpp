/*
	Created by Patricia Liu
	
	Examine the text file named gameBoard.txt.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 0
#define MAX_VALUE 5

typedef struct {
	int value;
	char colour;
	int visible;	// cell is open (1) or closed (0)
} cellType;

/*
	A gameBoard that is 5 X 3 has 5 rows
	and 3 columns
*/
typedef struct {
	cellType grid[MAX_ROWS][MAX_COLS];
	int rows;
	int cols;
} gameBoardType;

int main(){
	gameBoardType gb;
	FILE*gameFile=fopen("gameBoard.txt", "r");
	char temp[3];
	fscanf (gameFile, "%i", &gb.rows);
	fgets (temp, 3, gameFile); // passes over the x and spaces
	fscanf (gameFile, "%i", &gb.cols);
	
	for (int i=0; i<gb.rows;i++){
		for (int j=0; j<gb.cols; j++){
			fscanf (gameFile, "%s", temp);
			gb.grid[i][j].colour=temp[0];
			gb.grid[i][j].value=temp[1]-'0'+2; //instructions said Y3C has a value of 5 so that means 3 on the gameboard is equal to 5
			(temp[2]=='C')? gb.grid[i][j].visible=0 : gb.grid[i][j].visible=1;
			
			printf("%c%i%c\t",gb.grid[i][j].colour, gb.grid[i][j].value, (gb.grid[i][j].visible==0)? 'C': 'O'); // prints the gameboard
			
		}
		printf("\n"); //used in printing the gameboard
	}
}
