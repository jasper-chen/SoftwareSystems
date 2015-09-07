/*
Software Systems
Jasper Chen
September 7, 2015
*/

#include <stdio.h>
#include <stdlib.h>

void *ask_user(char *card_name){
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
	return 0;
}

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
		case 'X':
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)){
				puts("I don't understand that value");
			}
		}
	return val;
};

int counter(int val){
	int count = 0;	
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;	
}

int main() {
	char card_name[3];
	while (card_name[0]!='X') {
		ask_user(card_name);
		int val = decide_value(card_name);
		int count = counter(val);
		printf("Current count: %i\n", count);
	}
	return 0;
}