ACLOCAL_AMFLAGS = -I m4 --install
SRC_DIR = src

DEVFLAGS = -Wall -Werror

bin_PROGRAMS = test
test_SOURCES = $(SRC_DIR)/test.c\
		$(SRC_DIR)/list.c $(SRC_DIR)/list.h\
		$(SRC_DIR)/userFunctions.h $(SRC_DIR)/userFunctions.c
	
test_CFLAGS = $(DEVFLAGS)

lib_LTLIBRARIES = liblist.la
liblist_la_SOURCES = $(SRC_DIR)/list.h $(SRC_DIR)/list.c
