#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../src/card.h"

START_TEST (can_make_a_card)
{
  Card *a = new_card(0,1);
  ck_assert_msg (a->suit == 0, 
	       "Card doesn't have right suit");
  delete_card(a);
}
END_TEST

START_TEST (can_get_a_string_of_a_card_no_royalty)
{
  Card *a = new_card(0,1);
  char *my_str = card_str(a);
  char *test_result = "1 of Spades";
  ck_assert_msg (strcmp(my_str, test_result) == 0, 
         "Output Did Not Match");
  delete_card(a);
}
END_TEST

START_TEST (can_get_a_string_of_a_card_royalty)
{
  Card *a = new_card(0,11);
  char *my_str = card_str(a);
  char *test_result = "Jack of Spades";
  ck_assert_msg (strcmp(my_str, test_result) == 0, 
         "Incorrect Output");
  delete_card(a);
}
END_TEST

Suite *
card_suite (void)
{
  Suite *s = suite_create ("Cards");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_test (tc_core, can_make_a_card);
  tcase_add_test (tc_core, can_get_a_string_of_a_card_no_royalty);
  tcase_add_test (tc_core, can_get_a_string_of_a_card_royalty);

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
