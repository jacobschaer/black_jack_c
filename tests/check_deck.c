#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../src/deck.h"

START_TEST (can_get_a_new_deck)
{
  Deck* a = new_deck();
  ck_assert_msg(a->count == 0, "Failed to Properly Initialize Deck");
}
END_TEST

START_TEST (new_deck_has_null_top)
{
  Deck* a = new_deck();
  ck_assert_msg(a->top == NULL, "Top Of New Deck Was Non-Null");
  delete_deck(a);
}
END_TEST

START_TEST (can_add_a_card_to_a_deck)
{
  Deck* a = new_deck();
  Card* card = new_card(0,1);
  deck_push_card(a, card);
  ck_assert_msg(a->top->card->value == 1, "Failed to Properly Set Card Value");
  delete_card(card);
  delete_deck(a);
}
END_TEST

START_TEST (deck_is_updated_when_card_added)
{
  Deck* a = new_deck();
  Card* card = (Card*) malloc(sizeof(Card));
  card->suit = 1;
  card->value = 1;
  deck_push_card(a, card);
  ck_assert_msg(a->sum == 1, "Failed to Properly Increment Sum On Update");
}
END_TEST

START_TEST (valid_card_is_returned_from_deck)
{
  Deck* a = new_deck();
  Card* card = (Card*) malloc(sizeof(Card));
  card->suit = 1;
  card->value = 1;
  deck_push_card(a, card);
  Card* top_card = deck_pop_card(a);
  ck_assert_msg(top_card->value == 1, "Failed to Retrieve Top Card");

}
END_TEST



Suite *
deck_suite (void)
{
  Suite *s = suite_create ("Deck");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_test (tc_core, can_get_a_new_deck);
  tcase_add_test (tc_core, new_deck_has_null_top);
  tcase_add_test (tc_core, can_add_a_card_to_a_deck);
  tcase_add_test (tc_core, deck_is_updated_when_card_added);
  tcase_add_test (tc_core, valid_card_is_returned_from_deck);


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
