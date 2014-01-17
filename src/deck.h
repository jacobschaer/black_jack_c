#ifndef DECK_H
#define DECK_H

#include "stdio.h"
#include "stdlib.h"
#include "card.h"

typedef struct {
	struct DeckNode *above;
	struct DeckNode *below;
	Card* card;
} DeckNode;

typedef struct {
	int sum;
	int count;
	DeckNode* top;
} Deck;


Deck* new_deck();
void delete_deck(Deck* my_deck);
void deck_push_card(Deck* my_deck, Card* my_card);
void deck_shuffle(Deck* my_deck);
Deck* new_complete_deck();
Card* deck_pop_card(Deck* my_deck);

void deck_swap_cards(Deck* deck, DeckNode* node1, DeckNode* node2);

#endif /* DECK_H */