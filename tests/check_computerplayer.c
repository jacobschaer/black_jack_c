#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../src/computerplayer.h"

START_TEST (should_stand_if_they_have_21)
{
  Deck *sut = new_deck();
  Card *card1 = new_card(0,14);
  Card *card2 = new_card(0,7);
  deck_push_card(sut, card1);
  deck_push_card(sut,card2);
  ck_assert_msg ( stand(sut,sut) == 1, 
	       "Dealer didn't stand for 21");
}
END_TEST


Suite *
card_suite (void)
{
  Suite *s = suite_create ("Player AI");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_test (tc_core, should_stand_if_they_have_21);

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
