//calculate the sum of the first n terms in a arithmatic sequence
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int f_I(int n, int a, int d){
	int term=0;
	int first=a;
	int sum=a;
	for (int i=2; i<=n; i++){
		term=first+d;
		first=term;
		sum=sum+term;
	}
	return sum;

}

int f_R(int n, int first, int d, int *sum){
	//*sum=*sum+first;
	if (n==1){
		return first;
	}
	return first+f_R(n-1, first+d, d, sum);
}

int order_1(int n, int a, int d){
	if (n==1) return a;
	return (n/2)*((2*a)+(n-1)*d);
}

int main (){
	int a =5;
	int d=2;
	int n=10; //term
	int sum=0;
	printf ("The sum of the first %i terms is: %i\n", n, f_I(n, a, d)); //iterative
	 //f_R(n, a, d, &sum); //recursive
	printf ("The sum of the first %i terms is: %i\n", n, f_R(n, a, d, &sum)); 
	printf ("\The sum of the first %i terms is: %i", n, order_1(n, a, d)); //order 1
}
