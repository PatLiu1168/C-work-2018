/*These fuctions outputs characters of a string in reverse order*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void f_I (char*s){ //iterative solution
	int n=strlen(s);
	for (int i=0; i<n; i++){
		printf ("%c", s[n-1-i]);
	}
}

void f_R(char*s){ //recursive solution
	if (*s){
		f_R(s+1);
		printf ("%c", *s);
	}
}


int main (){
	f_I("\ngood morn");
	f_R("\ngood morn");
}
