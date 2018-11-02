//compute nth term in an geometric sequence defined by t1=a abd tn=rt(n-1)
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int f_I(int n, int a, int r){
	int term=0;
	int first=a;
	if (n==1){
		return first;
	}
	else {
		for (int i=2; i<=n; i++){
			term=first*r;
			first=term;
		}
		return term;
	}
}

int f_R(int n, int first, int r){
	if (n>1){
		return f_R(n-1, first*r, r);
	}
	return first;
}

int order_not_1(int n, int a, int r){
	return a* pow (r, n-1); //not order 1
}

int main(){
	int a =5;
	int r=2;
	int n=6; //term
	printf ("Term %i is : %i\n", n, f_I(n, a, r)); //iterative
	printf ("Term %i is : %i\n", n, f_R(n, a, r)); //recursive
	printf ("Term %i is : %i\n", n, order_not_1(n, a, r)); //not order 1 because the pow function is a loop
}
