## Process this file with automake to produce Makefile.in

TESTS = check_card check_deck check_computerplayer check_blackjack
check_PROGRAMS = check_card check_deck check_computerplayer check_blackjack

check_card_SOURCES = check_card.c $(top_builddir)/src/card.h
check_card_CFLAGS = @CHECK_CFLAGS@
check_card_LDADD = $(top_builddir)/src/libcard.la @CHECK_LIBS@

check_deck_SOURCES = check_deck.c $(top_builddir)/src/deck.h
check_deck_CFLAGS = @CHECK_CFLAGS@
check_deck_LDADD = $(top_builddir)/src/libdeck.la @CHECK_LIBS@

check_computerplayer_SOURCES = check_computerplayer.c $(top_builddir)/src/computerplayer.h
check_computerplayer_CFLAGS = @CHECK_CFLAGS@
check_computerplayer_LDADD = $(top_builddir)/src/libcomputerplayer.la @CHECK_LIBS@

check_blackjack_SOURCES = check_blackjack.c $(top_builddir)/src/blackjack.h
check_blackjack_CFLAGS = @CHECK_CFLAGS@
check_blackjack_LDADD = $(top_builddir)/src/libblackjack.la @CHECK_LIBS@
