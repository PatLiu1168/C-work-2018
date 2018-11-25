//These functions add up numbers between m and n inclusive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_I( int m, int n){ //iterative
	int sum=0;
	while (m<=n){
		sum=sum+m;
		m++;
	}
	return sum;
}

int f_R(int m, int n){ //recursive
	if (n==m){
		return n;
	}
	return n + f_R(m, n-1);
}

int order_1(int m, int n){ //order 1
	return (n*(n+1))/2-((m-1)*(m))/2;
}


int main (){
	int m=5;
	int n =11;
	printf ("The sum of all numbers between %i and %i inclusive is: %i\n", m, n, f_I(m,n));
	printf ("The sum of all numbers between %i and %i inclusive is: %i\n", m, n, f_R(m, n));
	printf ("The sum of all numbers between %i and %i inclusive is: %i", m, n, order_1(m, n));
}
