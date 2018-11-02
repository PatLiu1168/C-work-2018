//calculate the sum of the first n terms in a geometric sequence
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int f_I(int n, int a, int r){
	int term=0;
	int first=a;
	int sum=a;
	for (int i=2; i<=n; i++){
		term=first*r;
		first=term;
		sum=sum+term;
	}
	return sum;
}

int f_R(int n, int a, int r, int*sum){
	//*sum=*sum+a;
	if (n==1){
		return a;
	}
	return a+ f_R(n-1, a*r, r, sum);
}

int order_not_1(int n, int a, int r){
	if (n==1) return a;
	return (a*(a-pow(r, n)))/(1-r); //not order 1
}

int main(){
	int a =5;
	int r=3;
	int n=7; //term
	int sum=0;
	printf ("The sum of the first %i terms is: %i\n", n, f_I(n, a, r)); //iterative
	//f_R(n, a, r, &sum);//recursive
	printf ("The sum of the first %i terms is: %i\n", n, f_R(n, a, r, &sum)); 
	printf ("The sum of the first %i terms is: %i", n, order_not_1(n, a, r)); //not order 1 because the pow function is a loop
}
