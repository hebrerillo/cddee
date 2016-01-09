#debug options
CDEBUG = -g

CC     = gcc
GCC    = gcc
CFLAGS = -Wall $(CDEBUG) 

SRCS_C = main.c list.c userFunctions.c
OBJS = $(SRCS_C:.c=.o)



%.o: %.c %.h
	@$(CC) -c -fPIC $(CFLAGS) $< -o $@

%.o: %.c
	@$(CC) -c -fPIC $(CFLAGS) $< -o $@

all: main list

main : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	

list: list.o
	@$(CC) -shared -o lib$@.so $<
	

.PHONY: clean
clean:
	-rm $(OBJS) main *.so
	
