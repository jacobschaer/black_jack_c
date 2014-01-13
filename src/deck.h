#ifndef DECK_H
#define DECK_H

#include "stdio.h"
#include "stdlib.h"
#include "card.h"

typedef struct {
	struct DeckNode *previous;
	struct DeckNode *next;
	Card* card;
} DeckNode;

typedef struct {
	int sum;
	int count;
	DeckNode* top;
} Deck;


Deck* new_deck();
void delete_deck(Deck* my_deck;);
void deck_push_card(Deck* my_deck, Card* my_card);
Card* deck_pop_card(Deck* my_deck);

#endif /* DECK_H */