//These functions convert a given base into decimal. The base must be between 2 and 16 however, we assume the passed base WILL BE VALID (based of assignement criteria).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int f_I( char *s, int base){ //iterative
	int i=0;
	int dn=0;
	
	while (s[i]){
		if (s[i]>='0'&& s[i]<='9'&& (s[i]-'0')< base){ //prevents values greater than base from being entered
			dn=base*dn+s[i]-'0';
		}
		else if (s[i]>='A' && s[i]<='F'&& (s[i]-'A'+10)< base){//prevents values greater than base from being entered
			dn = base * dn + s[i] - 'A' + 10;
			printf ("%c", s[i]);
		}
		else break; //breaks if invalid
		
		i++;
	}
	return dn;
}

int f_R(char *s, int base, int number){
	int dn=0;
	if (*s){
		if (*s>='0'&&*s<='9'&& (*s-'0')< base){
			return f_R(s+1, base, base*number+*s-'0');
		}
		else if (*s>='A' && (*s-'A'+10)< base){
			return f_R(s+1, base, base*number+*s-'A'+10);
		}
		else return number;//returns already converted characters and exits if invalid
	}
	return number;
}




int main (){
	int base=12;
	char *number ="9B";
	int temp=0;
	printf ("Convert \"%s\" with a base of %i to decimal : %i\n", number, base, f_I(number, base));
	printf ("Convert \"%s\" with a base of %i to decimal : %i", number, base, f_R(number, base, temp));
}
