/*
    Created by Patricia Liu
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define MIN_DRAWS 2
#define MAX_DRAWS 100
#define MIN_GAMES_PLAYED 1000
#define MAX_GAMES_PLAYED 50000

int rb (int min, int max){
	return rand() % (max + 1 - min) + min;;
}

void getNumDraws(int * x, int min, int max){
	char s[10];
	int temp=0;
	while (1){
		printf ("Enter the number of draws (between %i and %i inclusive): ",min, max);
		temp=atoi(gets(s));
		if (temp<=max && temp>=min){
			*x=temp;
			system ("cls");
			return;
		}
		system ("cls");	
	}
}

void getGamesDraws(int * x, int min, int max){
	char s[10];
	int temp=0;
	while (1){
		printf ("Enter the number of draws (between %i and %i): ",min, max);
		temp=atoi(gets(s));
		if (temp<=max && temp>=min){
			*x=temp;
			system ("cls");
			return;
		}
		system ("cls");	
	}
}

void doSim (int * A, int n, int g, int * mbd){
    memset(A, 0, (MAX_DRAWS+1)*sizeof(A[0]));
	char bag[10][10]={"pink", "black", "pink", "pink", "black"};
	int marble=0; //temp
    int numPink;
    int numBlack;
    int i, j;
    for (i=0;i<g;i++){
    	numPink=0;
    	numBlack=0;
        for (j=0;j<n;j++){
            marble=rb(0,4);
            if (strcmp("pink",bag[marble])==0) {
              	numPink++;
            }
			else if(strcmp("black",bag[marble])==0){
				numBlack++;
			}
        }
        A[numPink]++;
        if (numBlack>=numPink){
        	*mbd+=1;
		}
    }
}

void outputSimResult (int * A, int n, int g, int mbd){
	int i;
	for (i=0; i<=n; i++){
    	printf("%i, %i, %0.2f\n", i, A[i], ((float)A[i]/(float)g)*100);
    }
    printf ("The probability of getting as many black as pink marbles is %0.2f", ((float)mbd/(float)g)*100);
}

int main(){
	srand(time(NULL));
	int freqDistTable[MAX_DRAWS+1];
	
	int moreBlackDrawn=0;
	int numDraws;//get from user
	int numGamesPlayed;//#of trials-get from user
	
	getNumDraws(&numDraws, MIN_DRAWS, MAX_DRAWS);
	getGamesDraws(&numGamesPlayed, MIN_GAMES_PLAYED, MAX_GAMES_PLAYED);	
	doSim (freqDistTable, numDraws, numGamesPlayed, &moreBlackDrawn);
	outputSimResult(freqDistTable, numDraws, numGamesPlayed, moreBlackDrawn);
}

