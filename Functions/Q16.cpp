//The function computes (n,r) in the pascal's triangle
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void f_I(int row, int column){
	int num;
	int temp=0;
	if (column > row) {printf("Invalid");}
	for (int i=0; i<=row; i++){
		num=1;
		for (int j=0; j<=temp; j++){ 
			if (j==temp) break;
        	num=(num*(i-j)/(j+1));
        }
        if (temp<column) temp++; //makes r an individual variable (column number does not need to be equal to row number)
	}
	printf("%i", num);
}

int f_R(int row, int column){ 	
	if (column<row && row && column){
		return f_R(row-1, column-1) + f_R(row-1, column);
	}
	else if (column>row){
		return -1; //if numbers are invalid
	}
	return 1;
}


int main (){
	int r=5;
	int n=7;
	f_I(n, r);
	printf("\n%i", f_R(n, r));
}
