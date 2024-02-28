#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main(int argc, char* argv[]){

	srand(time(NULL));

	int p1 = 0;

	int p2 = 0;

	int numRnd;

	printf("Enter the number of rounds: ");

	scanf("%d", &numRnd);

	printPlayerPoints(p1,p2);
	
        int i;

	int currentP = getRandomNumber(1,2);

        for(i = 1; i <= numRnd; i++){
		// this loop will give out the ouput based on the game rules	
	
                printf("\nROUND %d\n", i);

		printf("--------\n");

		printf("Player\t: %d\n", currentP);

                ROUNDTYPE roundType = getRoundType();

                int dice = getRandomNumber(1,6);

                int points = getRoundPoints(roundType);

                printRoundInfo(roundType, dice, points);

		//these if statements enforce the game rules and point distribution

		if ((currentP == 1 && dice % 2 != 0) || (currentP == 2 && dice % 2 == 0)) {
          
          		if (currentP == 1) {
               			p1 += points;
            		}
			else {
                		p2 += points;
            		}
        	}
		else {
       
            		if (currentP == 1) {
                		p1 -= points;
                		currentP = 2; // Change to the other player
            		} 
			else {
                		p2 -= points;
                		currentP = 1; // Change to the other player
            		}
        	}
	printPlayerPoints(p1,p2);
} 

	printf("\nGAME OVER!!\n");
	
	// these if statements determine the winner

	if(p1 > p2) {
        	printf("P1 Won\n");
    	} 
	else if(p2 > p1) {
        	printf("P2 Won\n");
    	} 
	else{
        	printf("It's a tie!\n");
    	}
               
        return 0;


}
