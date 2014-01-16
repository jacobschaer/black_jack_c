## Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libcard.la libdeck.la libcomputerplayer.la libblackjack.la

libcard_la_SOURCES = card.c card.h
libdeck_la_SOURCES = deck.c deck.h card.h card.c
libcomputerplayer_la_SOURCES = computerplayer.c computerplayer.h
libblackjack_la_SOURCES = blackjack.c blackjack.h deck.c deck.h card.h card.c

bin_PROGRAMS = main
main_SOURCES = main.c
main_LDADD = libcard.la libdeck.la libcomputerplayer.la libblackjack.la
