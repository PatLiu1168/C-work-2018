//These fucntions output the characters of a string in reverse order but skip all char c's

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_I (char*s, char c){ //iterative solution
	int n=strlen(s);
	for (int i=1; i<=n; i++){
		if (s[n-i]!=c){
			printf ("%c", s[n-i]);
		}
	}
}

void f_R(char*s, char c){ //recursive solution
	if (*s){
		f_R(s+1, c);
		if (*s!=c){
			printf ("%c", *s);
		}
	}
}

int main (){
	f_I("\nsickooooood", 'o');
	f_R("\nggggggggggggh", 'g');
}
