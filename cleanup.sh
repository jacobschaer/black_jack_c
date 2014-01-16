rm -f aclocal.m4 config.h config.h.in config.log config.status configure libtool Makefile Makefile.in stamp-h1
rm -rf autom4te.cache/ build-aux/
cd src
rm *.lo *.la Makefile Makefile.in main
cd ../tests
rm -f check_card check_deck *o Makefile.in Makefile