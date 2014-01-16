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

START_TEST (can_get_a_new_deck)
{
  ck_assert_msg(sut->count == 0, "Failed to Properly Initialize Deck");
}
END_TEST

START_TEST (new_deck_has_null_top)
{
  ck_assert_msg(sut->top == NULL, "Top Of New Deck Was Non-Null");
}
END_TEST

START_TEST (can_add_a_card_to_a_deck)
{
  Card *card = new_card(0,1);
  deck_push_card(sut, card);
  ck_assert_msg(sut->top->card->value == 1, "Failed to Properly Set Card Value");
}
END_TEST

START_TEST (deck_is_updated_when_card_added)
{
  Card *card = new_card(1,1);
  deck_push_card(sut, card);
  ck_assert_msg(sut->sum == 1, "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (deck_is_updated_when_two_cards_are_added)
{
  Card *card1 = new_card(1,1);
  Card *card2 = new_card(2,2);
  deck_push_card(sut, card1);
  deck_push_card(sut, card2);
  ck_assert_msg(sut->sum == (1 + 2), "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (deck_is_updated_when_card_removed_from_deck)
{
  Card *card1 = new_card(1,1);
  Card *card2 = new_card(2,2);
  deck_push_card(sut, card1);
  deck_push_card(sut, card2);
  deck_pop_card(sut);
  ck_assert_msg(sut->sum == (1), "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (valid_card_is_returned_from_deck)
{
  Card *card = new_card(1,1);
  deck_push_card(sut, card);
  Card *top_card = deck_pop_card(sut);
  ck_assert_msg(top_card->value == 1, "Failed to Retrieve Top Card");
}
END_TEST



Suite *
deck_suite (void)
{
  Suite *s = suite_create ("Deck");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_checked_fixture (tc_core, setup, teardown);
  tcase_add_test (tc_core, can_get_a_new_deck);
  tcase_add_test (tc_core, new_deck_has_null_top);
  tcase_add_test (tc_core, can_add_a_card_to_a_deck);
  tcase_add_test (tc_core, deck_is_updated_when_card_added);
  tcase_add_test (tc_core, valid_card_is_returned_from_deck);
  tcase_add_test (tc_core, deck_is_updated_when_card_removed_from_deck);
  
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
