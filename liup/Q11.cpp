//compute nth term in an arithmetic sequence defined by t1=a abd tn=t(n-1)+d
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int f_I(int n, int a, int d){
	int term=0;
	int first=a;
	if (n==1){
		return first;
	}
	else {
		for (int i=2; i<=n; i++){
			term=first+d;
			first=term;
		}
		return term;
	}
}

int f_R(int n, int first, int d){
	if (n>1){
		return f_R(n-1, first+d, d);
	}
	return first;
}

int order_1(int n, int a, int d){
	return a+(n-1)*d;
}

int main (){
	int a =5;
	int d=2;
	int n=8; //term
	printf ("Term %i is : %i\n", n, f_I(n, a, d)); //iterative
	printf ("Term %i is : %i\n", n, f_R(n, a, d)); //recursive
	printf ("Term %i is : %i", n, order_1(n, a, d)); //order 1
}
