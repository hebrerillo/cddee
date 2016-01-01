#debug options
CDEBUG = -g

CC     = gcc
GCC    = gcc
CFLAGS = -Wall $(CDEBUG) 




%.o: %.c %.h
	@$(CC) -c $(CFLAGS) $< -o $@

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

OBJS = main.o list.o


main : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	\rm list
	\find . -name '*.o' -delete
