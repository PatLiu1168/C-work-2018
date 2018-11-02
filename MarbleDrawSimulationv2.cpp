/*
    Created by Patricia Liu
    
    This program asks the user for several properties (the number of games, the number of draws, the number of marble colours, and frequency of each colour of marble) 
	Then, it simulates drawing a certain number of marbles for a certain number of games (both user provided values).
	The program then gets a number from the user corresponding to a colour of marble and prints the probability distribution table of this colour.
	The program also prints the probability of having a game with no repeated marble colours.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_DRAWS 2
#define MAX_DRAWS 100
#define MIN_GAMES 1000
#define MAX_GAMES 500000
#define MIN_COLOURS_IN_BAG 2
#define MAX_COLOURS_IN_BAG 8
#define MAX_MARBLES_IN_BAG 100


typedef struct {
    char coloursInBag [MAX_COLOURS_IN_BAG] [20];
    int colourDist [MAX_COLOURS_IN_BAG];
    int cumFreqColourDist[MAX_COLOURS_IN_BAG]; // simplifies drawing marble
    int totalMarblesInBag;    
    int numColours;     // bag will have have up to eight colours
} marbleBagType;

int rb(int min, int max){
    // go online to determine what the rand function does
	return rand()%(max-min+1) + min;
}

void getNumDraws(int *numDraws, int minDraws, int maxDraws){
    char temp [120];
    int valid;
    
    do {
        printf ("How many marbles do you wish to draw (with replacement)?\n");
        printf ("Enter an integer between %i and %i inclusive: ", MIN_DRAWS, MAX_DRAWS);
        gets (temp);
        *numDraws = atoi (temp);
        valid = *numDraws >= MIN_DRAWS && *numDraws <= MAX_DRAWS;
        if (!valid){
            printf ("Invalid Input ... Please try again ...\n\n");
            system ("pause");
            system ("cls");
        }
    } while (!valid);
    // now have a valid number of draws
}


void getNumGames(int *numGames, int minGames, int maxGames){
    char temp [120];
    int valid;
    
    do {
        printf ("How many games do you wish to play?\n");
        printf ("Enter an integer between %i and %i inclusive: ", MIN_GAMES, MAX_GAMES);
        gets (temp);
        *numGames = atoi (temp);
        valid = *numGames >= MIN_GAMES && *numGames <= MAX_GAMES;
        if (!valid){
            printf ("Invalid Input ... Please try again ...\n\n");
            system ("pause");
            system ("cls");
        }
    } while (!valid);
    // now have a valid number of games
}

int getNumColours (int minColours, int maxColours){
	char temp [120];
    int valid;
    int numColours;
    
    do {
        printf ("How many colours of marbles do you wish to have\n");
        printf ("Enter an integer between %i and %i inclusive: ", minColours, maxColours);
        gets (temp);
        numColours = atoi (temp);
        valid = numColours >= minColours && numColours <= maxColours;
        if (!valid){
            printf ("Invalid Input ... Please try again ...\n\n");
            system ("pause");
            system ("cls");
        }
        else {
        	return numColours;
		}
    } while (!valid); //now have a valid number of marble colours
}

void getColours (marbleBagType *mb){
	int i=0;
	char temp [20];
	while (i<mb->numColours){
		printf("Enter colour #%i: ", i+1);
		gets (temp);
		strcpy (mb->coloursInBag[i], temp);
		i++;
	}//now all colours have a name
}

void getNumMarbles (marbleBagType * mb){
	char temp [120];
	int i=0;
	mb->totalMarblesInBag=0;
	
	while (i<mb->numColours){
		printf ("How many %s marbles do you wish to have in the bag\n", mb->coloursInBag[i]);
        printf ("Enter an integer between 0 and %i:  ", MAX_MARBLES_IN_BAG);
        gets (temp);
        mb->colourDist[i] = atoi (temp);
        
        if (mb->colourDist[i] >= 0 && mb->colourDist[i] <= MAX_MARBLES_IN_BAG){
        	if (mb->totalMarblesInBag+ mb->colourDist[i]> MAX_MARBLES_IN_BAG){
            	printf ("Invalid Input...Total Number of Marbles in Bag Exceeds Limit ... Please try again ...\n\n");
            	printf ("Remaining Marbles Available: %i\n", MAX_MARBLES_IN_BAG-mb->totalMarblesInBag);
            	system ("pause");
            	system ("cls");
        	}else{
        		mb->totalMarblesInBag=mb->totalMarblesInBag+ mb->colourDist[i];
        		mb->cumFreqColourDist[i]=mb->totalMarblesInBag;
        		printf ("Remaining Marbles Available: %i\n\n", MAX_MARBLES_IN_BAG-mb->totalMarblesInBag);
        		i++;
			}
		}else{
        	printf ("Invalid Input ... Please try again ...\n\n");
            system ("pause");
            system ("cls");
		}//now each colour has a certain number of marbles in the bag
	}
}

/*
    This function obtains the properties of the marble bag
    For now these properties have been hard-coded to reflect the 
    requirements of your first simulation program
    
    I will set up the cumulative frequency distribution here to help with
    randomly drawing a marble from the bag
*/
void getMarbleBag (marbleBagType *mb){
    mb->numColours = getNumColours(MIN_COLOURS_IN_BAG, MAX_COLOURS_IN_BAG);
    printf("\n");
    getColours (mb);
    printf("\n");
    getNumMarbles (mb);
}

/*
    Use this function to display the contents of the bag of marbles
*/
void outputMarbleBag (marbleBagType mb){
	int i=0;
    printf ("Colour\t\tFrequency\n");
    for (i = 0; i < mb.numColours; i++){
        printf ("%s\t\t%6i\n", mb.coloursInBag[i], mb.colourDist[i]);
    }
    printf("\n");
}

/*
    This function simulates a single game
*/
void playGame (int fdt[][MAX_DRAWS+1], marbleBagType mb, int n, int* noRep){
    int temp=0;
    int colourCounter[mb.numColours];
    int sameMarb=0;
    for (int i = 0; i <= mb.numColours; i++) colourCounter[i] = 0;
    
    for (int j = 1; j <=n; j++){
    	temp = rb(1, mb.totalMarblesInBag);
    	if (temp <= mb.cumFreqColourDist[0]){
    		colourCounter[0]++;
		}else {
			for (int k = 1; k < mb.numColours; k++){
				if (temp<= mb.cumFreqColourDist[k]&& temp>mb.cumFreqColourDist[k-1]) colourCounter[k]++;
			}
		}
    }
    
    for (int h = 0; h < mb.numColours; h++){
    	fdt[h][colourCounter[h]]++;
	}
	
	for (int m=0; m < mb.numColours; m++){// for loop determines if there are matching colours
		if (colourCounter[m]>1) sameMarb++;
	}
	
	if (sameMarb==0) (*noRep)++; //increment if the marbles drawn are all different
}

/*
    For this simulation we will determine the probability distribution for the 
    number of pink marbles drawn ... the first colour
*/
void doSimulation (int fdt[][MAX_DRAWS+1], marbleBagType mb, int n, int g, int * noRep){
    for (int i = 0; i < MAX_COLOURS_IN_BAG; i++){
    	for (int j =0; j<=MAX_DRAWS; j++){
    		fdt[i][j] = 0;// initialize fdt 
		}
	}
    // play games
    for (int i = 1; i <= g; i++){
        playGame(fdt, mb, n, noRep);
    }   
}


void outputSimResults (int fdt[][MAX_DRAWS+1], int n, marbleBagType mb, int g, int noRep){
	int marbleColour;
	printf ("Enter a number corresponding to the marble colour frequency table you wish to print: \n");
	for ( int j=0; j<mb.numColours; j++){
		printf (" %i) %s\n", j, mb.coloursInBag[j]);
	}
	scanf ("%i", &marbleColour);
	
    printf ("\nHere is the Frequency Distribution Table for #%s Marbles Drawn\n", mb.coloursInBag[marbleColour]);
    printf ("#%s\t\tFrequency\t\tProbability\n", mb.coloursInBag[marbleColour]);
    for (int i= 0; i <= n; i++){
        printf("%4i\t\t%8i\t\t\%0.2f%%\n", i, fdt[marbleColour][i], ((float)fdt[marbleColour][i]/(float)g)*100);
    }
    
    printf ("Probability of no repetition in draws: %0.2f%%\n", ((float)noRep/(float)g)*100);
}

int main (){
    marbleBagType marbleBag;
    int fdt [MAX_COLOURS_IN_BAG][MAX_DRAWS+1];
    int numDraws;       // number of marbles drawn from bag
    int numGames;       // number of games to be simulated
    int numNoRep=0; //number of times there are no repeats in draws
    
    srand (time(NULL)); // Don't delete this!
    
    printf("Welcome to my program!\nThis program will simulate drawings marbles out of a bag (with replacements)\nand will create a probability distribution table of your choosing.\n");
    printf("The program will ask several values from you (the user) and in order for the\nprogram to run as efficiently as possible, please enter valid numbers.\n");
    printf("Enjoy!\n____________________________________________\n");
    
    
    getNumDraws(&numDraws, MIN_DRAWS, MAX_DRAWS);
    printf("\n");
    getNumGames (&numGames, MIN_GAMES, MAX_GAMES);
    printf("\n");
    getMarbleBag (&marbleBag);  
    outputMarbleBag(marbleBag);
    doSimulation (fdt, marbleBag, numDraws,numGames, &numNoRep);
    outputSimResults (fdt, numDraws, marbleBag, numGames, numNoRep);
    
    system ("pause");
}
