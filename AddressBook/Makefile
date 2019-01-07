# ################ template makefile ##############
# # We don't know what compiler to use to build fltk on this machine - but fltk-config does...
# CC  = $(shell fltk-config --cc)
# CXX = $(shell fltk-config --cxx)
#
# # Set the flags for compiler: fltk-config knows the basic settings, then we can add our own...
# CFLAGS   = $(shell fltk-config --cflags) -Wall -O3 -I/other/include/paths...
# CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -O3 -I/other/include/paths...
#
# # We don't know what libraries to link with: fltk-config does...
# LINKFLTK = $(shell fltk-config --ldstaticflags)
# LINKFLTK_GL = $(shell fltk-config --ldstaticflags)
# LINKFLTK_IMG = $(shell fltk-config --use-images --ldstaticflags)
#
# # Possible steps to run after linking...
# STRIP      = strip
# POSTBUILD  = fltk-config --post # Required on OSX, does nothing on other platforms, so safe to call
#
#
# # Define what your target application is called
# all: tryThis
#
# # Define how to build the various object files...
# AddressIO.o: AddressIO.C AddressIO.h Contact.h
# 	$(CC) -c $< $(CCFLAGS)
#
# Auxillary.o: Auxillary.C Auxillary.h
# 	$(CC) -c $< $(CCFLAGS)
#
# Contact.o: Contact.C Contact.h Auxillary.h
# 	$(CC) -c $< $(CCFLAGS)
#
# Book.o: Book.C Book.h Contact.h Auxillary.h AddressIO.h
# 	$(CC) -c $< $(CCFLAGS)
#
# AddressBook.o: AddressBook.C AddressBook.h Book.h Contact.h Auxillary.h # a "plain" C file
# 	$(CC) -c $< $(CCFLAGS)
#
# GUI.o: GUI.C AddressBook.h  # a C++ file
# 	$(CXX) -c $< $(CXXFLAGS)
#
# # Now define how to link the final app - let's assume it needs image and OpenGL support
# tryThis:  GUI.o AddressBook.o Book.o Contact.o Auxillary.o AddressIO.o
# 	$(CXX) -o $@ GUI.o AddressBook.o Book.o Contact.o Auxillary.o AddressIO.o $(LINKFLTK_IMG) $(LINKFLTK_GL)
# 	$(STRIP) $@
# 	$(POSTBUILD) $@  # only required on OSX, but call it anyway for portability
#

TARGET = test
CC = g++
CFLAGS = -g -c

all: test testcontact testbook testaddressbook

Auxillary.o: Auxillary.C
	$(CC) $(CFLAGS) $< -o $@
Contact.o: Contact.C
	$(CC) $(CFLAGS) $< -o $@
Book.o: Book.C
	$(CC) $(CFLAGS) $< -o $@
AddressBook.o: AddressBook.C
	$(CC) $(CFLAGS) $< -o $@
test1P1.o: test1P1.C
	$(CC) $(CFLAGS) $< -o $@
TestContact.o: TestContact.C
	$(CC) $(CFLAGS) $< -o $@
TestBook.o: TestBook.C
	$(CC) $(CFLAGS) $< -o $@
TestAdressBook.o: TestAddressBook.C
	$(CC) $(CFLAGS) $< -o $@
test: test1P1.o Book.o Contact.o Auxillary.o
	$(CC) $^ -o $@
testcontact: TestContact.o Contact.o Auxillary.o
	$(CC) $^ -o $@
testbook: TestBook.o Contact.o Book.o Auxillary.o
	$(CC) $^ -o $@
testaddressbook: TestAddressBook.o Contact.o Book.o AddressBook.o Auxillary.o
	$(CC) $^ -o $@

clean:
	rm *.o
	rm test
	rm testcontact
	rm testbook
	rm testaddressbook
