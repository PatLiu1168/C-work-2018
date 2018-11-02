//linear search to find the location of a given integer in an in array. (the locations range from 0-n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_I( int* A, int key, int n){ //iterative
	for (int i=0;i<n; i++){
		if (A[i]==key){
			return i;
		}
	}
	return -1; //if the key is invalid, the location will be -1
}

void f_R(int *A, int key, int n){ //recursive
	if (n < 1 ){ // can replace all of this with if (n>=1){ or (n>0)
		return;
	}
    else{
        f_R (A, key, n-1);
        if(A[n-1]==key){
            printf ("%i is at location %i\n",key, n-1);
        }
    }
    return; // the function doesn't print anything if the key is invalid. Nothing will be outputted
	
}


int main (){
	int A[20]={1,2,3,4,5,6,76,78,9,54,362,123,2687,13,456,56,665,39, 19, 20};
	int key=123;
	printf ("%i is at location %i\n",key, f_I(A, key, 20));
	f_R (A, key, 20);
}
