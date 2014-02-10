#include "blackjack.h"

int is_busted(Deck* player_deck) {
	return player_deck->sum > 21;
}

Game* new_game() {
	Game *retval = malloc(sizeof(Game));
	retval->player_one_hand = new_deck();
	retval->player_two_hand = new_deck();
	Deck *table_deck = new_complete_deck();
	deck_shuffle(table_deck);
	retval->table_deck = table_deck;
	return retval;
}