#include "computerplayer.h"

int stand(Deck *my_hand, Deck *opponent_hand) {
	if(my_hand->sum == 21) {
		return 1;
	} else {
		return 0;
	}
}