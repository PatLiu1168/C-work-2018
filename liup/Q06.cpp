//function computes the nth term in a sequence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_I(int n){
	int temp1=-3; // term 1
	int temp2=2; //term 2
	int term=0;
	if (n==1){
		return -3;
	}
	else if (n==2){
		return 2;
	}
	else{
		for ( int i=3; i<=n; i++){
			term=temp1-2*temp2;
			temp1=temp2;
			temp2=term;
		}
		return term;
	}
}

int f_R(int n, int first, int second){ 
	if (n>1){
		return f_R(n-1, second, first-second*2);
	}
	return first;
}


int main(){
	int n=3;
	printf ("%ith term is : %i\n", n, f_R(n, -3, 2));
	printf ("%ith term is : %i", n, f_I(n));
}
