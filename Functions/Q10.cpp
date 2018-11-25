//These functions finds the location of a given value in a integer array using binary search. (The location ranges from 0 - n)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void f_I(int*A, int first, int last, int key){
	int middle = (first+last)/2;
	while (first<=last){
		if (A[middle]< key){
			first=middle+1;
		}
		else if (A[middle] == key){
			printf ("The location of the number %i is index %i\n", key, middle);
			return;
		}
		else{
			last=middle-1;
		}
		middle=(first+last)/2;
	}
	printf("invalid, not found"); //prints of the key is not found in the array
}

void f_R(int *A, int first, int last, int key){
	int middle=(first+last)/2;
	if (first<=last){
		if (A[middle]==key){
		printf ("The location of the number %i is index %i\n", key, middle);
		return;
		}
		else if(A[middle]<key){
			f_R(A, middle+1, last, key);
		}
		else {
			f_R(A, first, middle-1, key);
		}
	}
	else{
		printf ("invalid");
		return;
	}
}

int main(){
	int A[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int key=11;
	f_I (A, 0, 19, key);
	f_R (A, 0, 19, key);
}
