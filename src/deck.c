#include "deck.h"

Deck* new_deck() {
	Deck* retval = malloc(sizeof(Deck));
	retval->sum = 0;
	retval->count = 0;
	retval->top = NULL;
	return retval;
}

void delete_deck(Deck* my_deck) {
	if(my_deck != NULL) {
		DeckNode *next_node;
		DeckNode *curr_node = my_deck->top;
		while(curr_node != NULL) {
			next_node = (DeckNode*)curr_node->next;
			delete_card(curr_node->card);
			free(curr_node);
			curr_node = next_node;
		}
		free(my_deck);
	}
}

void deck_push_card(Deck* my_deck, Card* my_card) {
	DeckNode* new_node = malloc(sizeof(DeckNode));
	/* Link Up New Node */
	new_node->card = my_card;
	new_node->next = NULL;
	new_node->previous = my_deck->top;

	/* Update Previous Top If Necessary */
	if (my_deck->top != NULL)  {
		my_deck->top->next = new_node;
	}

	/* Change Top of Deck */
	my_deck->top = new_node;

	/* Update Deck Properties */
	my_deck->count += 1;
	my_deck->sum += my_card->value;
}

Card* deck_pop_card(Deck* my_deck) {
	if(my_deck == NULL || my_deck->top == NULL) {
		return NULL;
	}
	else {
		Card *retval = my_deck->top->card;
		if (my_deck->top->previous != NULL) {
			my_deck->top = (DeckNode*)my_deck->top->previous;
		}
		else {
			my_deck->top = NULL;
		}
		return retval;
	}
}