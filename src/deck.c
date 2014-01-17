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

void deck_shuffle(Deck* my_deck) {
	printf("\n\nShuffling...\n\n");
}

Deck* new_complete_deck() {
	Deck* target_deck = new_deck();
	int suit, value;

	for(suit = 0; suit<4; suit++) {
		for(value = 1; value <=13; value++) {
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

void deck_swap_cards(Deck* deck, DeckNode* node1, DeckNode* node2) {
	Card* temp = node1->card;
	node1->card = node2->card;
	node2->card = temp;

	// /* IF THERE IS SOME REASON FOR DEEP SWAPPING */
	// DeckNode* temp;

	// /* Swap 'below' */
	// temp = node1->below;
	// node1->below = node2->below;
	// node2->below = temp;

	// /* Swap 'above' */
	// temp = node1->above;
	// node1->above = node2->above;
	// node2->above = temp;

	// /* Reset 'top' of deck */

	// if (node1->above == NULL) {
	// 	deck->top = node1;
	// }
	// else if(node2->above == NULL) {
	// 	deck->top = node2;
	// }

	// /* Fix 'below' nodes */
	
	// if(node1->below != NULL) {
	// 	((DeckNode*)node1->below)->above = node2;
	// }
	// if(node2->below != NULL) {
	// 	((DeckNode*)node2->below)->above = node1;
	// }

	// /* Fix 'above' nodes */
	// if(node1->above != NULL) {
	// 	((DeckNode*)node1->above)->below = node2;
	// }
	// if(node2->above != NULL) {
	// 	((DeckNode*)node2->above)->below = node1;
	// }

}
