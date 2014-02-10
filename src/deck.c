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
		DeckNode *curr_node = my_deck->top;
		DeckNode *next_node;
		while(curr_node != NULL) {
			next_node = (DeckNode*)curr_node->below;
			delete_card(curr_node->card);
			free(curr_node);
			curr_node = next_node;
		}
		free(my_deck);
	}
}

Deck* clone_deck(Deck* my_deck) {
	Deck *retval = new_deck();
	DeckNode *my_card = my_deck->top;
	int suit, value;
	do {
		suit = my_card->card->suit;
		value = my_card->card->value;
		deck_push_card(retval, new_card(suit, value));
	}
	while ((my_card = my_card->below) != NULL);
	return retval;
}

void deck_push_card(Deck* my_deck, Card* my_card) {
	DeckNode* new_node = malloc(sizeof(DeckNode));
	DeckNode* former_top_node = (DeckNode*)my_deck->top;

	/* Link Up New Node */
	new_node->card = (DeckNode*)my_card;
	new_node->above = NULL;
	new_node->below = former_top_node;

	/* Update below Top If Necessary */
	if (former_top_node != NULL)  {
		former_top_node->above = new_node;
	}

	/* Change Top of Deck */
	my_deck->top = new_node;

	/* Update Deck Properties */
	my_deck->count += 1;
	my_deck->sum += my_card->value;
}

DeckNode* get_nth_node(Deck* my_deck, int n) {
	DeckNode *curr_node = my_deck->top;
	int i = 0;
	for (i; i<n; i++) {
		curr_node = (DeckNode *)(curr_node->below);
		if (curr_node == NULL) {
			break;
		}
	}
	return curr_node;
}

void deck_swap_cards(Deck* deck, DeckNode* node1, DeckNode* node2) {
	Card* temp = node1->card;
	node1->card = node2->card;
	node2->card = temp;
}

int _uniform_distribution(int rangeLow, int rangeHigh)
{
    int range = rangeHigh - rangeLow;
    return ((rand()%range) + rangeLow);
}


void deck_shuffle(Deck* my_deck) {
	int i = 0 ,
		j = 0,
		n = my_deck->count;

    srand(time(NULL));
    for (i; i < n; i++) {
       j = _uniform_distribution(i, 52);
       deck_swap_cards(my_deck, get_nth_node(my_deck, i), get_nth_node(my_deck, j));
    }
}

Deck* new_complete_deck() {
	Deck* target_deck = new_deck();
	int suit, value;

	for(suit = 0; suit<4; suit++) {
		for(value = 2; value <=14; value++) {
			Card *curr_card = new_card(suit,value);
			deck_push_card(target_deck, curr_card);
		}
	}
	return target_deck;
}

Card* deck_pop_card(Deck* my_deck) {
	if(my_deck == NULL || my_deck->top == NULL) {
		return NULL;
	}
	else {
		Card *retval = my_deck->top->card;
		if (my_deck->top->below != NULL) {
			my_deck->top = (DeckNode*)my_deck->top->below;
			my_deck->sum -= retval->value;
			my_deck->count--;
		}
		else {
			my_deck->top = NULL;
			my_deck->sum = 0;
			my_deck->count = 0;
		}
		return retval;
	}
}
