#ifndef CARD_H
#define CARD_H

#include "stdio.h"
#include "stdlib.h"

typedef struct {
	int suit;
	int value;
} Card;

char* card_str(Card *mycard);
Card* new_card(int suit, int value);
void delete_card(Card *mycard);

#endif /* CARD_H */