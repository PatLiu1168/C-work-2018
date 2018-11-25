//These functions add up the squares of numbers between m and n inclusive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_I( int m, int n){ //iterative
	int sum=0;
	while (m<=n){
		sum=sum+(m*m);
		m++;
	}
	return sum;
}

int f_R(int m, int n){ //recursive
	if (n==m){
		return n*n;
	}
	return n*n + f_R(m, n-1);
}


int main (){
	int m=2;
	int n =4;
	printf ("The sum of all the squares of numbers between %i and %i inclusive is: %i\n", m, n, f_I(m,n));
	printf ("The sum of all the squares of numbers between %i and %i inclusive is: %i\n", m, n, f_R(m, n));
}
