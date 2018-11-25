/*This program parses the matrix.txt file. It uses fgetc.
Patricia Liu*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define NUM_OF_MATRICES 11
#define MAX_NAMELENGTH 20
#define MAX_ROWLENGTH 120

typedef struct {
	int value;
} cellType;

typedef struct {
	cellType grid[MAX_ROWS][MAX_COLS];
	char name[MAX_NAMELENGTH];
	int rows;
	int cols;
} matrixType;

void clearArray(matrixType * matrix){
	for (int i=0; i< NUM_OF_MATRICES; i++){
		for (int j=0; j<MAX_ROWS; j++){
			for (int k=0; k<MAX_COLS; k++){
				matrix[i].grid[j][k].value =0;
			}
		}	
	}	
}

void parseFile (matrixType* matrix, FILE * matrixFile_p){
	char temp[MAX_ROWLENGTH];
	int i=0;
	char numTemp;
		
	for (int counter=0; counter<NUM_OF_MATRICES; counter++){
		for (int o=0; o<=MAX_NAMELENGTH; o++) matrix[counter].name[o]=0; //clears name array
		fgets (temp, MAX_ROWLENGTH , matrixFile_p);
		while (1){//gets the name and row and column values
			if (temp[i]==':'){
				i++;
				matrix[counter].rows = atoi(&temp[i]);
				if (matrix[counter].rows >= MAX_ROWS){
					matrix[counter].rows = MAX_ROWS;
				}
				while (temp[i]!='X') i++;
				i++;
				matrix[counter].cols = atoi(&temp[i]);
				if (matrix[counter].cols >= MAX_COLS){ 
					matrix[counter].cols = MAX_COLS;
				}
				break;
			}
			
			if (i < MAX_NAMELENGTH){
				matrix[counter].name[i] = temp[i];
			}
			i++;
		}
		i=0;		
		
		for (int j=0; j<matrix[counter].rows; j++){
			for (int k=0; k<matrix[counter].cols; k++){
				numTemp= fgetc(matrixFile_p);
				if (numTemp=='-'){
					numTemp=fgetc(matrixFile_p);
					while (numTemp!='\t'){
						if (numTemp == '\n') break;
						matrix[counter].grid[j][k].value= (matrix[counter].grid[j][k].value)*10+ numTemp-'0';
						numTemp=fgetc(matrixFile_p);
						
					}
					matrix[counter].grid[j][k].value=(matrix[counter].grid[j][k].value)*(-1);
				}
				else{
					while (numTemp!='\t'){
						if (numTemp == '\n') break;
						matrix[counter].grid[j][k].value=(matrix[counter].grid[j][k].value) * 10 + (numTemp -'0');
						numTemp= fgetc(matrixFile_p);
					}
				}
			}

		}		
	}
}

void outputFile (matrixType* matrix, FILE * printFile_p){
	for (int counter=0; counter< NUM_OF_MATRICES; counter++){
		printf ("%s: %iX%i\n", matrix[counter].name, matrix[counter].rows, matrix[counter].cols);
		fprintf (printFile_p, "%s: %iX%i\n", matrix[counter].name, matrix[counter].rows, matrix[counter].cols); // prints in output file
		for (int j=0; j<matrix[counter].rows; j++){
			for (int k=0; k<matrix[counter].cols; k++){
				printf ("%i ", matrix[counter].grid[j][k].value);
				fprintf(printFile_p, "%i\t", matrix[counter].grid[j][k].value);
			}
			printf ("\n");
			fprintf(printFile_p, "\n");
		}
		printf ("\n");
		fprintf(printFile_p, "\n");	
	}
}

int main(){
	matrixType matrix[NUM_OF_MATRICES];
	FILE* matrixFile_p=fopen("matrices.txt", "r");
	FILE* printFile_p=fopen("output.txt", "w");
	
	clearArray(matrix); // or &matrix[0]
	
	parseFile (matrix, matrixFile_p);
	
	outputFile(matrix, printFile_p);
		
}
