#include "card.h"

char* card_str(Card *mycard) {
	char *out_str = malloc(20 * sizeof(char)); // Buffer

	const char *suits[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
	const char *royalty[4] = {"Jack","Queen","King","Ace"};

	int value = mycard->value;
	int suit = mycard->suit;


	if (value >= 11) {
		sprintf(out_str, "%s of %s", royalty[value - 11], suits[suit]);
	}
	else {
		sprintf(out_str, "%i of %s", value, suits[suit]);
	}
	return out_str;
}

Card* new_card(int suit, int value) {
	Card *retval = malloc(sizeof(Card));
	retval->suit = suit;
	retval->value = value;
	return retval;
}

void delete_card(Card *mycard) {
	free(mycard);
}