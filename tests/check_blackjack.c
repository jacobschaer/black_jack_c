#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../src/blackjack.h"

START_TEST (should_be_able_to_tell_if_an_empty_deck_has_busted)
{
  Deck *sut = new_deck();
  ck_assert_msg (is_busted(sut) == 0, 
	       "Empty Decks Shouldn't Bust");
}
END_TEST

START_TEST (should_be_able_to_tell_if_a_busted_deck_has_busted)
{
  Deck *sut = new_deck();
  Card* card1 = new_card(1, 11);
  Card* card2 = new_card(2, 12);
  deck_push_card(sut,card1);
  deck_push_card(sut,card2);
  ck_assert_msg (is_busted(sut) == 1, 
         "23 Point Deck Should Bust");
}
END_TEST

START_TEST (a_deck_with_21_cards_is_not_busted)
{
  Deck *sut = new_deck();
  Card* card1 = new_card(1, 10);
  Card* card2 = new_card(2, 11);
  deck_push_card(sut,card1);
  deck_push_card(sut,card2);
  ck_assert_msg (is_busted(sut) == 0, 
         "Deck with 21 Cards Is Not Busted");
}
END_TEST

START_TEST (should_be_able_to_create_new_game)
{
   Game *sut = new_game();
   ck_assert_msg (sut != NULL, "Must Make Non-Null Game");
}
END_TEST

START_TEST (players_should_start_game_with_no_cards)
{
   Game *sut = new_game();
   ck_assert_msg (((Deck*)sut->player_one_hand)->sum == 0 && ((Deck*)sut->player_two_hand)->sum == 0,
    "Players Should Start With No Cards");
}
END_TEST

START_TEST (table_deck_should_start_with_52_cards)
{
   Game *sut = new_game();
   ck_assert_msg (((Deck*)sut->table_deck)->count == 52,
    "Deck Should Start With 52 Cards");
}
END_TEST

Suite *
card_suite (void)
{
  Suite *s = suite_create ("Blackjack");

  /* Bust test case */
  TCase *tc_core = tcase_create ("Game Methods");
  tcase_add_test (tc_core, should_be_able_to_tell_if_an_empty_deck_has_busted);
  tcase_add_test (tc_core, should_be_able_to_tell_if_a_busted_deck_has_busted);
  tcase_add_test (tc_core, a_deck_with_21_cards_is_not_busted);
  tcase_add_test (tc_core, should_be_able_to_create_new_game);
  tcase_add_test (tc_core, players_should_start_game_with_no_cards);
  tcase_add_test (tc_core, table_deck_should_start_with_52_cards);



  suite_add_tcase (s, tc_core);

  return s;
}

int
main (void)
{
  int number_failed;
  Suite *s = card_suite ();
  SRunner *sr = srunner_create (s);
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
