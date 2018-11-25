//This program counts number of tiomes a given character occurs in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_I (char*s, char c){ //iterative solution
	int count=0;
	int i=0;
	while (s[i]){
		if (s[i]==c){
			count++;
		}
		i++;
	}
	return count;
}

int f_R (char *s, char c){
	if (*s){
		if (*s==c){
			return 1+f_R(s+1, c);
		}
		else{
			return f_R (s+1, c);
		}
	}
	else {
		return 0;
	}
}

int main (){
	printf("Number of a's in \"I am an apple\": %i \n", f_I("I am an apple", 'a'));
	printf("Number of p's in \"I am an apple\": %i", f_R("I am an apple", 'p'));

}
