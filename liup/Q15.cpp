/*Function comptutes the value of a string by giving:
lowercase-2 points
uppercase-10 points
numbers-30 points
others- 1 point
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int f_I(char*s){
	int count=0;
	while (*s){
		if (*s>='a'&& *s<='z'){
			count +=2;
		}
		else if (*s>='A'&& *s<='Z'){
			count +=10;
		}
		else if (*s>='0'&& *s<='9'){
			count +=30;
		}
		else{
			count++;
		}
		s++;
	}
	return count;
}

int f_R(char* s){
	if (*s){
		if (*s>='a'&& *s<='z'){
			return 2 +f_R(s+1);
		}
		else if (*s>='A'&& *s<='Z'){
			return 10+f_R(s+1);
		}
		else if (*s>='0'&& *s<='9'){
			return 30+f_R(s+1);
		}
		else{
			return 1+f_R(s+1);
		}
	}
}

int main(){
	char string[10]={"abH.R234K"};
	printf ("The value is %i\n", f_I(string));
	printf ("The value is %i", f_R(string));
}
