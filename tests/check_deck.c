#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../src/deck.h"

Deck *sut;

void setup(void) {
  sut = new_deck();
}

void teardown(void) {
  delete_deck(sut);
}

START_TEST (can_get_a_new_empty_deck)
{
  ck_assert_msg(sut->count == 0,
                "Failed to Properly Initialize Deck");
}
END_TEST

START_TEST (new_deck_has_null_top)
{
  ck_assert_msg(sut->top == NULL,
                "Top Of New Deck Was Non-Null");
}
END_TEST

START_TEST (can_add_a_card_to_a_deck)
{
  Card *card = new_card(0,2);
  deck_push_card(sut, card);
  ck_assert_msg(sut->top->card->value == 2,
                "Failed to Properly Set Card Value");
}
END_TEST

START_TEST (deck_is_updated_when_card_added)
{
  Card *card = new_card(1,2);
  deck_push_card(sut, card);
  ck_assert_msg(sut->sum == 2,
                "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (deck_is_updated_when_two_cards_are_added)
{
  Card *card1 = new_card(1,2);
  Card *card2 = new_card(2,3);
  deck_push_card(sut, card1);
  deck_push_card(sut, card2);
  ck_assert_msg(sut->sum == (2 + 3),
                "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (deck_is_updated_when_card_removed_from_deck)
{
  Card *card1 = new_card(1,2);
  Card *card2 = new_card(2,3);
  deck_push_card(sut, card1);
  deck_push_card(sut, card2);
  deck_pop_card(sut);
  ck_assert_msg(sut->sum == (2),
                "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (valid_card_is_returned_from_deck)
{
  Card *card = new_card(1,2);
  deck_push_card(sut, card);
  Card *top_card = deck_pop_card(sut);
  ck_assert_msg(top_card->value == 2,
                "Failed to Retrieve Top Card");
}
END_TEST

START_TEST (can_get_a_complete_deck)
{
  Deck* sut_full = new_complete_deck();
  DeckNode* curr_node = sut_full->top;
  Card* curr_card;
  ck_assert_msg(sut_full->count == 52,
                "Failed to Properly Initialize Complete Deck");
}
END_TEST

START_TEST (should_be_able_to_swap_two_nodes) {
  Card *card1 = new_card(1,2);
  Card *card2 = new_card(2,3);
  deck_push_card(sut,card1);
  deck_push_card(sut,card2); // New Top
  deck_swap_cards(sut,(DeckNode*)sut->top,(DeckNode*)sut->top->below);
  ck_assert_msg(((DeckNode*)sut->top)->card == card1 && ((DeckNode*)((DeckNode*)sut->top)->below)->card == card2,
                "Cards were not swapped");
}
END_TEST

START_TEST (should_be_able_to_shuffle_a_deck)
{
  Deck *complete_deck = new_complete_deck();
  Card *orig_deck[52];
  int i, is_equal = 1;

  DeckNode *curr_node = (DeckNode*)complete_deck->top;

  for(i = 0; i<52; i++) {
    orig_deck[i] = curr_node->card;
    curr_node = (DeckNode*)curr_node->below;
  }

  deck_shuffle(complete_deck);
  curr_node = (DeckNode*)complete_deck->top;

  for(i = 0; i<52; i++) {
    if(curr_node->card != orig_deck[i]) {
      is_equal = 0;
      break;
    }
    curr_node = (DeckNode*)curr_node->below;
  }

  ck_assert_msg(is_equal == 0, "Deck did not change.");
}
END_TEST

START_TEST (should_be_able_to_get_the_nth_card_in_deck)
{
  Deck *complete_deck = new_complete_deck();
  DeckNode *my_node = get_nth_node(complete_deck, 2);
  Card *my_card = my_node->card;
  //0,2
  ck_assert_msg(my_card->suit == 3 && my_card->value == 12, "Got Wrong Card");
}
END_TEST

START_TEST (should_be_able_to_get_a_random_number_in_a_range) 
{
  int max = 5,
      min = 1,
      my_random = _uniform_distribution(min,max);
  
  ck_assert_msg( (min <= my_random) && (my_random <= max), "Out of bounds");
}
END_TEST

START_TEST (should_be_able_to_clone_a_deck) 
{
  Deck *complete_deck = new_complete_deck();
  Deck *complete_deck_copy = clone_deck(complete_deck);
  int i=0;
  for (i; i < 52; i++) {
    deck_pop_card(complete_deck_copy);
  }

  ck_assert_msg( complete_deck->count == 52, "Original deck was effected...");
}
END_TEST

START_TEST (changing_cards_in_cloned_deck_should_not_affect_original) 
{
  Deck *complete_deck = new_complete_deck();
  Deck *complete_deck_copy = clone_deck(complete_deck);
  complete_deck_copy->top->card->value = 99;

  ck_assert_msg( complete_deck_copy->top->card->value != complete_deck->top->card->value, "Original deck was effected...");
}
END_TEST

Suite *
deck_suite (void)
{
  Suite *s = suite_create ("Deck");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_checked_fixture (tc_core, setup, teardown);
  tcase_add_test (tc_core, can_get_a_new_empty_deck);
  tcase_add_test (tc_core, new_deck_has_null_top);
  tcase_add_test (tc_core, can_add_a_card_to_a_deck);
  tcase_add_test (tc_core, deck_is_updated_when_card_added);
  tcase_add_test (tc_core, valid_card_is_returned_from_deck);
  tcase_add_test (tc_core, deck_is_updated_when_card_removed_from_deck);
  tcase_add_test (tc_core, can_get_a_complete_deck);
  tcase_add_test (tc_core, should_be_able_to_swap_two_nodes);
  tcase_add_test (tc_core, should_be_able_to_shuffle_a_deck);
  tcase_add_test (tc_core, should_be_able_to_get_the_nth_card_in_deck);
  tcase_add_test (tc_core, should_be_able_to_get_a_random_number_in_a_range);
  tcase_add_test (tc_core, should_be_able_to_clone_a_deck);
  tcase_add_test (tc_core, changing_cards_in_cloned_deck_should_not_affect_original);



  suite_add_tcase (s, tc_core);

  return s;
}

int
main (void)
{
  int number_failed;
  Suite *s = deck_suite ();
  SRunner *sr = srunner_create (s);
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
