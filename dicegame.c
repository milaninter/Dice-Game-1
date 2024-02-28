#include "dicegame.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int getRandomNumber(int min, int max)
{
	//returns a random num
	
	int rndNum = rand() % (max - min + 1) + min;

	return rndNum;
}


ROUNDTYPE getRoundType()
{
	//determines the roundType based on prbability 20%, 30%, 50%
	
	int prd = getRandomNumber(0,9);

	if(prd < 2){
		return BONUS;
	}
	else if(prd < 5){
		return DOUBLE;
	}
	else{
		return REGULAR;
	}
}


int getRoundPoints(ROUNDTYPE roundType)
{
	//determines the round points based on the roundtype

	int pt = getRandomNumber(1,10) * 10;

	if(roundType == DOUBLE){
		return pt * 2;
	}
	else if(roundType == BONUS){
		pt = 200;

		return pt;
	}
	else{
		return pt;
	}
}


void printPlayerPoints(int p1, int p2)
{
	printf("P1\t: %d\n", p1);

	printf("P2\t: %d\n", p2);
}


void printRoundInfo(ROUNDTYPE t, int dice, int points)
{

	printf("Type\t: ");

	switch(t){
		case BONUS:
			printf("BONUS\n");
			break;
		case DOUBLE:
			printf("DOUBLE\n");
			break;
		case REGULAR:
			printf("REGULAR\n");
			break;
	}

	printf("DICE\t: %d\n", dice);

	printf("POINTS\t: %d\n", points);
}

