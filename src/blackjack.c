#include "blackjack.h"

int is_busted(Deck* player_deck) {
	return player_deck->sum > 21;
}

Game* new_game() {
	Game *retval = malloc(sizeof(Game));
	retval->player_one_hand = new_deck();
	retval->player_two_hand = new_deck();
	Deck *table_deck = new_deck();

	int suit, value;

	for(suit = 0; suit<4; suit++) {
		for(value = 1; value <=13; value++) {
			Card *curr_card = new_card(suit,value);
			deck_push_card(table_deck, curr_card);
		}
	}

	retval->table_deck = table_deck;

	return retval;
}