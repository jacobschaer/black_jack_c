#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"

typedef struct {
	struct Deck *player_one_hand;
	struct Deck *player_two_hand;
	struct Deck *table_deck;
} Game;

int is_busted(Deck* player_deck);
Game* new_game();

#endif /* BLACKJACK_H */