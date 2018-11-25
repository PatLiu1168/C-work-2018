//This program outputs the the uppercase in order of appearance at the start, then the lowercase in reversed order at the end of the string 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_I (char*s){ //iterative solution
	int n=strlen(s);
	for (int i=1; i<=n; i++){
		if (s[i]>='A'&& s[i]<='Z'){
			printf ("%c", s[i]);
		}
	}
	
	for (int i=1; i<=n; i++){
		if (s[n-i]>='a'&& s[n-i]<='x'){
			printf ("%c", s[n-i]);
		}
	}
}

void f_R(char*s){ //recursive solution
	if (*s){
		if (*s>='A'&& *s<'Z'){
			printf("%c", *s);
		}
		f_R(s+1);
		if (*s>='a'&& *s<'z'){
			printf("%c", *s);
		} 
	}
}


int main (){
	f_I("gooIAMACOW MorN");
	printf ("\n");
	f_R("good NBSAmorn");
}
