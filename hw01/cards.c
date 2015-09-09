/*
Software Systems
Jasper Chen
September 7, 2015
*/

#include <stdio.h>
#include <stdlib.h>

int count = 0;

/* Prompts user for input and puts the reply in the buffer.
	card_name: buffer where result is stored
*/	

void ask_user(char *card_name){
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
/*	return 0;*/
}

/* Maps card value on user's input 
	card_name: array of chars on user's input */

int decide_value(char card_name[]){
	int val;
	switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)){
				puts("I don't understand that value");
			}
	}
	return val;
}

/* Changes count value based on card value
	val: card value */

int counter(int val){	
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;	
}

int main() {
	char card_name[3];
	int val;
	while (card_name[0]!='X') {
		ask_user(card_name);
		val = decide_value(card_name);
		counter(val);
		printf("Current count: %i\n", count);
	}
	return 0;
}
