## Process this file with automake to produce Makefile.in

TESTS = check_card check_deck
check_PROGRAMS = check_card check_deck
check_card_SOURCES = check_card.c $(top_builddir)/src/card.h
check_card_CFLAGS = @CHECK_CFLAGS@
check_card_LDADD = $(top_builddir)/src/libcard.la @CHECK_LIBS@

check_deck_SOURCES = check_deck.c $(top_builddir)/src/deck.h libdeck.la
check_deck_CFLAGS = @CHECK_CFLAGS@
check_deck_LDADD = $(top_builddir)/src/libdeck.la @CHECK_LIBS@
